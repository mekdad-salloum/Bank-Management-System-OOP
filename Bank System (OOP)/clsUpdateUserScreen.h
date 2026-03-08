#pragma once

class clsUpdateUserScreen : protected clsScreen
{

private:

	static void _UpdateUser()
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
		cout << "\nAre You Sure You Want To Update This User? (Y/N) ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n\nUpdate User Info:";
			cout << "\n_____________________\n";
			clsUserUI::ReadUserInfo(User);

			if (User.Save())
			{
				cout << "\nUser Updated Successfully :-)\n";
				clsUserUI::PrintUserCard(User);
			}

			else
			{
				cout << "\nError Account Was Not Saved :-(\n";
			}
		}

		else
		{
			cout << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");

		_UpdateUser();
	}

};