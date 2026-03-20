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

		cout << clsColor::ColorRGB(clsColor::Red) << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n\n";
		cout << clsColor::ColorRGB(clsColor::DeepPink) << clsUtility::Tabs(2);
		cout << "| " << setw(35) << left << "Date - Time";
		cout << "| " << setw(20) << left << "UserName";
		cout << "| " << setw(20) << left << "Password";
		cout << "| " << setw(10) << left << "Permissions\n";
		cout << clsColor::ColorRGB(clsColor::Red) << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n\n";

		if (vLoginRegisterRecords.size() == 0)
			cout << clsColor::ColorRGB(clsColor::Lime) << clsUtility::Tabs(6) << "No Records Available In the System!";

		else
		{
			for (clsUser::strLoginRegisterRecord& R : vLoginRegisterRecords)
			{
				clsUserUI::PrintLoginRegisterRecord(R);
			}
		}


		cout << clsColor::ColorRGB(clsColor::Red) << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n";
	}

};