#include "enemyc.h"
#include "main.h"
#include "math.h"

Enemyc::Enemyc(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->radius = 0.1;
    this->color = color;
    this->xspeed = 0.18;
    this->yspeed = 0.06;


    static const GLfloat vertex_buffer_data[] = {

        -0.2,0,0,
        0.2,0.4,0,
        0,0,0,

        -0.2,0,0,
        0.2,-0.4,0,
        0,0,0,

    };

    

    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
}


void Enemyc::tick() {
    this->rotation += 5;
    this->position.x -= xspeed;
    xspeed -= 0.002;
    float modis = 1.900000*1.9000000 - (this->position.x + 1.290000)*(this->position.x + 1.290000);
    if(modis<0)
        modis = 0 - modis;
    if(this->position.x>=-1.290000 && xspeed > 0)
        this->position.y = 2.500000;
    else if(this->position.x>=-1.290000 && xspeed < 0)
        this->position.y = -1.300000;
    else if(this->position.x<-1.290000 && xspeed >= 0 )
        this->position.y = sqrt(modis) -1.899983 + 2.500000;
    else if(this->position.x<-1.290000 && xspeed < 0 )
        this->position.y = - sqrt(modis) + 1.899983 - 1.300000;
}

void Enemyc::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Enemyc::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    //rotate = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}
