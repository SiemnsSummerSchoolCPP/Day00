#include "Wall.hpp"
#include "ColorSettings.h"

char const* Wall::defaultSprite =
	PUT_COLOR("\033[40m") "W " PUT_COLOR("\033[0m");

Wall::Wall() : GameObject(defaultSprite)
{
}
