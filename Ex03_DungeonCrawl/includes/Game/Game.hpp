#pragma once

#include "Human.hpp"
#include "GameObject.hpp"
#include "Treasure.hpp"
#include "Map.hpp"
#include <ostream>
#include <vector>

static const char spaceChar = '.';
static const char humanChar = 'H';
static const char wallChar = 'W';
static const char treasureChar = 'X';
static const char monsterChar = 'M';

class Game
{
public:
	static Game* instance;

	Map map;

	Game(const char* mapFilePath);
	~Game();
	
	void update();
	
	friend std::ostream& operator<<(std::ostream& o, Game const& target);
	
private:
	Human* human = nullptr;
	
	std::vector<GameObject*> gameObjects;
	
	void loadFromStream(std::istream& mapStream);
	GameObject* tryAddGameObject(char const objChar);
	GameObject* identifyGameObj(char const objChar);
	void onWin(Treasure const& treasure);
};

