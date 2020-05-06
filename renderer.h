/*
	HEADER FILE : renderer
*/

#ifndef RENDERER_H
#define RENDERER_H

#include <Windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

// static class Renderer

class Renderer {
protected:
	
	Renderer() {}
	
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
	
};

#endif
