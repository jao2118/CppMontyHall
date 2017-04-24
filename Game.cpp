#include "Door.h"
#include "Game.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

static int ChooseWinningDoor(int numDoors)
{
	// Seed the random number generator from the current time.
	srand((unsigned int)time(0));
	return rand() % numDoors;
}

static bool GetChoice(std::string& switchInput)
{
	std::getline(std::cin, switchInput);
	std::string choices[] = { "Y", "y", "N", "n" };
	for (int i = 0; i < 4; i++)
	{
		if (choices[i] == switchInput)
			return true;
	}
	return false;
}

Game::Game()
{
	winnerIndex = ChooseWinningDoor(NUM_DOORS);
#ifdef _DEBUG
	std::cout << "winner = " << winnerIndex << std::endl;
#endif
}

bool Game::Play()
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
			cin.ignore(10000, '\n');
			cout << "Invalid. Please try again: ";
		}
		isChoiceValid = (1 <= userChoice && userChoice <= NUM_DOORS);
		if (!isChoiceValid)
		{
			cout << "Please enter number in the correct range: ";
		}
	}
	cin.ignore(10000, '\n');
#ifdef _DEBUG
	cout << "DEBUG: User choice = " << userChoice << endl;
#endif

	int doorToOpenIndex = -1;
	srand((unsigned int)time(0));
	while (doorToOpenIndex < 0)
	{
		int randChoice = rand() % NUM_DOORS;
		if (randChoice != userChoice && randChoice != winnerIndex)
		{
			doorToOpenIndex = randChoice;
		}
	}
	doors[doorToOpenIndex].Open();
	string switchInput;
	cout << "A door has been opened." << endl;
	cout << "Would you like to switch doors? (y/n): ";
	while (!GetChoice(switchInput))
	{
		cout << "Invalid. Try again: ";
	}
	bool userWantsToSwitch = (switchInput == "Y" || switchInput == "y");
	if (userWantsToSwitch)
	{
		// Door that is closed and not the current user's choice!
		for (int i = 0; i < NUM_DOORS; i++)
		{
			auto* door = &doors[i];
			if (!door->IsOpen() && userChoice != i)
			{
				userChoice = i;
#ifdef _DEBUG
				cout << "New choice = " << i << endl;
#endif
				break;
			}
		}
	}
	bool winner = (userChoice == winnerIndex);
	if (winner)
		cout << "You win!" << endl;
	else
		cout << "You lose" << endl;
	return winner;
}