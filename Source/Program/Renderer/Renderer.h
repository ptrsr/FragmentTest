#ifndef RENDERER_H
#define RENDERER_H

#include "ShaderProgram.hpp"

class Renderer
{
public:
	Renderer();
	void GetShader();

	void Render();

private:
	ShaderProgram* _shader;
};

#endif // !RENDERER_H
