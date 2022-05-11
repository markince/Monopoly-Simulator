#include "CGoSquare.hpp"


// Constructor. Inherits from CSquare
CGoSquare::CGoSquare(int number, string name) : CSquare(number, name)
{

}

// De-structor
CGoSquare::~CGoSquare()
{

}


// Virtual function. Called if player lands on this square.
void CGoSquare::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	cout << currentPlayer->GetPlayerName() << " lands on " << GetSquareName() << endl; // Output new position
}
