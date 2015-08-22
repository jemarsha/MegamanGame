#include <fstream>
#include <cmath>
#include <iostream>
#include <vector>
#include "GameObject.h"
#include "constants.h"
#include "Bullet.h"	
#include "engine.h"
#include "MegaMan.h"
#include "Block.h"

using namespace std;
Bullet::Bullet():GameObject(0,0,BULLET_SPEED,0.0, BULLET_MASS ){
	setVelX(BULLET_SPEED);
	setDisplayID(BULLET_DISPLAY_ID);
	setWidth( BULLET_SPRITE_WIDTH);
	setHeight(BULLET_SPRITE_HEIGHT);
	setRadius(BULLET_RADIUS);
	setMass(BULLET_MASS);


}

Bullet::Bullet( int xx, int yy, float velvel){
	setPosX(xx);
	setPosY(yy);
	setVelY(velvel);
	setVelX(BULLET_SPEED);
	setDisplayID(BULLET_DISPLAY_ID);
	setWidth( BULLET_SPRITE_WIDTH);
	setHeight(BULLET_SPRITE_HEIGHT);
	setRadius(BULLET_RADIUS);
	setMass(BULLET_MASS);

}
Bullet::~Bullet(){

}

vector<GameObject*>Bullet:: move(string command){

	vector<GameObject*>bull;


	setPosX(getPosX()+getVelX());
	if(getPosX() >= SCREEN_WIDTH || getPosX()<= 0){
		setDead(true);
	}


	//}
	return(bull);

}




