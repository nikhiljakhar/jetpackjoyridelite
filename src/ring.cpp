#include "ring.h"
#include "main.h"
#include "math.h"

Ring::Ring(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->radius = 2;
    this->xspeed = 0.03;

    const int n = 720;
    const int tind = n * 9;
    GLfloat vertex_buffer_data[tind] = {};
    GLfloat vertex_buffer_data2[tind] = {};
    GLfloat vertex_buffer_data3[tind] = {};
    GLfloat vertex_buffer_data4[tind] = {};


    double angle = 0;
    const double pi = 4 * atan(1);
    double angd = (2 * pi) / (double)n;
    int ind = 0;

    for (int i = 0; i < n; i++)
    {

        vertex_buffer_data[ind++] = 0.0;
        vertex_buffer_data[ind++] = 0.0;
        vertex_buffer_data[ind++] = 0.0f;

        vertex_buffer_data[ind++] = radius * cos(angle);
        vertex_buffer_data[ind++] = radius * sin(angle);
        vertex_buffer_data[ind++] = 0.0f;

        angle -= angd;
        vertex_buffer_data[ind++] = radius * cos(angle);
        vertex_buffer_data[ind++] = radius * sin(angle);
        vertex_buffer_data[ind++] = 0.0f;
    }

    this->object = create3DObject(GL_TRIANGLES, 3 * n/2, vertex_buffer_data, COLOR_YELLOW, GL_FILL);
    angle = 0;
    angd = (2 * pi) / (double)n;
    ind = 0;
    for (int i = 0; i < n; i++)
    {
        vertex_buffer_data2[ind++] = 0.0;
        vertex_buffer_data2[ind++] = 0.0;
        vertex_buffer_data2[ind++] = 0.0f;

        vertex_buffer_data2[ind++] = (radius-0.2) * cos(angle);
        vertex_buffer_data2[ind++] = (radius-0.2) * sin(angle);
        vertex_buffer_data2[ind++] = 0.0f;

        angle -= angd;
        vertex_buffer_data2[ind++] = (radius-0.2) * cos(angle);
        vertex_buffer_data2[ind++] = (radius-0.2) * sin(angle);
        vertex_buffer_data2[ind++] = 0.0f;
    }

    this->object2 = create3DObject(GL_TRIANGLES, 3 * n/2, vertex_buffer_data2, COLOR_DBLUE, GL_FILL);
    angle = 0;
    angd = (2 * pi) / (double)n;
    ind = 0;
    for (int i = 0; i < n; i++)
    {
        //Origin
        vertex_buffer_data3[ind++] = -1.9;
        vertex_buffer_data3[ind++] = 0.0;
        vertex_buffer_data3[ind++] = 0.0f;

        //Point with lower angle
        vertex_buffer_data3[ind++] = (0.2) * cos(angle)-1.9;
        vertex_buffer_data3[ind++] = (0.2) * sin(angle);
        vertex_buffer_data3[ind++] = 0.0f;

        //Point with higher angle
        angle -= angd;
        vertex_buffer_data3[ind++] = (0.2) * cos(angle)-1.9;
        vertex_buffer_data3[ind++] = (0.2) * sin(angle);
        vertex_buffer_data3[ind++] = 0.0f;
    }

    this->object3 = create3DObject(GL_TRIANGLES, 3 * n, vertex_buffer_data3, COLOR_YELLOW, GL_FILL);
    angle = 0;
    angd = (2 * pi) / (double)n;
    ind = 0;
    for (int i = 0; i < n; i++)
    {
        //Origin
        vertex_buffer_data4[ind++] = -1.9;
        vertex_buffer_data4[ind++] = 0.0;
        vertex_buffer_data4[ind++] = 0.0f;

        //Point with lower angle
        vertex_buffer_data4[ind++] = (0.1) * cos(angle)-1.9;
        vertex_buffer_data4[ind++] = (0.1) * sin(angle);
        vertex_buffer_data4[ind++] = 0.0f;

        //Point with higher angle
        angle -= angd;
        vertex_buffer_data4[ind++] = (0.1) * cos(angle)-1.9;
        vertex_buffer_data4[ind++] = (0.1) * sin(angle);
        vertex_buffer_data4[ind++] = 0.0f;
    }

    this->object4 = create3DObject(GL_TRIANGLES, 3 * n, vertex_buffer_data4, COLOR_DBLUE, GL_FILL);
}


void Ring::tick() {
    //this->rotation += 1;
}

void Ring::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ring::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    //rotate = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
}