#include "Door.h"

#ifndef GAME_H_
#define GAME_H_

class Game
{
private:
	static const int NUM_DOORS = 3;
	Door doors[NUM_DOORS];
	Door* winner;
public:
	Game();
	void Play();
};

#endif