#ifndef __MYBONUSHEADER
#define __MYBONUSHEADER
#pragma once

#include "Definitions.hpp"
#include "CSquare.hpp"

// CBonus square Class
// Player recieves a bonus if they land on this square. A random number is generated between 1 and 6
// and the player recieves an bonus amount of money depending on the outcome
// Constructor inherits square number and name from CSquare
// Virtual function is called if landed on. Player details sent into this function

class CBonusSquare : public CSquare
{
public:
	CBonusSquare(int number, string name);
	~CBonusSquare();
	virtual void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
};

#endif