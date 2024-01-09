#pragma once
#include "Character.h"
#include "Weapon.h"


enum e_Action {
	e_Attack = 1,
	e_Block,
	e_Surrender,
};

class Player : public Character
{
private :
	Weapon* _pWeapon;

public:
	Player(const char* name, Weapon* weapon);
	virtual ~Player();
private:
	void Action(Character& opponent) override;
	void Surrender();
};