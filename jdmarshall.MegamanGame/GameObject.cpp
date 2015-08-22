#include <string>
#include "constants.h"
#include "GameObject.h"

using namespace std;

GameObject::GameObject(){
	posX = 0;
	posY = SCREEN_HEIGHT-MM_SPRITE_HEIGHT;
	velX = 0.0;
	velY = 0.0;
	mass = 1.0/RAND_MAX;
	height = 0;
	width = 0;
	radius = 0;
	dead = false;
}

GameObject::GameObject(int x,int y,float m){
	posX = x;
	posY = y;
	velX = 0.0;
	velY = 0.0;
	mass = m;
	height = 0;
	width = 0;
	radius = 0;
	dead = false;
}

GameObject::GameObject(int x, int y, float vX, float vY, float m){
	posX = x;
	posY = y;
	velX = vX;
	velY = vY;
	mass = m;
	height = 0;
	width = 0;
	radius = 0;
	dead = false;
}

//Physics Methods
void GameObject::fall(){
	setPosY(getPosY()+ceil(DELTA_T*getVelY()));
	setVelY(getVelY()+DELTA_T*FORCE/getMass());
}

void GameObject::stopFall(){
	setVelY(0.0);
}

//Get Methods
int GameObject::getPosX(){
	return(posX);
}

int GameObject::getPosY(){
	return(posY);
}

int GameObject::getCenterX(){
	return(posX+width/2);
}

int GameObject::getCenterY(){
	return(posY+height/2);
}

int GameObject::getRadius(){
	return(radius);
}

float GameObject::getMass(){
	return(mass);
}

float GameObject::getVelX(){
	return(velX);
}

float GameObject::getVelY(){
	return(velY);
}

int GameObject::getDisplayID(){
	return(displayID);
}

bool GameObject::getDead(){
	return(dead);
}

//Set Methods
void GameObject::setPosX(int x){
	posX = x;
}

void GameObject::setPosY(int y){
	posY = y;
}

void GameObject::setHeight(int h){
	height = h;
}

void GameObject::setWidth(int w){
	width = w;
}

void GameObject::setRadius(int r){
	radius = r;
}

void GameObject::setMass(float m){
	mass = m;
}

void GameObject::setVelX(float vX){
	velX = vX;
}

void GameObject::setVelY(float vY){
	velY = vY;
}

void GameObject::setDisplayID(int id){
	displayID = id;
}

void GameObject::setDead(bool d){
	dead = d;
}