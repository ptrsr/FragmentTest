#include "Quad.h"
#include <glm\glm.hpp>

Quad::Quad()
{
	glm::vec2 corners[] = {
		glm::vec2(0, 0),	// 0
		glm::vec2(0, 1),	// 1
		glm::vec2(1, 1),	// 2
		glm::vec2(1, 0),	// 3
	};

	glm::vec2 triangles[] = {
		corners[0], corners[1], corners[2],
		corners[0], corners[2], corners[3]
	};

	glGenBuffers(1, &_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangles), &triangles[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
	glEnableVertexAttribArray(pVerticesAttrib);
	glVertexAttribPointer(pVerticesAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

void Quad::Draw()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferId);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
}