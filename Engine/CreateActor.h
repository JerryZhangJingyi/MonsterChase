#pragma once
#include <assert.h>
#include <fstream>
#include <functional>
#include <map>
#include <iostream>
#include "json.hpp"
#include "GameObject.h"
#include <SmartPointer.h>

namespace _CreateActor {
	using json = nlohmann::json;
	void CreateActor(const char* i_pScriptFilename, _SmartPointer::SmartPointer<_GameObject::GameObject> actor);
}