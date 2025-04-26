#pragma once
#include "question.h"

using namespace System::IO;
using namespace System;

public ref class Game {
private:
	String^ _questionsFilePath;
	bool _isGameOn;
	int _currentScore,
		_wrongAnswers,
		_rightAnswers,
		_pointsForQuestion,
		_wrongAnswersLimit,
		_questionNumber;

	List<Question^>^ _questions;
	Question^ _currentQuestion;

public:
	Game(String^ questionsFilePath, int pointsForEachQuestion, int worngAnswersLimit) {
		_isGameOn = true;

		_currentScore = 0;
		_wrongAnswers = 0;
		_rightAnswers = 0;
		_questionNumber = 0;
		_pointsForQuestion = pointsForEachQuestion;
		_wrongAnswersLimit = worngAnswersLimit;

		_questionsFilePath = questionsFilePath;
		_questions = _getAllQuestions();
		_currentQuestion = nullptr;
	}

private:
	// Get all questions
	List<Question^>^ _getAllQuestions() {
		try {
			List<Question^>^ questions = gcnew List<Question^>();
			StreamReader^ reader = File::OpenText(_questionsFilePath);

			while (!reader->EndOfStream) {
				String^ line = reader->ReadLine();
				Question^ q = Question::convertLineToQuestion(line);
				questions->Add(q);
			}
			return questions;
		}
		catch (FileNotFoundException^ ex) {
			gcnew Exception(ex->Message + ", File Not Found");
		}
		catch (UnauthorizedAccessException^ ex) {
			gcnew Exception(ex->Message + ", Unauthorized");
		}
		catch (ArgumentNullException^ ex) {
			gcnew Exception(ex->Message + ", Null Exception");
		}

		return gcnew List<Question^>();
	}

	int _getRandomIndex() {
		// return -1 if no questions left
		if (_questions->Count == 0) return -1;

		Random^ rand = gcnew Random();
		int randomIndex = rand->Next(_questions->Count);
		return randomIndex;
	}

public:
	Question^ selectQuestion() {
		if (!_isGameOn) {
			throw gcnew Exception("Game is done, You can't have any more questions!");
			return nullptr;
		}

		int randomIndex = _getRandomIndex();

		if (randomIndex == -1) {
			throw gcnew Exception("No questions left");
			return nullptr;
		}

		_currentQuestion = _questions[randomIndex];

		// Safty stuff
		//int limitCounter = 1;
		//// check if the question already selected
		//while (_isSelectedQuestion(_currentQuestion)) {
		//	// Select new question
		//	randomIndex = randomIndex = _getRandomIndex();
		//	_currentQuestion = _questions[randomIndex];
		//	// To prevent infinite generating
		//	limitCounter++;
		//	if (limitCounter >= 15) {
		//		throw gcnew Exception("Number of generating question reached, Something went wrong");
		//	}
		//}

		// remove the selected question
		_questions->Remove(_currentQuestion);
		_questionNumber++;
		return _currentQuestion;
	}

	// 2 points for each question
	bool answer(String^ answer) {
		bool isAnsweredCorrect = _currentQuestion->answer(answer);

		if (isAnsweredCorrect) {
			_rightAnswers++;
			_currentScore += _pointsForQuestion;
		}
		else {
			_wrongAnswers++;

			if (_wrongAnswers >= _wrongAnswersLimit) {
				_isGameOn = false;
			}
		}

		return isAnsweredCorrect;
	}

	bool isGameOn() { return _isGameOn; }

	int getCurrentScore() { return _currentScore; }
	int getWrongAnsweres() { return _wrongAnswers; }
	int getRightAnswers() { return _rightAnswers; }
	int getQuestionNumber() { return _questionNumber; }
};