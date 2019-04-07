#include "main.h"

#ifndef COINS_H
#define COINS_H


class Coins {
public:
    Coins() {}
    Coins(float x, float y, float radius, color_t color);
    glm::vec3 position;
    double rotation;
    int score;
    int alive;
    double radius;
    double xspeed;
    color_t color;
    void tick();
    void set_position(float x, float y);
    void draw(glm::mat4 VP);
    // bounding_circle_t bounding_circle();
private:
    VAO *object;
};

#endif // COINS_H
