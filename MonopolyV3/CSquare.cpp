#include "CSquare.hpp"

// Constructor. Takes in the name and number of the square (read in from the text file)
// Details are stored in a pointer structure
CSquare::CSquare(int number, string name)
{
	mpSquareDetails = new SSquareDetails; // Allocate new memory

	mpSquareDetails->mSquareNumber = number; // Set data
	mpSquareDetails->mSquareName = name;
}

// Destructor - Deletes the member pointer used to hold data
CSquare::~CSquare()
{
	delete (mpSquareDetails);
}

// Setter - Set the details of the square
void CSquare::SetDetails(int number, string name)
{
	mpSquareDetails->mSquareNumber = number;
	mpSquareDetails->mSquareName   = name;
}

// Getter - Returns the square number
int CSquare::GetSquareNumber()
{
	return mpSquareDetails->mSquareNumber;
}

// Getter - Returns the square name
string CSquare::GetSquareName()
{
	return mpSquareDetails->mSquareName;
}

// Virtual base function. This one should never be called 
// as a player can never land on a basic CSquare. Will output an error if so
void CSquare::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	cout << "ERROR: cannot land on a none type square\n";
}