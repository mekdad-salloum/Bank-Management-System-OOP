#pragma once

#include "clsPerson.h"

class clsUser : public clsPerson
{

private:

	enum enMode {EmptyMode = 0, AddNewMode = 1, UpdateMode = 2};

	enMode _Mode;
	string _UserName;
	string _Password;
	short _Permissions;
	bool _MarkForDelete = false;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "//")
	{
		clsUser User;
		vector <string> sUser = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, sUser[0], sUser[1], sUser[2], sUser[3], sUser[4], sUser[5], stoi(sUser[6]));
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "//")
	{
		string sUser = "";

		sUser += User.FirstName + Seperator;
		sUser += User.LastName + Seperator;
		sUser += User.Email + Seperator;
		sUser += User.Phone + Seperator;
		sUser += User.UserName + Seperator;
		sUser += User.Password + Seperator;
		sUser += to_string(User.Permissions);

		return sUser;
	}

	static vector <clsUser> _LoadUsersFromFile()
	{
		vector <clsUser> Users;
		fstream File;
		File.open("Users.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";
			clsUser User;

			while (getline(File, Line))
			{
				User = _ConvertLineToUserObject(Line);
				Users.push_back(User);
			}

			File.close();
		}

		return Users;
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static bool _SaveUsersToFile(vector <clsUser>& Users)
	{
		fstream File;
		File.open("Users.txt", ios::out);

		if (!File.is_open())
			return false;

		string Line = "";

		for (clsUser& C : Users)
		{
			if (!C._MarkForDelete)
			{
				Line = _ConvertUserObjectToLine(C);
				File << Line << endl;
			}
		}

		File.close();
		return true;
	}

	bool _SaveUserObjectToFile(clsUser& User)
	{
		fstream File;
		File.open("Users.txt", ios::out | ios::app);

		if (!File.is_open())
			return false;

		string Line = _ConvertUserObjectToLine(User);
		File << Line << endl;

		File.close();
		return true;
	}

	bool _Update()
	{
		vector <clsUser> Users = _LoadUsersFromFile();

		for (clsUser& C : Users)
		{
			if (C.UserName == UserName)
			{
				C = *this;
				return _SaveUsersToFile(Users);
			}
		}

		return false;
	}

	bool _AddNew()
	{
		return _SaveUserObjectToFile(*this);
	}


public:

	enum enPermissions { pAllPermissions = -1, pShowClientsList = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64 };


	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, short Permissions)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	clsUser() : clsPerson()
	{
		_Mode = enMode::AddNewMode;
		_UserName = "";
		_Password = "";
		_Permissions = 0;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;


	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;


	void SetPermissions(short Permissions)
	{
		_Permissions = Permissions;
	}

	short GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

	
	
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsUser Find(string UserName)
	{
		fstream File;
		File.open("Users.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";
			clsUser User;

			while (getline(File, Line))
			{
				User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName)
				{
					File.close();
					return User;
				}
			}

			File.close();
		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		fstream File;
		File.open("Users.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";
			clsUser User;

			while (getline(File, Line))
			{
				User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName && User.Password == Password)
				{
					File.close();
					return User;
				}
			}

			File.close();
		}

		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = Find(UserName);

		return !(User.IsEmpty());
	}
	
	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
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
			if (IsUserExist(UserName))
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
		vector <clsUser> Users = _LoadUsersFromFile();

		for (clsUser& U : Users)
		{
			if (U.UserName == UserName)
			{
				U._MarkForDelete = true;
				break;
			}
		}

		bool IsSaved = _SaveUsersToFile(Users);

		if (IsSaved)
		{
			*this = _GetEmptyUserObject();
		}

		return IsSaved;
	}

	static vector <clsUser> GetAllUsers()
	{
		return _LoadUsersFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		return (this->Permissions == enPermissions::pAllPermissions) || ((this->Permissions & Permission) == Permission);
	}
};