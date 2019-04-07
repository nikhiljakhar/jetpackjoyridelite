#include "main.h"

#ifndef BALLOON_H
#define BALLOON_H


class Balloon {
public:
    Balloon() {}
    Balloon(float x, float y, float radius);
    glm::vec3 position;
    double rotation;
    int score;
    int alive;
    double radius;
    double xspeed;
    double yspeed;
    int thro;
    void tick();
    void set_position(float x, float y);
    void draw(glm::mat4 VP);
private:
    VAO *object;
};

#endif // BALLOON_H
