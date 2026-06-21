#include "PointLight.h"

PointLight::PointLight() : Light() {
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    constant = 1.0f;
    linear = 0.0f;
    exponent = 0.0f;
}
PointLight::PointLight(
    GLfloat red,
    GLfloat green,
    GLfloat blue,
    GLfloat ambIntensity,
    GLfloat dIntensity,
    GLfloat xPos,
    GLfloat yPos,
    GLfloat zPos,
    GLfloat cnst,
    GLfloat linr,
    GLfloat expn
) : Light(
    red, green, blue, ambIntensity, dIntensity
) {
    position = glm::vec3(xPos, yPos, zPos);
    constant = cnst;
    linear = linr;
    exponent = expn;
}

void PointLight::UseLight(
    GLuint ambientIntensityLocation,
    GLuint ambientColourLocation,
    GLuint diffusIntensityLocation,
    GLuint positionLocation,
    GLuint constantLocation,
    GLuint linearLocation,
    GLuint exponentLocation
) {
    glUniform3f(ambientColourLocation, colour.x, colour.y, colour.z);
    glUniform1f(ambientIntensityLocation, ambientIntensity);
    glUniform1f(diffusIntensityLocation, diffusIntensity);
    glUniform3f(positionLocation, position.x, position.y, position.z);
    glUniform1f(constantLocation, constant);
    glUniform1f(linearLocation, linear);
    glUniform1f(exponentLocation, exponent);
}

PointLight::~PointLight() {

}
