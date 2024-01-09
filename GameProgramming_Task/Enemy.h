#pragma once
#include "Character.h"

class Player;

class Enemy : public Character
{
public :
	Enemy(const char* name);
	virtual ~Enemy();

private :
	void Action(Character& opponent) override;
};

