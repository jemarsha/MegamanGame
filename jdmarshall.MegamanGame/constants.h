#ifndef CONSTANTS_H
#define CONSTANTS_H

#include<cmath>

//GUI Constants
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = int(floor((float(2)/3)*SCREEN_WIDTH));
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 25;
const int FRAME_DELAY = 1000/FRAMES_PER_SECOND;

//Animation Constants
const int STATIC_RIGHT = 0;
const int RUN_RIGHT= 1;
const int STATIC_LEFT = 2;
const int RUN_LEFT = 3;
const int CLIMB = 4;

//Physics Constants
const float FORCE = 15.0;
const float DELTA_T = 1.0/FRAMES_PER_SECOND;
const float MM_MASS = 1.0/30.0;
const float BLOCK_MASS = 1.0;
const float BULLET_MASS = 1.0;

//MegaMan Constants
const int MM_NUM_SPRITES = 96;
const int MM_SPRITE_HEIGHT = 60;
const int MM_SPRITE_WIDTH = 47;
const int MM_SPRITE_NCOLS = 24;
const int MM_SPRITE_NROWS = 4; 
const int MM_RUN_SPEED = 12;
const int MM_CLIMB_SPEED = 6;
const int MM_RADIUS = 23;

//Block Constants
const int BLOCK_SPRITE_WIDTH = 20;
const int BLOCK_SPRITE_HEIGHT = BLOCK_SPRITE_WIDTH;
const int BLOCK_RADIUS = 10;
const int MAX_BLOCK_HEIGHT = 300;
const int MAX_NUM_BLOCKS = 15;

//Bullet Constants
const int BULLET_SPRITE_WIDTH = 6;
const int BULLET_SPRITE_HEIGHT = BULLET_SPRITE_WIDTH;
const int BULLET_RADIUS = 3;
const int BULLET_SPEED = 23;
const int BULLET_RIGHT_OFFSET = MM_SPRITE_WIDTH+BULLET_SPRITE_WIDTH+4;
const int BULLET_LEFT_OFFSET = BULLET_SPRITE_WIDTH+4;
const int BULLET_Y_OFFSET = MM_SPRITE_HEIGHT/2-5;

//Engine to GUI Conversions
const int MM_DISPLAY_ID = 1;
const int BLOCK_DISPLAY_ID = 2;
const int BULLET_DISPLAY_ID = 3;
const int MinSpriteID=0;
const int MaxSpriteID=96;

#endif