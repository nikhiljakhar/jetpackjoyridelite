#include "main.h"

#ifndef MAGNET_H
#define MAGNET_H


class Magnet {
public:
    Magnet() {}
    Magnet(float x, float y);
    glm::vec3 position;
    double rotation;
    void tick();
    void set_position(float x, float y);
    void draw(glm::mat4 VP, int flg);
private:
    VAO *object;
    VAO *object2;
    VAO *object3;
    VAO *object4;
};

#endif // MAGNET_H
