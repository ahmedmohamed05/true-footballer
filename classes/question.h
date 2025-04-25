#pragma once
#include <vector>
#include <algorithm>
#include <random>

using namespace System;
using namespace System::IO;
using namespace Collections::Generic; // For List

public  ref class Question {
private:
	String^ _question;
	String^ _rightAnswer;
	String^ _answer1;
	String^ _answer2;
	String^ _answer3;

	bool _isAnsweredCorrect;

	Question(String^ q, String^ r, String^ a1, String^ a2, String^ a3) {
		_question = q;
		_rightAnswer = r;
		_answer1 = a1;
		_answer2 = a2;
		_answer3 = a3;
		_isAnsweredCorrect = false;
	}

public:
	Question() {}
	// Question getters
public:
	String^ getQuestionText() { return _question; }

	String^ getAnswer1() { return _answer1; }
	String^ getAnswer2() { return _answer2; }
	String^ getAnswer3() { return _answer3; }

	bool answer(String^ answer) {
		this->_isAnsweredCorrect = answer->Equals(_rightAnswer);
		return this->_isAnsweredCorrect;
	}


public:
	// Formated as [Question]:[Right answer]:[Wrong answer 1]:[Wrong answer 2]
	static Question^ convertLineToQuestion(String^ line) {

		auto QuestionAsArray = line->Split(':');

		String^ question = QuestionAsArray[0];
		String^ rightAnswer = QuestionAsArray[1];

		std::vector<int> index = { 1, 2, 3 };

		// Shuffle using std::shuffle()
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(index.begin(), index.end(), g);

		String^ answer1 = QuestionAsArray[index[0]];
		String^ answer2 = QuestionAsArray[index[1]];
		String^ answer3 = QuestionAsArray[index[2]];

		return gcnew Question(question, rightAnswer, answer1, answer2, answer3);
	}

};