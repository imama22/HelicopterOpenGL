#define _USE_MATH_DEFINES
#include "Helicopter.h"
#include <cmath>


Helicopter::Helicopter()
{
	MOVE_SPEED = 0.01;
	ROTATION_DEGREE = 0.04;
	sr = 90.0;
	wrd = 0.0;
	ground = -2.0;
	Running = true;
	sxt = 0.0; syt = 0.0; szt = 0.0;
}

Helicopter::~Helicopter()
{
	//dtor
}

void Helicopter::setSpeed(float speed){
	this->MOVE_SPEED = speed;
}

void Helicopter::onDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	drawHelicopter();
	SDL_GL_SwapBuffers();
}

void Helicopter::draw(){
	if (onInit() == false) return;

	SDL_Event evnt;

	while (Running)
	{
		while (SDL_PollEvent(&evnt)){
			onEvent(&evnt);
		}
		processInput();
		// display the image and swap buffers
		onDisplay();
	}
	onCleanup();
}

void Helicopter::processInput()
{
	Uint8* keystate = SDL_GetKeyState(NULL);

	//continuous-response keys
	if (keystate[SDLK_LEFT]) sr += ROTATION_DEGREE;
	if (keystate[SDLK_RIGHT]) sr -= ROTATION_DEGREE;
	if (keystate[SDLK_UP]){
		sxt += MOVE_SPEED * (cos(-sr * 3.14/ 180.0));
		szt += MOVE_SPEED * (sin(-sr * 3.14 / 180.0));
	}
	if (keystate[SDLK_DOWN]){
		sxt -= MOVE_SPEED * (cos(-sr * 3.14 / 180.0));
		szt -= MOVE_SPEED * (sin(-sr * 3.14 / 180.0));
	}
	if (keystate[SDLK_w]) syt += MOVE_SPEED;
	if (keystate[SDLK_s])
		if (syt >= 0.0)
			syt -= MOVE_SPEED;
}

bool Helicopter::onInit(){
	// Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;
	if ((SDL_SetVideoMode(800, 480, 32, SDL_SWSURFACE | SDL_OPENGL)) == NULL) {
		return false;
	}
	glClearColor(0.0, 1.0, 1.0, 0.0);       // background color
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 640.0 / 480.0, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);

	return true;
}

void Helicopter::onEvent(SDL_Event* evnt)
{
	if (evnt->type == SDL_QUIT)
		Running = false;
}

void Helicopter::onCleanup()
{
	SDL_Quit();
}

