#include "CJailSquare.hpp"

// Constructor. Inherits from CSquare
CJailSquare::CJailSquare(int number, string name) : CSquare(number, name)
{

}

// Destructor
CJailSquare::~CJailSquare()
{

}

// Virtual function. Called if player lands on this square.
// Player is sent to this square if they land on the GoToJail square
// Outputs message that they are just visiting

void CJailSquare::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayerr)
{
	cout << currentPlayer->GetPlayerName() << " lands on " << GetSquareName() << endl; // Output new position
	cout << currentPlayer->GetPlayerName() << " is just visiting" << endl;

} // End of LandedOn function