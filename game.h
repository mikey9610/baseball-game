/*
	HEADER FILE : game
*/

#ifndef GAME_H
#define GAME_H

#include <ctime>
#include <iostream>
using namespace std;

#include "player.h"

// class Game

class Game {
protected:
	
public:
	
	void run() {
		srand(time(NULL));
	
		Answer a1 = Answer::createAnswer();
		Answer a2 = Answer::createRandom();
	
		a2.test_render();
	
		Evaluation e = a1.evaluate(a2);
	
		cout << e.strike_ << "S " << e.ball_ << "B" << endl;
	}
	
};

#endif
