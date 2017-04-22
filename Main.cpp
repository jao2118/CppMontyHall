#include "Game.h"
#include <iostream>

int main()
{
	Game g;
	g.Play();
	std::cin.ignore(10000, '\n');
	std::cin.get();
	return 0;
}