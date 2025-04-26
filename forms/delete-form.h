#pragma once
#include "../classes/account.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class DeleteAccountForm : public System::Windows::Forms::Form {
private:
	AccountsManager^ _manager;

public:
	DeleteAccountForm(AccountsManager^% manager) {
		InitializeComponent();
		_manager = manager;
	}

protected:
	~DeleteAccountForm() {
		if (components) delete components;
	}

private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::TextBox^ password_tb;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Button^ cancel_btn;
private: System::Windows::Forms::Button^ deleteAccount_btn;

private:
	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
	void InitializeComponent(void) {
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->password_tb = (gcnew System::Windows::Forms::TextBox());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->cancel_btn = (gcnew System::Windows::Forms::Button());
		this->deleteAccount_btn = (gcnew System::Windows::Forms::Button());
		this->SuspendLayout();
		// 
		// label1
		// 
		this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
		this->label1->AutoSize = true;
		this->label1->Font = (gcnew System::Drawing::Font(L"Rubik", 20.75F, System::Drawing::FontStyle::Bold));
		this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label1->Location = System::Drawing::Point(25, 9);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(534, 43);
		this->label1->TabIndex = 1;
		this->label1->Text = L"Do You Want To Delete Your Account\?";
		// 
		// password_tb
		// 
		this->password_tb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
		this->password_tb->Location = System::Drawing::Point(33, 95);
		this->password_tb->Name = L"password_tb";
		this->password_tb->PasswordChar = '#';
		this->password_tb->Size = System::Drawing::Size(526, 26);
		this->password_tb->TabIndex = 2;
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Font = (gcnew System::Drawing::Font(L"Rubik", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->label2->Location = System::Drawing::Point(29, 66);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(153, 24);
		this->label2->TabIndex = 3;
		this->label2->Text = L"Confirm Password*";
		// 
		// cancel_btn
		// 
		this->cancel_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->cancel_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
			static_cast<System::Int32>(static_cast<System::Byte>(91)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->cancel_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
			static_cast<System::Int32>(static_cast<System::Byte>(91)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->cancel_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->cancel_btn->Font = (gcnew System::Drawing::Font(L"Rubik", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->cancel_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->cancel_btn->Location = System::Drawing::Point(301, 127);
		this->cancel_btn->Name = L"cancel_btn";
		this->cancel_btn->Size = System::Drawing::Size(258, 44);
		this->cancel_btn->TabIndex = 6;
		this->cancel_btn->Text = L"Cancel";
		this->cancel_btn->UseVisualStyleBackColor = false;
		this->cancel_btn->Click += gcnew System::EventHandler(this, &DeleteAccountForm::cancel_btn_Click);
		// 
		// deleteAccount_btn
		// 
		this->deleteAccount_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->deleteAccount_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)),
			static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(17)));
		this->deleteAccount_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->deleteAccount_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)),
			static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->deleteAccount_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->deleteAccount_btn->Font = (gcnew System::Drawing::Font(L"Rubik", 14.25F, System::Drawing::FontStyle::Bold));
		this->deleteAccount_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
		this->deleteAccount_btn->Location = System::Drawing::Point(33, 127);
		this->deleteAccount_btn->Name = L"deleteAccount_btn";
		this->deleteAccount_btn->Size = System::Drawing::Size(262, 44);
		this->deleteAccount_btn->TabIndex = 7;
		this->deleteAccount_btn->Text = L"Delete Account";
		this->deleteAccount_btn->UseVisualStyleBackColor = false;
		this->deleteAccount_btn->Click += gcnew System::EventHandler(this, &DeleteAccountForm::deleteAccount_btn_Click);
		// 
		// DeleteAccountForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(9, 24);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(84)));
		this->ClientSize = System::Drawing::Size(585, 193);
		this->Controls->Add(this->deleteAccount_btn);
		this->Controls->Add(this->cancel_btn);
		this->Controls->Add(this->password_tb);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->label1);
		this->Font = (gcnew System::Drawing::Font(L"Rubik", 12));
		this->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
		this->Name = L"DeleteAccountForm";
		this->Text = L"Delete Account";
		this->ResumeLayout(false);
		this->PerformLayout();

	}

private:
	bool _confirmDeletion() {
		auto result = MessageBox::Show(
			"Do you want to DELETE your account?",
			"Deletion Confirmation",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Warning);

		return result == Windows::Forms::DialogResult::Yes;
	}


private: System::Void deleteAccount_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ password = password_tb->Text;

	// Text Box State To Error State
	if (password->Equals("")) {
		password_tb->BackColor = Color::FromArgb(218, 44, 56); // Red
		password_tb->ForeColor = Color::FromArgb(244, 240, 187); // White
		return;
	}

	// Change Text Box State To Normal
	password_tb->BackColor = Color::White;
	password_tb->ForeColor = Color::Black;

	// Last confirmation
	if (!_confirmDeletion()) {
		this->Close();
		return;
	}

	bool result = _manager->deleteAccount(password);
	// Check for the password
	if (!result) {
		MessageBox::Show(
			"Wrong Password",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
		return;
	}

	MessageBox::Show(
		"Your account has been deleted successfully",
		"Deletion Successed",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information);

	Application::Restart();
}

private: System::Void cancel_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};