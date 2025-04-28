#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class Score {
private:
	String^ _username;
	String^ _timeDate;
	int _score, _questions, _rightAnswers, _wrongAnswers;

public:
	Score(String^ username, int score, String^ timeDate, int questions, int rightAnswers, int wrongAnswers) {
		_username = username;
		_score = score;
		_timeDate = timeDate;
		_questions = questions;
		_rightAnswers = rightAnswers;
		_wrongAnswers = wrongAnswers;
	}

	String^ getUsername() { return _username; }
	String^ getTimeDate() { return _timeDate; }
	int getScore() { return _score; }
	int getNumberOfQuestions() { return _questions; }
	int getRightAnswers() { return _rightAnswers; }
	int getWrongAnswers() { return _wrongAnswers; }

public: // Static Converters
	static Score^ convertToScore(String^ record) {
		array<String^>^ arr = record->Split('#');

		if (arr->Length != 6) throw gcnew Exception("Format Error");

		try {
			String^ username = arr[0];
			int score = Int32::Parse(arr[1]);
			String^ timeDate = arr[2];
			int questions = Int32::Parse(arr[3]);
			int rightAnswers = Int32::Parse(arr[4]);
			int wrongAnswers = Int32::Parse(arr[5]);
			return gcnew Score(username, score, timeDate, questions, rightAnswers, wrongAnswers);
		}
		catch (ArgumentNullException^ e) {
			throw gcnew Exception(e->Message);
		}
		catch (FormatException^ e) {
			throw gcnew Exception(e->Message);
		}
		catch (OverflowException^ e) {
			throw gcnew Exception(e->Message);
		}
		return nullptr;// This will never happene
	}

	static String^ converToRecord(Score^ score) {
		String^ record = "";

		record += score->getUsername() + "#";
		record += score->getScore().ToString() + "#";
		record += score->getTimeDate() + "#";
		record += score->getNumberOfQuestions().ToString() + "#";
		record += score->getRightAnswers().ToString() + "#";
		record += score->getWrongAnswers().ToString();

		return record;
	}

public:
	String^ getRecord() { return converToRecord(this); }
};