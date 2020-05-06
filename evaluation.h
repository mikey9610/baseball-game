/*
	HEADER FILE : evaluation
*/

#ifndef EVALUATION_H
#define EVALUATION_H

#include <iostream>

// struct Evaluation

struct Evaluation {
	
	int strike_;
	int ball_;
	
	inline std::string toString() const {	return std::to_string(strike_)+"S "+std::to_string(ball_)+"B";	}
	
	inline bool operator==(const Evaluation& opr) const {	return this->strike_==opr.strike_ && this->ball_==opr.ball_;	}
	inline bool operator!=(const Evaluation& opr) const {	return this->strike_!=opr.strike_ || this->ball_!=opr.ball_;	}
	
};

#endif
