#include "Monster.hpp"
#include "ColorSettings.h"
#include "Game.hpp"

const Coords kUpCoords =	Coords(0, -1);
const Coords kDownCoords =	Coords(0, 1);
const Coords kLeftCoords =	Coords(-1, 0);
const Coords kRightCoords =	Coords(1, 0);

char const* Monster::defaultSprite =
	PUT_COLOR("\033[0;31" "m") "\xF0\x9F\x98\xA1"
	PUT_COLOR("\033[0m");

Monster::Monster() : GameObject(defaultSprite)
{
	lastDirection = Coords(0, 0);
}

void Monster::update()
{
	auto& map = Game::instance->map;
	Coords possibleDirections[4];
	
	auto nbOfDirectins = getMoveDirections(possibleDirections);
	
	if (nbOfDirectins == 0)
	{
		lastDirection = Coords(0, 0);
		return;
	}
	
	const auto direction = possibleDirections[rand() % nbOfDirectins];
	const auto newPos = Coords(coords.x + direction.x, coords.y + direction.y);
	
	map.objects[coords.y][coords.x] = nullptr;
	auto human = dynamic_cast<Human*>(map.objects[newPos.y][newPos.x]);
	map.objects[newPos.y][newPos.x] = this;
	coords = newPos;
	
	if (human)
	{
		human->die();
	}
	
	lastDirection = direction;
}

static bool celIsValidAndEmpty(const Map& map, int x, int y)
{
	if (!map.validPos(Coords(x, y)))
		return false;
	
	const auto obj = map.objects[y][x];
	if (obj == nullptr || dynamic_cast<Human*>(obj))
		return true;
	
	return false;
}

static bool oppositeDirections(const Coords& dir1, const Coords& dir2)
{
	return dir1.x == -dir2.x && dir1.y == -dir2.y;
}

bool Monster::itsAValidMoveDirection(const Coords& direction) const
{
	const auto& map = Game::instance->map;
	const auto newPos = Coords(coords.x + direction.x, coords.y + direction.y);
	
	if (!celIsValidAndEmpty(map, newPos.x, newPos.y))
		return false;
	
	if (oppositeDirections(lastDirection, direction))
		return false;
	
	return true;
}

int Monster::getMoveDirections(Coords* directions) const
{
	int count = 0;

	if (itsAValidMoveDirection(kUpCoords))
		directions[count++] = kUpCoords;
	if (itsAValidMoveDirection(kDownCoords))
		directions[count++] = kDownCoords;
	if (itsAValidMoveDirection(kLeftCoords))
		directions[count++] = kLeftCoords;
	if (itsAValidMoveDirection(kRightCoords))
		directions[count++] = kRightCoords;
	return count;
}
