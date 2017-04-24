#include "Game.h"
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	int totalPlays = 0;
	int wins = 0;
	bool playing = true;
	while (playing)
	{
		Game* g = new Game();
		bool winner = g->Play();
		if (winner)
			wins++;
		totalPlays++;
		delete g;
		cout << "Current win percentage = " << ((double)wins / totalPlays * 100) << endl;
		string again;
		cout << "Play again? (y/n): ";
		getline(cin, again);
		playing = (again == "Y" || again == "y");
	}
	cout << "Goodbye!" << endl;
	cin.get();
	return 0;
}