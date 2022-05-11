#ifndef __MYPENALTYHEADER
#define __MYPENALTYHEADER
#pragma once

#include "Definitions.hpp"
#include "CSquare.hpp"

// CPenalty square Class
// Player suffers a penalty if they land on this square. A random number is generated between 1 and 6
// and the player recieves an fine amoutn depending on the outcome
// Constructor inherits square number and name from CSquare
// Virtual function is called if landed on. Player details sent into this function

class CPenaltySquare : public CSquare
{
public:
	CPenaltySquare(int number, string name);
	~CPenaltySquare();
	virtual void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
};

#endif