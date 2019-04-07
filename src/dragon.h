#include "main.h"

#ifndef DRAGON_H
#define DRAGON_H


class Dragon {
public:
    Dragon() {}
    Dragon(float x, float y);
    glm::vec3 position;
    double rotation;
    double yspeed;
    double rac;
    int fire;
    color_t color;
    void tick();
    void set_position(float x, float y);
    void draw(glm::mat4 VP, int flg);
private:
    VAO *object;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
    VAO *object7;
};

#endif // DRAGON_H
