#include <iostream>
#include <conio.h>
#include <assert.h>
#include <list>
#include "AddMonster.h"
#include "MonsterAI.h"
#include "RemoveMonster.h"
#include "GLib.h"
#include "Timer.h"
#include "KeyInput.h"
#include "GameObject.h"
#include "Physics.h"
#include "FloatHelperTest.h"
#include "SmartPointer.h"
#include "WeakPointer.h"
#include "RenderSprite.h"
#include "CreateActor.h"
#include "JobSystem.h"
#include "MatrixTest.h"
#include "Vector4Test.h"
#include "CollisionTest.h"
#include "Bullet.h"

#if defined _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif // _DEBUG

using namespace std;
using namespace _AddMonster;
using namespace _RemoveMonster;
using namespace _MonsterAI;

int WINAPI wWinMain(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow) 
{
	//screen size
	const int screenWidth = 1000;
	const int screenHeight = 600;

	bool bSuccess = GLib::Initialize(i_hInstance, i_nCmdShow, "MonsterChase", -1, screenWidth, screenHeight, true);

	if (bSuccess)
	{
		GLib::SetKeyStateChangeCallback(_RenderSprite::TestKeyCallback);

		bool bQuit = false;

		int playerDirection = 1;
		int bulletDirection = 1;

		//Load actor sprites
		GLib::Sprite* pGoodGuy = _RenderSprite::CreateSprite("data\\playerE.dds");
		GLib::Sprite* pBadGuy = _RenderSprite::CreateSprite("data\\monster.dds");
		GLib::Sprite* pBadGuy2 = _RenderSprite::CreateSprite("data\\monster.dds");
		GLib::Sprite* pBullet = _RenderSprite::CreateSprite("data\\bullet.dds");

		//Sprits for HP
		GLib::Sprite* pFull = _RenderSprite::CreateSprite("data\\full.dds");
		GLib::Sprite* pHalf = _RenderSprite::CreateSprite("data\\half.dds");
		const float HPOffset = 60;

		//Load UI sprites
		GLib::Sprite* pThree = _RenderSprite::CreateSprite("data\\three.dds");
		GLib::Sprite* pTwo = _RenderSprite::CreateSprite("data\\two.dds");
		GLib::Sprite* pOne = _RenderSprite::CreateSprite("data\\one.dds");
		GLib::Sprite* pWin = _RenderSprite::CreateSprite("data\\win.dds");
		GLib::Sprite* pLose = _RenderSprite::CreateSprite("data\\lose.dds");

		//Create actors
		_SmartPointer::SmartPointer<_GameObject::GameObject> player(new _GameObject::GameObject());
		_SmartPointer::SmartPointer<_GameObject::GameObject> monster(new _GameObject::GameObject());
		_SmartPointer::SmartPointer<_GameObject::GameObject> monster2(new _GameObject::GameObject());
		_SmartPointer::SmartPointer<_GameObject::GameObject> bullet(new _GameObject::GameObject());
		bool fired = false;

		//Load actor data from json
		_JobSystem::Initialize();
		_JobSystem::Execute([&] { _CreateActor::CreateActor("data\\Player.json", player); });
		_JobSystem::Execute([&] { _CreateActor::CreateActor("data\\Monster.json", monster); });
		_JobSystem::Execute([&] { _CreateActor::CreateActor("data\\Monster2.json", monster2); });
		_JobSystem::Execute([&] { _CreateActor::CreateActor("data\\Bullet.json", bullet); });
		_JobSystem::Wait();

		//Delta time
		float deltaTime = 1;
		clock_t beginTime = clock();
		bool displayingScreen = true;
		bool clockReset = false;

		bool resetGame = false;
		
		while (bQuit == false)
		{

			GLib::Service(bQuit);

			if (!bQuit)
			{
				GLib::BeginRendering();

				GLib::Sprites::BeginRendering();

				//Display UI
				if (displayingScreen == true)
				{
					//Q to quit
					_KeyInput::KeyValue playerValues = _KeyInput::checkInput(*player, bQuit, deltaTime);
					bQuit = playerValues.quit;

					if (clockReset == false)
					{
						beginTime = clock();
						clockReset = true;
					}
					
					deltaTime = (clock() - beginTime) / 1000;

					if (deltaTime > 3)
					{
						deltaTime = 1;
						displayingScreen = false;
						clockReset = false;

						//Rest game data for game loop
						if (resetGame == true)
						{
							_CreateActor::CreateActor("data\\Player.json", player);
							_CreateActor::CreateActor("data\\Monster.json", monster);
							_CreateActor::CreateActor("data\\Monster2.json", monster2);
							_CreateActor::CreateActor("data\\Bullet.json", bullet);
						}
					}

					//Display count down
					static GLib::Point2D Offset;
					if (resetGame == false)
					{
						Offset = { 0, -100 };
					}
					else
					{
						Offset = { 0, -300 };
					}

					if (deltaTime <= 1)
					{
						GLib::Render(*pThree, Offset, 0.0f);
					}
					else if (deltaTime <= 2)
					{
						GLib::Render(*pTwo, Offset, 0.0f);
					}
					else
					{
						GLib::Render(*pOne, Offset, 0.0f);
					}

					//Display game result
					if (resetGame == true)
					{
						Offset = { 0, 0 };
						if (player->HP == 0)
						{
							GLib::Render(*pLose, Offset, 0.0f);
						}
						else if (monster->HP == 0 && monster2->HP == 0)
						{
							GLib::Render(*pWin, Offset, 0.0f);
						}
					}
				}
				//Update gameplay actors
				else
				{
					//Update player
					if (player->HP > 0)
					{
						static GLib::Point2D Offset = { player->X, player->Y };

						_KeyInput::KeyValue playerValues = _KeyInput::checkInput(*player, bQuit, deltaTime);

						if (playerDirection != playerValues.direction)
						{
							if (playerValues.direction == 0)
							{
								pGoodGuy = _RenderSprite::CreateSprite("data\\playerN.dds");
								playerDirection = playerValues.direction;
							}
							else if (playerValues.direction == 1)
							{
								pGoodGuy = _RenderSprite::CreateSprite("data\\playerE.dds");
								playerDirection = playerValues.direction;
							}
							else if (playerValues.direction == 2)
							{
								pGoodGuy = _RenderSprite::CreateSprite("data\\playerS.dds");
								playerDirection = playerValues.direction;
							}
							else if (playerValues.direction == 3)
							{
								pGoodGuy = _RenderSprite::CreateSprite("data\\playerW.dds");
								playerDirection = playerValues.direction;
							}
						}

						if (playerValues.fire == true && fired == false)
						{
							_CreateActor::CreateActor("data\\Bullet.json", bullet);
							bullet->X = player->X;
							bullet->Y = player->Y;
							bulletDirection = playerDirection;
							fired = true;
						}

						*player = playerValues.actor;
						bQuit = playerValues.quit;

						Offset.x = player->X;
						Offset.y = player->Y;

						GLib::Render(*pGoodGuy, Offset, 0.0f);
					}
					//Update monsters
					if (monster->HP > 0)
					{
						monster->Y = monsterAIY(monster->Y, player->Y);
						monster->X = monsterAIX(monster->X, player->X);

						static GLib::Point2D	Offset = { monster->X, monster->Y };
						Offset.x = monster->X;
						Offset.y = monster->Y;

						GLib::Render(*pBadGuy, Offset, 0.0f);

						//Display HP
						Offset.y = monster->Y + HPOffset;
						if (monster->HP == 100)
						{
							GLib::Render(*pFull, Offset, 0.0f);
						}
						else
						{
							GLib::Render(*pHalf, Offset, 0.0f);
						}
						//Check collision with player
						if (_Collision::AABBCollision(player, monster) == false)
						{
							player->HP -= 100;
						}
					}

					if (monster2->HP > 0)
					{
						monster2->Y = monsterAIY(monster2->Y, player->Y);
						monster2->X = monsterAIX(monster2->X, player->X);

						static GLib::Point2D	Offset = { monster2->X, monster2->Y };
						Offset.x = monster2->X;
						Offset.y = monster2->Y;

						GLib::Render(*pBadGuy2, Offset, 0.0f);

						//Display HP
						Offset.y = monster2->Y + HPOffset;
						if (monster2->HP == 100)
						{
							GLib::Render(*pFull, Offset, 0.0f);
						}
						else
						{
							GLib::Render(*pHalf, Offset, 0.0f);
						}
						//Check collision with player
						if (_Collision::AABBCollision(player, monster2) == false)
						{
							player->HP -= 100;
						}
					}
					//Update bullet
					if (bullet->X > screenWidth / 2 || bullet->X < -screenWidth / 2
						|| bullet->Y > screenHeight / 2 || bullet->Y < -screenHeight / 2)
					{
						fired = false;
					}
					if (fired == true)
					{
						static GLib::Point2D	Offset = { bullet->X, bullet->Y };
						bullet = _Bullet::UpdateBullet(bullet, bulletDirection);
						Offset.x = bullet->X;
						Offset.y = bullet->Y;
						GLib::Render(*pBullet, Offset, 0.0f);

						if (_Collision::AABBCollision(bullet, monster) == false && monster->HP > 0)
						{
							monster->HP -= 50;
							fired = false;
						}

						if (_Collision::AABBCollision(bullet, monster2) == false && monster2->HP > 0)
						{
							monster2->HP -= 50;
							fired = false;
						}
					}
					//Reset game based on actor HP
					if ((monster->HP <= 0 && monster2->HP <= 0) || player->HP <= 0)
					{
						resetGame = true;
						displayingScreen = true;
					}
				}

				GLib::Sprites::EndRendering();

				GLib::EndRendering();
			}
		}

			GLib::Release(pGoodGuy);
			GLib::Release(pBadGuy);			
			GLib::Release(pBadGuy2);
			GLib::Release(pBullet);
			GLib::Release(pThree);
			GLib::Release(pTwo);
			GLib::Release(pOne);
			GLib::Release(pWin);
			GLib::Release(pLose);
			GLib::Release(pHalf);
			GLib::Release(pFull);

			//Tell GLib to shutdown, releasing resources.
			GLib::Shutdown();
		}

#if defined _DEBUG
	_CrtDumpMemoryLeaks();
#endif // _DEBUG

	return 0;
}

