#pragma once

typedef struct Coords
{
	int x;
	int y;
	
	Coords()
	{
	}
	
	Coords(int xPos, int yPos)
	{
		this->x = xPos;
		this->y = yPos;
	}
} Coords;
