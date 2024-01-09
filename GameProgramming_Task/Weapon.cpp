#define _CRT_SECURE_NO_WARNINGS
#include "Weapon.h"
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;


Weapon::Weapon(const char* pName) {
	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);
	_atk = 0;
	_def = 0;
}


Weapon::~Weapon() {
	// printf("%s デストラクタ\n", _pName);
	if (_pName != nullptr) {
		delete[] _pName;
		_pName = nullptr;
	}
}

const char* Weapon::getName() {
	return _pName;
}

const int Weapon::getAttack() const {
	return _atk;
}

const int Weapon::getDefense() const {
	return _def;
}


//Sword::Sword() : Weapon("片手剣") {
//	_atk = 50;
//	_def = 10;
//}
//
//Sword::~Sword() {
//
//}
