#pragma once


class clsTransfersLogScreen : protected clsScreen
{

public:

	static void ShowTransfersLogScreen()
	{
		vector <clsClient::strTransferLogRecord> vTransfersLogRecords = clsClient::GetTransfersLogList();

		_DrawScreenHeader("Transfers Log List Screen", "   (" + to_string(vTransfersLogRecords.size()) + ") Record(s).");

		cout << clsColor::ColorRGB(clsColor::LemonYellow) << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n\n";
		cout << clsUtility::Tabs(2);
		cout << clsColor::ColorRGB(clsColor::Cyan) << "| " << setw(25) << left << "Date - Time";
		cout << clsColor::ColorRGB(clsColor::Red) << "| " << setw(15) << left << "S.AccNum";
		cout << clsColor::ColorRGB(clsColor::Green) << "| " << setw(15) << left << "D.AccNum";
		cout << clsColor::ColorRGB(clsColor::Magenta) << "| " << setw(10) << left << "Amount";
		cout << clsColor::ColorRGB(clsColor::Red) << "| " << setw(10) << left << "S.Balance";
		cout << clsColor::ColorRGB(clsColor::Green) << "| " << setw(10) << left << "D.Balance";
		cout << clsColor::ColorRGB(clsColor::Yellow) << "| " << setw(10) << left << "UserName\n";
		cout << clsColor::ColorRGB(clsColor::LemonYellow) << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n\n";

		if (vTransfersLogRecords.size() == 0)
			cout << clsColor::ColorRGB(clsColor::Lime) << clsUtility::Tabs(6) << "No Records Available In the System!";

		else
		{
			for (clsClient::strTransferLogRecord& R : vTransfersLogRecords)
			{
				clsClientUI::PrintTransferLogRecord(R);
			}
		}


		cout << clsColor::ColorRGB(clsColor::LemonYellow) << clsUtility::Tabs(2) << "___________________________________________________________________________________________________________\n";
	}
};