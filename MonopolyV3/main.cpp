// File:	      MonopolyV3.cpp: A program written in C++
// Author:	      Mark Ince
// Date:	      13-03-2019
// Last Edited:   24-03-2019
// Version:		  3.0

/*
Program (game) to meet the full specification of C02402 Advanced C++ Assignment 2019
- A simplified version of the game Monopoly.
- The game will be played on a board containing twenty-six squares laid out as shown in the specification.
- Random numbers are generated using the code given in “random.cpp”.
- Game board details are read in from a text file - Monopoly.txt.
- Game board set up using a vector of pointers and classes.
- Inheritance and polymorphism used to action the squares the player lands on.
- Pointers and memory allocation detection used to find memory leaks
*/

#include "Definitions.hpp"
#include "CPlayer.hpp"
#include "CSquare.hpp"
#include "CPropertySquare.hpp"
#include "CGoSquare.hpp"
#include "CBonusSquare.hpp"
#include "CJailSquare.hpp"
#include "CSpeedyAirportSquare.hpp"
#include "CFreeParkingSquare.hpp"
#include "CPenaltySquare.hpp"
#include "CGoToJailSquare.hpp"
#include "CShuttleAirportSquare.hpp"
using namespace std;

#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>

// -------------------------------------------------------------------------------//
// Function declarations                                                          //
// -------------------------------------------------------------------------------//

void OpenMonopolyFile (ifstream &inFile);  // Displays an error is no file is found
void ReadMonopolyFile (ifstream &inFile, vector <CSquare*> &gameBoard);  
void OpenSeedFile     (ifstream &inFile); // Displays an error is no file is found
int  ReadSeedFile     (ifstream &inFile);
void MyProgram        ();  // Main Program function

// -------------------------------------------------------------------------------//
// Main Program                                                                   //
// -------------------------------------------------------------------------------//

int main()
{
	MyProgram();
	_CrtDumpMemoryLeaks(); // Outputs any memory leaks in the program
	system("pause");

} // End of main program

void MyProgram()
{
	_crtBreakAlloc = -1;

	// ***** Define Classes ***** //

	vector <CSquare*> pGameBoard;                             // Main gameBoard vector
	CPlayer* pDog = new CPlayer("Dog", PLAYER_START_MONEY);   // Player 1
	CPlayer* pCar = new CPlayer("Car", PLAYER_START_MONEY);   // Player 2

	// ***** Setup gameboard ***** //
 
	ifstream          monopolyFileStream;              // Monopoly file stream
	ifstream          seedFileStream;                  // See file stream
	OpenMonopolyFile (monopolyFileStream);             // Opens monopoly file
	ReadMonopolyFile (monopolyFileStream, pGameBoard); // Reads in data from monopoly file and populates gameboard vector
	OpenSeedFile     (seedFileStream);                 // Opens seed file

	// ***** Seed file action ***** //

	//srand(static_cast<unsigned int> (time(0)));  // Generates a random number each time
	srand(ReadSeedFile(seedFileStream));           // Generates a specific set of numbers based on the value read in from the seed file

	// ***** Main game ***** //
	
	cout << "Welcome to Monopoly\n\n";

	int* pDogPosition = new int; // Temp Variables used in main program
	int* pCarPosition = new int;

	for (int i = 0; i < NUM_OF_ROUNDS; i++) // 20 rounds
	{
		// Player 1
		pDog->RollDice(); // Populates player class mCurrentRoll variable
		*pDogPosition = pDog->MovePlayer(); // Get new player position
		pGameBoard[*pDogPosition]->LandedOn(pDog, pCar); // Calls approprate virtual function depending on which square was landed on
		cout << pDog->GetPlayerName() << " has " << POUND << pDog->GetMoney() << endl; // Final money amount at end of turn

		// Player 2
		pCar->RollDice();
		*pCarPosition = pCar->MovePlayer();
		pGameBoard[*pCarPosition]->LandedOn(pCar, pDog);
		cout << pCar->GetPlayerName() << " has " << POUND << pCar->GetMoney() << endl;

		cout << endl;

	} // End of main game for-loop


	// ***** Clean-up data ***** //
	
	vector<CSquare*>::iterator it; 
	for (it = pGameBoard.begin(); it != pGameBoard.end(); it++)
	{
		delete (*it); // Delete gameBoard vector
	}

	delete (pDogPosition); // Delete pointer variables
	delete (pCarPosition);
	delete (pDog);
	delete (pCar);

} // End of MyProgram function

// -------------------------------------------------------------------------------//
// Functions                                                                      //
// -------------------------------------------------------------------------------//

// Function to open the Monopoly.txt file
// Displays an error if no file is found
void OpenMonopolyFile(ifstream &inFile)
{
	inFile.open("Monopoly.txt");
	if (!inFile)
	{
		cout << "ERROR:\n";
		cout << "Unable to read text file for game data input!\n";
		cout << "Please check your Monopoly.txt file and try again.\n";
	}

} // End of OpenMonopolyFile function

// Function to read in data from the Monopoly.txt file
// Sends in 2 variables, inFile for the stream and a vector of the C Square class to store the square game data
void ReadMonopolyFile(ifstream &inFile, vector <CSquare*> &pGameBoard)
{
	// Temporary pointers used to store data read in from the text file
	string* pTempString    = new string;  // Holds line and words from text file
	int*    pNumOfWords    = new int;     // used to count number of words on a line
	int*    pTempCode      = new int;     // Temp Square code
	string* pTempPropName  = new string;  // Temp property square name
	int*    pTempPropCost  = new int;     // Temp property square cost 
	int*    pTempPropRent  = new int;     // Temp property square rent
	int*    pTempPropGroup = new int;     // Temp property square group
	vector<string> words;                 // Vector used to could number of words on a line
	CSquare* pTmp;                        // Temp pointer used to push data onto the Gameboard

	for (int i = 0; i < NUM_OF_SQUARES; i++) // 26 Squares
	{
		*pNumOfWords = ZERO;
		getline(inFile, *pTempString);   // Reads in line from text file
		istringstream iss(*pTempString);
		while (iss >> *pTempString)      // Seperate the words on each line and store in a vector
		{
			(*pNumOfWords) = (*pNumOfWords) + ONE;
			words.push_back(*pTempString);

		} // End of while loop
		
		*pTempString = words[ZERO];   // Set the Property type into a temp Variable
		*pTempCode = atoi((*pTempString).c_str()); // Converts to int

		if (*pTempCode != ONE) // Does the line from the text file contain special square data?
		{
			switch (*pNumOfWords) // Calculate how many words are in the property name
			{
			case TWO: // 2 words
			{
				*pTempPropName = words[ONE];
				break;
			}
			case THREE: // 3 words
			{
				*pTempPropName = words[ONE] + " " + words[TWO];
				break;
			}
			case FOUR: // 4 words
			{
				*pTempPropName = words[ONE] + " " + words[TWO] + " " + words[THREE];
				break;
			}
			} // End of switch statment

			// reset temporary variable vaules
			*pTempPropCost  = ZERO;
			*pTempPropRent  = ZERO;
			*pTempPropGroup = ZERO;
		}
		else // Does the line from the text file contain property data?
		{
			*pTempPropName = words[ONE] + " " + words[TWO];  // Read in property name

			*pTempString = words[THREE];
			*pTempPropCost = atoi((*pTempString).c_str());  // Read in property cost

			*pTempString = words[FOUR];
			*pTempPropRent = atoi((*pTempString).c_str());  // Read in property rent

			*pTempString = words[FIVE];
			*pTempPropGroup = atoi((*pTempString).c_str()); // Read in property group

		} // End of if statment
		
		// This next if statment allocates memory for the new Property squares in the CSquare vector
		// It populates the data variables in the class using the constructor
		if (i == ONE || i == TWO || i == FOUR || i == FIVE || i == SEVEN || i == EIGHT || i == TEN || i == ELEVEN
			|| i == TWELVE || i == FOURTEEN || i == FIFTEEN || i == SEVENTEEN || i == EIGHTEEN || i == TWENTY || 
			i == TWENTYONE || i == TWENTYTWO || i == TWENTYFOUR || i == TWENTYFIVE)
			pTmp = new CPropertySquare(*pTempCode, *pTempPropName, *pTempPropCost, *pTempPropRent, *pTempPropGroup);

		// This next switch statment creates new instances of the special squares into the CSquare vector
		// depening on which position in the vector it is. It also populates the data variables in the class using the constructor
		switch (i)
		{
		case ZERO: 
		{
			// Go square
			pTmp = new CGoSquare(*pTempCode, *pTempPropName);
			break;
		}
		case THREE: 
		{			
			// Bonus square
			pTmp = new CBonusSquare(*pTempCode, *pTempPropName);
			break;
		}
		case SIX: 
		{
			// Go to jail square
			pTmp = new CJailSquare(*pTempCode, *pTempPropName);
			break;
		}
		case NINE: 
		{
			// Speedy Airport square
			pTmp = new CSpeedyAirportSquare(*pTempCode, *pTempPropName, AIRPORT_COST, AIRPORT_RENT);
			break;
		}
		case THIRTEEN: 
		{
			// Free parking square
			pTmp = new CFreeParkingSquare(*pTempCode, *pTempPropName);
			break;
		}
		case SIXTEEN: 
		{
			// Penalty square
			pTmp = new CPenaltySquare(*pTempCode, *pTempPropName);
			break;
		}
		case NINETEEN: 
		{
			// Go to jail square
			pTmp = new CGoToJailSquare(*pTempCode, *pTempPropName);
			break;
		}
		case TWENTYTHREE: 
		{
			// Shuttle Airport square
			pTmp = new CShuttleAirportSquare(*pTempCode, *pTempPropName, AIRPORT_COST, AIRPORT_RENT);
			break;
		}
		} // End of switch statment

		pGameBoard.push_back(pTmp); // push data back into the final vector
		words.clear();  // Clear the vector so it can be used again in the next iteration of the loop
		
	} // End of if statment

	// ***** Clean up memory used in the temporary variables ***** //
	delete (pTempString);
	delete (pNumOfWords);
	delete (pTempCode);
	delete (pTempPropName);
	delete (pTempPropCost);
	delete (pTempPropRent);
	delete (pTempPropGroup);

} // End of ReadMonopolyFile function

// Function to open the Seed.txt file
// Displays an error if no file is found
void OpenSeedFile(ifstream &inFile)
{
	inFile.clear();
	inFile.open("seed.txt");
	if (!inFile)
	{
		cout << "ERROR:\n";
		cout << "Unable to read seed file!\n";
		cout << "Please check your seed.txt file and try again.\n";

	} // End of if statment

} // End of OpenSeedFile function

// Function to read in data from the Seed.txt file
// returns a single integer value that is used in the main program if a specific 
// set of numbers is needed
int ReadSeedFile(ifstream &inFile)
{
	int seedNum;
	
	inFile >> seedNum;

	return seedNum;

} // End of ReadSeedFile function

