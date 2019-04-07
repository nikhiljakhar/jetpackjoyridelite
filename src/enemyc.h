#include "main.h"

#ifndef ENEMYC_H
#define ENEMYC_H


class Enemyc {
public:
    Enemyc() {}
    Enemyc(float x, float y, color_t color);
    glm::vec3 position;
    double rotation;
    int score;
    int alive;
    double radius;
    double xspeed;
    double yspeed;
    color_t color;
    void tick();
    void set_position(float x, float y);
    void draw(glm::mat4 VP);
private:
    VAO *object;
};

#endif // ENEMYC_H
