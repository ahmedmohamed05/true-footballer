#pragma once
#include "../classes/scores-manager.h"
#include "../global.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
public ref class ScoresForm : public System::Windows::Forms::Form {
private:
	ScoresManager^ _scoreManager;
public:
	ScoresForm() {
		InitializeComponent();
		_scoreManager = gcnew ScoresManager(Global::SCORES_FILE_PATH, Global::SCORES_SEPARATOR);
	}

protected:
	~ScoresForm() {
		if (components) delete components;
	}

private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::ListBox^ scores_lst;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Label^ score_l;
private: System::Windows::Forms::Label^ timeDate_l;
private: System::Windows::Forms::Label^ questions_l;
private: System::Windows::Forms::Label^ rightAnswers_l;
private: System::Windows::Forms::Label^ wrongAnswers_l;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ username_l;
private: System::Windows::Forms::Button^ back_btn;
private: System::Windows::Forms::ComboBox^ filters_cb;



private:
	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
	void InitializeComponent(void) {
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->scores_lst = (gcnew System::Windows::Forms::ListBox());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->label6 = (gcnew System::Windows::Forms::Label());
		this->label7 = (gcnew System::Windows::Forms::Label());
		this->label8 = (gcnew System::Windows::Forms::Label());
		this->score_l = (gcnew System::Windows::Forms::Label());
		this->timeDate_l = (gcnew System::Windows::Forms::Label());
		this->questions_l = (gcnew System::Windows::Forms::Label());
		this->rightAnswers_l = (gcnew System::Windows::Forms::Label());
		this->wrongAnswers_l = (gcnew System::Windows::Forms::Label());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->username_l = (gcnew System::Windows::Forms::Label());
		this->back_btn = (gcnew System::Windows::Forms::Button());
		this->filters_cb = (gcnew System::Windows::Forms::ComboBox());
		this->SuspendLayout();
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Font = (gcnew System::Drawing::Font(L"Rubik", 20.75F, System::Drawing::FontStyle::Bold));
		this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label1->Location = System::Drawing::Point(12, 76);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(176, 43);
		this->label1->TabIndex = 2;
		this->label1->Text = L"Scores List";
		// 
		// scores_lst
		// 
		this->scores_lst->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
			| System::Windows::Forms::AnchorStyles::Left));
		this->scores_lst->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
			static_cast<System::Int32>(static_cast<System::Byte>(72)));
		this->scores_lst->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->scores_lst->Font = (gcnew System::Drawing::Font(L"Rubik", 14));
		this->scores_lst->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->scores_lst->FormattingEnabled = true;
		this->scores_lst->ItemHeight = 29;
		this->scores_lst->Location = System::Drawing::Point(20, 122);
		this->scores_lst->Name = L"scores_lst";
		this->scores_lst->Size = System::Drawing::Size(458, 261);
		this->scores_lst->TabIndex = 3;
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Font = (gcnew System::Drawing::Font(L"Rubik", 20.75F, System::Drawing::FontStyle::Bold));
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label2->Location = System::Drawing::Point(586, 11);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(206, 43);
		this->label2->TabIndex = 4;
		this->label2->Text = L"Score Details";
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Font = (gcnew System::Drawing::Font(L"Rubik", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label4->Location = System::Drawing::Point(552, 154);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(75, 29);
		this->label4->TabIndex = 6;
		this->label4->Text = L"Score:";
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Font = (gcnew System::Drawing::Font(L"Rubik", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label5->Location = System::Drawing::Point(552, 207);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(107, 29);
		this->label5->TabIndex = 7;
		this->label5->Text = L"Timedate:";
		// 
		// label6
		// 
		this->label6->AutoSize = true;
		this->label6->Font = (gcnew System::Drawing::Font(L"Rubik", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label6->Location = System::Drawing::Point(552, 260);
		this->label6->Name = L"label6";
		this->label6->Size = System::Drawing::Size(145, 29);
		this->label6->TabIndex = 8;
		this->label6->Text = L"No. Questions";
		// 
		// label7
		// 
		this->label7->AutoSize = true;
		this->label7->Font = (gcnew System::Drawing::Font(L"Rubik", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label7->Location = System::Drawing::Point(552, 313);
		this->label7->Name = L"label7";
		this->label7->Size = System::Drawing::Size(151, 29);
		this->label7->TabIndex = 9;
		this->label7->Text = L"Right Answers";
		// 
		// label8
		// 
		this->label8->AutoSize = true;
		this->label8->Font = (gcnew System::Drawing::Font(L"Rubik", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label8->Location = System::Drawing::Point(552, 366);
		this->label8->Name = L"label8";
		this->label8->Size = System::Drawing::Size(161, 29);
		this->label8->TabIndex = 10;
		this->label8->Text = L"Wrong Answers";
		// 
		// score_l
		// 
		this->score_l->AutoSize = true;
		this->score_l->Font = (gcnew System::Drawing::Font(L"Rubik", 14));
		this->score_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->score_l->Location = System::Drawing::Point(732, 154);
		this->score_l->Name = L"score_l";
		this->score_l->Size = System::Drawing::Size(109, 29);
		this->score_l->TabIndex = 12;
		this->score_l->Text = L"Username:";
		// 
		// timeDate_l
		// 
		this->timeDate_l->AutoSize = true;
		this->timeDate_l->Font = (gcnew System::Drawing::Font(L"Rubik", 14));
		this->timeDate_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->timeDate_l->Location = System::Drawing::Point(732, 207);
		this->timeDate_l->Name = L"timeDate_l";
		this->timeDate_l->Size = System::Drawing::Size(109, 29);
		this->timeDate_l->TabIndex = 13;
		this->timeDate_l->Text = L"Username:";
		// 
		// questions_l
		// 
		this->questions_l->AutoSize = true;
		this->questions_l->Font = (gcnew System::Drawing::Font(L"Rubik", 14));
		this->questions_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->questions_l->Location = System::Drawing::Point(732, 260);
		this->questions_l->Name = L"questions_l";
		this->questions_l->Size = System::Drawing::Size(109, 29);
		this->questions_l->TabIndex = 14;
		this->questions_l->Text = L"Username:";
		// 
		// rightAnswers_l
		// 
		this->rightAnswers_l->AutoSize = true;
		this->rightAnswers_l->Font = (gcnew System::Drawing::Font(L"Rubik", 14));
		this->rightAnswers_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->rightAnswers_l->Location = System::Drawing::Point(732, 313);
		this->rightAnswers_l->Name = L"rightAnswers_l";
		this->rightAnswers_l->Size = System::Drawing::Size(109, 29);
		this->rightAnswers_l->TabIndex = 15;
		this->rightAnswers_l->Text = L"Username:";
		// 
		// wrongAnswers_l
		// 
		this->wrongAnswers_l->AutoSize = true;
		this->wrongAnswers_l->Font = (gcnew System::Drawing::Font(L"Rubik", 14));
		this->wrongAnswers_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->wrongAnswers_l->Location = System::Drawing::Point(732, 366);
		this->wrongAnswers_l->Name = L"wrongAnswers_l";
		this->wrongAnswers_l->Size = System::Drawing::Size(109, 29);
		this->wrongAnswers_l->TabIndex = 16;
		this->wrongAnswers_l->Text = L"Username:";
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Font = (gcnew System::Drawing::Font(L"Rubik", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label3->Location = System::Drawing::Point(552, 94);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(115, 29);
		this->label3->TabIndex = 5;
		this->label3->Text = L"Username:";
		// 
		// username_l
		// 
		this->username_l->AutoSize = true;
		this->username_l->Font = (gcnew System::Drawing::Font(L"Rubik", 14));
		this->username_l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->username_l->Location = System::Drawing::Point(732, 94);
		this->username_l->Name = L"username_l";
		this->username_l->Size = System::Drawing::Size(109, 29);
		this->username_l->TabIndex = 11;
		this->username_l->Text = L"Username:";
		// 
		// back_btn
		// 
		this->back_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(91)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->back_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->back_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
			static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->back_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->back_btn->Font = (gcnew System::Drawing::Font(L"Rubik", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->back_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->back_btn->Location = System::Drawing::Point(20, 14);
		this->back_btn->Name = L"back_btn";
		this->back_btn->Size = System::Drawing::Size(66, 40);
		this->back_btn->TabIndex = 17;
		this->back_btn->Text = L"Back";
		this->back_btn->UseVisualStyleBackColor = false;
		this->back_btn->Click += gcnew System::EventHandler(this, &ScoresForm::back_btn_Click);
		// 
		// filters_cb
		// 
		this->filters_cb->FormattingEnabled = true;
		this->filters_cb->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Ascending", L"Descending", L"My scores", L"All" });
		this->filters_cb->Location = System::Drawing::Point(194, 84);
		this->filters_cb->Name = L"filters_cb";
		this->filters_cb->Size = System::Drawing::Size(284, 32);
		this->filters_cb->TabIndex = 18;
		// 
		// ScoresForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(9, 24);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->ClientSize = System::Drawing::Size(970, 413);
		this->Controls->Add(this->filters_cb);
		this->Controls->Add(this->back_btn);
		this->Controls->Add(this->username_l);
		this->Controls->Add(this->label3);
		this->Controls->Add(this->wrongAnswers_l);
		this->Controls->Add(this->rightAnswers_l);
		this->Controls->Add(this->questions_l);
		this->Controls->Add(this->timeDate_l);
		this->Controls->Add(this->score_l);
		this->Controls->Add(this->label8);
		this->Controls->Add(this->label7);
		this->Controls->Add(this->label6);
		this->Controls->Add(this->label5);
		this->Controls->Add(this->label4);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->scores_lst);
		this->Controls->Add(this->label1);
		this->Font = (gcnew System::Drawing::Font(L"Rubik", 12));
		this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
		this->MaximumSize = System::Drawing::Size(986, 99999);
		this->MinimumSize = System::Drawing::Size(986, 452);
		this->Name = L"ScoresForm";
		this->Text = L"Scores List ";
		this->Load += gcnew System::EventHandler(this, &ScoresForm::scoresform_Load);
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion

private: System::Void back_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

private: String^ getScoreAsListItem(Score^% score) {
	String^ item = "";
	item += score->getUsername() + " Scored ";
	item += score->getScore().ToString() + " At ";
	item += score->getTimeDate();
	return item;
}

private: System::Void scoresform_Load(System::Object^ sender, System::EventArgs^ e) {
	List<Score^>^ list = _scoreManager->getList();
	scores_lst->Items->Clear();

	for each (Score ^ %score in list) {
		scores_lst->Items->Add(getScoreAsListItem(score));
	}
}
};
