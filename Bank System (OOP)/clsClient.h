#pragma once

#include "clsPerson.h"


using namespace std;

class clsClient : public clsPerson
{

private:

	struct strTransferLogRecord;

	enum enMode {EmptyMode = 0, AddNewMode = 1, UpdateMode = 2};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _Balance;
	bool _MarkForDelete = false;
	
	static clsClient _ConvertLineToClientObject(string Line, string Seperator = "//")
	{
		clsClient Client;
		vector <string> sClient = clsString::Split(Line, Seperator);

		return clsClient(enMode::UpdateMode, sClient[0], sClient[1], sClient[2], sClient[3], sClient[4], sClient[5], stod(sClient[6]));
	}

	static string _ConvertClientObjectToLine(clsClient Client, string Seperator = "//")
	{
		string sClient = "";

		sClient += Client.FirstName + Seperator;
		sClient += Client.LastName + Seperator;
		sClient += Client.Email + Seperator;
		sClient += Client.Phone + Seperator;
		sClient += Client.AccountNumber() + Seperator;
		sClient += Client.PinCode + Seperator;
		sClient += to_string(Client.Balance);

		return sClient;
	}

	static vector <clsClient> _LoadClientsFromFile()
	{
		vector <clsClient> Clients;
		fstream File;
		File.open("Clients.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";
			clsClient Client;

			while (getline(File, Line))
			{
				Client = _ConvertLineToClientObject(Line);
				Clients.push_back(Client);
			}

			File.close();
		}

		return Clients;
	}

	static clsClient _GetEmptyClientObject()
	{
		return clsClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static bool _SaveClientsToFile(vector <clsClient>& Clients)
	{
		fstream File;
		File.open("Clients.txt", ios::out);

		if (!File.is_open())
			return false;

		string Line = "";

		for (clsClient& C : Clients)
		{
			if (!C._MarkForDelete)
			{
				Line = _ConvertClientObjectToLine(C);
				File << Line << endl;
			}
		}

		File.close();
		return true;
	}

	bool _SaveClientObjectToFile(clsClient& Client)
	{
		fstream File;
		File.open("Clients.txt", ios::out | ios::app);

		if (!File.is_open())
			return false;

		string Line = _ConvertClientObjectToLine(Client);
		File << Line << endl;

		File.close();
		return true;
	}

	bool _Update()
	{
		vector <clsClient> Clients = _LoadClientsFromFile();

		for (clsClient& C : Clients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				return _SaveClientsToFile(Clients);
			}
		}

		return false;
	}
	
	bool _AddNew()
	{
		return _SaveClientObjectToFile(*this);
	}

	
	string _PrepareTransferRecord(double Amount, clsClient& DestinationClient, string UserName, string Seperator = "//")
	{
		string TransferRecord = "";

		TransferRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferRecord += AccountNumber() + Seperator;
		TransferRecord += DestinationClient.AccountNumber() + Seperator;
		TransferRecord += to_string(Amount) + Seperator;
		TransferRecord += to_string(Balance) + Seperator;
		TransferRecord += to_string(DestinationClient.Balance) + Seperator;
		TransferRecord += UserName;

		return TransferRecord;
	}

	bool _RegisterTransferLog(double Amount, clsClient& DestinationClient, string UserName)
	{
		string Line = _PrepareTransferRecord(Amount, DestinationClient, UserName);

		fstream File;
		File.open("TransfersLog.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << Line << endl;
			File.close();
			return true;
		}

		return false;
	}

	static strTransferLogRecord _ConvertLineToTransferLogRecord(string Line, string Seperator = "//")
	{
		strTransferLogRecord Record;
		vector <string> vRecord = clsString::Split(Line, Seperator);

		Record.DateTime = vRecord[0];
		Record.SourceAccountNumber = vRecord[1];
		Record.DestinationAccountNumber = vRecord[2];
		Record.Amount = stoi(vRecord[3]);
		Record.SourceBalanceAfter = stoi(vRecord[4]);
		Record.DestinationBalanceAfter = stoi(vRecord[5]);
		Record.UserName = vRecord[6];

		return Record;
	}


public:

	struct strTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		double Amount;
		double SourceBalanceAfter;
		double DestinationBalanceAfter;
		string UserName;
	};


	clsClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double Balance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;
	}

	clsClient() : clsPerson()
	{
		_Mode = enMode::AddNewMode;
		_AccountNumber = "";
		_PinCode = "";
		_Balance = 0;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}


	string AccountNumber()
	{
		return _AccountNumber;
	}


	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


	void SetBalance(double Balance)
	{
		_Balance = Balance;
	}

	double GetBalance()
	{
		return _Balance;
	}

	__declspec(property(get = GetBalance, put = SetBalance)) double Balance;


	static clsClient Find(string AccountNumber)
	{
		fstream File;
		File.open("Clients.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			clsClient Client;

			while (getline(File, Line))
			{
				Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					File.close();
					return Client;
				}
			}

			File.close();
		}

		return _GetEmptyClientObject();
	}

	static clsClient Find(string AccountNumber, string PinCode)
	{
		fstream File;
		File.open("Clients.txt", ios::in);

		if (File.is_open())
		{
			string Line;
			clsClient Client;

			while (getline(File, Line))
			{
				Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					File.close();
					return Client;
				}
			}

			File.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsClient Client = Find(AccountNumber);

		return !(Client.IsEmpty());
	}

	static clsClient GetAddNewClientObject(string AccountNumber)
	{
		return clsClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Save()
	{
		switch (_Mode)
		{
			case enMode::UpdateMode:
			{
				return _Update();
				break;
			}

			case enMode::AddNewMode:
			{
				if (IsClientExist(AccountNumber()))
					return false;
				else
				{
					_Mode = enMode::UpdateMode;
					return _AddNew();
				}

				break;
			}

			case enMode::EmptyMode:
			{
				if (IsEmpty())
					return false;
				
				break;
			}

			default:
				return false;
		}
	}
	
	bool Delete()
	{
		vector <clsClient> Clients = _LoadClientsFromFile();

		for (clsClient& C : Clients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._MarkForDelete = true;
				break;
			}
		}

		bool IsSaved = _SaveClientsToFile(Clients);

		if (IsSaved)
		{
			*this = _GetEmptyClientObject();
		}

		return IsSaved;
	}

	static vector <clsClient> GetAllClients()
	{
		return _LoadClientsFromFile();
	}

	static double GetTotalBalances()
	{
		double TotalBalances = 0;

		vector <clsClient> Clients = _LoadClientsFromFile();

		for (clsClient& C : Clients)
		{
			TotalBalances += C.Balance;
		}

		return TotalBalances;
	}

	bool Deposite(double Amount)
	{
		_Balance += Amount;
		return Save();
	}

	bool Withdraw(double Amount)
	{
		if (_Balance >= Amount)
		{
			_Balance -= Amount;
			return Save();
		}

		return false;
	}

	bool Transfer(double Amount, clsClient& DestinationClient, string UserName)
	{
		if (Amount <= 0)
			return false;

		if (AccountNumber() == DestinationClient.AccountNumber())
			return false;

		if (Amount > Balance)
			return false;

		if (!Withdraw(Amount))
			return false;

		if (!DestinationClient.Deposite(Amount))
		{
			Deposite(Amount); // rollback
			return false;
		}

		if (!_RegisterTransferLog(Amount, DestinationClient, UserName))
		{
			return false;
		}

		return true;
	}

	static vector <strTransferLogRecord> GetTransfersLogList()
	{
		vector <strTransferLogRecord> Records;

		fstream File;
		File.open("TransfersLog.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";
			strTransferLogRecord Record;

			while (getline(File, Line))
			{
				Record = _ConvertLineToTransferLogRecord(Line);

				Records.push_back(Record);
			}

			File.close();
		}

		return Records;
	}


};