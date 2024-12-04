# define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"			//iGraphics Is an OpenGL
# include "LoadGame.h"			//Contains Load From File & GameState Structure 
# include "GlobalVars.h"		//Contains All The Global Variables
# include "GamePlayAnimation.h"	//Contains Run, Jump, Crouch Animations
# include "Obstacle.h"			//Contains Obstacle Drawing, Movement, Collision Detection Funcs
# include "ShowStatistics.h"	//TimeCount, Score Increase, Draw Stats to the Screen
# include "SkyAnimation.h"		//Contains SkyBackGround, Cloud, Birds
# include "DrawGameStates.h"	//Draws the screen for each of the gamestates
# include <stdio.h>

using namespace std;

bool musicOn = true; 
void iDraw(){ 
    iClear();													//Clear and refreshes screen every gameloop
	iSetColor(0,0,0);											//Sets Color to rgb000 as in black
	if(GameCurrentState== MainMenuState){  //loop test, funtion call
		DrawMainMenu();	
	}
	else if(GameCurrentState==GamePlayState){					//GamePlay
		DrawGamePlay();
	}
	
	else if(GameCurrentState==HighScoreState){					//HighScore
		DrawHighScore();	
	}
	else if(GameCurrentState==SettingsState){					//Settings
		DrawSettings();	
	}
	else if(GameCurrentState==AboutState){						//About
		DrawAbout();	
	}
	else if(GameCurrentState==ExitState){						//Exit
		exit(0);
	}
	else if(GameCurrentState==GameOverState){					//Game Over
		DrawGameOver();	
	}
}


void iKeyboard(unsigned char key){} //FOR other key like arrow

void iSpecialKeyboard(unsigned char key)//TURAG 
{
    if(key == GLUT_KEY_UP){  //up arrow dile jump
        if(Crouch) Crouch=false;
		else Jump=true;
	}
	if(key == GLUT_KEY_DOWN){
        Crouch=true;
	}
	
	if(key == GLUT_KEY_END){
		exit(0);
	}
}

void iMouseMove(int mx, int my){}

void iMouse(int button, int state, int mx, int my){ //ALIF

	if(GameCurrentState==MainMenuState){
		if(mx>100 && mx<356 && my>600 && my<664){			//New Game
			GameCurrentState=GamePlayState;
			LoadNew=1;
			LoadGame(LoadNew);
		}


		else if(mx>100 && mx<356 && my>400 && my<464){		//High Score
			GameCurrentState=HighScoreState;
		}


		 else if(mx>100 && mx<356 && my>200 && my<264){		//About
			GameCurrentState=AboutState;
		}
	


		if(mx>100 && mx<356 && my>100 && my<164){			//Exit
			GameCurrentState=ExitState;
		}	
	}

	if(GameCurrentState==GamePlayState){
		if(mx>50 && mx<50+64 && my>ScrHeight-100 && my<ScrHeight-100+64){
			GameCurrentState=PauseMenuState;
		}
	}

	if(GameCurrentState==HighScoreState){
		if(mx>50 && mx<50+64 && my>ScrHeight-100 && my<ScrHeight-100+64){
			GameCurrentState=MainMenuState;
		}
	}

	
	if(GameCurrentState==AboutState){
		if(mx>50 && mx<50+64 && my>ScrHeight-100 && my<ScrHeight-100+64){
			GameCurrentState=MainMenuState;
		}
		
	}

	if(GameCurrentState==ExitState){
		if(mx>50 && mx<50+64 && my>ScrHeight-100 && my<ScrHeight-100+64){
			GameCurrentState=MainMenuState;
		}
	}
	
	if(GameCurrentState==GameOverState){
		if(mx>50 && mx<50+64 && my>ScrHeight-100 && my<ScrHeight-100+64){
			GameCurrentState=MainMenuState;
			LoadNew = 1;
		}
	}
}

int main(){
	LoadGame(1);   
	//iSetTimer(1000,TimeCount);
	iSetTimer(500,Clouds);
	//Fayyaz
	if (musicOn) 
	PlaySound("music//yb.wav", NULL, SND_LOOP | SND_ASYNC); 
	iInitialize(ScrWidth, ScrHeight, "Getting Through It");  //Window Initialization

	return 0;
}

