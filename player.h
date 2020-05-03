/*
	HEADER FILE : player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "answer.h"

// interface Player

class Player {
protected:
	Player(string name, bool isAI) : name_(name), isAI_(isAI) {}
	
	string name_;
	bool isAI_;
	
	vector<Answer> logs_ans_;
	vector<Evaluation> logs_evl_;
	
public:
	
	inline bool isAI() const {	return this->isAI_;	}
	
	virtual Answer getAnswer() const = 0;

	virtual void learn(Answer ans, Evaluation evl) {
		this->logs_ans_.push_back(ans);
		this->logs_evl_.push_back(evl);
	}
	
	inline string getName() const {	return this->name_;	}
	inline vector<Answer> getAnswerLogs() const {	return this->logs_ans_;	}
	inline vector<Evaluation> getEvaluationLogs() const {	return this->logs_evl_;	}

};

class Human : public Player {
protected:

public:
	
	Human(string name = "Player") : Player(name,false) {}
	
	virtual Answer getAnswer() const override {
		vector<int> numeral;
		int number;
		bool flag;
		
		for(int i=0;i<AnswerLength;i++) {
			do {
				flag = false;
				cout << "input " << i+1 << "th number : ";
				cin >> number;	
				if(number<AnswerMin || number>AnswerMax) flag=true;
				for(auto& n : numeral) {
					if(number == n) {
						flag = true;
						break;
					}
				}
			} while(flag);
			numeral.push_back(number);
		}
		return Answer::createAnswer(numeral);
	}
	
};

class BaseballAI : public Player {
protected:

public:
	
	BaseballAI() : Player("Computer",true) {}
	
	virtual Answer getAnswer() const override {
		if(this->logs_ans_.empty())
			return Answer::createRandom();
		
		
	}
	
};

#endif
