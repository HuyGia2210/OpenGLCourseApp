#include "SpotLight.h"

SpotLight::SpotLight() : PointLight() {
	direction = glm::normalize(glm::vec3(0.0f, -1.0f, 0.0f));
	edge = 0.0f;
}

SpotLight::SpotLight(
	GLfloat red, 
	GLfloat green, 
	GLfloat blue, 
	GLfloat ambIntensity, 
	GLfloat dIntensity, 
	GLfloat xPos, 
	GLfloat yPos, 
	GLfloat zPos,
	GLfloat xDir, 
	GLfloat yDir, 
	GLfloat zDir, 
	GLfloat cnst, 
	GLfloat linr, 
	GLfloat expn, 
	GLfloat edg
) : PointLight(
	red, green, blue, ambIntensity, dIntensity, xPos, yPos, zPos, cnst, linr, expn
){
	direction = glm::normalize(glm::vec3(xDir, yDir, zDir));

	edge = edg;
	procEdge = cosf(glm::radians(edge));
}

void SpotLight::UseLight(
	GLuint ambientIntensityLocation, 
	GLuint ambientColourLocation, 
	GLuint diffusIntensityLocation, 
	GLuint positionLocation, 
	GLuint directionLocation, 
	GLuint constantLocation, 
	GLuint linearLocation, 
	GLuint exponentLocation, 
	GLuint egdeLocation
){
	glUniform3f(ambientColourLocation, colour.x, colour.y, colour.z);
	glUniform1f(ambientIntensityLocation, ambientIntensity);
	glUniform1f(diffusIntensityLocation, diffusIntensity);

	glUniform3f(positionLocation, position.x, position.y, position.z);
	glUniform1f(constantLocation, constant);
	glUniform1f(linearLocation, linear);
	glUniform1f(exponentLocation, exponent);

	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
	glUniform1f(egdeLocation, procEdge);
}

void SpotLight::SetFlash(glm::vec3 pos, glm::vec3 dir){
	position = pos;
	direction = dir;
}

SpotLight::~SpotLight(){

}
