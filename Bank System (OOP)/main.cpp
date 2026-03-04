#include <iostream>
#include "clsClient.h"

using namespace std;

int main()
{

	clsClient Client1 = clsClient::Find("A10");
	Client1.Print();

	clsClient Client2 = clsClient::Find("A1011");
	Client2.Print();

	cout << clsClient::IsClientExist("A10") << endl;
	

	return 0;
}