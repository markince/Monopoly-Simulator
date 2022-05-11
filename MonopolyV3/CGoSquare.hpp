#ifndef __MYGOHEADER
#define __MYGOHEADER

#pragma once

#include "Definitions.hpp"
#include "CSquare.hpp"

// CGoSquare Class
// Constructor inherits square number and name from CSquare
// Virtual function is called if landed on. Player details sent into this function

class CGoSquare : public CSquare
{
public:
	CGoSquare(int number, string name);
	~CGoSquare();
	virtual void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
};

#endif