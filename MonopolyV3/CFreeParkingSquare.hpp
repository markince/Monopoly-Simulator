#ifndef __MYFREEPARKINGHEADER
#define __MYFREEPARKINGHEADER
#pragma once

#include "Definitions.hpp"
#include "CSquare.hpp"

// CFreeParking Square Class
// Nothing happens if a player lands on this square. Thre is no penalty
// Constructor inherits square number and name from CSquare
// Virtual function is called if landed on. Player details sent into this function

class CFreeParkingSquare : public CSquare
{
public:
	CFreeParkingSquare(int number, string name);
	~CFreeParkingSquare();
	virtual void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
};


#endif