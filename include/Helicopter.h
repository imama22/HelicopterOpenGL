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

	GLfloat MOVE_SPEED, ROTATION_DEGREE;

	GLfloat sxt, syt, szt, ground, wrd, sr;
	static GLfloat cube_buffer[8][3];

	bool Running;
};

#endif // HELICOPTER_H
