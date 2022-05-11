#ifndef __MYPROPHEADER
#define __MYPROPHEADER
#pragma once

#include "Definitions.hpp"
#include "CSquare.hpp"

// Structure to store property details
struct SPropertyDetails
{
	int       mPropertyCost;
	int       mPropertyRent;
	int       mPropertyColourGroup;
	CPlayer*  mpCurrenOwner = NULL;
};

// CProperty Class
// Constructor takes in Property cost, rent and group read in from text file. Also inherits basic square
// details from CSquare. Used to create an instance of each property on the board
// Virtual function takes approraite actions depending on which square has been landed on
class CPropertySquare : public CSquare
{
private:
	SPropertyDetails* mpPropertyDetails;
public:
	CPropertySquare(int number, string name, int cost, int rent, int group);
	virtual ~CPropertySquare();
	int  GetSquareCost();
	int  GetSquareRent();
	int  GetSquareColourGroup();
	void SetSquareCost(int cost);
	void SetSquareRent(int rent);
	void SetSquareColourGroup(int group);
	virtual void LandedOn(CPlayer* pCurrentPlayer, CPlayer* pOtherPlayer);
};

#endif