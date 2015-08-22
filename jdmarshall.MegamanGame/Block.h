#ifndef BLOCK_H
#define BLOCK_H

#include "GameObject.h"
#include <string>

using namespace std;

class Block : public GameObject{

public:
	Block();

	//Action methods
	vector<GameObject*> move(string);
	void resetState();
	void bounceState();
};


#endif	
