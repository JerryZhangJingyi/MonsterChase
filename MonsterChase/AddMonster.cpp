#include "AddMonster.h"
#include <iostream>
using namespace std;
namespace _AddMonster {
	AddMonster addMonster(int* monsterX, int* monsterY, char** monsterName, int monsterAmount) {
		monsterAmount += 1;

		int* tempX = new int[monsterAmount]; // expand array
		int* tempY = new int[monsterAmount];
		char** tempName = new char* [monsterAmount];

		for (int i = 0; i < monsterAmount - 1; i++) {
			tempX[i] = monsterX[i];
			tempY[i] = monsterY[i];
			tempName[i] = monsterName[i];
		}

		delete[]monsterX;
		delete[]monsterY;
		delete[]monsterName;

		tempName[monsterAmount - 1] = new char[50];
		cout << "Enter name of monster " << monsterAmount << " : \n";
		cin >> tempName[monsterAmount - 1];
		size_t monsterNameSize = strlen(tempName[monsterAmount - 1]);
		tempName[monsterAmount - 1][monsterNameSize];

		tempX[monsterAmount - 1] = rand() % 100;
		tempY[monsterAmount - 1] = rand() % 100;

		monsterX = new int[monsterAmount];;
		monsterY = new int[monsterAmount];;
		monsterName = new char* [monsterAmount];

		for (int i = 0; i < monsterAmount; i++) {
			monsterX[i] = tempX[i];
			monsterY[i] = tempY[i];
			monsterName[i] = tempName[i];
		}

		delete[]tempX;
		delete[]tempY;
		delete[]tempName;

		AddMonster remove;
		remove.monsterX = monsterX;
		remove.monsterY = monsterY;
		remove.monsterName = monsterName;
		remove.monsterAmount = monsterAmount;
		return remove;
	}

}