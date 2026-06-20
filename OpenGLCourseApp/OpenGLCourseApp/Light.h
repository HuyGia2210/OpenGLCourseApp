#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

class Light
{
public:
	Light();
	Light(
		GLfloat red, 
		GLfloat green, 
		GLfloat blue, 
		GLfloat ambIntensity, 
		GLfloat xDir, 
		GLfloat yDir, 
		GLfloat zDir, 
		GLfloat dIntensity
	);

	void UseLight(
		GLuint ambientIntensityLocation, 
		GLuint ambientColourLocation,
		GLuint diffusIntensityLocation,
		GLuint directionLocation
	);

	~Light();

private:
	glm::vec3 colour;
	GLfloat ambientIntensity;

	//for diffuse lighting
	glm::vec3 direction;
	GLfloat diffusIntensity;


};

