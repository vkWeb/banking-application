using namespace std;

//Header files
#include <iostream>
#include <string>
#include <cstdlib>

//Structures for Initializing datamembers
struct profile_details
{
    string username;
    string pass;
    string email;
} profile;

//global variables
char name[32];

//function declarations
void welcome_screen(profile_details profile);
void home_screen();
void customer();
void goToHomeScreen();
void valid_acc_num(string a);

/*
-------------------------------------------------------------------------------------------------------------------
                                        Start of main() fucntion                                              
-------------------------------------------------------------------------------------------------------------------
*/

int main()
{
    system("clear");
    welcome_screen(profile);
    home_screen();
    return 0;
}

//welcome screen
void welcome_screen(profile_details profile)
{
    system("clear");
    int count = 0;
    cout << "\t\t\t\t\t\t\t\t\t Welcome!\n\t\t\t\t\t\t\t\tBanking Humantics Version 1.0";
    cout << "\n------------";
    cout << "\nInstructions:";
    cout << "\n------------";
    cout << "\n• Here, you'll be setting up your profile as a banking officer.\n• Your username can consist of alphanumeric characters and your Password must be atleast 6 characters long.\n• Fields marked with '*' are necessary.";
    cout << "\n\n-> Enter Username*: ";
    cin >> profile.username;
    cout << "-> Enter Password*: ";

    do
    {
        if (count > 0)
        {
            cout << ":( Sorry! Your Password must be atleast six characters, please try again: ";
        }
        cin >> profile.pass;
        count++;
    } while (profile.pass.length() < 6);

    cout << "-> Enter Email Address*: ";
    cin >> profile.email;
    cout << "\nVerifying your details...\nNow, You're ready to go :) \n-> Press 'Enter' to continue." << endl;
    cin.ignore();
    cin.ignore();
}

//home_screen function()
void home_screen()
{
    system("clear");
    char a;
    bool test = true;
    cout << "\t\t\t\t\t\t\t\t\t Home Screen\n\t\t\t\t\t\t\t\tBanking Humantics Version 1.0";
    cout << "\n------------";
    cout << "\nInstructions:";
    cout << "\n------------";
    cout << "\n• This is your Home Screen where you'll be carrying out all your work.\n• There are different sections of services you can work with.\n• To select a particular service press the mentioned 'numeral' key and then to select an option press the mentioned 'alphabetical' key.\n• Here's a quick example, to open a new account. You'll have to press '1' and then 'a'.";

    cout << "\n\n\n1. Customer Centric Services: \t\t\t2. Transaction Services:";
    cout << "\na) Open an bank account. \t\t\ta) Fund transfer to one of your own accounts.";
    cout << "\nb) Close a bank account. \t\t\tb) Fund transfer to another account of same bank - Intra Banking Transfer.";
    cout << "\nc) Get your Account statement or balance. \tc) Fund transfer to another account of same bank - Intra Banking Transfer.";
    cout << "\n\t\t\t\t\t\td) Fund transfer to another account of different bank - Inter Banking Transfer.";

    cout << "\n\n3. Loan Services: \t\t\t\t4.Customer Care, Support and Helpdesk: ";
    cout << "\na) Startup Buisness Loan.\t\t\ta)Account issues.";
    cout << "\nb) Loan for girl education.\t\t\tb)Debit or Credit Card issues.";
    cout << "\nc) Loan for farmers. \t\t\t\tc)Net banking issues.";
    cout << "\nd) Indian citizen loan. \t\t\td)Other support.";
    cout << "\n\n-> Please enter your choice between '1' to '4' OR 'Q' to Quit: ";

    do
    {
        cin >> a;

        test = (((a == 'q') || (a == 'Q')) || ((a >= '1') && (a <= '4'))) ? true : false;
        if (test == false)
        {
            cout << "Re-enter your choice between 1 to 4 OR 'Q'.";
        }
    } while (test == false);

    switch (a)
    {
    case '1':
    {
        customer();
        break;
    }
    case '2':
    {
        cout << "test: working case 2!";
        break;
    }
    case '3':
    {
        cout << "test: working case 3!";
        break;
    }
    case '4':
    {
        cout << "test: working case 4!";
        break;
    }
    case 'q':
    {
        exit(0);
        break;
    }
    case 'Q':
    {
        exit(0);
        break;
    }
    default:
        cout << "Something looks wrong.";
        home_screen();
    }
}

void customer()
{
    system("clear");
    char a;
    bool test = true;
    cout << "1. Customer Centric Services: ";
    cout << "\na) Open an bank account.";
    cout << "\nb) Close a bank account.";
    cout << "\nc) Get your Account statement or balance.";
    cout << "\n\n-> Please enter your choice between 'a', 'b' or 'c': ";
    cout << "\nOR Press 'H' to go back to the home screen.";
    cout << endl;
    cin >> a;
    if (a == 'h' || a == 'H')
    {
        home_screen();
    }

    do
    {
        test = (a >= 'a' && a <= 'c') ? true : false;
        if (test == false)
        {
            cout << "Re-enter your choice between 'a' to 'c': ";
            cin >> a;
        }
    } while (test == false);

    switch (a)
    {
    case 'a':
    {
        int a;
        cout << "• To open a bank account you'll need to provide your name, age, date of birth and addhar card details.";
        cout << "\n-> Enter your name: ";
        gets(name);gets(name);
        cout << "\n-> Enter your age: ";
        cin >> a;
        cout << "\n-> Enter your DOB: ";
        cin >> a;
        cout << "\n-> Enter your adhar card number: ";
        cin >> a;
        cout << "\nAccount created. You'll get the details along with your passbook delivered to the registered address in your adhar card within few days.";
        break;
    }

    case 'b':
    {
        string num;
        cout << "Enter your account number: ";
        getline(cin, num);
        valid_acc_num(num);
        cout << "\n:( Account Closed!";
        break;
    }

    case 'c':
    {
        string num;
        cout << "Enter your account number: ";
        getline(cin, num);
        valid_acc_num(num);
        double bal = rand() % 10 + 50000;
        cout << "\nBalance = " << bal;
        break;
    }

    default:
        cout << "Something looks wrong. We're shifting you to homescreen.";
        home_screen();
    }

    cout << "\nPress 'H' to go back to the home screen:";
    goToHomeScreen();
}

void goToHomeScreen()
{
    char a;
    bool test = true;
    do
    {
        cin >> a;
        if (a == 'h' || a == 'H')
        {
            home_screen();
        }
        else
        {
            test = false;
            cout << "Wrong input received. Press 'H' to go straight onto the Home Screen.";
        }
    } while (test == false);
}

void valid_acc_num(string a)
{
    do
    {
        if ((a.length()) < 9)
        {
            cout << "\nAccount Number must be atleast 10 numerals long:";
            cin >> a;
        }
    } while ((a.length()) < 9);
}