#include "Treasure.hpp"
#include "ColorSettings.h"

char const* Treasure::defaultSprite =
	PUT_COLOR("\033[33" BLINKING_CHARS "m") "\xF0\x9F\x92\xB0"
	PUT_COLOR("\033[0m");

Treasure::Treasure() : GameObject(defaultSprite)
{
}
