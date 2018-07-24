#pragma once

#include "Coords.h"

class GameObject
{
public:
	char const* sprite;
	Coords coords;
	
	GameObject(char const* sprite);
	
	virtual void update();
	
};
