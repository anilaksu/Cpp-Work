#include <iostream>
//#include <stdlib.h> 
//#include <fstream>
//#define GLEW_STATIC
#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include "SDL.h"
#include "display.h"
#include "shader.h"
#include "Mesh.h"
#include "stb_image.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"
//#include "OffLoader.h"
#include<glm/glm.hpp>
#include<glm/gtx/transform.hpp>
//#include "bitmap_image.hpp"
#define WIDTH  800
#define HEIGHT 600

using namespace std;

// Window dimensions
//const GLint WIDTH = 1600, HEIGHT = 900;

//void lineSegment(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT); // Clear display window.
//	glColor3f(0.0, 0.4, 0.2);     // Set line color to green
//	glBegin (GL_LINES);
//		glVertex2i (180, 15);     // Set line segment geometry
//		glVertex2i(10, 145);
//	glEnd ( );
//	glFlush ( );                  // process all OpenGL routines as quickly as possible
//
//}




// The MAIN function, from here we start the application and run the game loop
int main(int argc, char *argv[])
{
	//GLenum status = glewInit(); 
	//cout << "Hello world!" << endl;
	Display display(WIDTH, HEIGHT, "What starts here changes the world for better");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 3), glm::vec2(0.0 , 0.0 )),
						  Vertex(glm::vec3(   0,  0.5, 3), glm::vec2(0.5 , 1.0 )),
		                  Vertex(glm::vec3( 0.5, -0.5, 3), glm::vec2(1.0 , 0.0)),
	};

	unsigned int indices[] = {0, 1, 2};

	//Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	Mesh mesh2("./res/monkey3.obj");
	//Mesh mesh2("./res/1.obj");
	// Binary space partitioning : cutting things in half to fix overwriting in non-convex geometries
	// ZBuffer by graphics cards : this is what we use here
	Shader shader("./res/basicShader");
	Texture texture("./res/Tolga.jpg");
	Camera camera(glm::vec3(0,0,-3.0), 70.0f, (float)WIDTH/(float)HEIGHT, 0.01f, 1000.0f);
	Transform transform;

	float counter = 0.5*3.14f;
	//if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
	//	cout << "SDL could not initialise! SDL Error: " << SDL_GetError() << endl;
	//}

	//while (!display.IsClosed()) {


	//}
	//Shader shader("./res/basicShader");

	while (!display.IsClosed())
	{
		
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPos().x = sinf(counter);
		transform.GetPos().z = 4.0+2.0*sinf(0.5*counter);
		//transform.GetRot().z = 1.5;
		transform.GetRot().x = cosf(1.5 * counter);
		//transform.GetRot().z = sinf(1.5 * counter);
		transform.GetRot().y = sinf(1.5 * counter);;
		//transform.GetRot().x = counter;
		//transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

		shader.Bind();
		shader.Update(transform, camera);
		texture.Bind(0);
		mesh2.Draw();

		display.Update();
		counter += 0.002f;
	}

	return 0;
}