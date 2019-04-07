#include "main.h"

#ifndef GROUND_H
#define GROUND_H

class Ground
{
  public:
    Ground() {}
    Ground(float x, float y, color_t color, color_t color2, color_t color3, color_t color4);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
  private:
    VAO *object;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
};

#endif // GROUND_H