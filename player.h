/*
	HEADER FILE : player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "answer.h"

// interface Player

class Player {
protected:
	Player() {}
	
public:
	
	Answer getQuestion() const {
	
	}
	
	void getInformation(Answer,Evaluation);

};



#endif
