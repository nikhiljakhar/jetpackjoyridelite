#include "main.h"

#ifndef ENEMYA_H
#define ENEMYA_H


class Enemya {
public:
    Enemya() {}
    Enemya(float x, float y, color_t color);
    glm::vec3 position;
    double rotation;
    double yspeed;
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

#endif // ENEMYA_H
