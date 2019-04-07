#include "dragon.h"
#include "main.h"
#include "math.h"

Dragon::Dragon(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->yspeed = 0.132;
    this->rac = 0.907*2;
    this->fire = 0;

    
    static const GLfloat vertex_buffer_data[] = {

        0,0,0,
        1,-0.3,0,
        1,0.2,0,
        0,0,0,
        0,0.4,0,
        1,0.1,0,
        0,0.4,0,
        1,0.1,0,
        0.6,0.3,0,

        1,0,0,
        1,0.2,0,
        1.4,0.6,0,

        0,0,0,
        1,-0.3,0,
        0.2,-0.1,0,

        0,0.3,0,
        -0.3,0.2,0,
        -0.25,0,0,
        0,0.3,0,
        -0.3,0.2,0,
        -0.1,0.45,0,
        0,0.3,0,
        -0.2,0.1,0,
        0,0.1,0,



    };

    this->object = create3DObject(GL_TRIANGLES, 24, vertex_buffer_data, COLOR_RED, GL_FILL);
    static const GLfloat vertex_buffer_data2[] = {
        0.8,0,0,
        0.9,-0.4,0,
        0.7,-0.4,0,

        0.3,0.1,0,
        1.6,1.5,0,
        0.8,1.4,0,


    };
    this->object2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, COLOR_GREY, GL_FILL);
    static const GLfloat vertex_buffer_data3[] = {
        0.6,0,0,
        0.7,-0.4,0,
        0.5,-0.4,0,

        0.2,0.1,0,
        1.4,1.5,0,
        0.6,1.4,0, 

    };
    this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, COLOR_DGREY, GL_FILL);
    static const GLfloat vertex_buffer_data4[] = {
        -0.27,0.08,0,
        -4,-2.05,0,
        -1.5,-2.1,0,


    };
    this->object4 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data4, COLOR_ORANGE, GL_FILL);
    // static const GLfloat vertex_buffer_data5[] = {


    // };
    // this->object5 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data5, COLOR_ORANGE, GL_FILL);
    // static const GLfloat vertex_buffer_data6[] = {


    // };
    // this->object6 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data6, COLOR_ORANGE, GL_FILL);
    // static const GLfloat vertex_buffer_data7[] = {

    // };
    // this->object7 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data7, COLOR_ORANGE, GL_FILL);

}


void Dragon::tick() {
    if(!fire)
    {
        yspeed -= 0.005;
        rac -= 0.03571429*2;
        this->position.y += yspeed;
        if(this->position.y<0)
        {
            yspeed = 0.132;
            rac = 0.9073*2;
        }
        // if(yspeed>0)
        //     this->rotation -=1;
        // if(yspeed<0)
        this->rotation -= rac;
    }



}

void Dragon::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Dragon::draw(glm::mat4 VP, int flg) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    //rotate = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object3);
    draw3DObject(this->object);    
    draw3DObject(this->object2);
    if(fire)
        draw3DObject(this->object4);
    // draw3DObject(this->object5);
    // draw3DObject(this->object6);
    
    // draw3DObject(this->object7);
    
}