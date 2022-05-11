#ifndef __MYSHUTTLEHEADER
#define __MYSHUTTLEHEADER

#pragma once

#include "Definitions.hpp"
#include "CSquare.hpp"

// CShuttleAirport square Class
// Player purchases this square if they land on it and it is not owned already
// If the none owner lands on it they must pay a fine (AIRPORT_RENT)
// Constructor inherits square number and name from CSquare
// Virtual function is called if landed on. Player details sent into this function
class CShuttleAirportSquare : public CSquare
{
private:
	int mAirportCost; 
	int mAirportRent;
	CPlayer*  mCurrenOwner = NULL;
public:
	CShuttleAirportSquare(int number, string name, int cost, int rent);
	~CShuttleAirportSquare();
	int GetCost();
	virtual void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
};

#endif