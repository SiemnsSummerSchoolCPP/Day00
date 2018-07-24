#include "Game/Game.hpp"
#include <iostream>

int main(const int argc, char const** argv)
{
	if (argc == 1)
	{
		std::cerr << "No file map provided" << std::endl;
		return EXIT_FAILURE;
	}
	
	auto game = Game(argv[1]);
	system("clear");
	std::cout << game;
	
	srand(time(NULL));
	while (true)
	{
		game.update();
	}
	return 0;
}
