#include "Console.h"

void Console::Error(std::string message) {
	std::cout << termcolor::red << "ERROR  : " << termcolor::reset << message << std::endl;
}

void Console::Warning(std::string message) {
	std::cout << termcolor::yellow << "WARNING: " << termcolor::reset << message << std::endl;
}

void Console::Log(std::string message) {
	std::cout << termcolor::green << "MESSAGE: " << termcolor::reset << message << std::endl;
}