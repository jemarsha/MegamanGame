#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>
#include "GameObject.h"

using namespace std;

class Engine{

public:

	//Constructor
	Engine();

	//Get Methods
	vector<GameObject*> & getObjects();
	
	//Game Methods
	void changeGameState(string command);

private:
	vector<GameObject*> objects;

};

#endif