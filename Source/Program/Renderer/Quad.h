#ifndef QUAD_H
#define QUAD_H

#include <GL\glew.h>

class Quad
{
public:
	Quad();
	void Draw();

private:
	GLuint _bufferID;
};

#endif // !QUAD_H
