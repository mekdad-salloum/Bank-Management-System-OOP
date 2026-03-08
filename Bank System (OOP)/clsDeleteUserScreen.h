#pragma once

class clsDeleteUserScreen : protected clsScreen
{

private:

	static void _DeleteUser()
	{
		cout << "Enter User UserName: ";
		string UserName = clsInputValidate::ReadString();

		cout << "\n";
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "UserName Is Not Found: Choose Another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		clsUserUI::PrintUserCard(User);

		char Answer = 'N';
		cout << "\nAre You Sure You Want To Delete This User? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully :-)\n";
				clsUserUI::PrintUserCard(User);
			}

			else
			{
				cout << "\nError, Account Was Not Deleted :-(\n";
			}
		}

		else
		{
			cout << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("Delete User Screen");

		_DeleteUser();
	}


};

