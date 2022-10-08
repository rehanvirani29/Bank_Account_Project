
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::ofstream;
using std::ios;

class account_query
{
private:
    char account_number[20];
    char firstName[10];
    char lastName[10];
    float total_Balance;
public:
    void read_data();
    void write_rec();
};


void account_query::read_data()
{
    cout << "\nEnter Account Number: ";
    cin >> account_number;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Balance: ";
    cin >> total_Balance;
    cout << "\n";
}

void account_query::write_rec()
{
    ofstream outfile;
    outfile.open("record.bank", ios::binary | ios::app);
    read_data();
    outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outfile.close();
}
int main()
{
    account_query A;

    int choice;
    cout << "Welcome to the Bank of Virani!\n";

    while (true)
    {
        cout << "Please select one of the options below.\n";
        cout << "1-->Add record to file\n";
        cout << "2-->Quit\n";
        cout << "Enter your choice: \n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            A.write_rec();
            break;
        case 2:
            exit(0);
            break;
        }
    }
}



