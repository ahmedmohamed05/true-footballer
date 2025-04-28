#pragma once
#include "./account.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

public ref class AccountsManager {
private:
	String^ _accountsPath;
	List<Account^>^ _accounts;
	Account^ _currentAccount;

	// Converting Functions
private:
	String^ _convertAccountToRecord(Account^ account) {
		String^ record = "";

		record = account->getUsername() + ":";
		record += account->getPassword() + ":";
		record += account->getHighestScore().ToString();

		return record;
	}

	Account^ _convertRecordToAccount(String^ record) {
		array<String^>^ accountArray = record->Split(':');

		String^ username = accountArray[0];
		String^ password = accountArray[1];
		int highestScore = Int32::Parse(accountArray[2]);

		return gcnew Account(username, password, highestScore);
	}

	// Files Functions
private:
	// Create the file if not exist
	void _createFileIfNotExists() {
		if (!File::Exists(_accountsPath))
			File::CreateText(_accountsPath)->Close();
	}

	// Load Accounts From file
	List<Account^>^ _loadAccounts() {
		List<Account^>^ accounts = gcnew List<Account^>;
		_createFileIfNotExists();
		try {
			StreamReader^ reader = File::OpenText(_accountsPath);

			while (!reader->EndOfStream) {
				String^ record = reader->ReadLine();
				Account^ account = _convertRecordToAccount(record);
				accounts->Add(account);
			}

			reader->Close();
		}
		catch (FileNotFoundException^ ex) {
			throw gcnew Exception(ex->Message + ", Not Found Error");
		}
		catch (UnauthorizedAccessException^ ex) {
			throw gcnew Exception(ex->Message + ", Unauthorized Error");
		}

		return accounts;
	}

	// Save accounts to the file form _accounts list
	void _saveAccounts() {
		if (_accounts->Count == 0) return;

		try {
			_createFileIfNotExists();
			StreamWriter^ writer = gcnew StreamWriter(_accountsPath, false);

			// Convert each account to record and write it to the file
			for each (Account ^ %account in _accounts) {
				writer->WriteLine(_convertAccountToRecord(account));
			}

			writer->Close();
		}
		catch (FileNotFoundException^ ex) {
			// Handle missing file
			throw gcnew Exception(ex->Message + ", File Not Found");
		}
		catch (UnauthorizedAccessException^ ex) {
			throw gcnew Exception(ex->Message + ", Unauthorized Error");
		}
	}

private:
	void _updateList() {
		// found the current account inside the list
		for each (Account ^ %account in _accounts) {
			if (_currentAccount->getUsername()->Equals(account->getUsername())) {
				account = _currentAccount;
				break;
			}
		}
	}

public:
	AccountsManager(String^ accountsPath) {
		_accountsPath = accountsPath;
		_createFileIfNotExists();
		_accounts = _loadAccounts();
		_currentAccount = nullptr;
	}

public:
	void signIn(String^ username, String^ password) {

		if (_accounts->Count == 0) throw gcnew Exception("There is no accounts yet, Be The First One !");


		// Format as: [user name]:[password]:[highest score]
		for each (Account ^ account in _accounts) {
			// check for the user name
			if (account->getUsername()->Equals(username)) {

				// check the password of that account
				if (account->getPassword()->Equals(password)) {
					int highestScore = account->getHighestScore();
					_currentAccount = account;
					return;
				}
				// correct user name but wrong password
				else {
					throw gcnew Exception("Wrong password");
				}
			}
		}

		// the loop ends without finding any account with the same user name
		throw gcnew Exception("No Account Found With This User name");
	}

	void signUp(String^ username, String^ password) {
		//check for spaces in the user name
		if (username->Contains(" ")) throw gcnew Exception("User name can't contain a space");

		// check for the password length 
		if (password->Length < 4) throw gcnew Exception("Password length must be at least 4 characters");

		// Check if the username is used
		for each (Account ^ %account in _accounts) {
			if (account->getUsername() == username) {
				throw gcnew Exception("Account with this user name already exists");
			}
		}

		_currentAccount = gcnew Account(username, password, 0);;
		_accounts->Add(_currentAccount);
		_saveAccounts();
	}

	void logout() {
		delete _currentAccount;
		_currentAccount = nullptr;
	}

	// Returns true account deleted successfully
	bool deleteAccount(String^ password) {
		if (!password->Equals(_currentAccount->getPassword())) return false;

		_accounts->Remove(_currentAccount);
		_saveAccounts();
		logout();
		return true;
	}

	// Account Properties
public:
	String^ getAccountUsername() { return _currentAccount->getUsername(); }
	int getAccountHighestScore() { return _currentAccount->getHighestScore(); }
	void setHighestScore(int value) {
		_currentAccount->setHighestScore(value);
		_saveAccounts();
	}
};
