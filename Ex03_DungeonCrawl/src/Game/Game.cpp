#include "Game.hpp"
#include <iostream>
#include <fstream>
#include <ostream>
#include "GameExceptions.h"
#include "Human.hpp"
#include "Wall.hpp"
#include "Treasure.hpp"
#include "Monster.hpp"

Game* Game::instance = nullptr;

/*
** Constructors & destructors.
*/

Game::Game(const char* mapFilePath)
{
	Game::instance = this;
	
	auto mapFileStream = std::ifstream(mapFilePath);
	if (!mapFileStream.is_open())
	{
		throw GameExceptions::InvalidFileMap(strerror(errno));
	}
	
	try
	{
		loadFromStream(mapFileStream);
	}
	catch (GameExceptions::GameException const& e)
	{
		mapFileStream.close();
		throw e;
	}
	
	mapFileStream.close();
}

Game::~Game()
{
	for (auto& obj : gameObjects)
	{
		delete obj;
	}
	
	
}

/*
** Public members
*/

void Game::update()
{
	for (auto obj : gameObjects)
	{
		obj->update();
	}
	system("clear");
	std::cout << *this;
}

/*
** Private members.
*/

static void throwIfNotChar(const char targetChar, std::istream &stream)
{
	char newlineBuf;
	
	stream.read(&newlineBuf, sizeof(newlineBuf));
	if (newlineBuf != targetChar)
	{
		throw GameExceptions::InvalidFileMap(
			(std::string("Unexpected char: ") + newlineBuf + ".")
			.c_str()
		);
	}
}

void Game::loadFromStream(std::istream &mapStream)
{
	int width;
	int height;
	
	mapStream >> (width) >> (height);
	if (!mapStream || mapStream.eof())
	{
		throw GameExceptions::InvalidFileMap("Failed to read game dimensions");
	}
	throwIfNotChar('\n', mapStream);
	
	map.Init(width, height);
	auto line = std::unique_ptr<char>(new char[width]);
	for (int i = 0; i < height; i++)
	{
		mapStream.read(line.get(), width);
		throwIfNotChar('\n', mapStream);
		
		for (int j = 0; j < width; j++)
		{
			auto newObj = tryAddGameObject(line.get()[j]);
			map.objects[i][j] = newObj;
			
			if (newObj != nullptr)
			{
				Coords pos;
				pos.x = j;
				pos.y = i;
				newObj->coords = pos;
			}
		}
	}
	
	if (human == nullptr)
		throw GameExceptions::InvalidFileMap("No human player on the map.");
}

GameObject* Game::identifyGameObj(char const objChar)
{
	switch (objChar)
	{
		case spaceChar:
			return nullptr;
		case wallChar:
			return new Wall();
		case humanChar:
			return new Human(std::bind(
				&Game::onWin,
				this,
				std::placeholders::_1));
		case monsterChar:
			return new Monster();
		case treasureChar:
			return new Treasure();
		default:
		{
			throw GameExceptions::InvalidFileMap(
				(std::string("Invalid map object: ") + objChar).c_str()
			);
		}
	}
}

GameObject* Game::tryAddGameObject(char const objChar)
{
	auto obj = identifyGameObj(objChar);
	if (obj != nullptr)
		gameObjects.push_back(obj);
	
	auto loadedHuman = dynamic_cast<Human*>(obj);
	if (loadedHuman)
	{
		if (this->human != nullptr)
			throw GameExceptions::InvalidFileMap("Too many humans on the map");
		this->human = loadedHuman;
	}
	
	return obj;
}

void Game::onWin(Treasure const& treasure)
{
	system("clear");
	std::cout << *this;
	std::cout << "U won!" << std::endl;
	exit(EXIT_SUCCESS);
}

/*
** Operators.
*/

std::ostream& operator<<(std::ostream& o, Game const& target)
{
	for (int i = 0; i < target.map.getHeight(); i++)
	{
		for (int j = 0; j < target.map.getWidth(); j++)
		{
			if (target.map.objects[i][j] == nullptr)
			{
				o << "  ";
			}
			else
			{
				o << target.map.objects[i][j]->sprite;
			}
		}
		o << std::endl;
	}
	return o;
}
