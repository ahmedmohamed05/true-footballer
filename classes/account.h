#pragma once

using namespace System;
public ref class Account {
private:
	String^ _username;
	String^ _password;
	int _highestScore;

public:
	Account(String^ username, String^ password, int highestScore) {
		_username = username;
		_password = password;
		_highestScore = highestScore;
	}

	String^ getUsername() { return _username; }
	String^ getPassword() { return _password; }
	int getHighestScore() { return _highestScore; }

	void incrementScore(int value) {
		_highestScore += value;
	}

	void setHighestScore(int value) {
		_highestScore = value;
	}

};
