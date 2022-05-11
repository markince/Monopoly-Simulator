#ifndef __MYPLAYERHEADER
#define __MYPLAYERHEADER
#pragma once

#include "Definitions.hpp"

// CPlayer Class
// Class that controls the players of the game
// Propties owned by the player are stored in a vector. Constructor takes in player name and starting money
// The virtual function in this class should never be called and will output an error if it is

class CPlayer
{
private:
	string mPlayerName;
	int    mMoney;
	int    mCurrentLocation;
	int    mCurrentRoll;
	vector <int> mPropertiesOwned;  
public:
	CPlayer();
	CPlayer(string name, int startingMoney); // Constructor
	~CPlayer(); // De-structor
	void RollDice();
	string GetPlayerName();
	void SetProperyOwned(int squareNumber);
	int MovePlayer();
	void SetMoney(int amount);
	int GetMoney();
	void SetLocation(int squareNumber);
	int GetCurrentRoll();
};



#endif