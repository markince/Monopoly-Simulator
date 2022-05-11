#ifndef __MYGOTOJAILHEADER
#define __MYGOTOJAILHEADER
#pragma once

#include "Definitions.hpp"
#include "CSquare.hpp"

// CGoToJail square Class
// Player position is moved to the jail square
// and the player has to pay a fine of 50 (JAIL_FINE constant)
// Constructor inherits square number and name from CSquare
// Virtual function is called if landed on. Player details sent into this function

class CGoToJailSquare : public CSquare
{
private:

public:
	CGoToJailSquare(int number, string name);
	~CGoToJailSquare();
	virtual void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
};


#endif