#include "Map.hpp"

Map::~Map()
{
	if (objects == nullptr)
		return;
	
	for (int i = 0; i < height; i++)
	{
		if (objects[i] != nullptr)
		{
			delete[] objects[i];
		}
	}
	
	delete[] objects;
}

void Map::Init(int width, int height)
{
	this->width = width;
	this->height = height;
	
	objects = new GameObject**[height];
	for (int i = 0; i < height; i++)
	{
		objects[i] = new GameObject*[width];
		for (int j = 0; j < width; j++)
			objects[i][j] = nullptr;
	}
}

bool Map::validPos(Coords const& coords) const
{
	return
		coords.x >= 0 && coords.x < width &&
		coords.y >= 0 && coords.y < height;
}
