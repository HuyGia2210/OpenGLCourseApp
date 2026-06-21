#pragma once
#include "Light.h"

class PointLight :
    public Light
{

public:
    PointLight();
    PointLight(
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
    );

    void UseLight(
        GLuint ambientIntensityLocation,
        GLuint ambientColourLocation,
        GLuint diffusIntensityLocation,
        GLuint positionLocation,
        GLuint constantLocation,
        GLuint linearLocation,
        GLuint exponentLocation
    );
    ~PointLight();

protected:
    glm::vec3 position;

    GLfloat constant, linear, exponent;


};

