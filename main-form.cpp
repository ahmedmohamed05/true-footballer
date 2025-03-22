#include "login-form.h"
#include "main-form.h"
#include "game-form.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]


void main() {
	String^ ACCOUNTS_FILE_PATH = "C:\\Users\\Ahmed\\Documents\\study\\visual-programming\\true-footballer\\data\\accounts.txt";
	String^ SCORES_FILE_PATH = "C:\\Users\\Ahmed\\Documents\\study\\visual-programming\\true-footballer\\data\\scores.txt";
	String^ QUESTIONS_FILE_PATH = "C:\\Users\\Ahmed\\Documents\\study\\visual-programming\\true-footballer\\data\\questions.txt";

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	while (1) {
		LoginForm^ loginForm = gcnew LoginForm(ACCOUNTS_FILE_PATH);
		if (loginForm->ShowDialog() != DialogResult::OK) break;
		MainForm^ form = gcnew MainForm(loginForm->getAccount(), ACCOUNTS_FILE_PATH, QUESTIONS_FILE_PATH, SCORES_FILE_PATH);
		Application::Run(form);
	}

}