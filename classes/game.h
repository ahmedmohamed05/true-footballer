#pragma once
#include "account.h"
#include "question.h"
#include "../global.h"

using namespace System::IO;
using namespace System;


public ref class Game {
private:
	AccountsManager^ _account;
	bool _isGameOn;
	int _currentScore, _wrongAnswers, _rightAnswers;
	List<Question^>^ _selectedQuestions;
	List<Question^>^ _notSelectedQuestions;

	//String^ _questionsFilePath;
	//String^ _scoreFilePath;
	//String^ _accountsFilePath;

	Question^ _currentQuestion;


private:
	void _getAllQuestions() {
		// Store all the questions inside a list
		try {
			//StreamReader^ reader = File::OpenText(_questionsFilePath);
			StreamReader^ reader = File::OpenText(Global::QUESTIONS_FILE_PATH);

			while (!reader->EndOfStream) {
				String^ line = reader->ReadLine();
				Question^ q = Question::convertLineToQuestion(line);
				_notSelectedQuestions->Add(q);
			}

		}
		catch (FileNotFoundException^ ex) {
			// Handle missing file
			MessageBox::Show(ex->Message, "File Not Found");
		}
		catch (UnauthorizedAccessException^ ex) {
			MessageBox::Show(ex->Message, "Unauthorized");
		}

	}

public:
	Game(AccountsManager^ account/*, String^ accuontsFilePath, String^ questionsFilePath, String^ scoresFilePath*/) {
		_account = account;
		_isGameOn = true;

		_currentScore = 0;
		_wrongAnswers = 0;
		_rightAnswers = 0;

		//_questionsFilePath = questionsFilePath;
		//_scoreFilePath = scoresFilePath;
		//_accountsFilePath = accuontsFilePath;

		_selectedQuestions = gcnew List<Question^>();
		_notSelectedQuestions = gcnew List<Question^>();
		_currentQuestion = gcnew Question;

		_getAllQuestions();
	}

	bool _isSelectedQuestion(Question^ q) {

		for each (Question ^ question  in _selectedQuestions) {
			if (question->getQuestionText()->Equals(q->getQuestionText())) {
				return true;
			}
		}

		return false;
	}

private:
	int _getRandomIndex() {
		int selectedQuestions = _selectedQuestions->Count;
		if (selectedQuestions == 100) return -1;
		Random^ rand = gcnew Random();
		int randomIndex = rand->Next(_notSelectedQuestions->Count);
		return randomIndex;
	}

public:
	Question^ selectQuestion() {
		if (!_isGameOn) {
			return nullptr;
		}

		int randomIndex = _getRandomIndex();

		if (randomIndex == -1) {
			MessageBox::Show("No questions left");
			Application::Exit();
		}

		_currentQuestion = _notSelectedQuestions[randomIndex];

		int limitCounter = 1;
		// check if the question already selected
		while (_isSelectedQuestion(_currentQuestion)) {
			// Select new question
			randomIndex = randomIndex = _getRandomIndex();
			_currentQuestion = _notSelectedQuestions[randomIndex];

			// To prevent infinite generating
			limitCounter++;
			if (limitCounter >= 15) {
				throw runtime_error("Number of generating question reached, Something went wrong");
			}
		}

		// remove the selected question
		_notSelectedQuestions->Remove(_currentQuestion);

		return _currentQuestion;
	}

	// 2 points for each question
	bool answer(String^ answer) {
		bool isAnsweredCorrect = _currentQuestion->answer(answer);

		if (isAnsweredCorrect) {
			_rightAnswers++;
			_currentScore += 2;
			//_account->incrementScore(_accountsFilePath);
			_account->incrementScore(Global::ACCOUNTS_FILE_PATH);
		}
		else {
			_wrongAnswers++;

			if (_wrongAnswers >= 3) {
				_isGameOn = false;
			}
		}

		_selectedQuestions->Add(_currentQuestion);

		return isAnsweredCorrect;
	}

	bool isGameOn() { return _isGameOn; }

	int getCurrentScore() { return _currentScore; }
	int getWrongAnsweres() { return _wrongAnswers; }
	int getRightAnswers() { return _rightAnswers; }

};