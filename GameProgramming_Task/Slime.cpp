#include "Slime.h"

Slime::Slime() : Enemy("Slime") {
	_hp = 100;
	_maxHp = _hp;
	_atk = 30;
	_def = 10;
}

Slime::~Slime() {

}