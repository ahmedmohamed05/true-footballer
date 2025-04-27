#pragma once
#include "../classes/account.h"
#include "game-form.h"
#include "./delete-form.h"
#include "./scores-form.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class MainForm : public System::Windows::Forms::Form {
private:
	void updateGreetingLabel(String^ username) {
		greeting_l->Text = "Welcome!, " + username;
	}
	void updateHighestScoreLabel(int newScore) {
		highestScore_l->Text = "Highest Score: " + newScore.ToString();
	}
private: System::Windows::Forms::Button^ showScores_btn;
private: System::Windows::Forms::Label^ label1;


private:
	AccountsManager^ _manager;

public:
	MainForm(AccountsManager^% manager) {
		InitializeComponent();
		_manager = manager;

		updateGreetingLabel(_manager->getAccountUsername());
		updateHighestScoreLabel(_manager->getAccountHighestScore());
	}

protected:
	~MainForm() {
		if (components) delete components;
	}

private:
	System::ComponentModel::Container^ components;
	System::Windows::Forms::Label^ greeting_l;
	System::Windows::Forms::Button^ logout_btn;
	System::Windows::Forms::Label^ highestScore_l;
	System::Windows::Forms::Button^ deleteAccount_btn;
	System::Windows::Forms::Button^ startGame_btn;

#pragma region Windows Form Designer generated code
	void InitializeComponent(void) {
		this->greeting_l = (gcnew System::Windows::Forms::Label());
		this->logout_btn = (gcnew System::Windows::Forms::Button());
		this->highestScore_l = (gcnew System::Windows::Forms::Label());
		this->startGame_btn = (gcnew System::Windows::Forms::Button());
		this->deleteAccount_btn = (gcnew System::Windows::Forms::Button());
		this->showScores_btn = (gcnew System::Windows::Forms::Button());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->SuspendLayout();
		// 
		// greeting_l
		// 
		this->greeting_l->AutoSize = true;
		this->greeting_l->Font = (gcnew System::Drawing::Font(L"Rubik", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->greeting_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->greeting_l->Location = System::Drawing::Point(12, 9);
		this->greeting_l->Name = L"greeting_l";
		this->greeting_l->Size = System::Drawing::Size(244, 42);
		this->greeting_l->TabIndex = 0;
		this->greeting_l->Text = L"Welcome!, Player";
		// 
		// logout_btn
		// 
		this->logout_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
		this->logout_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(188)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
			static_cast<System::Int32>(static_cast<System::Byte>(83)));
		this->logout_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->logout_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
			static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->logout_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->logout_btn->Font = (gcnew System::Drawing::Font(L"Rubik", 15.75F, System::Drawing::FontStyle::Bold));
		this->logout_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->logout_btn->Location = System::Drawing::Point(305, 243);
		this->logout_btn->Name = L"logout_btn";
		this->logout_btn->Size = System::Drawing::Size(290, 58);
		this->logout_btn->TabIndex = 1;
		this->logout_btn->Text = L"Logout ";
		this->logout_btn->UseVisualStyleBackColor = false;
		this->logout_btn->Click += gcnew System::EventHandler(this, &MainForm::logout_btn_Click);
		// 
		// highestScore_l
		// 
		this->highestScore_l->AutoSize = true;
		this->highestScore_l->Font = (gcnew System::Drawing::Font(L"Rubik", 14));
		this->highestScore_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->highestScore_l->Location = System::Drawing::Point(12, 51);
		this->highestScore_l->Name = L"highestScore_l";
		this->highestScore_l->Size = System::Drawing::Size(161, 29);
		this->highestScore_l->TabIndex = 2;
		this->highestScore_l->Text = L"Highest Score: 0";
		// 
		// startGame_btn
		// 
		this->startGame_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
		this->startGame_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(91)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->startGame_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->startGame_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
			static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->startGame_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->startGame_btn->Font = (gcnew System::Drawing::Font(L"Rubik", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->startGame_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->startGame_btn->Location = System::Drawing::Point(12, 113);
		this->startGame_btn->Name = L"startGame_btn";
		this->startGame_btn->Size = System::Drawing::Size(583, 58);
		this->startGame_btn->TabIndex = 5;
		this->startGame_btn->Text = L"Start Playing";
		this->startGame_btn->UseVisualStyleBackColor = false;
		this->startGame_btn->Click += gcnew System::EventHandler(this, &MainForm::startGame_btn_Click);
		// 
		// deleteAccount_btn
		// 
		this->deleteAccount_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
		this->deleteAccount_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)),
			static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(17)));
		this->deleteAccount_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->deleteAccount_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
			static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->deleteAccount_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->deleteAccount_btn->Font = (gcnew System::Drawing::Font(L"Rubik", 15.75F, System::Drawing::FontStyle::Bold));
		this->deleteAccount_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->deleteAccount_btn->Location = System::Drawing::Point(12, 243);
		this->deleteAccount_btn->Name = L"deleteAccount_btn";
		this->deleteAccount_btn->Size = System::Drawing::Size(287, 58);
		this->deleteAccount_btn->TabIndex = 6;
		this->deleteAccount_btn->Text = L"Delete Account";
		this->deleteAccount_btn->UseVisualStyleBackColor = false;
		this->deleteAccount_btn->Click += gcnew System::EventHandler(this, &MainForm::deleteAccount_btn_click);
		// 
		// showScores_btn
		// 
		this->showScores_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
		this->showScores_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->showScores_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->showScores_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
			static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->showScores_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->showScores_btn->Font = (gcnew System::Drawing::Font(L"Rubik", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->showScores_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->showScores_btn->Location = System::Drawing::Point(12, 179);
		this->showScores_btn->Name = L"showScores_btn";
		this->showScores_btn->Size = System::Drawing::Size(583, 58);
		this->showScores_btn->TabIndex = 7;
		this->showScores_btn->Text = L"Show Scores List";
		this->showScores_btn->UseVisualStyleBackColor = false;
		this->showScores_btn->Click += gcnew System::EventHandler(this, &MainForm::showScores_btn_Click);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Font = (gcnew System::Drawing::Font(L"Rubik", 14));
		this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label1->Location = System::Drawing::Point(294, 16);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(95, 29);
		this->label1->TabIndex = 8;
		this->label1->Text = L"Difficulty:";
		// 
		// MainForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(9, 24);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->ClientSize = System::Drawing::Size(607, 319);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->showScores_btn);
		this->Controls->Add(this->deleteAccount_btn);
		this->Controls->Add(this->startGame_btn);
		this->Controls->Add(this->highestScore_l);
		this->Controls->Add(this->logout_btn);
		this->Controls->Add(this->greeting_l);
		this->Font = (gcnew System::Drawing::Font(L"Rubik", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
		this->MaximizeBox = false;
		this->MinimizeBox = false;
		this->MinimumSize = System::Drawing::Size(436, 227);
		this->Name = L"MainForm";
		this->Text = L"True Footballer";
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion

private: System::Void logout_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult logoutConfirmation = MessageBox::Show("Do you want to log out", "Confirmation", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
	if (logoutConfirmation == Windows::Forms::DialogResult::Yes) {
		this->Close();
	}
}

private: System::Void startGame_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();

	GameForm^ gameForm = gcnew GameForm(_manager);
	gameForm->ShowDialog();

	this->Show();
	updateHighestScoreLabel(_manager->getAccountHighestScore());
}

private: System::Void deleteAccount_btn_click(System::Object^ sender, System::EventArgs^ e) {
	DeleteAccountForm^ form = gcnew DeleteAccountForm(_manager);
	form->ShowDialog();
}

private: System::Void showScores_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();

	ScoresForm^ scoresForm = gcnew ScoresForm();
	scoresForm->ShowDialog();

	this->Show();
}
};
