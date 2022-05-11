#include "CGoToJailSquare.hpp"

// Constructor. Inherits from CSquare
CGoToJailSquare::CGoToJailSquare(int number, string name) : CSquare(number, name)
{

}

// Destructor
CGoToJailSquare::~CGoToJailSquare()
{

}

// Virtual function. Called if player lands on this square.
// Player has to pay a fine of 50 (JAIL_FINE constant)
void CGoToJailSquare::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	cout << currentPlayer->GetPlayerName() << " lands on " << GetSquareName() << endl; // Output new position
	currentPlayer->SetLocation(JAIL_POSITION); // Move player to Jail Square
	currentPlayer->SetMoney(currentPlayer->GetMoney() - JAIL_FINE); // Pay fine
	cout << currentPlayer->GetPlayerName() << " goes to Jail"        << endl; 
	cout << currentPlayer->GetPlayerName() << " pays "               << POUND << JAIL_FINE << endl;

} // End of LandedOn funtion