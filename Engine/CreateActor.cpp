#include "CreateActor.h"
#include "LoadFileToBuffer.h"
#include "GameObject.h"

void _CreateActor::CreateActor(const char* i_pScriptFilename, _SmartPointer::SmartPointer<_GameObject::GameObject> actor)
{
	using json = nlohmann::json;

	std::vector<uint8_t> PlayerData = Engine::LoadFileToBuffer(i_pScriptFilename);

	if (!PlayerData.empty())
	{
		json PlayerJSON = json::parse(PlayerData);

		if (PlayerJSON.contains("actor_data"))
		{
			assert(PlayerJSON["actor_data"]["X"].is_number_float());
			assert(PlayerJSON["actor_data"]["Y"].is_number_float());
			assert(PlayerJSON["actor_data"]["width"].is_number_float());
			assert(PlayerJSON["actor_data"]["height"].is_number_float());
			assert(PlayerJSON["actor_data"]["mass"].is_number_float());
			assert(PlayerJSON["actor_data"]["velocity"].is_number_float());
			assert(PlayerJSON["actor_data"]["HP"].is_number_integer());

			actor->X = PlayerJSON["actor_data"]["X"];
			actor->Y = PlayerJSON["actor_data"]["Y"];
			actor->width = PlayerJSON["actor_data"]["width"];
			actor->height = PlayerJSON["actor_data"]["height"];
			actor->mass = PlayerJSON["actor_data"]["mass"];
			actor->velocity = PlayerJSON["actor_data"]["velocity"];
			actor->HP = PlayerJSON["actor_data"]["HP"];
		}

	}
}


