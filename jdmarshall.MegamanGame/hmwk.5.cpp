/*
* Author:	Jermaine Marshall  I made him teleport!! hit insert to watch him
*			
* 

*
* Purpose:	The purpose of this is to complete the basic mechanics
* of a platform game inheritance, polymorphism, and class collections
*/
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include <string>
#include <iostream>

#include "constants.h"
#include "timer.h"
#include "engine.h"
#include "gui.h"

using namespace std;

int main(int argc, char *argv[]){

	//Seed random number generator
	srand((unsigned)time(0)); 

	
	Timer fps;

	
	Engine engine;

	
	GUI gui;

	
	string command;

	
	bool quit = false;
	
	
	while(quit == false){

		
		fps.start();
		
		//GUI waits for mouse events
		while(gui.observeEvent()){

			//Receive Command From GUI
			command = gui.getCommand();

			//GUI transmits quit event
			if(gui.quitGame()){
				quit=true;
			}
		}

		//Update Game state
		engine.changeGameState(command);

		//Render Game Data
		gui.displayGameState(engine);

		//Adjust Frame Rate

		if(fps.get_ticks() < FRAME_DELAY){
			SDL_Delay(FRAME_DELAY - fps.get_ticks());
		}

	}

	
	return 0;

}