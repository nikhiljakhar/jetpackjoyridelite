#include "bricks.h"
#include "main.h"

Bricks::Bricks(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 0.01;
    xspeed = 0.03;
    index = 0;
    bascx = -1, bascx2 = -1.02, bascx3 = -1.5, bascx4 = -1.52;
    bascy = -1, bascy2 = -0.5, bascy3 = -0.5, bascy4 = 0;

    GLfloat vertex_buffer_data[36005];

    for(int i=0; i<5; i++)
    {
        double tmpx = bascx, tmpx2 = bascx2, tmpx3 = bascx3, tmpx4 = bascx4;
        for(int j=0; j<200; j++)
        {
            vertex_buffer_data[index] = tmpx2;
            index = index + 1;
            vertex_buffer_data[index] = bascy;
            index = index + 1;
            vertex_buffer_data[index] = -1;
            index = index + 1;

            vertex_buffer_data[index] = tmpx;
            index = index + 1;
            vertex_buffer_data[index] = bascy;
            index = index + 1;
            vertex_buffer_data[index] = 0-1;
            index = index + 1;

            vertex_buffer_data[index] = tmpx;
            index = index + 1;
            vertex_buffer_data[index] = bascy2;
            index = index + 1;
            vertex_buffer_data[index] = 0-1;
            index = index + 1;

            vertex_buffer_data[index] = tmpx2;
            index = index + 1;
            vertex_buffer_data[index] = bascy2;
            index = index + 1;
            vertex_buffer_data[index] = 0-1;
            index = index + 1;

            vertex_buffer_data[index] = tmpx;
            index = index + 1;
            vertex_buffer_data[index] = bascy;
            index = index + 1;
            vertex_buffer_data[index] = 0-1;
            index = index + 1;

            vertex_buffer_data[index] = tmpx;
            index = index + 1;
            vertex_buffer_data[index] = bascy2;
            index = index + 1;
            vertex_buffer_data[index] = 0-1;
            index = index + 1;

            vertex_buffer_data[index] = tmpx4;
            index = index + 1;
            vertex_buffer_data[index] = bascy3;
            index = index + 1;
            vertex_buffer_data[index] = 0-1;
            index = index + 1;

            vertex_buffer_data[index] = tmpx3;
            index = index + 1;
            vertex_buffer_data[index] = bascy3;
            index = index + 1;
            vertex_buffer_data[index] = 0-1;
            index = index + 1;

            vertex_buffer_data[index] = tmpx3;
            index = index + 1;
            vertex_buffer_data[index] = bascy4;
            index = index + 1;
            vertex_buffer_data[index] = 0-1;
            index = index + 1;

            vertex_buffer_data[index] = tmpx4;
            index = index + 1;
            vertex_buffer_data[index] = bascy4;
            index = index + 1;
            vertex_buffer_data[index] = 0-1;
            index = index + 1;

            vertex_buffer_data[index] = tmpx3;
            index = index + 1;
            vertex_buffer_data[index] = bascy3;
            index = index + 1;
            vertex_buffer_data[index] = 0-1;
            index = index + 1;

            vertex_buffer_data[index] = tmpx3;
            index = index + 1;
            vertex_buffer_data[index] = bascy4;
            index = index + 1;
            vertex_buffer_data[index] = 0-1;
            index = index + 1;
            //printf("%d\n",index );

            tmpx = tmpx + 1;
            tmpx2 = tmpx2 + 1;
            tmpx3 = tmpx3 + 1;
            tmpx4 = tmpx4 + 1;
        }
        bascy = bascy + 1;
        bascy2 = bascy2 + 1;
        bascy3 = bascy3 + 1;
        bascy4 = bascy4 + 1;

    }
    this->object = create3DObject(GL_TRIANGLES, 12000, vertex_buffer_data, color, GL_FILL);
}

void Bricks::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Bricks::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}


