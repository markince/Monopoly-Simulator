#ifndef __MYDEFHEADER
#define __MYDEFHEADER
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

// -------------------------------------------------------------------------------//
// Constants                                                                      //
// -------------------------------------------------------------------------------//

const int             NUM_OF_SQUARES     = 26;   // Total number of squares on the game board
const int             NUM_OF_ROUNDS      = 20;   // Total number of rounds in game
const int             PLAYER_START_MONEY = 1500; // Player starting funds
const int             PASS_GO_AMOUNT     = 200;  // Amount player receives when they pass GO
const int             AIRPORT_COST       = 200;  // Cost of Airport square to buy
const int             AIRPORT_RENT       = 10;   // Cost player has to pay when they land on an airport square
const int             JAIL_FINE          = 50;   // Cost player has to pay when they land on an jail square
const int             JAIL_POSITION      = 6;    // Cost player has to pay when they land on an jail square
const int             ROLL_ONE_AMOUNT    = 20;   // Position on the board of the jail square
const int             ROLL_TWO_AMOUNT    = 50;   // Amount used in Bonus/Penalty square roll
const int             ROLL_THREE_AMOUNT  = 100;  // Amount used in Bonus/Penalty square roll
const int             ROLL_FOUR_AMOUNT   = 150;  // Amount used in Bonus/Penalty square roll
const int             ROLL_FIVE_AMOUNT   = 200;  // Amount used in Bonus/Penalty square roll
const int             ROLL_SIX_AMOUNT    = 300;  // Amount used in Bonus/Penalty square roll
const unsigned char   POUND              = 156;  // Used to display pound sign in the console

// -------------------------------------------------------------------------------//
// Macros                                                                         //
// -------------------------------------------------------------------------------//

#define ZERO        0
#define ONE         1
#define TWO         2
#define THREE       3
#define FOUR        4
#define FIVE        5
#define SIX         6
#define SEVEN       7
#define EIGHT       8
#define NINE        9
#define TEN         10
#define ELEVEN      11
#define TWELVE      12
#define THIRTEEN    13
#define FOURTEEN    14
#define FIFTEEN     15
#define SIXTEEN     16
#define SEVENTEEN   17
#define EIGHTEEN    18
#define NINETEEN    19
#define TWENTY      20
#define TWENTYONE   21
#define TWENTYTWO   22
#define TWENTYTHREE 23
#define TWENTYFOUR  24
#define TWENTYFIVE  25

// -------------------------------------------------------------------------------//
// Structures                                                                      //
// -------------------------------------------------------------------------------//

struct SSquareDetails
{
	int    mSquareNumber;
	string mSquareName;
};



#endif