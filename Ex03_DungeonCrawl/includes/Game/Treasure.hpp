#pragma once

#include "GameObject.hpp"

class Treasure: public GameObject
{
public:
	Treasure();
	
private:
	static char const* defaultSprite;
};
