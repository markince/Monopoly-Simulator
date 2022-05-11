#include "CPlayer.hpp"

// Default Constructor
CPlayer::CPlayer()
{

}

// Constructor. Takes in the name and starting money balance of the player
// Each player starts with £1500
// Current Location is set to 0 to start
CPlayer::CPlayer(string name, int startingMoney)
{
	mPlayerName = name;
	mMoney     = startingMoney;
	mCurrentLocation = 0;
}

// Destructor
CPlayer::~CPlayer()
{

}

// RollDice generates a random number between 1 and 6 and stores it in mCurrentRoll variable
// Also outputs the roll to the console window
void CPlayer::RollDice()
{
	mCurrentRoll = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
	cout << mPlayerName << " rolls " << mCurrentRoll << endl;

}

// Getter - Gets the current players name
string CPlayer::GetPlayerName()
{
	return mPlayerName;
}

// Setter - Sets the square number sent into the function to the players owned list
// which is a vector
void CPlayer::SetProperyOwned(int squareNumber)
{
	mPropertiesOwned.push_back(squareNumber);
}

// Moves the player depending on the current roll and returns the new location that the
// player has moved too
int CPlayer::MovePlayer()
{
	// Check to see if the current location plus the dice roll is less than the
	// number of squares
	if (mCurrentLocation + mCurrentRoll < NUM_OF_SQUARES)
	{
		mCurrentLocation += mCurrentRoll;
	}
	else // If so, reset the current position to zero and collect the pass go money
	{
		for (int i = 0; i < mCurrentRoll; i++)
		{
			mCurrentLocation++; // Increment counter

			if (mCurrentLocation == NUM_OF_SQUARES)
			{
				mCurrentLocation = 0;
				cout << mPlayerName << " passes go and collects " << POUND << "200" << endl;
				SetMoney(GetMoney() + PASS_GO_AMOUNT);
			
			} // End of if statment

		} // End of for loop

	} // End of if statment

	return mCurrentLocation;

} // End of MovePlayer function

// Setter - sets the players money balance
void CPlayer::SetMoney(int amount)
{
	mMoney = amount;
}

// Getter - returns the players money balance
int CPlayer::GetMoney()
{
	return mMoney;
}

// Setter - sets the players current location on the board
void CPlayer::SetLocation(int squareNumber)
{
	mCurrentLocation = squareNumber;
}

// Getter - gets the current dice roll of the player
int CPlayer::GetCurrentRoll()
{
	return mCurrentRoll;
}