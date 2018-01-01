#include "Console.h"

void Console::Error(std::string message) {
	std::cout << clr::red << "ERROR  : " << clr::reset << message << std::endl;
}

void Console::Warning(std::string message) {
	std::cout << clr::yellow << "WARNING: " << clr::reset << message << std::endl;
}

void Console::Log(std::string message) {
	std::cout << clr::green << "MESSAGE: " << clr::reset << message << std::endl;
}