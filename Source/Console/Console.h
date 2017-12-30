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

void Console::Error(std::string message) {
	std::cout << termcolor::red << "ERROR  : " << termcolor::reset << message << std::endl;
}

void Console::Warning(std::string message) {
	std::cout << termcolor::yellow << "WARNING: " << termcolor::reset << message << std::endl;
}

void Console::Log(std::string message) {
	std::cout << termcolor::green << "MESSAGE: " << termcolor::reset << message << std::endl;
}


#endif // !CONSOLE_H
