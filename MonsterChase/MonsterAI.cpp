#include "MonsterAI.h"

namespace _MonsterAI {
	float monsterAIY(float monsterY, float playerY) {
		if (monsterY <= playerY) {
			monsterY += 0.01f;
		}
		if (monsterY > playerY) {
			monsterY -= 0.01f;
		}

		return monsterY;
	}

	float monsterAIX(float monsterX, float playerX)
	{
		if (monsterX <= playerX) {
			monsterX += 0.01f;
		}
		if (monsterX > playerX) {
			monsterX -= 0.01f;
		}

		return monsterX;
	}
}

