#include "ground.h"
#include "main.h"

Ground::Ground(float x, float y, color_t color, color_t color2, color_t color3, color_t color4)
{
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    static const GLfloat vertex_buffer_data[] = {
        -7, -2, 0, // vertex 1
        7, -2, 0,  // vertex 2
        7, -7, 0,   // vertex 3

        7, -7, 0,  // vertex 3
        -7, -7, 0, // vertex 4
        -7, -2, 0, // vertex 1

        -7, 3.7, 0, // vertex 1
        7, 3.7, 0,  // vertex 2
        7, 7, 0,   // vertex 3

        7, 7, 0,  // vertex 3
        -7, 7, 0, // vertex 4
        -7, 3.7, 0

    };

    this->object = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data, color, GL_FILL);

    static const GLfloat vertex_buffer_data2[] = {
        -7, -2, 0, // vertex 1
        7, -2, 0,  // vertex 2
        7, -1.75, 0,   // vertex 3

        7, -1.75, 0,  // vertex 3
        -7, -1.75, 0, // vertex 4
        -7, -2, 0, // vertex 1

        -7, 3.25, 0, // vertex 1
        7, 3.25, 0,  // vertex 2
        7, 3.5, 0,   // vertex 3

        7, 3.5, 0,  // vertex 3
        -7, 3.5, 0, // vertex 4
        -7, 3.25, 0
    };

    this->object2 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data2, color2, GL_FILL);
    static const GLfloat vertex_buffer_data3[] = {
        -7, -1.75, -1, // vertex 1
        7, 3.25, -1,  // vertex 2
        7, -1.75, -1,   // vertex 3

        -7, -1.75, -1,  // vertex 3
        -7, 3.25, -1, // vertex 4
        7, 3.25, -1 // vertex 1
    };

    this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, color3, GL_FILL);
    static const GLfloat vertex_buffer_data4[] = {
        // -1000, -1.5, 0, // vertex 1
        // 1000, -1.53, 0,  // vertex 2
        // 1000, -1.5, 0,   // vertex 3

        -1000, -1.25, -1,  // vertex 3
        1000, -1.28, -1, // vertex 4
        1000, -1.25, -1, // vertex 1

        // -1000, -1, 0,  // vertex 3
        // 1000, -1.03, 0, // vertex 4
        // 1000, -1, 0,

        -1000, -0.75, -1,  // vertex 3
        1000, -0.78, -1, // vertex 4
        1000, -0.75, -1,

        // -1000, -0.5, 0,  // vertex 3
        // 1000, -0.53, 0, // vertex 4
        // 1000, -0.5, 0,

        -1000, -0.25, -1,  // vertex 3
        1000, -0.28, -1, // vertex 4
        1000, -0.25, -1,

        // -1000, 0, 0,  // vertex 3
        // 1000, 0.03, 0, // vertex 4
        // 1000, 0, 0,

        -1000, 0.25, -1,  // vertex 3
        1000, 0.28, -1, // vertex 4
        1000, 0.25, -1,

        // -1000, 0.5, 0,  // vertex 3
        // 1000, 0.53, 0, // vertex 4
        // 1000, 0.5, 0,

        -1000, 0.75, -1,  // vertex 3
        1000, 0.78, -1, // vertex 4
        1000, 0.75, -1,

        // -1000, 1, 0,  // vertex 3
        // 1000, 1.03, 0, // vertex 4
        // 1000, 1., 0,

        -1000, 1.25, -1,  // vertex 3
        1000, 1.28,  -1, // vertex 4
        1000, 1.25, -1,

        // -1000, 1.5, 0,  // vertex 3
        // 1000, 1.53, 0, // vertex 4
        // 1000, 1.5, 0,

        -1000, 1.75, -1,  // vertex 3
        1000, 1.78, -1, // vertex 4
        1000, 1.75, -1,

        // -1000, 2, 0,  // vertex 3
        // 1000, 2.03, 0, // vertex 4
        // 1000, 2, 0,

        -1000, 2.25, -1,  // vertex 3
        1000, 2.28, -1, // vertex 4
        1000, 2.25, -1,

        // -1000, 2.5, 0,  // vertex 3
        // 1000, 2.53, 0, // vertex 4
        // 1000, 2.5, 0,

        -1000, 2.75, -1,  // vertex 3
        1000, 2.78, -1, // vertex 4
        1000, 2.75, -1,

    };

    this->object4 = create3DObject(GL_TRIANGLES, 27, vertex_buffer_data4, color4, GL_FILL);
    static const GLfloat vertex_buffer_data5[] = {
        -7, -2.2, 0, // vertex 1
        7, -2.2, 0,  // vertex 2
        7, -2, 0,   // vertex 3

        7, -2, 0,  // vertex 3
        -7, -2, 0, // vertex 4
        -7, -2.2, 0, // vertex 1

        -7, 3.5, 0, // vertex 1
        7, 3.5, 0,  // vertex 2
        7, 3.7, 0,   // vertex 3

        7, 3.7, 0,  // vertex 3
        -7, 3.7, 0, // vertex 4
        -7, 3.5, 0
    };

    this->object5 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data5, COLOR_BLACK, GL_FILL);
}

void Ground::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(glm::vec3(0, -0.25, 0)); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    //rotate = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);
}
