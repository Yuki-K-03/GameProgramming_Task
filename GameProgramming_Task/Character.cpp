#define _CRT_SECURE_NO_WARNINGS
#include "Character.h"
#include "Sword.h"
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;


Character::Character(const char* pName) {
	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);
	_hp = 0;
	_maxHp = _hp;
	_atk = 0;
	_def = 0;
	_block = false;
	_death = false;
}

Character::~Character() {
	//printf("%s�@�f�X�g���N�^\n", _pName);
	if (_pName != nullptr) {
		delete[] _pName;
		_pName = nullptr;
	}
}

const char* Character::getName() const {
	return _pName;
}

const int Character::getHp() const {
	return _hp;
}

const int Character::getAttack() const {
	return _atk;
}

const int Character::getDefense() const {
	return _def;
}

const bool Character::getBlock() const {
	return _block;
}

const bool Character::getDeath() const {
	return _death;
}

bool Character::Play(Character& opponent) {
	if (!_death) {
		Action(opponent);
	}
	return opponent.getDeath();
}

void Character::Damage(int damage) {
	if (damage < 0) {
		printf("�_���[�W�����G���[\n");
		return;
	}

	_hp -= damage;

	if (_hp <= 0) {
		printf("%s �͓|�ꂽ...\n", _pName);
		_death = true;
		_hp = 0;
	}
}

void Character::Attack(Character& opponent) {
	_block = false;

	printf("%s�̍U���I\n", _pName);
	if (!opponent.getBlock()) {
		int damage = _atk - opponent.getDefense();
		printf("%s �� %d �_���[�W�^����\n", opponent.getName(), damage);
		opponent.Damage(damage);
	}
	else {
		printf("%s �͍U����h����\n", opponent.getName());
	}
}

void Character::Block() {

	cout << rand() % 2 << endl;

	if (_block) {
		if (_block = rand() % 2) {
			printf("%s �̓K�[�h�𒣂���\n", _pName);
		}
		else {
			printf("%s �̓K�[�h�𒣂낤�Ƃ��������s�����I\n", _pName);
		}
	}
	else {
		_block = true;
		printf("%s �̓K�[�h�𒣂���\n", _pName);
	}
}