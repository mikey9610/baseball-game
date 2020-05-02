/*
	HEADER FILE : gamelauncher
*/

#ifndef GAMELAUNCHER_H
#define GAMELAUNCHER_H

#include "game.h"
#include "renderer.h"

// class GameLauncher

class GameLauncher {
private:
	
	enum Menu {
		START_GAME,
		EXIT,
		EN_MENU
	};
	const string menu_name[EN_MENU] = {"START GAME","EXIT"};
	
	void showTitle() {
		
	}
	
	int showMainMenu() {
		int menu=0;
		
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),new CONSOLE_CURSOR_INFO{10,false});
		
		system("cls");
		cout << "======= Main Menu =======" << endl;
		for(int i=0;i<EN_MENU;i++) {
			cout << "   " << menu_name[i] << endl;
		}
		cout << "=========================" << endl;
		
		return Renderer::selectMenu(1,EN_MENU);

	}
	
	void playGame() {
		Game game;
		
		game.initialize();
		int winner = game.run();
		
		system("cls");
		cout << "PLAYER " << winner << " WIN THE GAME !" << endl;
		cout << "CONGRATULATION !";
		getchar();
	}
	
public:
	
	void run() {
		bool flag=true;
		int menu;
		
		showTitle();
		while(flag) {
			menu = showMainMenu();
			
			switch(menu) {
			case START_GAME:
				playGame();
				break;
				
			case EXIT:
				flag = false;			
			}
		}
		
	}
	
};

#endif
