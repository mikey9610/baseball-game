/*
	HEADER FILE : player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <map>
#include "renderer.h"
#include "answer.h"

// interface Player

class Player {
protected:
	
	string name_;
	
	bool isAI_;
		
	Player(string name, bool isAI) : name_(name), isAI_(isAI) {}
	// constructor (concealed)
	
public:
	
	inline string getName() const {	return this->name_;	}
	
	inline bool isAI() const {	return this->isAI_;	}
	
	virtual Answer getAnswer() const = 0;

	virtual void learn(Answer,Evaluation) = 0;
	
};

// class Human

class Human : public Player {
protected:
	
	map<Answer,Evaluation> logs_;

public:
	
	Human(string name = "Player") : Player(name,false) {}
	// constructor
	
	virtual Answer getAnswer() const override final {
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
	
	virtual void learn(Answer ans, Evaluation evl) override final {
		this->logs_.insert(make_pair(ans,evl));
	}
	
	void renderLogs(int x, int y) {
		int row=1;
		
		Renderer::gotoxy(x,y);
		cout << "===== RECORD =====";
		
		for(auto& l : logs_) {
			Renderer::gotoxy(x,y+row);
			cout << l.first.toString() << "-> " << l.second.toString();
			row++;
		}
		
		Renderer::gotoxy(x,y+row);
		cout << "==================" << endl << endl;
	}
	
};

// class BaseballAI

class BaseballAI : public Player {
protected:

	vector<Answer> possible_;

	vector<Answer> rCreateAnswer(vector<Answer> list) {		
		vector<Answer> new_list;
		for(auto& a : list) {
			for(int i=AnswerMin;i<=AnswerMax;i++) {
				if(!a.contain(i))
					new_list.push_back(a.add(i));
			}
		}
		return new_list;
	}
	
public:
	
	BaseballAI() : Player("Computer",true) {
		for(int i=AnswerMin;i<=AnswerMax;i++)
			this->possible_.push_back(Answer::createAnswer(vector<int>{i}));
		
		for(int i=1;i<AnswerLength;i++) {
			this->possible_ = rCreateAnswer(this->possible_);		
		}
	}
	
	virtual Answer getAnswer() const override final {		
		return possible_[rand()%this->possible_.size()];		
	}
	
	virtual void learn(Answer ans, Evaluation evl) override final {
		for(auto iter = possible_.begin(); iter<possible_.end(); iter++) {
			while((*iter).evaluate(ans)!=evl && iter<possible_.end()) {
				possible_.erase(iter);
			}	
		}
	}	
	
};

#endif
