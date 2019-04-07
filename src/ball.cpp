#include "ball.h"
#include "main.h"

Ball::Ball(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->radius = 0.2;
    speed = 0.01;
    jump = 0;
    xspeed = 0.03;
    yspeed = 0;
    static const GLfloat vertex_buffer_data[] = {
        0.0f,0.0f-1,0.0f, // triangle 1 : begin
        -0.3f,0.0f-1, 0.0f,
        -0.15f, 0.3f-1, 0.0f, // triangle 1 : end
        0.0f, 0.3f-1,0.0f, // triangle 2 : begin
        0.0f,0.7f-1,0.0f,
        -0.3f, 0.3f-1,0.0f, // triangle 2 : end
        -0.3f, 0.3f-1,0.0f,
        -0.3f, 0.7f-1,0.0f,
        0.0f,0.7f-1,0.0f,
        -0.3f, 0.4f-1,0.0f,
        -0.5f,0.4f-1,0.0f,
        -0.35f,0.7f-1,0.0f,
        -0.05f,0.85f-1,0.0f,
        -0.15f, 0.7f-1, 0.0f,
        -0.25f, 0.85f-1,0.0f,
        0.05f,0.85f-1,0.0f,
        -0.15f, 1.0f-1, 0.0f,
        -0.25f, 0.85f-1,0.0f,
    };

    this->object = create3DObject(GL_TRIANGLES, 18, vertex_buffer_data, color, GL_FILL);
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Ball::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ball::tick() {
}


