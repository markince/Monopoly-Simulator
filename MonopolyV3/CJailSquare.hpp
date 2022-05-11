#ifndef __MYJAILHEADER
#define __MYJAILHEADER

#pragma once

#include "Definitions.hpp"
#include "CSquare.hpp"

// CJail square Class
// Player is sent to this square if they land on the GoToJail square 
// If a play lands on this square when passing, nothing happens
// Constructor inherits square number and name from CSquare
// Virtual function is called if landed on. Player details sent into this function
class CJailSquare : public CSquare
{
public:
	CJailSquare(int number, string name);
	~CJailSquare();
	virtual void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
};

#endif