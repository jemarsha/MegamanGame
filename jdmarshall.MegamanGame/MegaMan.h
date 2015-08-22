#ifndef MEGAMAN_H
#define MEGAMAN_H

#include <string>
#include <vector>
#include "GameObject.h"

using namespace std;

class MegaMan : public GameObject{

public:
	MegaMan();
	MegaMan(int,int);
	
	//Get Methods
	int getState();
	int getSpriteID();

	//Set Methods
	void setState(int);
	void setSpriteID(int);

	//Action Methods
	vector<GameObject*> move(string);

private:
	//Declare  MegaMan Properties
	int state;
	int spriteID;
	
	//Action Methods
	void staticRight(vector<GameObject*> &, string);
	void runRight(vector<GameObject*> &, string);
	void staticLeft(vector<GameObject*> &, string);
	void runLeft(vector<GameObject*> &, string);
	void climb(string);
	
	//Animation Methods
	void teleport();
	void climbAnim();
	void turnRightAnim();
	void runRightAnim();
	void stopRightAnim();
	void shootRightAnim();
	void turnLeftAnim();
	void runLeftAnim();
	void stopLeftAnim();
	void shootLeftAnim();
};

#endif