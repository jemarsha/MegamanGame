#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include "constants.h"
#include "engine.h"
#include "MegaMan.h"
#include "Block.h"
#include "Bullet.h"
#include "GameObject.h"


using namespace std;
Engine::Engine(){// make objects appear on screen and set random number of blocks and megaman
	objects.push_back(new MegaMan);

	vector<GameObject*> nuObjects;
	vector<GameObject*>::iterator viter;


	int numbeob=rand()%(MAX_NUM_BLOCKS)+1;

	for (int i=0; i<numbeob; i++){
		objects.push_back(new Block);



	}



}

void Engine::changeGameState(string command){ // mke objects move

	vector<GameObject*> tempo;
	vector<GameObject*>::iterator gg;
	vector<GameObject*>::iterator te;

	for(gg=objects.begin(); gg!=objects.end(); gg++){// loop through objects

		vector<GameObject*> temp2=(*gg)->move(command);// set the vector temp 2 = to the iterator pointing to the move command
		if(temp2.size()>0) //if temp2size>0 copy contents of temp 2 to tempo 
			for(te=temp2.begin(); te!=temp2.end(); te++)
				tempo.push_back(*te);



	}//copy contents of tempo to objects
	for(gg=tempo.begin(); gg!= tempo.end(); gg++){

		objects.push_back(*gg);
	}

}

vector<GameObject*> &Engine::getObjects(){ // return the objects
	return(objects);

}


