/*
	HEADER FILE : answer
*/

#ifndef ANSWER_H
#define ANSWER_H

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
	
	static Answer createAnswer(vector<int> numeral) {
		return Answer(numeral);
	}
	
	static Answer createRandom() {	
		vector<int> numeral;
		int random;
		bool flag;
		
		for(int i=0;i<AnswerLength;i++) {
			do {
				random = rand()%(AnswerMax-AnswerMin+1)+AnswerMin;	
				flag = false;	
				for(auto& n : numeral) {
					if(random == n) {
						flag = true;
						break;
					}
				}
			} while(flag);
			numeral.push_back(random);
		}		
		return Answer(numeral);
	}
	
	Evaluation evaluate(const Answer& obj) {
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
	
	void test_render() {
		for(auto& n : numeral_)
			cout << n << " ";
		cout << endl;
	}
	
	inline string toString() const {
		string str = "";
		for(int i=0;i<AnswerLength;i++) {
			str += to_string(this->numeral_[i]) + " ";
		}
		return str;
	}
	
};



#endif
