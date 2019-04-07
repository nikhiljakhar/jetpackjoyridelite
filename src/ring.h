#include "main.h"

#ifndef RING_H
#define RING_H


class Ring {
public:
    Ring() {}
    Ring(float x, float y);
    glm::vec3 position;
    double rotation;
    double radius;
    double xspeed;
    void tick();
    void set_position(float x, float y);
    void draw(glm::mat4 VP);
    // bounding_circle_t bounding_circle();
private:
    VAO *object;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
    VAO *object7;
    VAO *object8;
};

#endif // RING_H
