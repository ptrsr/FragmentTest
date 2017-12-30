#include "Console/Console.h"
#include "Program/Program.h"

int main()
{
	Console::Log("Starting up fragment test");

	Program* program = new Program();

	program->Run();
	std::cin.get();

	delete program;

	return 0;
}