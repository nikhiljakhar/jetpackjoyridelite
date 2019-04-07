#include "enemyb.h"
#include "main.h"
#include "math.h"

Enemyb::Enemyb(float x, float y, float radius, float xshift, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->radius = radius;
    this->color = color;
    this->xspeed = 0.03;
    this->xshift = xshift;
    this->working = 1;

    const int n = 360;
    const int reqd = n * 9;
    GLfloat vertex_buffer_data[reqd] = {};

    double angle = 0;
    const double pi = 4 * atan(1);
    double angd = (2 * pi) / (double)n;
    int ind = 0;
    //GLfloat vertex_buffer_data[12345];

    for (int i = 0; i < n; i++)
    {
        //Origin
        vertex_buffer_data[ind++] = 0.0;
        vertex_buffer_data[ind++] = 0.0;
        vertex_buffer_data[ind++] = 0.0f;

        //Point with lower angle
        vertex_buffer_data[ind++] = radius * cos(angle);
        vertex_buffer_data[ind++] = radius * sin(angle);
        vertex_buffer_data[ind++] = 0.0f;

        //Point with higher angle
        angle += angd;
        vertex_buffer_data[ind++] = radius * cos(angle);
        vertex_buffer_data[ind++] = radius * sin(angle);
        vertex_buffer_data[ind++] = 0.0f;
    }

    this->object = create3DObject(GL_TRIANGLES, 3 * n, vertex_buffer_data, color, GL_FILL);
    angle = 0;
    ind = 0;
    angd = (2 * pi) / (double)10;
    GLfloat vertex_buffer_data2[451] = {};
    for (int i = 0; i < 10; i++)
    {
        //Origin
        vertex_buffer_data2[ind++] = 0.0;
        vertex_buffer_data2[ind++] = 0.0;
        vertex_buffer_data2[ind++] = 0.0f;

        //Point with lower angle
        vertex_buffer_data2[ind++] = (radius+0.1) * cos(angle);
        vertex_buffer_data2[ind++] = (radius+0.1) * sin(angle);
        vertex_buffer_data2[ind++] = 0.0f;

        //Point with higher angle
        angle += angd;
        vertex_buffer_data2[ind++] = (radius+0.1) * cos(angle);
        vertex_buffer_data2[ind++] = (radius+0.1) * sin(angle);
        vertex_buffer_data2[ind++] = 0.0f;
    }

    this->object2 = create3DObject(GL_TRIANGLES, 3 * 10, vertex_buffer_data2, COLOR_ORANGE, GL_FILL);
    GLfloat vertex_buffer_data3[reqd] = {};
    angle = 0;
    ind = 0;
    angd = (2 * pi) / (double)n;
    for (int i = 0; i < n; i++)
    {
        //Origin
        vertex_buffer_data3[ind++] = 0.0 + xshift;
        vertex_buffer_data3[ind++] = 1.0;
        vertex_buffer_data3[ind++] = 0.0f;

        //Point with lower angle
        vertex_buffer_data3[ind++] = radius * cos(angle) + xshift;
        vertex_buffer_data3[ind++] = radius * sin(angle) + 1;
        vertex_buffer_data3[ind++] = 0.0f;

        //Point with higher angle
        angle += angd;
        vertex_buffer_data3[ind++] = radius * cos(angle) + xshift;
        vertex_buffer_data3[ind++] = radius * sin(angle) + 1;
        vertex_buffer_data3[ind++] = 0.0f;
    }

    this->object3 = create3DObject(GL_TRIANGLES, 3 * n, vertex_buffer_data3, color, GL_FILL);
    angle = 0;
    ind = 0;
    angd = (2 * pi) / (double)10;
    GLfloat vertex_buffer_data4[451] = {};
    for (int i = 0; i < 10; i++)
    {
        //Origin
        vertex_buffer_data4[ind++] = 0.0 + xshift;
        vertex_buffer_data4[ind++] = 1.0;
        vertex_buffer_data4[ind++] = 0.0f;

        //Point with lower angle
        vertex_buffer_data4[ind++] = (radius+0.1) * cos(angle) + xshift;
        vertex_buffer_data4[ind++] = (radius+0.1) * sin(angle) + 1;
        vertex_buffer_data4[ind++] = 0.0f;

        //Point with higher angle
        angle += angd;
        vertex_buffer_data4[ind++] = (radius+0.1) * cos(angle) + xshift;
        vertex_buffer_data4[ind++] = (radius+0.1) * sin(angle) + 1;
        vertex_buffer_data4[ind++] = 0.0f;
    }

    this->object4 = create3DObject(GL_TRIANGLES, 3 * 10, vertex_buffer_data4, COLOR_ORANGE, GL_FILL);
    GLfloat vertex_buffer_data5[] = {
        -0.15,0.0f,0.0f, // triangle 1 : begin
        0.15f,0.0f, 0.0f,
        xshift - 0.15, 1, 0.0f, // triangle 1 : end
        xshift - 0.15, 1,0.0f, // triangle 2 : begin
        xshift + 0.15,1,0.0f,
        0.15, 0,0.0f, // triangle 2 : end
    };

    this->object5 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data5, COLOR_ORANGE, GL_FILL);
}


void Enemyb::tick() {
    //this->position.x += xspeed;
}

void Enemyb::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Enemyb::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(this->working)
    {
        draw3DObject(this->object5);
        draw3DObject(this->object2);
        draw3DObject(this->object4);
    }
    draw3DObject(this->object);
    draw3DObject(this->object3);
}

