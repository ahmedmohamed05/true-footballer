#pragma once
#include "../classes/game.h"
#include "../classes/question.h"
#include "./main-form.h"
#include "../global.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class GameForm : public System::Windows::Forms::Form {
private:
	AccountsManager^ _manager;
	Game^ _game;

public:
	GameForm(AccountsManager^% manager) {
		InitializeComponent();
		_manager = manager;
		_game = gcnew Game(Global::QUESTIONS_FILE_PATH, 2, 3);

		startGame();
	}

protected:
	~GameForm() {
		if (components) delete components;
	}

private: System::Windows::Forms::Label^ questionNumber_l;
private: System::Windows::Forms::Label^ sessionScore_l;
private: System::Windows::Forms::Label^ question_l;
private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::Button^ answer1_btn;
private: System::Windows::Forms::Button^ answer2_btn;
private: System::Windows::Forms::Button^ answer3_btn;
private: System::Windows::Forms::Label^ wrongAnswers_l;
private: System::Windows::Forms::Label^ rightAnswers_l;
private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
private:
	void InitializeComponent(void) {
		this->questionNumber_l = (gcnew System::Windows::Forms::Label());
		this->sessionScore_l = (gcnew System::Windows::Forms::Label());
		this->question_l = (gcnew System::Windows::Forms::Label());
		this->panel1 = (gcnew System::Windows::Forms::Panel());
		this->answer1_btn = (gcnew System::Windows::Forms::Button());
		this->answer2_btn = (gcnew System::Windows::Forms::Button());
		this->answer3_btn = (gcnew System::Windows::Forms::Button());
		this->wrongAnswers_l = (gcnew System::Windows::Forms::Label());
		this->rightAnswers_l = (gcnew System::Windows::Forms::Label());
		this->SuspendLayout();
		// 
		// questionNumber_l
		// 
		this->questionNumber_l->AutoSize = true;
		this->questionNumber_l->Font = (gcnew System::Drawing::Font(L"Rubik", 14, System::Drawing::FontStyle::Bold));
		this->questionNumber_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->questionNumber_l->Location = System::Drawing::Point(7, 8);
		this->questionNumber_l->Name = L"questionNumber_l";
		this->questionNumber_l->Size = System::Drawing::Size(147, 29);
		this->questionNumber_l->TabIndex = 1;
		this->questionNumber_l->Text = L"Question No. 1";
		// 
		// sessionScore_l
		// 
		this->sessionScore_l->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->sessionScore_l->AutoSize = true;
		this->sessionScore_l->Font = (gcnew System::Drawing::Font(L"Rubik", 14, System::Drawing::FontStyle::Bold));
		this->sessionScore_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->sessionScore_l->Location = System::Drawing::Point(185, 8);
		this->sessionScore_l->Name = L"sessionScore_l";
		this->sessionScore_l->Size = System::Drawing::Size(169, 29);
		this->sessionScore_l->TabIndex = 2;
		this->sessionScore_l->Text = L"current Score: 0";
		// 
		// question_l
		// 
		this->question_l->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->question_l->AutoEllipsis = true;
		this->question_l->Font = (gcnew System::Drawing::Font(L"Rubik", 16, System::Drawing::FontStyle::Bold));
		this->question_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->question_l->Location = System::Drawing::Point(12, 72);
		this->question_l->Name = L"question_l";
		this->question_l->Size = System::Drawing::Size(756, 156);
		this->question_l->TabIndex = 3;
		this->question_l->Text = L"Which country won the first FIFA World Cup in 1930\?";
		// 
		// panel1
		// 
		this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(61)),
			static_cast<System::Int32>(static_cast<System::Byte>(96)));
		this->panel1->Location = System::Drawing::Point(-21, 40);
		this->panel1->Name = L"panel1";
		this->panel1->Size = System::Drawing::Size(837, 5);
		this->panel1->TabIndex = 4;
		// 
		// answer1_btn
		// 
		this->answer1_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->answer1_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(61)),
			static_cast<System::Int32>(static_cast<System::Byte>(96)));
		this->answer1_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->answer1_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
			static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->answer1_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->answer1_btn->Font = (gcnew System::Drawing::Font(L"Rubik", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->answer1_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->answer1_btn->Location = System::Drawing::Point(12, 244);
		this->answer1_btn->Name = L"answer1_btn";
		this->answer1_btn->Size = System::Drawing::Size(756, 62);
		this->answer1_btn->TabIndex = 5;
		this->answer1_btn->Text = L"Uruguay";
		this->answer1_btn->UseVisualStyleBackColor = false;
		this->answer1_btn->Click += gcnew System::EventHandler(this, &GameForm::answer1_btn_Click);
		// 
		// answer2_btn
		// 
		this->answer2_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->answer2_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(61)),
			static_cast<System::Int32>(static_cast<System::Byte>(96)));
		this->answer2_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->answer2_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
			static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->answer2_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->answer2_btn->Font = (gcnew System::Drawing::Font(L"Rubik", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->answer2_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->answer2_btn->Location = System::Drawing::Point(12, 319);
		this->answer2_btn->Name = L"answer2_btn";
		this->answer2_btn->Size = System::Drawing::Size(756, 62);
		this->answer2_btn->TabIndex = 6;
		this->answer2_btn->Text = L"Brazil";
		this->answer2_btn->UseVisualStyleBackColor = false;
		this->answer2_btn->Click += gcnew System::EventHandler(this, &GameForm::answer2_btn_Click);
		// 
		// answer3_btn
		// 
		this->answer3_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->answer3_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(61)),
			static_cast<System::Int32>(static_cast<System::Byte>(96)));
		this->answer3_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->answer3_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
			static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->answer3_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->answer3_btn->Font = (gcnew System::Drawing::Font(L"Rubik", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->answer3_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->answer3_btn->Location = System::Drawing::Point(12, 394);
		this->answer3_btn->Name = L"answer3_btn";
		this->answer3_btn->Size = System::Drawing::Size(756, 62);
		this->answer3_btn->TabIndex = 7;
		this->answer3_btn->Text = L"Argentina";
		this->answer3_btn->UseVisualStyleBackColor = false;
		this->answer3_btn->Click += gcnew System::EventHandler(this, &GameForm::answer3_btn_Click);
		// 
		// wrongAnswers_l
		// 
		this->wrongAnswers_l->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->wrongAnswers_l->AutoSize = true;
		this->wrongAnswers_l->Font = (gcnew System::Drawing::Font(L"Rubik", 14, System::Drawing::FontStyle::Bold));
		this->wrongAnswers_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->wrongAnswers_l->Location = System::Drawing::Point(385, 8);
		this->wrongAnswers_l->Name = L"wrongAnswers_l";
		this->wrongAnswers_l->Size = System::Drawing::Size(184, 29);
		this->wrongAnswers_l->TabIndex = 8;
		this->wrongAnswers_l->Text = L"Wrong Answers: 0";
		// 
		// rightAnswers_l
		// 
		this->rightAnswers_l->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->rightAnswers_l->AutoSize = true;
		this->rightAnswers_l->Font = (gcnew System::Drawing::Font(L"Rubik", 14, System::Drawing::FontStyle::Bold));
		this->rightAnswers_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->rightAnswers_l->Location = System::Drawing::Point(600, 8);
		this->rightAnswers_l->Name = L"rightAnswers_l";
		this->rightAnswers_l->Size = System::Drawing::Size(174, 29);
		this->rightAnswers_l->TabIndex = 9;
		this->rightAnswers_l->Text = L"Right Answers: 0";
		// 
		// GameForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(9, 24);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->ClientSize = System::Drawing::Size(780, 477);
		this->Controls->Add(this->rightAnswers_l);
		this->Controls->Add(this->wrongAnswers_l);
		this->Controls->Add(this->answer3_btn);
		this->Controls->Add(this->answer2_btn);
		this->Controls->Add(this->answer1_btn);
		this->Controls->Add(this->panel1);
		this->Controls->Add(this->question_l);
		this->Controls->Add(this->sessionScore_l);
		this->Controls->Add(this->questionNumber_l);
		this->Font = (gcnew System::Drawing::Font(L"Rubik", 12));
		this->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
		this->MaximumSize = System::Drawing::Size(796, 516);
		this->MinimumSize = System::Drawing::Size(796, 516);
		this->Name = L"GameForm";
		this->Text = L"Game ";
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion

private:
	void checkAnswer(String^ answer) {
		bool answerState = _game->answer(answer);

		if (!_game->isGameOn()) {
			wrongAnswers_l->Text = "Wrong Answers: " + _game->getWrongAnsweres().ToString();
			MessageBox::Show(
				"Game Over, Great Job!, Your Score Was: " + _game->getCurrentScore().ToString(),
				"Game Results",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information);

			if (_manager->getAccountHighestScore() < _game->getCurrentScore()) {
				_manager->setHighestScore(_game->getCurrentScore());
				MessageBox::Show(
					"Congratulations you have achived new score!",
					"Game Results",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
			}

			this->Close();
			return;
		}
		startGame();
	}

	System::Void answer1_btn_Click(System::Object^ sender, System::EventArgs^ e) { checkAnswer(answer1_btn->Text); }
	System::Void answer2_btn_Click(System::Object^ sender, System::EventArgs^ e) { checkAnswer(answer2_btn->Text); }
	System::Void answer3_btn_Click(System::Object^ sender, System::EventArgs^ e) { checkAnswer(answer3_btn->Text); }

private:
	void _updateUI(Question^ q) {
		// Update question details
		question_l->Text = q->getQuestionText();
		answer1_btn->Text = q->getAnswer1();
		answer2_btn->Text = q->getAnswer2();
		answer3_btn->Text = q->getAnswer3();

		// Update question number
		questionNumber_l->Text = "Question No. " + _game->getQuestionNumber().ToString();

		sessionScore_l->Text = "current Score: " + _game->getCurrentScore().ToString();

		wrongAnswers_l->Text = "Wrong Answers: " + _game->getWrongAnsweres().ToString();
		rightAnswers_l->Text = "Right Answers: " + _game->getRightAnswers().ToString();
	}

	void startGame() {
		try {
			Question^ q = _game->selectQuestion();
			_updateUI(q);
		}

		catch (Exception^ err) {
			String^ errMsg = gcnew String(err->Message);
			MessageBox::Show(errMsg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			Application::Exit();
		}
	}
};
