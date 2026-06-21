#pragma once
#include "Light.h"

class DirectionalLight :
    public Light
{

public:
    DirectionalLight();
	DirectionalLight(
		GLfloat red,
		GLfloat green,
		GLfloat blue,
		GLfloat ambIntensity,
		GLfloat dIntensity,
		GLfloat xDir,
		GLfloat yDir,
		GLfloat zDir
	);

	void UseLight(
		GLuint ambientIntensityLocation,
		GLuint ambientColourLocation,
		GLuint diffusIntensityLocation,
		GLuint directionLocation
	);
    ~DirectionalLight();

private:
    glm::vec3 direction;
};

