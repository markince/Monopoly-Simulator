#include "CPropertySquare.hpp"

// Constructor. inherits from CSquare
// Allowcates memory for the structure and sets other property details 
CPropertySquare::CPropertySquare(int number, string name, int cost, int rent, int group) : CSquare(number, name)
{
	mpPropertyDetails = new SPropertyDetails;

	mpPropertyDetails->mPropertyCost        = cost;
	mpPropertyDetails->mPropertyRent        = rent;
	mpPropertyDetails->mPropertyColourGroup = group;
}

// Destructor. Deletes memory for the structure
CPropertySquare::~CPropertySquare()
{
	delete (mpPropertyDetails);
}

// Getter - returns the cost of the square
int CPropertySquare::GetSquareCost()
{
	return mpPropertyDetails->mPropertyCost;
}

// Getter - returns the rent of the square
int CPropertySquare::GetSquareRent()
{
	return mpPropertyDetails->mPropertyRent;
}

// Getter - returns the colour of the square
int CPropertySquare::GetSquareColourGroup()
{
	return mpPropertyDetails->mPropertyColourGroup;
}

// Setter - sets the property cost
void CPropertySquare::SetSquareCost(int cost)
{
	mpPropertyDetails->mPropertyCost = cost;
}

// Setter - sets the property rent
void CPropertySquare::SetSquareRent(int rent)
{
	mpPropertyDetails->mPropertyRent = rent;
}

// Setter - sets the colour group
void CPropertySquare::SetSquareColourGroup(int group)
{
	mpPropertyDetails->mPropertyColourGroup = group;
}

// Virtual function. Takes approrite actions depending on which square has been landed on
void CPropertySquare::LandedOn(CPlayer* pCurrentPlayer, CPlayer* pOtherPlayer)
{
	cout << pCurrentPlayer->GetPlayerName() << " lands on " << GetSquareName() << endl; // Output new position

	if (mpPropertyDetails->mpCurrenOwner == NULL) // Is the property free to buy?
	{
		if ((pCurrentPlayer->GetMoney() - mpPropertyDetails->mPropertyCost) > ZERO) //  Does the player have enough money?
		{
			mpPropertyDetails->mpCurrenOwner = pCurrentPlayer;
			pCurrentPlayer->SetProperyOwned(GetSquareNumber()); // Add property to player owned list
			cout << pCurrentPlayer->GetPlayerName() << " buys " << GetSquareName() << " for " << POUND << GetSquareCost() << endl;
			pCurrentPlayer->SetMoney(pCurrentPlayer->GetMoney() - GetSquareCost()); // Deduct money from player balance
		
		} // End of if statment
	}
	else // Is the property owned?
	{
		if (mpPropertyDetails->mpCurrenOwner == pOtherPlayer) // Is it owned by the other player?
		{
			cout << pCurrentPlayer->GetPlayerName() << " pays " << POUND << GetSquareRent() << endl;
			pCurrentPlayer->SetMoney(pCurrentPlayer->GetMoney() - GetSquareRent()); // Deduct rent
			pOtherPlayer->SetMoney(pOtherPlayer->GetMoney() + GetSquareRent()); // Add rent to other players balance
		}
		else // Is it owned by the current player?
		{
			cout << pCurrentPlayer->GetPlayerName() << " owns " << GetSquareName() << endl; // Do nothing
		
		} // End of if statment

	} // End of if statment

} // End of LandedOn function