#include "main.h"

#ifndef POWERUPC_H
#define POWERUPC_H


class Powerupc {
public:
    Powerupc() {}
    Powerupc(float x, float y);
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

#endif // POWERUPC_H
