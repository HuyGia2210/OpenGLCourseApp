#include "Light.h"

Light::Light(){
	colour = glm::vec3(1.0f, 1.0f, 1.0f);
	ambientIntensity = 1.0f;

	direction = glm::vec3(0.0f, -1.0f, 0.0f);
	diffusIntensity = 0.0f;
}

Light::Light(
	GLfloat red, 
	GLfloat green, 
	GLfloat blue, 
	GLfloat ambIntensity, 
	GLfloat xDir,
	GLfloat yDir,
	GLfloat zDir,
	GLfloat dIntensity
) {
	colour = glm::vec3(red, green, blue);
	ambientIntensity = ambIntensity;

	direction = glm::vec3(xDir, yDir, zDir);
	diffusIntensity = dIntensity;
}

void Light::UseLight(
	GLuint ambientIntensityLocation,
	GLuint ambientColourLocation,
	GLuint diffusIntensityLocation,
	GLuint directionLocation
) {
	glUniform3f(ambientColourLocation, colour.x, colour.y, colour.z);
	glUniform1f(ambientIntensityLocation, ambientIntensity);

	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
	glUniform1f(diffusIntensityLocation, diffusIntensity);
}

Light::~Light() {

}
