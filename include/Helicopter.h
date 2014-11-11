#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Helicopter
{
    public:
        Helicopter();
        virtual ~Helicopter();

        void draw();                // onExecute()
        void setSpeed(float speed);
    protected:
    private:
        // private functions to execute program
        void onEvent(SDL_Event* evnt);
        bool onInit();
        void onCleanup();
        void onDisplay();
        void processInput();

        // private functions to draw helicopter
        void drawCube();
        void drawHelicopter();
        void drawGround();
        void drawWings();
        void drawBody();

        float speed;

        float sxt, syt, szt, ground;
        GLfloat sr;
        static GLfloat cube_buffer[8][3];

        bool Running;
};

#endif // HELICOPTER_H
