#include "Player.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Sword.h"
#include <iostream>
using namespace std;

Player::Player(const char* name, Weapon* weapon) : Character(name) {
	_pWeapon = weapon;
	_hp = 100;
	_maxHp = _hp;
	_atk = _pWeapon->getAttack();
	_def = _pWeapon->getDefense();
}

Player::~Player() {

}

void Player::Action(Character& opponent) {
	int select = 0;
	printf("%s はどうする？", _pName);
	printf("1 攻撃, 2 ガード, 3 降参\n");
	cin >> select;

	switch (select)
	{
	case e_Attack :
		Attack(opponent);
		break;
	case e_Block :
		Block();
		break;
	case e_Surrender :
		Surrender();
		break;
	default:
		break;
	}
}

void Player::Surrender() {
	printf("%s は降参した\n", _pName);
	_hp = 0;
}