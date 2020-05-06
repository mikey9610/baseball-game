/*
	HEADER FILE : game
*/

#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;
#include <ctime>
#include <conio.h>

#include "player.h"
#include "renderer.h"

// class Game

class Game {
private:
	
	Player* player[2];
	Answer* correct[2];	
	
	inline int opposite(int n) { return (n==0)?1:0;	}
	
	Game() {}
	// constructor (concealed)
	
public:
	
	static Game newGame() {
		Game game;
		
		srand(time(NULL));
		
		for(int i=0;i<2;i++) {
			system("cls");
			cout << "== Set Player " << i+1 << " Control ==" << endl;
			cout << "   User" << endl;
			cout << "   Computer" << endl;
			
			if(Renderer::selectMenu(1,2) == 0)
				game.player[i] = new Human();
			else
				game.player[i] = new BaseballAI();
		}
		
		for(int i=0;i<2;i++) {
			system("cls");
			cout << "== Set Player " << i+1 << " Answer ==" << endl;
			if(game.player[i]->isAI()) {
				cout << endl << "Now Computer Answer Being Created... Please Wait...";
				Sleep(2000);
			}
			game.correct[i] = new Answer(game.player[i]->getAnswer());
		}		
		
		return game;
	}
	
	int run() {	
		int current = 0;
				
		while(true) {
			system("cls");
			cout << player[current]->getName() << " Turn" << endl;
			if(player[current]->isAI()) {
				cout << "Now Computer Guessing... Please Wait...";
				Sleep(2000);
			}
			else {
				dynamic_cast<Human*>(player[current])->renderLogs(0,2);
				cout << "Now Guess Computer's Code..." << endl;
			}			
			
			Answer question = player[current]->getAnswer();
			Evaluation evaluation = correct[opposite(current)]->evaluate(question);			
			player[current]->learn(question,evaluation);
			
			cout << endl << "Guess : " << question.toString();
			cout << endl << "Result : " << evaluation.toString() << endl;
			cout << endl << "Press any key to Continue...";
			fflush(stdin);
			getch();
			
			if(evaluation.strike_ == AnswerLength)
				return current;
			else
				current = opposite(current);
		}		
	}	
};

#endif
