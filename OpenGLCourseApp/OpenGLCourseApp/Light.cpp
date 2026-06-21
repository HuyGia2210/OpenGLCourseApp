#include "Light.h"

Light::Light(){
	colour = glm::vec3(1.0f, 1.0f, 1.0f);
	ambientIntensity = 1.0f;
	diffusIntensity = 0.0f;
}

Light::Light(
	GLfloat red, 
	GLfloat green, 
	GLfloat blue, 
	GLfloat ambIntensity,
	GLfloat dIntensity
) {
	colour = glm::vec3(red, green, blue);
	ambientIntensity = ambIntensity;

	diffusIntensity = dIntensity;
}

Light::~Light() {

}
