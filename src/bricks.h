#include "main.h"

#ifndef BRICKS_H
#define BRICKS_H


class Bricks {
public:
    Bricks() {}
    Bricks(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    double xspeed;
    double bascx;
    double bascx2;
    double bascx3;
    double bascx4;
    double bascy;
    double bascy2;
    double bascy3;
    double bascy4;
    int index;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    double speed;
private:
    VAO *object;
};

#endif // BRICKS_H
