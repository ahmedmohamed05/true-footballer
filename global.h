#pragma once
#include "./classes/accounts-manager.h"

using namespace System;
public ref class Global {
public:
	static String^ ACCOUNTS_FILE_PATH = "./data\\accounts.txt";
	static String^ SCORES_FILE_PATH = "./data\\scores.txt";
	static String^ QUESTIONS_FILE_PATH = "./data\\questions.txt";
};