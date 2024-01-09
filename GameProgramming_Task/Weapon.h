#pragma once


class Character;

class Weapon
{
protected :
	char* _pName;
	int _atk;
	int _def;


public :
	Weapon(const char* pName);
	virtual ~Weapon();
	void operator = (const Weapon& other);
	const char* getName();
	const int getAttack()const;
	const int getDefense()const;
};

//#pragma once
//
//
//class Character;
//
//class Weapon
//{
//protected:
//	char _name[10];
//	int _atk;
//	int _def;
//
//
//public:
//	Weapon();
//
//	const int getAttack()const;
//	const int getDefense()const;
//};

