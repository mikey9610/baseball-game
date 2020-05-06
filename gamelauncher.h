/*
	HEADER FILE : gamelauncher
*/

#ifndef GAMELAUNCHER_H
#define GAMELAUNCHER_H

#include "gameconstants.h"
#include "renderer.h"
#include "game.h"

// class GameLauncher

class GameLauncher {
private:	
	
	void showTitle() {
		
	}
	
	int showStartMenu() {
		int menu=0;
		
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),new CONSOLE_CURSOR_INFO{10,false});
		
		system("cls");
		cout << "======= Main Menu =======" << endl;
		for(int i=0;i<EN_MENU;i++) {
			cout << "   " << startmenu_name[i] << endl;
		}
		cout << "=========================" << endl;
		
		return Renderer::selectMenu(1,EN_MENU);
	}
	
	void playGame() {
		Game game = Game::newGame();
		
		int winner = game.run();
		
		system("cls");
		cout << "PLAYER " << winner+1 << " WIN THE GAME !" << endl;
		cout << "CONGRATULATION !";
		getchar();
	}
	
public:
	
	void run() {
		bool flag=true;
		
		showTitle();
		while(flag) {
			int menu = showStartMenu();
			
			switch(menu) {
			case START_GAME:
				playGame();
				break;
				
			case SETTING:
				break;
				
			case EXIT:
				flag = false;			
			}
		}		
	}
	
};

#endif
