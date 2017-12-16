using namespace std;

//Included files
#include <iostream>
#include <string>
#include <cstdlib>

//structures and objects
struct profile_details
{
    string username;
    string pass;
    string email;
} profile;

//function declarations
void welcome_screen(profile_details profile);
void main_screen(profile_details profile);

//start main()
int main()
{
    //welcome_screen(profile);
    main_screen(profile);
    return 0;
}

//welcome screen
void welcome_screen(profile_details profile)
{
    int count = 0;
    cout << "\t\t\t\t\t\t\t\t\t Welcome!\n\t\t\t\t\t\t\t\tBanking Humantics Version 1.0";
    cout << "\n------------";
    cout << "\nInstructions:";
    cout << "\n------------";
    cout << "\n-> Here, you'll be setting up your profile as a banking officer.\n-> Your username can consist of alphanumeric characters and your Password must be atleast 6 characters long.\n-> Fields marked with '*' are necessary.";
    cout << "\n\n\n1. Enter Your Username*: ";
    cin >> profile.username;
    cout << "\n2. Enter Your Password*: ";

    do
    {
        if (count > 0)
        {
            cout << ":( Sorry! Your Password must be atleast six characters, please try again: ";
        }
        cin >> profile.pass;
        count++;
    } while (profile.pass.length() < 6);

    cout << "\n3. Enter Your Email Address*: ";
    cin >> profile.email;
    cout << "\n\nVerifying details...Now, you're ready to go! Please, Press 'Enter' to continue." << endl;
    cin.ignore();
    cin.ignore();
    system("clear");
}

//main_screen function()
void main_screen(profile_details profile)
{
    cout << "\t\t\t\t\t\t\t\t\t Home Screen\n\t\t\t\t\t\t\t\tBanking Humantics Version 1.0";
    cout << "\n------------";
    cout << "\nInstructions:";
    cout << "\n------------";
    cout << "\n-> This is your Home Screen where you'll be carrying out all your work.\n-> There are different sections of services you can work with.\n-> To select a particular service press the mentioned 'numeral' key and then to select an option press the mentioned 'alphabetical' key.\n-> Here's a quick example, to open a new account. You'll have to press '1' and then 'a'.";

    cout << "\n\n\n1. Customer Centric Services: \t\t\t2. Transaction Services:";
    cout << "\na) Open an bank account. \t\t\ta) Fund transfer to one of your own accounts.";
    cout << "\nb) Close a bank account. \t\t\tb) Fund transfer to another account of same bank - Intra Banking Transfer.";
    cout << "\nc) Get your Account statement. \t\t\tc) Fund transfer to another account of same bank - Intra Banking Transfer.";
    cout << "\n\t\t\t\t\t\td) Fund transfer to another account of different bank - Inter Banking Transfer.";

    cout << "\n\n3. Loan Services: \t\t\t\t4.Customer Care, Support and Helpdesk: ";
    cout << "\na) Startup Buisness Loan.\t\t\ta)Account issues.";
    cout << "\nb) Loan for girl education.\t\t\tb)Debit or Credit Card issues.";
    cout << "\nc) Loan for farmers. \t\t\t\tc)Net banking issues.";
    cout << "\nd) Indian citizen loan. \t\t\td)Other support.";
}