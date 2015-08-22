#include <iostream>
#include <vector>
#include "constants.h"
#include "MegaMan.h"
#include "Bullet.h"
#include "GameObject.h"




MegaMan::MegaMan():GameObject(0,SCREEN_HEIGHT-MM_SPRITE_HEIGHT,0.0,0.0, MM_MASS ){// constructor default
	state = 0;  //0=right static, 1=run right, 2=left static, 3 = run left
	setDisplayID(MM_DISPLAY_ID);// display the megaman
	spriteID = 3;

}
MegaMan::MegaMan(int x,int y):GameObject(x,y,0.0,0.0, MM_MASS ){//construtctor conversion
	state = 0;
	setDisplayID(MM_DISPLAY_ID);//display the megaman
	spriteID = 3;
}


//Get Methods

int MegaMan::getState(){// return the state of megaman
	return(state);
}

int MegaMan::getSpriteID(){//return megamam sprite
	return(spriteID);
}

//Set Methods


void MegaMan::setState(int s){//set the state
	state = s;
}

void MegaMan::setSpriteID(int id){//set the sprite id
	spriteID = id;
}

vector<GameObject*>MegaMan::move(string command){///move megamn


	vector<GameObject*>megam;
	switch(state){
	case STATIC_RIGHT:	//if case right turn right
		staticRight(megam, command);
		fall();
		break;
	case RUN_RIGHT:  //if run right run right
		runRight(megam, command);
		fall();
		break;
	case STATIC_LEFT:   //if case left turn left
		staticLeft(megam, command);
		fall();
		break;
	case RUN_LEFT:    // if case run left run left
		runLeft(megam, command);
		fall();
		break;
	case CLIMB:		// if case clim climb up or down
		stopFall();
		climb(command);

	}

	//check all boundaries
	if(getPosX() >= SCREEN_WIDTH-MM_SPRITE_WIDTH){
		setPosX(SCREEN_WIDTH-MM_SPRITE_WIDTH);
	}
	if(getPosX() <= 0){
		setPosX(0);
	}

	if(getPosY() >= SCREEN_HEIGHT-MM_SPRITE_HEIGHT){
		setPosY ( SCREEN_HEIGHT-MM_SPRITE_HEIGHT);
	}
	if(getPosY() <= 0){
		setPosY(0);

		//Boundary Checking
	}	
	return(megam);
}

void MegaMan::staticRight(vector<GameObject*> & megam, string command){// megamn turning right

	if(command.compare("shoot")==0){// shoot right megaman

		shootRightAnim();
		megam.push_back(new Bullet(getPosX()+BULLET_RIGHT_OFFSET, getPosY()+BULLET_Y_OFFSET,BULLET_SPEED ));// pass in new bullet values for position and velocity

	}
	if(command.compare("up")==0){
		climbAnim();
		setState(4);
		setPosY(getPosY()-MM_CLIMB_SPEED);
	}	
	if(command.compare("tele")==0){// teleport to get out of the way of a falling block hit the insert key
		
		teleport();
		stopFall();// reset velocity
		setState(3);
		setPosX(rand()%(SCREEN_WIDTH-MM_SPRITE_WIDTH+1)); // make megaman's x position random when he teleports
		setPosY(rand()%(SCREEN_HEIGHT-MM_SPRITE_HEIGHT)); // make megaman's y position random when he teleports
		
	}
	if(command.compare("down")==0){
		climbAnim();
		setState(4);
		setPosY(getPosY()+MM_CLIMB_SPEED);
	}	
	if(command.compare("left")==0){
		turnLeftAnim();
		setState(2);
	}
	if(command.compare("right")==0){
		runRightAnim();
		setState(1);
		setPosX(getPosX()+MM_RUN_SPEED);
	}
	if(command.compare("shoot")==0){

		if(command.compare("NA")==0){
			stopRightAnim();
		}
	}
}
void MegaMan::runRight(vector<GameObject*> & megam, string command){ //megamn running right

	if(command.compare("shoot")==0){ //shoot right megaman

		shootRightAnim();
		megam.push_back(new Bullet(getPosX()+BULLET_LEFT_OFFSET, getPosY()+BULLET_Y_OFFSET,BULLET_SPEED ));// pass in new bullet values for position and velocity

	}
	if(command.compare("up")==0){

	}	
	if(command.compare("tele")==0){// teleport to get out of the way of the block hit insert key

		teleport();
		stopFall();// reset velocity
		setState(3);
		setPosX(rand()%(SCREEN_WIDTH-MM_SPRITE_WIDTH+1)); // make megaman's x position random when he teleports
		setPosY(rand()%(SCREEN_HEIGHT-MM_SPRITE_HEIGHT)); // make megaman's y position random when he teleports
		
	}
	if(command.compare("left")==0){
		turnLeftAnim();
		setState(2);
	}
	if(command.compare("right")==0){
		runRightAnim();
		setPosX(getPosX()+MM_RUN_SPEED);
	}
	if(command.compare("NA")==0){
		stopRightAnim();
		setState(0);
	}
}

void  MegaMan::staticLeft(vector<GameObject*> & megam, string command){// turn left position

	if(command.compare("shoot")==0){// shoot left
		shootLeftAnim();
		megam.push_back(new Bullet(getPosX()-BULLET_LEFT_OFFSET, getPosY()+BULLET_Y_OFFSET,BULLET_SPEED) );//pass in values for the bullet positions and velocity

	}

	if(command.compare("tele")==0){// teleport to get out of the way of falling block hit insert key
		teleport();
		stopFall();// reset velocity
		setState(2);
		setPosX(rand()%(SCREEN_WIDTH-MM_SPRITE_WIDTH+1)); // make megaman's x position random when he teleports
		setPosY(rand()%(SCREEN_HEIGHT-MM_SPRITE_HEIGHT)); // make megaman's y position random when he teleports
		
	}
	if(command.compare("up")==0){// go up
		climbAnim();
		setState(4);
		setPosY(getPosY()-MM_CLIMB_SPEED);
	}	
	if(command.compare("down")==0){ // go down
		climbAnim();
		setState(4);
		setPosY(getPosY()+MM_CLIMB_SPEED);
	}	
	if(command.compare("left")==0){  // run left
		runLeftAnim();
		setState(3);
		setPosX(getPosX()-MM_RUN_SPEED);
	}
	if(command.compare("right")==0){  //turn to the right
		turnRightAnim();
		setState(0);
	}
	if(command.compare("NA")==0){

	}
}

void  MegaMan::runLeft(vector<GameObject*> & megam, string command){// run left position

	if(command.compare("shoot")==0){ // shoot left megaman
		shootLeftAnim();
		megam.push_back(new Bullet(getPosX()-(BULLET_LEFT_OFFSET), getPosY()+BULLET_Y_OFFSET,-BULLET_SPEED ));

	}
	if(command.compare("up")==0){
		//Do nothing
	}	
	if(command.compare("tele")==0){// teleport to get out of the way of fallign block hit insert key
		teleport();
		stopFall();// reset velocity
		setState(2);
		setPosX(rand()%(SCREEN_WIDTH-MM_SPRITE_WIDTH+1)); // make megaman's x position random when he teleports
		setPosY(rand()%(SCREEN_HEIGHT-MM_SPRITE_HEIGHT)); // make megaman's y position random when he teleports
	}
	if(command.compare("left")==0){
		runLeftAnim();
		setPosX(getPosX()-MM_RUN_SPEED);
	}
	if(command.compare("right")==0){
		turnRightAnim();
		setState(0);
	}
	if(command.compare("NA")==0){
		stopLeftAnim();
		setState(2);
	}
}

void MegaMan::climb(string command){ //climb up or down position

	if(command.compare("up")==0){
		climbAnim();
		setPosY(getPosY()-MM_CLIMB_SPEED);		
	}else{
		if(command.compare("down")==0){
			climbAnim();
			setState(4);
			setPosY(getPosY()+MM_CLIMB_SPEED);
		}else{
			setSpriteID(3);
			setState(0);
		}
	}
}

void MegaMan::climbAnim(){ //sprite ids for climbing
	switch(spriteID){
	case 3:
		spriteID = 7;

		break;
	case 7:
		spriteID = 16;

		break;
	case 16:
		spriteID = 7;

		break;
	case 20:
		spriteID = 7;

		break;
	default:
		break;
	}
}

void MegaMan::turnRightAnim(){ //turn right sprite
	spriteID = 3;
}

void MegaMan::runRightAnim(){ //run right sprites

	if(spriteID==3){
		spriteID = 27;
	}else{
		spriteID+=24;
		spriteID%=MM_NUM_SPRITES;
		if(spriteID==3){
			spriteID = 27;
		}
	}
}

void MegaMan::stopRightAnim(){ //stop right sprite
	spriteID = 3;
}

void MegaMan::turnLeftAnim(){ // turn left sprite
	spriteID = 20;
}

void MegaMan::runLeftAnim(){// run left sprites

	if(spriteID==20){
		spriteID = 44;
	}else{
		spriteID+=24;
		spriteID%=MM_NUM_SPRITES;
		if(spriteID==20){
			spriteID = 44;
		}
	}
}

void MegaMan::stopLeftAnim(){ // stop left sprite
	spriteID = 20;
}
void MegaMan:: shootRightAnim(){

	spriteID= 59;

}
void MegaMan:: shootLeftAnim(){

	spriteID=60;


}
void MegaMan:: teleport(){
	spriteID=rand()%(MaxSpriteID-MinSpriteID);
}
