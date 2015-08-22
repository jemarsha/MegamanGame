#include <cmath>
#include <iostream>

#include "constants.h"
#include "Block.h"	

using namespace std;

Block::Block():GameObject(0,0,0.0,0.0,BLOCK_MASS){// set values from Game Object
	resetState();
	setHeight(BLOCK_SPRITE_HEIGHT);
	setWidth(BLOCK_SPRITE_WIDTH);
	setRadius(BLOCK_RADIUS);
	setDisplayID(BLOCK_DISPLAY_ID);
}

vector<GameObject*> Block::move(string command){//creating a vector to move the blocks

	vector<GameObject*> addObjects;// add more blocks

	
	fall();// update position of the blocks while falling

	//Boundary Checking
	if(getPosY() >= SCREEN_HEIGHT){
		resetState();
	}

	return(addObjects);// return the vector

}

void Block::resetState(){// start the blocks over at the top when they hit bottom
	setPosX(rand()%(SCREEN_WIDTH-BLOCK_SPRITE_WIDTH+1));
	setPosY(-(rand()%MAX_BLOCK_HEIGHT+BLOCK_SPRITE_HEIGHT));
	stopFall();
}