#include "Texture.h"
#include "stb_image.h""
#include <iostream>
//#include <fstream>
#include <cassert>

Texture::Texture(const std::string& fileName)
{
	int width, height, numComponents;  
	unsigned char* imageData = stbi_load(fileName.c_str(), &width, &height, &numComponents, 4);                          // this function loads the image data
	 
	if (imageData == NULL) {
		std::cerr << "Texture loading failed for texture: " << fileName << std::endl;
	}

	glGenTextures(1,&m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);                                                    // reads texture widht 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);                                                    // reads texture widht 

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);                                                // Fits the pixel number on the screen area spared for the texture
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);												 // Fits the pixel number on the screen area spared for the texture

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData); // mip mapping technique !! check in detail

	stbi_image_free(imageData);                    // this function clears the image data from memory

}

Texture::~Texture()
{
	glDeleteTextures(1, &m_texture);

}

void Texture::Bind(unsigned int unit) {

	assert(unit >= 0 && unit <= 31);                         // This function checks if the unit is within the range specified
	glActiveTexture(GL_TEXTURE0 + unit );                    // This function species the pixel unit with default GL_TEXTURE0
	glBindTexture(GL_TEXTURE_2D, m_texture);                 // This function actually binds the texture to reflect on the window


}