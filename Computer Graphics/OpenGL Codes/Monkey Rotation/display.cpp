#include "display.h"
#include <iostream>


Display::Display(int width, int height, const std::string& title) {
  
	//std::cout << "Constructor" << std::endl;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);        // Number of bits to generate different shades of Red
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);      // Number of bits to generate different shades of Green
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);       // Number of bits to generate different shades of Blue
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);      // Number of bits to generate different shades of transparancy
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);    // How much data SDL allocats for each bit
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);     // It stores the depth of each pixel to be reflected on window
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);     // Allocate space for two windows

	// It specifes, we use  OpenGL
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_window);

	GLenum status = glewInit();

	if (status != GLEW_OK) {
		std::cerr << "Glew failed to initialize" << std::endl;
	}

	m_isClosed = false;

	glEnable(GL_DEPTH_TEST); // it avoids overwriting of pixels in non-convex geometries
	glEnable(GL_CULL_FACE);  // this avoids overwriting  of pixels in convex geometries
	glCullFace(GL_BACK);     // this avoids overwriting  of pixels in convex geometries
}

Display::~Display() {
	//std::cout << "Destructor" << std::endl;
	SDL_GL_DeleteContext(m_glContext);   // First destroy the context
	SDL_DestroyWindow(m_window);         // Then destroy the window
	SDL_Quit();                          // Finally quit
}

void Display::Clear(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Display::IsClosed() {
	return m_isClosed;
}
void Display::Update() {

	SDL_GL_SwapWindow(m_window);

	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT)
			m_isClosed = true;
	}

}