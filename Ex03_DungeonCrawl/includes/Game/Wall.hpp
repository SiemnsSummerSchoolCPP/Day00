#pragma once

#include "GameObject.hpp"

class Wall : public GameObject
{
public:
	Wall();

private:
	static char const* defaultSprite;
};
