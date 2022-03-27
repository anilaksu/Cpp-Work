#ifndef MESH_H
#define MESH_H
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "obj_loader.h"


class Vertex {
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord, const glm::vec3& normal = glm::vec3(0 , 0 , 0 )) {
		this->pos = pos;
		this->texCoord = texCoord;
		this->normal = normal;
	}

	inline glm::vec3* GetPos() { return &pos; }
	inline glm::vec2* GetTexCoord() { return &texCoord; }
	inline glm::vec3* GetNormal() { return &normal; }

protected:

private:
	glm::vec3 pos;                      // position of the vertices
	glm::vec2 texCoord;                 // Texture coordinates to be mapped onto image
	glm::vec3 normal;                    // Normal of the vertices
};

class Mesh
{

public:
	Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);  // Reads an input for the shader
	Mesh(const std::string& fileName);


	void Draw();                 // Sets GPU to a state where it uses Vertex Shader and Fragment Shader

	virtual ~Mesh();           // destructor of the shader
protected:
private:
	//static const unsigned int NUM_SHADERS = 2; // One is for Vertex Shader and the other one is for Fragment Shader
	Mesh(const Mesh& other) {}
	void operator=(const Mesh& other) {}

	void InitMesh(const IndexedModel& model);

	enum {
		POSITION_VB,
		TEXCOORD_VB,
		NORMAL_VB,
		INDEX_VB,

		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];

	unsigned int m_drawCount;            // Number of vertices to be drawn
};

#endif // MESH_H
