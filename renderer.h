/*
	HEADER FILE : renderer
*/

#ifndef RENDERER_H
#define RENDERER_H

#include <Windows.h>
#include "player.h"

// class Renderer

class Renderer {
public:
	
	static void gotoxy(int x, int y) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),COORD{x,y});
	}
	
	static int selectMenu(int start, int max) {
		int result = 0;

		while(true) {
			gotoxy(0,start+result);
			cout << "->";
			
			char buf = getch();
			
			gotoxy(0,start+result);
			cout << "  ";
			
			switch(buf) {
			case 72:
				if(result>0)	result--;
				break;
			case 80:
				if(result<max-1)	result++;
				break;
			case 13:
				return result;
			}
		}
	}
	
	static void rendererPlayerLog(Player& player, int x, int y) {
		gotoxy(x,y);
		cout << "===== RECORD =====";
		
		int row=1;
		for(auto& answer : player.getAnswerLogs()) {
			gotoxy(x,y+row);
			cout << answer.toString() << "->";
			row++;
		}
		
		row = 1;
		for(auto& evaluation : player.getEvaluationLogs()) {
			gotoxy(x+11,y+row);
			cout << evaluation.toString();
			row++;
		}
		
		gotoxy(x,y+row);
		cout << "==================" << endl << endl;
	}

};

#endif
