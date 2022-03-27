#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>
#include "Transform.h"
#include "Camera.h"

class Shader
{
	public:
		Shader(const std::string& filename);  // Reads an input for the shader
        
		void Bind();                 // Sets GPU to a state where it uses Vertex Shader and Fragment Shader
		void Update(const Transform& transform, const Camera& camera);

		virtual ~Shader();           // destructor of the shader
	protected:
	private:
		static const unsigned int NUM_SHADERS = 2; // One is for Vertex Shader and the other one is for Fragment Shader
		//static const unsigned int NUM_SHADERS = 2; // One is for Vertex Shader and the other one is for Fragment Shader
		Shader(const Shader& other) {}
		void operator=(const Shader& other) {}

		enum
		{
			TRANSFORM_U,

			NUM_UNIFORMS
		};

		GLuint m_program;                  // This is how the shader program is referred within the code
		GLuint m_shaders[NUM_SHADERS];      // Let's generate Vertex and Fragmen shaders
		GLuint m_uniforms[NUM_UNIFORMS];      // Let's generate Vertex and Fragmen shaders
};

#endif // SHADER_H


