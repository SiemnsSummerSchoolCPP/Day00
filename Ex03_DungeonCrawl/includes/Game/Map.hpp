#pragma once

#include "GameObject.hpp"

class Map
{
public:
	int getWidth() const { return width; }
	int getHeight() const { return height; }

	GameObject*** objects;
	
	void Init(int width, int height);
	bool validPos(Coords const& coords) const;
	
private:
	int width;
	int height;
};
