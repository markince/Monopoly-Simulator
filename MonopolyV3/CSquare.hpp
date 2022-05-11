#ifndef _MYSQUAREHEADER
#define _MYSQUAREHEADER
#pragma once

#include "Definitions.hpp"
#include "CPlayer.hpp"

// CSquare Base Class
// Constructor takes in square number and name (basic information every square has). 
// The virtual function in this class should never be called and will output an error if it is
class CSquare
{
private:
	SSquareDetails* mpSquareDetails;
public:
	CSquare(int number, string name); 
	virtual ~CSquare();
	void SetDetails(int number, string name);
	int GetSquareNumber();
	string GetSquareName();
	virtual void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
};

#endif