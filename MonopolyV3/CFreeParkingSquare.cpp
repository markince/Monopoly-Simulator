#include "CFreeParkingSquare.hpp"

// Constructor. Inherits from CSquare
CFreeParkingSquare::CFreeParkingSquare(int number, string name) : CSquare(number, name)
{

}

// Destructor
CFreeParkingSquare::~CFreeParkingSquare()
{

}

// Virtual function. Called if player lands on this square.
// Nothing happens if a player lands on this square. There is no penalty
void CFreeParkingSquare::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	cout << currentPlayer->GetPlayerName() << " lands on " << GetSquareName() << endl; // Output new position
	cout << currentPlayer->GetPlayerName() << " is resting" << endl;

} // End of LandedOn funtion