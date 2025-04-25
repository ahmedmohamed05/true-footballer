#pragma once
//#include <string>
#include "../classes/account.h"
#include "../global.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class LoginForm : public System::Windows::Forms::Form {
private:
	//String^ _ACCOUNTS_FILE_PATH;
	AccountsManager^ _account;
public:
	LoginForm(/*String^ accountsFilePath*/) {
		//_ACCOUNTS_FILE_PATH = accountsFilePath;
		InitializeComponent();
	}


protected:
	~LoginForm() {
		if (components) delete components;
	}

private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::TextBox^ username_tb;
private: System::Windows::Forms::TextBox^ password_tb;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Button^ singin_btn;
private: System::Windows::Forms::Button^ createAccount_btn;

private:
	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
	void InitializeComponent(void) {
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->username_tb = (gcnew System::Windows::Forms::TextBox());
		this->password_tb = (gcnew System::Windows::Forms::TextBox());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->singin_btn = (gcnew System::Windows::Forms::Button());
		this->createAccount_btn = (gcnew System::Windows::Forms::Button());
		this->SuspendLayout();
		// 
		// label1
		// 
		this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
		this->label1->AutoSize = true;
		this->label1->Font = (gcnew System::Drawing::Font(L"Rubik", 20.75F, System::Drawing::FontStyle::Bold));
		this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label1->Location = System::Drawing::Point(101, 33);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(219, 43);
		this->label1->TabIndex = 0;
		this->label1->Text = L"Welcome Back";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Font = (gcnew System::Drawing::Font(L"Rubik", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label2->Location = System::Drawing::Point(14, 111);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(86, 24);
		this->label2->TabIndex = 1;
		this->label2->Text = L"Username";
		// 
		// username_tb
		// 
		this->username_tb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
		this->username_tb->Location = System::Drawing::Point(18, 140);
		this->username_tb->Name = L"username_tb";
		this->username_tb->Size = System::Drawing::Size(385, 26);
		this->username_tb->TabIndex = 1;
		// 
		// password_tb
		// 
		this->password_tb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
		this->password_tb->Location = System::Drawing::Point(18, 215);
		this->password_tb->Name = L"password_tb";
		this->password_tb->PasswordChar = '#';
		this->password_tb->Size = System::Drawing::Size(385, 26);
		this->password_tb->TabIndex = 2;
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Font = (gcnew System::Drawing::Font(L"Rubik", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label3->Location = System::Drawing::Point(14, 186);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(83, 24);
		this->label3->TabIndex = 3;
		this->label3->Text = L"Password";
		// 
		// singin_btn
		// 
		this->singin_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(91)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->singin_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->singin_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
			static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->singin_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->singin_btn->Font = (gcnew System::Drawing::Font(L"Rubik", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->singin_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->singin_btn->Location = System::Drawing::Point(18, 258);
		this->singin_btn->Name = L"singin_btn";
		this->singin_btn->Size = System::Drawing::Size(385, 44);
		this->singin_btn->TabIndex = 3;
		this->singin_btn->Text = L"Sing In";
		this->singin_btn->UseVisualStyleBackColor = false;
		this->singin_btn->Click += gcnew System::EventHandler(this, &LoginForm::signIn_btn_Click);
		// 
		// createAccount_btn
		// 
		this->createAccount_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
			static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->createAccount_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
			static_cast<System::Int32>(static_cast<System::Byte>(91)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->createAccount_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
			static_cast<System::Int32>(static_cast<System::Byte>(91)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->createAccount_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->createAccount_btn->Font = (gcnew System::Drawing::Font(L"Rubik", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->createAccount_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->createAccount_btn->Location = System::Drawing::Point(18, 339);
		this->createAccount_btn->Name = L"createAccount_btn";
		this->createAccount_btn->Size = System::Drawing::Size(385, 44);
		this->createAccount_btn->TabIndex = 4;
		this->createAccount_btn->Text = L"Create New Account";
		this->createAccount_btn->UseVisualStyleBackColor = false;
		this->createAccount_btn->Click += gcnew System::EventHandler(this, &LoginForm::createAccount_btn_Click);
		// 
		// LoginForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(9, 24);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->ClientSize = System::Drawing::Size(421, 437);
		this->Controls->Add(this->createAccount_btn);
		this->Controls->Add(this->singin_btn);
		this->Controls->Add(this->password_tb);
		this->Controls->Add(this->label3);
		this->Controls->Add(this->username_tb);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->label1);
		this->Font = (gcnew System::Drawing::Font(L"Rubik", 12));
		this->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
		this->MaximizeBox = false;
		this->MinimizeBox = false;
		this->Name = L"LoginForm";
		this->Text = L"Log in";
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion

private:

	void changeTextBoxToErrorState(TextBox^% tb, String^ errorText) {
		tb->BackColor = Color::FromArgb(218, 44, 56); // Red
		tb->ForeColor = Color::FromArgb(244, 240, 187); // White
		tb->Text = errorText;
	}

	void changeTextboxToNormalState(TextBox^% tb) {
		tb->BackColor = Color::White;
		tb->ForeColor = Color::Black;
	}

	System::Void signIn_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (username_tb->Text->Equals("")) {
			changeTextBoxToErrorState(username_tb, "This filed is required");
			return;
		}
		changeTextboxToNormalState(username_tb);

		if (password_tb->Text->Equals("")) {
			changeTextBoxToErrorState(password_tb, "This filed is required");
			return;
		}
		changeTextboxToNormalState(password_tb);

		String^ username = username_tb->Text;
		String^ password = password_tb->Text;

		try {
			_account = AccountsManager::findAccount(Global::ACCOUNTS_FILE_PATH, username, password);
			this->DialogResult = Windows::Forms::DialogResult::OK;
			this->Close();
		}
		catch (const runtime_error& err) {
			String^ errMsg = gcnew String(err.what());
			MessageBox::Show(errMsg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	System::Void createAccount_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		if (username_tb->Text->Equals("")) {
			changeTextBoxToErrorState(username_tb, "This filed is required");
			return;
		}
		changeTextboxToNormalState(username_tb);

		if (password_tb->Text->Equals("")) {
			changeTextBoxToErrorState(password_tb, "This filed is required");
			return;
		}
		changeTextboxToNormalState(password_tb);

		String^ username = username_tb->Text;
		String^ password = password_tb->Text;

		try {
			AccountsManager::addAccount(Global::ACCOUNTS_FILE_PATH, username, password);
			_account = AccountsManager::findAccount(Global::ACCOUNTS_FILE_PATH, username, password);
			this->DialogResult = Windows::Forms::DialogResult::OK;
			this->Close();
		}
		catch (runtime_error& err) {
			String^ errMsg = gcnew String(err.what());
			MessageBox::Show(errMsg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

public:
	AccountsManager^ getAccount() {
		return _account;
	}
};