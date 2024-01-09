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
	printf("%s ÇÕÇ«Ç§Ç∑ÇÈÅH", _pName);
	printf("1 çUåÇ, 2 ÉKÅ[Éh, 3 ç~éQ\n");
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
	printf("%s ÇÕç~éQÇµÇΩ\n", _pName);
	_hp = 0;
}