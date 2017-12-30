#ifndef PROGRAM_H
#define PROGRAM_H

#include <SFML/Graphics.hpp>
#include <GL/glew.h>

class Program
{
public:
	// functions
	Program();
	void Run();

private:
	// functions
	void InitializeWindow(bool vcync = true);
	void PrintVersionInfo();
	void InitializeGlew();
	void ProcessEvents();
	
	// variables
	sf::RenderWindow* _window;  //sfml window to render to

	float _desiredFPS;
	float _currentFPS;

};


#endif // !PROGRAM_H

