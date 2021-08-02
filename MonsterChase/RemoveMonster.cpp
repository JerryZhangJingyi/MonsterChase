#include "RemoveMonster.h"
#include <xutility>
namespace _RemoveMonster {
	RemoveMonster removeMonster(int* monsterX, int* monsterY, char** monsterName, int monsterAmount) {
		for (int i = rand() % monsterAmount; i < monsterAmount - 1; i++) {
			if (strlen(monsterName[i]) < strlen(monsterName[i + 1])) {
				monsterName[i][strlen(monsterName[i + 1])];
				monsterName[i] = monsterName[i + 1];
			}
			else {
				monsterName[i] = monsterName[i + 1];
			}
			monsterX[i] = monsterX[i + 1];
			monsterY[i] = monsterY[i + 1];
		}
		monsterAmount -= 1;

		RemoveMonster remove;
		remove.monsterX = monsterX;
		remove.monsterY = monsterY;
		remove.monsterName = monsterName;
		remove.monsterAmount = monsterAmount;
		return remove;
	}

}