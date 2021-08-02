#pragma once

namespace _RemoveMonster {
	struct RemoveMonster
	{
		int* monsterX;
		int* monsterY;
		char** monsterName;
		int monsterAmount;
	};
	RemoveMonster removeMonster(int* monsterX, int* monsterY, char** monsterName, int monsterAmount);
}
