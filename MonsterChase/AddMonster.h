#pragma once
namespace _AddMonster {
	struct AddMonster
	{
		int* monsterX;
		int* monsterY;
		char** monsterName;
		int monsterAmount;
	};
	AddMonster addMonster(int* monsterX, int* monsterY, char** monsterName, int monsterAmount);
}