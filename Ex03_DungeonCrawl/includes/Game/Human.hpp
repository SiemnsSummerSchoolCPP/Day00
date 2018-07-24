#pragma once

#include <functional>
#include "GameObject.hpp"
#include "Map.hpp"
#include "Treasure.hpp"

typedef std::function<void(Treasure const&)> OnWinEvent;

class Human : public GameObject
{
public:
	Human(OnWinEvent onWin);
	~Human();
	
	bool move(Coords newPos, Map& map);

	void update();
	void die();

private:
	static char const* defaultSprite;
	
	OnWinEvent onWin;
};
