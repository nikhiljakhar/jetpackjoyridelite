#include "powerup.h"
#include "main.h"
#include "math.h"

Powerup::Powerup(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->radius = 0.3;
    this->xspeed = 0.01;
    this->yspeed = 0.02;

    static const GLfloat vertex_buffer_data[] = {

        0.3,0,0,
        -0.3,0.3,0,
        -0.3,-0.3,0,

    };
    this->object = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data, COLOR_RED, GL_FILL);
    static const GLfloat vertex_buffer_data2[] = {

        0.3,0,0,
        0,0.15,0,
        0,-0.15,0,
        0,0,0,
        -0.3,0.15,0,
        -0.3,-0.15,0,

    };
    this->object2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, COLOR_YELLOW, GL_FILL);
}


void Powerup::tick() {
    this->position.x += xspeed;
    this->position.y -= yspeed;
    if(this->position.y<=-1 || this->position.y>=2)
        yspeed = 0 - yspeed;
}

void Powerup::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Powerup::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    //rotate = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
}
