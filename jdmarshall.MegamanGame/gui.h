#ifndef GUI_H
#define GUI_H

#include <string>

//GUI definitions
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "constants.h"
#include "engine.h"

using namespace std;

class GUI{

public:
	GUI();
	~GUI();
	bool observeEvent();
	bool quitGame();
	string getCommand();
	void displayGameState(Engine &);

private:

	//PRIVATE METHODS
	void initGUI();
	SDL_Surface* loadImage(string, int);
	void cleanUp();
	void applySurface(int, int, SDL_Surface*, SDL_Surface*, SDL_Rect* = NULL);

	//PRIVATE MEMBERS
	bool quit;

	/*The surfaces that will be used for text*/
	SDL_Surface* commandSheet;

	//The surfaces that will be used for images
	SDL_Surface* megaManSheetForward;
	SDL_Rect megaManClipsForward[MM_NUM_SPRITES];
	SDL_Surface* blockSheet;
	SDL_Surface* bulletSheet;
	SDL_Surface* cheatSheet;
	SDL_Surface* screen;
	
	//The event structure that will be used
	SDL_Event event;

	/*The font that's going to be used*/
	TTF_Font* fontHuge;

	/*The command to display*/
	string command;
};

#endif
















