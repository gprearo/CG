#define _USE_MATH_DEFINES
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <cmath>


class Sphere {
protected:
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> normals;
    std::vector<GLfloat> texcoords;
    std::vector<GLushort> indices;

public:
    Sphere(float radius, unsigned int rings, unsigned int sectors);

    void draw(GLfloat x, GLfloat y, GLfloat z, float ax, float ay, float az);
};
