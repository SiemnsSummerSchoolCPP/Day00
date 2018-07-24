#pragma once

#include <exception>

namespace GameExceptions
{
	struct GameException : std::exception {};
	
	struct InvalidFileMap : GameException
	{
		char const* msg;
		InvalidFileMap(char const* msg) { this->msg = msg; }
		char const* what() const throw() { return msg; }
	};
}
