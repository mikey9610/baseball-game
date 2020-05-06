/*
	HEADER FILE : answer
*/

#ifndef ANSWER_H
#define ANSWER_H

#include <vector>
#include "evaluation.h"

// class Answer

const int AnswerLength = 4;
const int AnswerMin = 0;
const int AnswerMax = 9;

class Answer {
private:

	vector<int> numeral_;
	// field contains correct answer
	
	Answer(vector<int> numeral) : numeral_(numeral) {}
	
public:	
	
	static Answer createAnswer(vector<int> numeral) {	return Answer(numeral);	}
	
	Evaluation evaluate(Answer obj) {
		Evaluation evaluation{0,0};
		for(int i=0;i<AnswerLength;i++) {
			for(int j=0;j<AnswerLength;j++) {
				if(numeral_[i] == obj.numeral_[j]) {
					if(i == j)
						evaluation.strike_++;
					else
						evaluation.ball_++;
				}
			}
		}
		return evaluation;
	}
	
	bool contain(int n) {
		for(const auto& a : numeral_)
			if(a==n)
				return true;
		return false;
	}
	
	Answer add(int n) {
		Answer answer(*this);
		answer.numeral_.push_back(n);
		return answer;
	}
	
	inline string toString() const {
		string str = "";
		for(int i=0;i<AnswerLength;i++) {
			str += to_string(this->numeral_[i]) + " ";
		}
		return str;
	}
	
	inline bool operator<(const Answer& opr) const {
		for(int i=0;i<numeral_.size();i++) {
			if(numeral_[i] != opr.numeral_[i])
				return numeral_[i] < opr.numeral_[i];
		}
		return false;
	}
	
};

#endif
