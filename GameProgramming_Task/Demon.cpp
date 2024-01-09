#include "Demon.h"


Demon::Demon() : Enemy("Demon") {
	_hp = 200;
	_maxHp = _hp;
	_atk = 50;
	_def = 25;
}

Demon::~Demon() {

}