#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include "TermColor.hpp"

class Console
{
public:
	// functions
	static void Error(std::string message);
	static void Warning(std::string message);
	static void Log(std::string message);
};




#endif // !CONSOLE_H
