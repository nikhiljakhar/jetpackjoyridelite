#include "enemya.h"
#include "main.h"
#include "math.h"

Enemya::Enemya(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->color = color;
    this->yspeed = 0.01;

    
    static const GLfloat vertex_buffer_data[] = {

        -3.9,3,0,
        -3.4,3,0,
        -3.9,2.6,0,
        -3.4,2.6,0,
        -3.4,3,0,
        -3.9,2.6,0,

        3.9,3,0,
        3.4,3,0,
        3.9,2.6,0,
        3.4,2.6,0,
        3.4,3,0,
        3.9,2.6,0,

        -3.9,2.4,0,
        -3.4,2.4,0,
        -3.9,2,0,
        -3.4,2,0,
        -3.4,2.4,0,
        -3.9,2,0,

        3.9,2.4,0,
        3.4,2.4,0,
        3.9,2,0,
        3.4,2,0,
        3.4,2.4,0,
        3.9,2,0,

        -3.9,1.8,0,
        -3.4,1.8,0,
        -3.9,1.4,0,
        -3.4,1.4,0,
        -3.4,1.8,0,
        -3.9,1.4,0,

        3.9,1.8,0,
        3.4,1.8,0,
        3.9,1.4,0,
        3.4,1.4,0,
        3.4,1.8,0,
        3.9,1.4,0,

        -3.9,1.2,0,
        -3.4,1.2,0,
        -3.9,0.8,0,
        -3.4,0.8,0,
        -3.4,1.2,0,
        -3.9,0.8,0,

        3.9,1.2,0,
        3.4,1.2,0,
        3.9,0.8,0,
        3.4,0.8,0,
        3.4,1.2,0,
        3.9,0.8,0,

        -3.9,0.6,0,
        -3.4,0.6,0,
        -3.9,0.2,0,
        -3.4,0.2,0,
        -3.4,0.6,0,
        -3.9,0.2,0,

        3.9,0.6,0,
        3.4,0.6,0,
        3.9,0.2,0,
        3.4,0.2,0,
        3.4,0.6,0,
        3.9,0.2,0,

        -3.9,0,0,
        -3.4,0,0,
        -3.9,-0.4,0,
        -3.4,-0.4,0,
        -3.4,0,0,
        -3.9,-0.4,0,

        3.9,0,0,
        3.4,0,0,
        3.9,-0.4,0,
        3.4,-0.4,0,
        3.4,0,0,
        3.9,-0.4,0,

    };

    this->object = create3DObject(GL_TRIANGLES, 72, vertex_buffer_data, color, GL_FILL);
    static const GLfloat vertex_buffer_data2[] = {
        -3.38,-0.35,0,
        -3.38,-0.05,0,
        -3.1,-0.2,0,

        -3.38,0.55,0,
        -3.38,0.25,0,
        -3.1,0.4,0,

    };
    this->object2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, COLOR_ORANGE, GL_FILL);
    static const GLfloat vertex_buffer_data3[] = {
        -3.38,1.15,0,
        -3.38,0.85,0,
        -3.1,1,0,

        -3.38,1.75,0,
        -3.38,1.45,0,
        -3.1,1.6,0,

    };
    this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, COLOR_ORANGE, GL_FILL);
    static const GLfloat vertex_buffer_data4[] = {
        -3.38,2.05,0,
        -3.38,2.35,0,
        -3.1,2.2,0,

        -3.38,2.95,0,
        -3.38,2.65,0,
        -3.1,2.8,0,

    };
    this->object4 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data4, COLOR_ORANGE, GL_FILL);
    static const GLfloat vertex_buffer_data5[] = {
        -3.38,-0.35,0,
        -3.38,-0.05,0,
        3.38,-0.35,0,
        -3.38,-0.05,0,
        3.38,-0.05,0,
        3.38,-0.35,0,

        -3.38,0.55,0,
        -3.38,0.25,0,
        3.38,0.55,0,
        -3.38,0.25,0,
        3.38,0.25,0,
        3.38,0.55,0,

    };
    this->object5 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data5, COLOR_ORANGE, GL_FILL);
    static const GLfloat vertex_buffer_data6[] = {
        -3.38,1.15,0,
        -3.38,0.85,0,
        3.38,1.15,0,
        -3.38,0.85,0,
        3.38,0.85,0,
        3.38,1.15,0,

        -3.38,1.75,0,
        -3.38,1.45,0,
        3.38,1.75,0,
        -3.38,1.45,0,
        3.38,1.45,0,
        3.38,1.75,0,

    };
    this->object6 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data6, COLOR_ORANGE, GL_FILL);
    static const GLfloat vertex_buffer_data7[] = {
        -3.38,2.35,0,
        -3.38,2.05,0,
        3.38,2.35,0,
        -3.38,2.05,0,
        3.38,2.05,0,
        3.38,2.35,0,

        -3.38,2.95,0,
        -3.38,2.65,0,
        3.38,2.95,0,
        -3.38,2.65,0,
        3.38,2.65,0,
        3.38,2.95,0,

    };
    this->object7 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data7, COLOR_ORANGE, GL_FILL);

}


void Enemya::tick() {
    this->position.y += yspeed;
    if(this->position.y<-1.1 || this->position.y>0.7)
        yspeed = 0- yspeed;
}

void Enemya::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Enemya::draw(glm::mat4 VP, int flg) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    if(flg == 0)
        draw3DObject(this->object2);
    else if(flg == 1)
        draw3DObject(this->object5);
    else if(flg == 2)
        draw3DObject(this->object3);
    else if(flg == 3)
        draw3DObject(this->object6);
    else if(flg == 4)
        draw3DObject(this->object4);
    else if(flg == 5)
        draw3DObject(this->object7);
    
}