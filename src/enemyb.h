#include "main.h"

#ifndef ENEMYB_H
#define ENEMYB_H


class Enemyb {
public:
    Enemyb() {}
    Enemyb(float x, float y, float radius, float xshift, color_t color);
    glm::vec3 position;
    double rotation;
    int working;
    double radius;
    double xspeed;
    double xshift;
    color_t color;
    void tick();
    void set_position(float x, float y);
    void draw(glm::mat4 VP);
private:
    VAO *object;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
};

#endif // ENEMYB_H
