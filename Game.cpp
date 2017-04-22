#include "Door.h"
#include "Game.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

static int ChooseWinningDoor(int numDoors)
{
	// Seed the random number generator from the current time.
	srand((unsigned int)time(0));
	return rand() % numDoors;
}

Game::Game()
{
	int winnerIndex = ChooseWinningDoor(NUM_DOORS);
	winner = &doors[winnerIndex];
#ifdef _DEBUG
	std::cout << "winner = " << winnerIndex << std::endl;
#endif
}

void Game::Play()
{
	using namespace std;
	cout << "Which door contains the prize? [1-"
		<< NUM_DOORS << "]: ";
	int userChoice;
	bool isChoiceValid = false;
	while (!isChoiceValid)
	{
		while (!(cin >> userChoice))
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid. Please try again: ";
		}
		isChoiceValid = (1 <= userChoice && userChoice <= NUM_DOORS);
		if (!isChoiceValid)
		{
			cout << "Please enter number in the correct range: ";
		}
	}
#ifdef _DEBUG
	cout << "DEBUG: User choice = " << userChoice << endl;
#endif
}