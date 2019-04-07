#include "main.h"

#ifndef POWERUP_H
#define POWERUP_H


class Powerup {
public:
    Powerup() {}
    Powerup(float x, float y);
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
    VAO *object2;
};

#endif // POWERUP_H
