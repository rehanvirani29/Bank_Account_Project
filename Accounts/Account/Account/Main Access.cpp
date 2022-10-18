#include<iostream>
#include <fstream>
#include <string>
#include <filesystem>
using std::string;
using std::cout;
using std::cin;
using std::ios;
using std::endl;
using std::ofstream;


class account_options {
private:
	

public:
	int record_number=1;

	void new_account();
	void view_accounts();

};

void account_options::new_account()
{

	string filename; // name of record to create
	string filename_complete; // name of complete file name with .txt to add to master record
	cout << "Enter name of new file to create no spaces please!" << endl;
	cin >> filename;
	filename_complete = filename + ".txt"; //Complete file name is temp generated to be added to master record
	
	ofstream outfile;
	outfile.open(filename + ".txt", ios::binary | ios::app);
	/*
	Here is code for information to be added to file
	
	*/
	outfile.close();

	outfile.open("Master_Record.txt", ios::app);
	outfile << filename_complete << endl;
	outfile.close();

}

void account_options::view_accounts()
{


}

int main()

{
	int option;
	account_options A;

	cout << "Welcome to the record sysem. There are may differnt ";
	cout << "actions that can be done. Please select one of the following" << endl;
	cout << "1: Create new account" << endl;
	cout << "2: View Accounts" << endl;
	cout << "5: Exit System" << endl;
	cin >> option;

	switch (option) {
	case 1:
		A.new_account();
		break;
	case 2:
		A.view_accounts();
		break;
	case 3:

		break;
	case 4:

		break;
	case 5:
		exit(0);
		break;
	default:
		cout << "\nEnter corret choice";
		exit(0);
	}




}