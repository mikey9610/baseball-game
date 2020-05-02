/*
	HEADER FILE : answer
*/

#ifndef ANSWER_H
#define ANSWER_H

#include "evaluation.h"

// class Answer

const int AnswerLength = 4;

class Answer {
private:

	int numeral_[AnswerLength];
	// field contains correct answer
		
	Answer() {}
	// constructor ( concealed )
	
public:	
	
	static Answer createAnswer() {
		Answer answer;		
		for(int i=0;i<AnswerLength;i++) {
			cout << "input " << i+1 << "th number : ";
			cin >> answer.numeral_[i];
		}		
		return answer;
	}
	
	static Answer createRandom() {
		Answer answer;		
		for(int i=0;i<AnswerLength;i++) {
			answer.numeral_[i] = rand()%10;
			for(int j=0;j<i;j++) {
				if(answer.numeral_[i]==answer.numeral_[j]) {
					i--;
					break;
				}
			}
		}		
		return answer;
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
		for(int i=0;i<AnswerLength;i++) {
			cout << this->numeral_[i] << " ";
		}
		cout << endl;
	}
	
};



#endif
