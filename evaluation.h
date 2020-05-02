/*
	HEADER FILE : evaluation
*/

#ifndef EVALUATION_H
#define EVALUATION_H

#include <iostream>
using namespace std;

// struct Evaluation

struct Evaluation {
	int strike_;
	int ball_;
	
	inline string toString() const {	return to_string(strike_)+"S "+to_string(ball_)+"B";	}
};

#endif
