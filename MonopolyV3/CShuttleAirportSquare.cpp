#include "CShuttleAirportSquare.hpp"

// Constructor. inherits from CSquare
// Sets the rent and cost of the Airport
CShuttleAirportSquare::CShuttleAirportSquare(int number, string name, int cost, int rent) : CSquare(number, name)
{
	mAirportCost = cost;
	mAirportRent = rent;
}

// Destructor
CShuttleAirportSquare::~CShuttleAirportSquare()
{

}

// Getter. Returns airport cost
int CShuttleAirportSquare::GetCost()
{
	return mAirportCost;
}

// Virtual function. Takes approrite action when player lands on Shuttle Airport square
// purchases this square if they land on it and it is not owned already
// If the none owner lands on it they must pay a fine (AIRPORT_RENT)
void CShuttleAirportSquare::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	cout << currentPlayer->GetPlayerName() << " lands on " << GetSquareName() << endl; // Output new position

	if ((mCurrenOwner == NULL)) // Is the airport free to buy?
	{
		if ((currentPlayer->GetMoney() - mAirportCost) > ZERO) //  Does the player have enough money?
		{
			mCurrenOwner = currentPlayer;
			currentPlayer->SetProperyOwned(GetSquareNumber()); // Add property owned to players owned properties list
			cout << currentPlayer->GetPlayerName() << " buys " << GetSquareName() << " for " << POUND << mAirportCost << endl;
			currentPlayer->SetMoney(currentPlayer->GetMoney() - mAirportCost); // Deduct money from players balance
		}
	}
	else // Is the airport owned?
	{
		if (mCurrenOwner == otherPlayer) // Is it owned by the other player?
		{
			cout << currentPlayer->GetPlayerName() << " pays " << POUND << mAirportRent << " of goods " << endl;
			currentPlayer->SetMoney(currentPlayer->GetMoney() - mAirportRent); // Deduct rent from players balance

			otherPlayer->SetMoney(otherPlayer->GetMoney() + mAirportRent); // Add rent to current players balance

		}
		else // Is the airport owned by the current player?
		{
			cout << currentPlayer->GetPlayerName() << " owns " << GetSquareName() << endl; // Do nothing
		
		} // End of if statment
	
	} // End of if statment

} // End of LandedOn function