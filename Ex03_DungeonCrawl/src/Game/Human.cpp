#include "Human.hpp"
#include "ColorSettings.h"
#include "Treasure.hpp"
#include "Game.hpp"
#include <iostream>
#include <termios.h>
#include <unistd.h>

int getch(void)
{
	struct termios oldt, newt;
	int ch;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

	return ch;
}

char const* Human::defaultSprite =
	PUT_COLOR("\033[0;32" "m") "\xF0\x9F\x90\xB7"
	PUT_COLOR("\033[0m");

Human::Human(OnWinEvent onWin) : GameObject(defaultSprite), onWin(onWin)
{
}

bool Human::move(Coords const newPos, Map& map)
{
	if (!map.validPos(newPos))
	{
		return false;
	}
	
	const Treasure* treasure;
	auto obj = map.objects[newPos.y][newPos.x];
	
	treasure = dynamic_cast<Treasure*>(obj);
	if (obj != nullptr && !treasure)
	{
		return false;
	}
	
	map.objects[coords.y][coords.x] = nullptr;
	map.objects[newPos.y][newPos.x] = this;
	coords = newPos;
	
	if (treasure)
	{
		onWin(*treasure);
	}
	
	return true;
}

void Human::update()
{
	char inputKey;
	
	inputKey = tolower(getch());
	
	auto newPos = coords;
	switch (inputKey)
	{
		case 'w':
			newPos.y--;
			break;
		case 's':
			newPos.y++;
			break;
		case 'a':
			newPos.x--;
			break;
		case 'd':
			newPos.x++;
			break;
		default:
		{
			std::cerr << inputKey << ": Invalid key" << std::endl;
		}
	}
	
	move(newPos, Game::instance->map);
}

void Human::die()
{
	system("clear");
	std::cout << *Game::instance;
	std::cout << "You die lol" << std::endl;
	exit(EXIT_SUCCESS);
}
