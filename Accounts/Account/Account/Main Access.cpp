#include<iostream>
#include <fstream>
#include <string>
#include <filesystem>
using std::string;
using std::to_string;
using std::cout;
using std::cin;
using std::ios;
using std::endl;
using std::ofstream;
using std::ifstream;


class account_options {
private:
	

public:
	int record_number;

	void new_account();
	void view_accounts();
	void exit();

};

void account_options::new_account()
{
	ifstream check_file;
	check_file.open("Master_Record.txt");
	if(!check_file){
		record_number = 0;
	}
	


	string filename; // name of record to create
	string filename_complete; // name of complete file name with .txt to add to master record
	string record_number_string = to_string(record_number);
	cout << "Enter name of new file to create no spaces please!" << endl;
	cin >> filename;
	filename_complete = record_number_string+  ": " + filename + ".txt"; //Complete file name is temp generated to be added to master record
	
	ofstream outfile;
	outfile.open(filename + ".txt", ios::binary | ios::app);
	/*
	
	Here is code for information to be added to file
	
	*/
	outfile.close();

	outfile.open("Master_Record.txt", ios::app);
	outfile << filename_complete << endl;
	outfile.close();

	record_number++ ;
}

void account_options::view_accounts()
{


}


void account_options::exit()
{


}

int main()

{
	int option;
	account_options A;

	while (bool loop = true) {

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
			A.exit();
			exit(0);
			loop = false;
			break;
		default:
			cout << "\nEnter corret choice";

		}

	}


}