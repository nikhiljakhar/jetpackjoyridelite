#include "magnet.h"
#include "main.h"
#include "math.h"

Magnet::Magnet(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;

    
    static const GLfloat vertex_buffer_data[] = {

        0.4,0,0,
        0.4,-0.2,0,
        -0.4,0,0,
        -0.4,-0.2,0,
        0.4,-0.2,0,
        -0.4,0,0,

        0.4,0,0,
        0.2,0,0,
        0.4,-0.4,0,
        0.2,-0.4,0,
        0.2,0,0,
        0.4,-0.4,0,

        -0.4,0,0,
        -0.2,0,0,
        -0.4,-0.4,0,
        -0.2,-0.4,0,
        -0.2,0,0,
        -0.4,-0.4,0,



    };

    this->object = create3DObject(GL_TRIANGLES, 18, vertex_buffer_data, COLOR_RED, GL_FILL);
    static const GLfloat vertex_buffer_data2[] = {
        0.4,-0.5,0,
        0.2,-0.5,0,
        0.4,-0.4,0,
        0.2,-0.4,0,
        0.2,-0.5,0,
        0.4,-0.4,0,

        -0.4,-0.5,0,
        -0.2,-0.5,0,
        -0.4,-0.4,0,
        -0.2,-0.4,0,
        -0.2,-0.5,0,
        -0.4,-0.4,0,

    };
    this->object2 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data2, COLOR_GREY, GL_FILL);
    static const GLfloat vertex_buffer_data3[] = {

        0,0.4,0,
        -0.2,0.4,0,
        0,-0.4,0,
        -0.2,-0.4,0,
        -0.2,0.4,0,
        0,-0.4,0,

        0,0.4,0,
        0,0.2,0,
        -0.4,0.4,0,
        -0.4,0.2,0,
        0,0.2,0,
        -0.4,0.4,0,

        0,-0.4,0,
        0,-0.2,0,
        -0.4,-0.4,0,
        -0.4,-0.2,0,
        0,-0.2,0,
        -0.4,-0.4,0,



    };

    this->object3 = create3DObject(GL_TRIANGLES, 18, vertex_buffer_data3, COLOR_RED, GL_FILL);
    static const GLfloat vertex_buffer_data4[] = {
        -0.5,0.4,0,
        -0.5,0.2,0,
        -0.4,0.4,0,
        -0.4,0.2,0,
        -0.5,0.2,0,
        -0.4,0.4,0,

        -0.5,-0.4,0,
        -0.5,-0.2,0,
        -0.4,-0.4,0,
        -0.4,-0.2,0,
        -0.5,-0.2,0,
        -0.4,-0.4,0,

    };
    this->object4 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data4, COLOR_GREY, GL_FILL);
}


void Magnet::tick() {

}

void Magnet::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Magnet::draw(glm::mat4 VP, int flg) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    //rotate = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(flg == 0)
    {
        draw3DObject(this->object);
        draw3DObject(this->object2);
    }
    if(flg == 1)
    {
        draw3DObject(this->object3);
        draw3DObject(this->object4);
    }
    // draw3DObject(this->object3);
    
}