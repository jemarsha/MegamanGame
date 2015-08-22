#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>

using namespace std;

class GameObject{

public:
	GameObject();
	GameObject(int,int, float);
	GameObject(int,int, float, float,float);
	
	//Game Methods
	virtual vector<GameObject*> move(string)=0;

	//Physics Methods
	void fall();
	void stopFall();

	//Get Methods
	int getPosX();
	int getPosY();
	int getCenterX();
	int getCenterY();
	int getRadius();
	float getMass();
	float getVelX();
	float getVelY();
	bool getDead();
	virtual int getDisplayID();

	//Set Methods
	void setPosX(int);
	void setPosY(int);
	void setHeight(int);
	void setWidth(int);
	void setRadius(int);
	void setMass(float);
	void setVelX(float);
	void setVelY(float);
	void setDead(bool);
	void setDisplayID(int);

private:

	//Declare  MegaMan Properties
	int posX;
	int posY;
	int height;
	int width;
	int radius;

	float velX;
	float velY;
	float mass;
	int displayID;
	bool dead;

};


#endif