#include "./forms/login-form.h"
#include "./forms/main-form.h"
#include "./forms/game-form.h"
#include "./global.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	while (1) {
		LoginForm^ loginForm = gcnew LoginForm();
		if (loginForm->ShowDialog() != DialogResult::OK) break;
		MainForm^ form = gcnew MainForm(loginForm->getManager());
		Application::Run(form);
	}
}