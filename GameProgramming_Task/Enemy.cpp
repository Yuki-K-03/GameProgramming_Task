#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

Enemy::Enemy(const char* name) : Character(name) {
	
}

Enemy::~Enemy() {

}

void Enemy::Action(Character& opponent) {
	if (rand() % 3) {
		Attack(opponent);
	}
	else {
		Block();
	}
	printf("\n\n");
}