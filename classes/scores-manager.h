#pragma once
#include "./score.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

public ref class ScoresManager {
private:
	String^ _scoresPath;
	List<Score^>^ _scores;

	// Files Functions
private:
	void _createFileIfNotExists() {
		if (!File::Exists(_scoresPath))
			File::CreateText(_scoresPath)->Close();
	}

	List<Score^>^ _loadScores() {
		List<Score^>^ list = gcnew List<Score^>;

		try {
			StreamReader^ reader = File::OpenText(_scoresPath);

			while (!reader->EndOfStream) {
				String^ record = reader->ReadLine();
				Score^ score = Score::convertToScore(record);
				list->Add(score);
			}

			reader->Close();
		}
		catch (FileNotFoundException^ ex) {
			throw gcnew Exception(ex->Message + ", Not Found Error");
		}
		catch (UnauthorizedAccessException^ ex) {
			throw gcnew Exception(ex->Message + ", Unauthorized Error");
		}

		return list;
	}

	void _saveScores() {
		if (_scores->Count == 0) return;

		try {
			StreamWriter^ writer = gcnew StreamWriter(_scoresPath, false);

			// Convert scores to record and write them
			for each (Score ^ %score in _scores) {
				writer->WriteLine(score->getRecord());
			}

			writer->Close();
		}
		catch (FileNotFoundException^ ex) {
			throw gcnew Exception(ex->Message + ", File Not Found");
		}
		catch (UnauthorizedAccessException^ ex) {
			throw gcnew Exception(ex->Message + ", Unauthorized Error");
		}
	}

public:
	ScoresManager(String^ scoresFilePath) {
		_scoresPath = scoresFilePath;

		_createFileIfNotExists();

		_scores = _loadScores();
	}

	const Score^ getScore(int index) {
		if (index < 0 || index >= _scores->Count) throw gcnew Exception("Index out of range");

		return _scores[index];
	}
	const int scoresNumber() { return _scores->Count; }

	// Edit Scores List
public:
	void addScore(Score^ score) {
		_scores->Add(score);
		_saveScores();
	}

	List<Score^>^ getList() { return _scores; }
};