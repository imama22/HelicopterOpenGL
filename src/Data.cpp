#include "Helicopter.h"
GLfloat Helicopter::cube_buffer[8][3] = {
    {0.5f, 0.5f, 0.5f},
    {-0.5f, 0.5f, 0.5f},
    {-0.5f, -0.5f, 0.5f},
    {0.5f, -0.5f, 0.5f},
    {0.5f, 0.5f, -0.5f},
    {-0.5f, 0.5f, -0.5f},
    {-0.5f, -0.5f, -0.5f},
    {0.5f, -0.5f, -0.5f}
};

GLfloat sr = 80;

void drawVertex(GLfloat vertex_buffer[][3], int i)
{
    glVertex3f(vertex_buffer[i][0], vertex_buffer[i][1], vertex_buffer[i][2]);
}

void Helicopter::drawCube()
{
    glBegin(GL_POLYGON);    // front face
    drawVertex(cube_buffer, 0);
    drawVertex(cube_buffer, 1);
    drawVertex(cube_buffer, 2);
    drawVertex(cube_buffer, 3);
    glEnd();

    glBegin(GL_POLYGON);    // back face
    drawVertex(cube_buffer, 4);
    drawVertex(cube_buffer, 5);
    drawVertex(cube_buffer, 6);
    drawVertex(cube_buffer, 7);
    glEnd();

    glBegin(GL_POLYGON);    // up face
    drawVertex(cube_buffer, 0);
    drawVertex(cube_buffer, 1);
    drawVertex(cube_buffer, 5);
    drawVertex(cube_buffer, 4);
    glEnd();

    glBegin(GL_POLYGON);    // bottom face
    drawVertex(cube_buffer, 2);
    drawVertex(cube_buffer, 3);
    drawVertex(cube_buffer, 7);
    drawVertex(cube_buffer, 6);
    glEnd();

    glBegin(GL_POLYGON);    // right face
    drawVertex(cube_buffer, 0);
    drawVertex(cube_buffer, 3);
    drawVertex(cube_buffer, 7);
    drawVertex(cube_buffer, 4);
    glEnd();

    glBegin(GL_POLYGON);    // left face
    drawVertex(cube_buffer, 1);
    drawVertex(cube_buffer, 2);
    drawVertex(cube_buffer, 6);
    drawVertex(cube_buffer, 5);
    glEnd();
}

void Helicopter::drawGround()
{
    glTranslatef(-10.0, ground, -45.0);
    glScalef(1.0, 0.001, 100.0);
    glColor3f(0.2, 0.2, 0.2);
    drawCube();
    for (int i = 0; i < 10; ++i){
        glTranslatef(2.0, 0.0, 0.0);
        drawCube();
    }
    glColor3f(0.3, 0.3, 0.3);
    glTranslatef(-20 - 1.0, 0.0, 0.0);
    for (int i = 0; i < 10; ++i){
        glTranslatef(2.0, 0.0, 0.0);
        drawCube();
    }
}

void Helicopter::drawWings()
{
// the first wing
    static double yrd = 0;
    yrd += 2.0;
    glPushMatrix();
    glTranslatef(0.0, 0.7, 0.0);
    glRotatef(yrd, 0.0, 1.0, 0.0);
    glScalef(4.0, 0.04, 0.1);
    glColor3f(1.0, 1.0, 1.0);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.7, 0.0);
    glRotatef(yrd, 0.0, 1.0, 0.0);
    glRotatef(90, 0.0, 1.0, 0.0);
    glScalef(4.0, 0.04, 0.1);
    drawCube();
    glPopMatrix();

    // the tail's wing
    static double xrd = 0;
    xrd += 2.0;
    glPushMatrix();
    glTranslatef(-3.2, 0.3, 0.08);
    glRotatef(xrd, 1.0, 0.0, 0.0);
    glScalef(0.02, 1.0, 0.08);
    glColor3f(1.0, 1.0, 1.0);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.2, 0.3, 0.08);
    glRotatef(xrd, 1.0, 0.0, 0.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(0.02, 1.0, 0.08);
    glColor3f(1.0, 1.0, 1.0);
    drawCube();
    glPopMatrix();

}

void Helicopter::drawBody()
{
    glRotatef(90, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(1.5, 1.0, 1.0);
    glColor3f(1.0, 165/255.0, 0);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.6, 0.0);
    glScalef(0.3, 0.3, 0.3);
    glColor3f(0.7, 0.7, 0.7);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, -0.5, 0.5);
    glScalef(0.05, 0.7, 0.04);
    glColor3f(0.2, 0.2, 0.2);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, -0.5, 0.5);
    glScalef(0.05, 0.7, 0.04);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -0.8, 0.5);
    glScalef(1.5, 0.04, 0.3);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, -0.5, -0.5);
    glScalef(0.05, 0.7, 0.04);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, -0.5, -0.5);
    glScalef(0.05, 0.7, 0.04);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -0.8, -0.5);
    glScalef(1.5, 0.04, 0.3);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0, 0.3, 0.0);
    glRotatef(3, 0.0, 0.0, 1.0);
    glScalef(3.0, 0.2, 0.1);
    glColor3f(0.6, 0.6, 0.6);
    drawCube();
    glPopMatrix();
}

void Helicopter::drawHelicopter()
{
    glTranslatef(0.0, 0.0, -5.0);     // translate the whole system
    glRotatef(20, 1.0, 0.0, 0.0);     // rotate the whole system

    glPushMatrix();
    drawGround();
    glPopMatrix();

    glRotatef(sr, 0.0, 1.0, 0.0);               // rotate the helicopter
    glTranslatef(0, syt,szt);     // translate the helicopter
    drawBody();
    drawWings();
}


