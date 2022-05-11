#include "CPenaltySquare.hpp"

// Constructor. Inherits from CSquare
CPenaltySquare::CPenaltySquare(int number, string name) : CSquare(number, name)
{

}

// Destructor
CPenaltySquare::~CPenaltySquare()
{

}

// Virtual function. Called if player lands on this square.
// A random number is generated between 1 and 6
// and the player recieves an fine amount depending on the outcome

void CPenaltySquare::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	int* tempRoll = new int; // Temporary pointer used for the Bonus roll

	cout << currentPlayer->GetPlayerName() << " lands on " << GetSquareName() << endl; // Output new position

	*tempRoll = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1); // Roll

	switch (*tempRoll) // Penalty roll output
	{
	case ONE:
	{
		// Pay food bill - Loose £20
		cout << "Pay food bill. Player loses " << POUND <<  ROLL_ONE_AMOUNT << endl;
		currentPlayer->SetMoney(currentPlayer->GetMoney() - ROLL_ONE_AMOUNT);
		break;
	}
	case TWO:
	{
		// Pay phone bill - Loose £50
		cout << "Pay phone bill. Player loses " << POUND << ROLL_TWO_AMOUNT << endl;
		currentPlayer->SetMoney(currentPlayer->GetMoney() - ROLL_TWO_AMOUNT);
		break;
	}
	case THREE:
	{
		// Pay heating bill - Loose £100
		cout << "Pay heating bill. Player loses " << POUND << ROLL_THREE_AMOUNT << endl;
		currentPlayer->SetMoney(currentPlayer->GetMoney() -   ROLL_THREE_AMOUNT);
		break;
	}
	case FOUR:
	{
		// Pay vehicle tax - Loose £150
		cout << "Pay vehicle tax. Player loses " << POUND << ROLL_FOUR_AMOUNT << endl;
		currentPlayer->SetMoney(currentPlayer->GetMoney() -  ROLL_FOUR_AMOUNT);
		break;
	}
	case FIVE:
	{
		// Pay fuel bill - Loose £200
		cout << "Pay fuel bill. Player loses " << POUND <<  ROLL_FIVE_AMOUNT << endl;
		currentPlayer->SetMoney(currentPlayer->GetMoney() - ROLL_FIVE_AMOUNT);
		break;
	}
	case SIX:
	{
		// Pay windfall tax - Loose £300
		cout << "Pay windfall tax. Player loses " << POUND << ROLL_SIX_AMOUNT << endl;
		currentPlayer->SetMoney(currentPlayer->GetMoney() -   ROLL_SIX_AMOUNT);
		break;
	}
	} // End of switch statment
	
	delete (tempRoll);

} // End of LandedOn funtion