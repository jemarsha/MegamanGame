#include <iostream>
#include <fstream>
#include <string>
#include <vector>
# include <windows.h>
#include "gui.h"
#include "constants.h"
#include "engine.h"
#include "GameObject.h"
#include "MegaMan.h"
#include "Block.h"
#include "Bullet.h"

using namespace std;

GUI::GUI(){
	 
	//Text Surfaces
	commandSheet = NULL;
	 
	//Images surfaces used in GUI
	megaManSheetForward = NULL;
	blockSheet = NULL;
	bulletSheet = NULL;
	screen = NULL;
	cheatSheet=NULL;
	//The fonts used int GUI
	fontHuge = NULL;

	//The command placeholder
	command = "NA";

	//Start-up the GUI!
	initGUI();

	//Exit criteria
	quit=false;

}

GUI::~GUI(){
	cleanUp();
}

bool GUI::observeEvent(){
	return(SDL_PollEvent( &event ));
}

bool GUI::quitGame(){
	return(event.type == SDL_QUIT );
}


//Initialize SDL Components
void GUI::initGUI(){

	//Initialize all SDL subsystems
    SDL_Init( SDL_INIT_EVERYTHING );	//Initialize SDL subsystems

	//Initialize True Type Fonts*/
	TTF_Init();

	//Construct Basic GUI components
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

	//Open MegaMan Sprite Sheet Forward
	megaManSheetForward = loadImage("./images/megaman-full.gif", 255);

	//Parse MegaMan Sprite Sheet Forward
	for(int i=0;i<MM_NUM_SPRITES;i++){		
		int row = i/MM_SPRITE_NCOLS;
		int col = i%MM_SPRITE_NCOLS;
		megaManClipsForward[i].x = col*MM_SPRITE_WIDTH;
		megaManClipsForward[i].y = row*MM_SPRITE_HEIGHT;
		megaManClipsForward[i].w = MM_SPRITE_WIDTH;
		megaManClipsForward[i].h = MM_SPRITE_HEIGHT;
	}

	//Open Block Sprite Sheet
	blockSheet = loadImage("./images/smallblock.gif", 255);

	//Open Bullet Sprite Sheet
	bulletSheet = loadImage("./images/dot.png", 255);
	
	/*Open fonts*/
	fontHuge = TTF_OpenFont("./fonts/impact.ttf", 20);

	//Set the window caption
    SDL_WM_SetCaption( "MegaMan", NULL );

}

void GUI::cleanUp(){

	//Free the graphics
	SDL_FreeSurface( commandSheet );
	SDL_FreeSurface( megaManSheetForward );
	SDL_FreeSurface( blockSheet );
	SDL_FreeSurface( screen );
    SDL_FreeSurface( cheatSheet);
    //Quit SDL
    SDL_Quit();

}

SDL_Surface* GUI::loadImage(string filename, int mapkey ) 
{

	//The image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
	
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    loadedImage = IMG_Load( filename.c_str() );
    
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
       
        //Free the old image
        SDL_FreeSurface( loadedImage );


		//If the image was optimized just fine
        if( optimizedImage != NULL )
        {
            //Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, mapkey, mapkey, mapkey );
 
			//Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
	}
	
	//Return the optimized image
    return optimizedImage;

}

void GUI::applySurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

string GUI::getCommand(){

	//Base command is "NA" for "Not Applicable"
	command = "NA";

	//If a key was pressed
    if( event.type == SDL_KEYDOWN ){

        //Animate
        switch( event.key.keysym.sym )
        {
			case SDLK_SPACE: command = "shoot"; break;
            case SDLK_UP: command = "up"; break;
            case SDLK_DOWN: command = "down"; break;
            case SDLK_LEFT: command = "left"; break;
            case SDLK_RIGHT: command = "right"; break;   
			case SDLK_INSERT: command="tele"; break;
			default: command= "NA"; break;
        }
    }

	return(command);
}


//Base GameState Display...just shows active Territory
void GUI::displayGameState(Engine & engine){

	vector<GameObject*> objects = engine.getObjects();

	//Set base text color to "white"
	SDL_Color textColor = {9000,9000,9000};
	// system ( "color 03" );
    
	//Fill the screen white
    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 6500, 6644, 6500) );

	//Render Object
	for(int i=0;i<objects.size();i++){

		if(objects[i]->getDisplayID()==MM_DISPLAY_ID){
			MegaMan* mega = (MegaMan*)objects[i];
			applySurface(mega->getPosX(), mega->getPosY(), megaManSheetForward, screen, &megaManClipsForward[mega->getSpriteID()]);
		}
		if(objects[i]->getDisplayID()==BLOCK_DISPLAY_ID){
			Block* block = (Block*)objects[i];
			applySurface(block->getPosX(),block->getPosY(), blockSheet, screen, NULL);
		}
		if(objects[i]->getDisplayID()==BULLET_DISPLAY_ID){
			Bullet* bullet = (Bullet*)objects[i];
			applySurface(bullet->getPosX(),bullet->getPosY(), bulletSheet, screen, NULL);
		}
		/*if(objects[i]->getDisplayID()==BLOCK_DISPLAY_ID){
			Cheat* cheat = (Cheat*)objects[i];
			applySurface(cheat->getPosX(),block->getPosY(), cheatSheet, screen, NULL);
	}
	*/
	}
	//Generate Command Text
	string commandString = "";

	if(command.compare("up")==0){
		commandString = "Climb Up";
	}

	if(command.compare("down")==0){
		commandString = "Climb Down";
	}

	if(command.compare("left")==0){
		commandString = "Left";
	}

	if(command.compare("right")==0){
		commandString = "Right";
	}

	if(command.compare("shoot")==0){
		commandString = "Shoot";
	}
	if(command.compare("tele")==0){
		commandString=" tele";
	}
	commandSheet = TTF_RenderText_Solid( fontHuge, commandString.c_str(), textColor );
	applySurface (220,170, commandSheet, screen );

	//Update the visible screen
	SDL_Flip( screen );
	
}