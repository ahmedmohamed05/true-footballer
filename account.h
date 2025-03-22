#pragma once
#include <iostream>
#include <msclr/marshal.h>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace Collections::Generic; // For List
using namespace System::IO;

public ref class AccountsManager {
private:
	String^ _username;
	String^ _password;
	String^ _path;
	int _highestScore;

private:
	AccountsManager(String^ username, String^ password, int highestScore) {
		_username = username;
		_password = password;
		_highestScore = highestScore;
	}

public:
	AccountsManager(String^ path, String^ username, String^ password) {
		_path = path;
		AccountsManager^ foundAccount = findAccount(path, username, password);

		if (foundAccount == nullptr) {
			throw runtime_error("No Account Fond");
		}

		this->_password = foundAccount->getPassword();
		this->_username = foundAccount->getUsername();
		this->_highestScore = foundAccount->getHighestScore();
	}

	// Helper functions to work with files
private:
	static string _managedStrToNative(String^ sysstr) {
		using System::IntPtr;
		using Runtime::InteropServices::Marshal;

		IntPtr ip = Marshal::StringToHGlobalAnsi(sysstr);
		string outString = static_cast<const char*>(ip.ToPointer());
		Marshal::FreeHGlobal(ip);
		return outString;
	}

	static String^ _convertAccountToRecord(AccountsManager^ account) {
		String^ record = "";
		record = account->getUsername() + ":";
		record += account->getPassword() + ":";
		record += account->getHighestScore().ToString();

		return record;
	}

	static AccountsManager^ _convertRecordToAccount(String^ record) {
		auto accountArray = record->Split(':');

		String^ username = accountArray[0];
		String^ password = accountArray[1];
		int highestScore = INT32::Parse(accountArray[2]);

		return gcnew AccountsManager(username, password, highestScore);
	}

	static void _createFileIfNotExists(String^ path) {
		if (!File::Exists(path))
			File::CreateText(path)->Close();
	}

	// getter and setter to the accounts file
private:
	static List<AccountsManager^>^ _getAccountsFromFile(String^ path) {
		List<AccountsManager^>^ accounts = gcnew List<AccountsManager^>;
		try {
			_createFileIfNotExists(path);
			StreamReader^ reader = File::OpenText(path);

			while (!reader->EndOfStream) {
				String^ record = reader->ReadLine();
				AccountsManager^ account = _convertRecordToAccount(record);
				accounts->Add(account);
			}

			reader->Close();
		}
		catch (FileNotFoundException^ ex) {
			// Handle missing file
			MessageBox::Show(ex->Message, "Not Found Error");
		}
		catch (UnauthorizedAccessException^ ex) {
			MessageBox::Show(ex->Message, "Unauthorized Error");
		}

		return accounts;
	}

	static void _writesAccountsToFile(String^ path, List<AccountsManager^>^& accounts) {
		if (accounts == nullptr) return;

		try {
			_createFileIfNotExists(path);
			StreamWriter^ writer = gcnew StreamWriter(path, false);

			// Convert each account to record and write it to the file
			for each (AccountsManager ^ account in accounts) {
				writer->WriteLine(_convertAccountToRecord(account));
			}

			writer->Close();
		}
		catch (FileNotFoundException^ ex) {
			// Handle missing file
			MessageBox::Show(ex->Message, "Not Found Error");
		}
		catch (UnauthorizedAccessException^ ex) {
			MessageBox::Show(ex->Message, "Unauthorized Error");
		}
	}

	// find and adds an account
public:
	static AccountsManager^ findAccount(String^ fileName, String^ username, String^ password) {

		List<AccountsManager^>^ accounts = _getAccountsFromFile(fileName);

		// Format as: [user name]:[password]:[highest score]
		if (accounts != nullptr) {
			for each (AccountsManager ^ account in accounts) {
				// check for the user name
				if (account->getUsername()->Equals(username)) {

					// check the password of that account
					if (account->getPassword()->Equals(password)) {
						int highestScore = account->getHighestScore();
						return account;
					}
					// correct user name but wrong password
					else {
						throw runtime_error("Wrong password");
					}
				}
			}
		}

		// the loop ends without finding any account with the same user name
		throw runtime_error("No Account Found With This User name");
		return nullptr; // this will never happened
	}

	static void addAccount(String^ path, String^ username, String^ password) {

		// check for spaces in the user name
		for (int i = 0; i < username->Length; i++) {
			if (username[i].Equals(' ')) throw runtime_error("User name can't contain a space");
		}

		List<AccountsManager^>^ accounts = _getAccountsFromFile(path);

		// check if the user name already used
		if (accounts != nullptr) {
			for each (AccountsManager ^ account in accounts) {
				if (account->getUsername() == username) {
					throw runtime_error("Account with this user name already exist");
				}
			}
		}

		// check for the password length 
		if (password->Length < 4) throw runtime_error("Password length must be at least 4 characters");

		AccountsManager^ account = gcnew AccountsManager(username, password, 0);
		accounts->Add(account);
		_writesAccountsToFile(path, accounts);

	}

private:
	void _updateFile(String^ path) {
		List<AccountsManager^>^ accounts = _getAccountsFromFile(path);

		// found the current account inside the list
		for (int i = 0; i < accounts->Count; i++) {
			if (this->_username->Equals(accounts[i]->getUsername())) {
				accounts[i] = this;
				break;
			}
		}

		_writesAccountsToFile(path, accounts);
	}

	// Class Properties getters and setters
public:
	String^ getPassword() { return _password; }

	String^ getUsername() { return _username; }

	int getHighestScore() { return _highestScore; }
	// TODO Fried with the game class
	void incrementScore(String^ path) {
		_highestScore += 2;
		_updateFile(path);
	}

};
