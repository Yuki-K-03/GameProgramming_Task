#pragma once

class Character
{
protected :
	char* _pName;
	int _maxHp;
	int _hp;
	int _atk;
	int _def;
	bool _block;
	bool _death;

public :
	Character(const char* pName);
	virtual ~Character();

	const char* getName()const;
	const int getHp()const;
	const int getAttack()const;
	const int getDefense()const;
	const bool getBlock() const;
	const bool getDeath()const;

	bool Play(Character& opponent);
	void Damage(int damage);
protected :
	virtual void Action(Character& opponent) = 0;
	void Attack(Character& opponent);
	void Block();
};

