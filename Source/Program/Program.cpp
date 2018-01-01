#include "Program.h"

#include "..\Console\Console.h"

Program::Program() : _window(NULL), _desiredFPS(60)
{
	InitializeWindow();
	PrintVersionInfo();
	InitializeGlew();
	InitializeRenderer();
}

void Program::InitializeWindow(bool vcync)
{
	_window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Shader Tester", sf::Style::Default, sf::ContextSettings(24, 8, 0, 3, 3));
	
	if (vcync)
		_window->setVerticalSyncEnabled(true);

	Console::Log("Initialized window");
}

void Program::PrintVersionInfo()
{
	Console::Log("Machine info:");
	std::cout << "----------------------------------" << std::endl;
	//print some debug stats for whoever cares
	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *vendor = glGetString(GL_VENDOR);
	const GLubyte *version = glGetString(GL_VERSION);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	//nice consistency here in the way OpenGl retrieves values
	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);

	printf("GL Vendor : %s\n", vendor);
	printf("GL Renderer : %s\n", renderer);
	printf("GL Version (string) : %s\n", version);
	printf("GL Version (integer) : %d.%d\n", major, minor);
	printf("GLSL Version : %s\n", glslVersion);

	std::cout << "----------------------------------" << std::endl << std::endl;
}

void Program::InitializeGlew()
{
	//initialize the opengl extension wrangler
	GLint glewStatus = glewInit();

	if (glewStatus != GLEW_OK)
		Console::Error("Couldn't initialize GLEW!");
	else
		Console::Log("Initialized GLEW");
}

void Program::InitializeRenderer()
{
	_renderer = new Renderer();
	Console::Log("Initialized renderer");
}

void Program::Run()
{
	sf::Clock updateClock;
	sf::Clock renderClock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / _desiredFPS);


	while (_window->isOpen()) {
		timeSinceLastUpdate += updateClock.restart();

		if (timeSinceLastUpdate > timePerFrame)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			while (timeSinceLastUpdate > timePerFrame) {
				timeSinceLastUpdate -= timePerFrame;
				std::cout << timeSinceLastUpdate.asMilliseconds() << std::endl; // REPLACE
			}

			//_render();
			_window->display();

			float timeSinceLastRender = renderClock.restart().asSeconds();
			
			if (timeSinceLastRender != 0)
				_currentFPS = 1.0f / timeSinceLastRender;
		}

		ProcessEvents();
	}
}

void Program::ProcessEvents()
{
	sf::Event event;
	bool exit = false;

	while (_window->pollEvent(event)) 
	{
		switch (event.type) 
		{
		case sf::Event::Closed:
			exit = true;
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				exit = true;
			break;

		case sf::Event::Resized:
			glViewport(0, 0, event.size.width, event.size.height);
			break;

		default:
			break;
		}
	}

	if (exit)
		_window->close();
}