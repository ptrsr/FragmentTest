#include "Renderer.h"

Renderer::Renderer()
{
	GetShader();
}

void Renderer::GetShader()
{
	std::string path = "Source/Data/";

	_shader = new ShaderProgram();
	_shader->addShader(GL_VERTEX_SHADER, path + "color.vs");
	_shader->addShader(GL_FRAGMENT_SHADER, path + "color.fs");
	_shader->finalize();

	_shader->use();
}

void Renderer::Render()
{

}