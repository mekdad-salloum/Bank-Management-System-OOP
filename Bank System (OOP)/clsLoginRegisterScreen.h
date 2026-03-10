#pragma once

class clsLoginRegisterScreen : protected clsScreen
{

public:

	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::pLoginRegister))
		{
			return;
		}

		vector <clsUser::strLoginRegisterRecord> vLoginRegisterRecords = clsUser::GetLoginRegistersList();

		_DrawScreenHeader("Login Register List Screen", "   (" + to_string(vLoginRegisterRecords.size()) + ") Record(s).");

		cout << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n\n";
		cout << clsUtility::Tabs(2);
		cout << "| " << setw(35) << left << "Date - Time";
		cout << "| " << setw(20) << left << "UserName";
		cout << "| " << setw(20) << left << "Password";
		cout << "| " << setw(10) << left << "Permissions\n";
		cout << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n\n";

		if (vLoginRegisterRecords.size() == 0)
			cout << clsUtility::Tabs(6) << "No Records Available In the System!";

		else
		{
			for (clsUser::strLoginRegisterRecord& R : vLoginRegisterRecords)
			{
				clsUserUI::PrintLoginRegisterRecord(R);
			}
		}


		cout << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n";
	}

};