#include "Door.h"

Door::Door()
{
	open = false;
}

void Door::Open()
{
	open = true;
}

void Door::Close()
{
	open = false;
}

bool Door::IsOpen() const
{
	return open;
}