#include "CBonusSquare.hpp"

// Constructor. Inherits from CSquare
CBonusSquare::CBonusSquare(int number, string name) : CSquare(number, name)
{

}

// Destructor
CBonusSquare::~CBonusSquare()
{

}

// Virtual function. Called if player lands on this square.
// A random number is generated between 1 and 6
// and the player recieves an bonus amount of money depending on the outcome
void CBonusSquare::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	int* tempRoll = new int; // Temporary pointer used for the Bonus roll

	cout << currentPlayer->GetPlayerName() << " lands on " << GetSquareName() << endl; // Output new position

	*tempRoll = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1); // Roll

	switch (*tempRoll) // Bonus roll output
	{
	case ONE:
	{
		// Find money - Win £20
		cout << "Find some money. Player gains " << POUND << ROLL_ONE_AMOUNT << endl; // Output result
		currentPlayer->SetMoney(currentPlayer->GetMoney() + ROLL_ONE_AMOUNT);         // Add money to player balance
		break;
	}
	case TWO:
	{
		// Win competition - Win £50
		cout << "Win competition. Player gains " << POUND << ROLL_TWO_AMOUNT << endl;
		currentPlayer->SetMoney(currentPlayer->GetMoney() + ROLL_TWO_AMOUNT);
		break;
	}
	case THREE:
	{
		// Tax rebate - Win £100
		cout << "Tax rebate. Player gains " << POUND << ROLL_THREE_AMOUNT << endl;
		currentPlayer->SetMoney(currentPlayer->GetMoney() + ROLL_THREE_AMOUNT);
		break;
	}
	case FOUR:
	{
		// Win lottery - Win £150
		cout << "Win lottery. Player gains " << POUND << ROLL_FOUR_AMOUNT << endl;
		currentPlayer->SetMoney(currentPlayer->GetMoney() + ROLL_FOUR_AMOUNT);
		break;
	}
	case FIVE:
	{
		// Bequest - Win £200
		cout << "Bequest. Player gains " << POUND << ROLL_FIVE_AMOUNT << endl;
		currentPlayer->SetMoney(currentPlayer->GetMoney() + ROLL_FIVE_AMOUNT);
		break;
	}
	case SIX:
	{
		// Birthday - £300
		cout << "Birthday. Player gains " << POUND << ROLL_SIX_AMOUNT << endl;
		currentPlayer->SetMoney(currentPlayer->GetMoney() + ROLL_SIX_AMOUNT);
		break;
	}
	}  // End of switch statment

	// Delete memory

	delete (tempRoll);

} // End of LandedOn funtion