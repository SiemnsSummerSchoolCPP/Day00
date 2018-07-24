#pragma once

#include "GameObject.hpp"

class Monster: public GameObject
{
public:
	Monster();

	void update();
	
	int getMoveDirections(Coords* directions) const;
	
private:
	static char const* defaultSprite;
	Coords lastDirection;
	
	bool itsAValidMoveDirection(const Coords& direction) const;
};
