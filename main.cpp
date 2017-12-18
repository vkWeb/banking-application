using namespace std;

/*
Following latest C++ Standard and Using Latest header files provided by MingGW.
*/
//Header files
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

//Structures for Initializing datamembers
struct profile_details
{
    string username; //bank operator's name
    string pass;
    string email;
} profile;

//global variables
char name[32]; //customer's name

//function declarations
int random_num(); //random balance generator
char confirm(char a); //confirmation screen for yes, no and quit
char checker(char a); //back button checker
void welcome_screen(profile_details profile);
void home_screen();
void customer();
void valid_acc_num(long a);
void loan();
void Care();
void Transaction();

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
    char a;
    cout << "\t\t\t\t\t\t\t\t\tWelcome Employee!\n\t\t\t\t\t\tBanking Humantics Version 1.0 By Yash, Sukhprit Paaji and Vivek.";
    cout << "\n------------";
    cout << "\nInstructions:";
    cout << "\n------------";
    cout << "\n• Here, you'll be setting up your profile as a banking officer.\n• Your username can consist of alphanumeric characters and your Password must be atleast 6 characters long.\n• Fields marked with '*' are necessary. \n• IMPORTANT: Strictly Follow the ethics of datatypes otherwise you'll be punished with a crash of the whole system.";
    cout << "\n\n-> Enter User name*: ";
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
    cout << "\n-> You won't be able to change the user name or password later due to security reasons corporated by SBI systems. Are you sure you want to continue? Press ['Y'] to continue OR ['N'] to re-enter the details OR ['Q'] to quit: ";
    cin >> a;
    if ((confirm(a) == 'y') || (confirm(a) == 'Y'))
    {
        cout << "\nVerifying Your Details...\nNow, You're ready to go :) \n-> Press ['Enter'] to continue." << endl;
        cin.ignore();
        cin.ignore();
    }
    else if ((confirm(a) == 'n') || (confirm(a) == 'N'))
    {
        welcome_screen(profile);
    }
    else
    {
        exit(0);
    }
}

//home_screen function()
void home_screen()
{
    system("clear");
    char a;
    bool test = true;
    cout << "\t\t\t\t\t\t\t\t\tHome Screen\n\t\t\t\t\tBanking Humantics Version 1.0 By Yash, Sukhprit Paaji and Vivek.";
    cout << "\n------------";
    cout << "\nInstructions:";
    cout << "\n------------";
    cout << "\n• This is your Home Screen where you'll be carrying out all your work.\n• There are different sections of services you can work with.\n• To select a particular service press the mentioned 'numeral' key and then to select an option press the mentioned 'alphabetical' key.\n• Here's a quick example, to open a new account. You'll have to press '1' and then 'a'.";

    cout << "\n\n\n1. Customer Centric Services: \t\t\t2. Transaction Services:";
    cout << "\na) Open an bank account. \t\t\ta) Fund transfer to one of your own accounts.";
    cout << "\nb) Close a bank account. \t\t\tb) Fund transfer to another account of same bank - Intra Banking Transfer.";
    cout << "\nc) Get your Account statement or balance. \tc) Fund transfer to another account of different bank - Inter Banking Transfer.";

    cout << "\n\n3. Loan Services: \t\t\t\t4.Customer Care, Support and Helpdesk: ";
    cout << "\na) Startup Buisness Loan.\t\t\ta)Account issues.";
    cout << "\nb) Loan for girl education.\t\t\tb)Debit or Credit Card issues.";
    cout << "\nc) Loan for farmers. \t\t\t\tc)Net banking issues.";
    cout << "\nd) Indian citizen loan. \t\t\td)Other support.";
    cout << "\n\n-> Please enter your choice between ['1'] to ['4'] OR ['Q'] to Quit: ";

    do
    {
        cin >> a;

        test = (((a == 'q') || (a == 'Q')) || ((a >= '1') && (a <= '4'))) ? true : false;
        if (test == false)
        {
            cout << "Re-enter your choice between 1 to 4 OR ['Q'].";
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
        Transaction();
        break;
    }
    case '3':
    {
        loan();
        break;
    }
    case '4':
    {
        Care();
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
    cout << "\n\n-> Please enter your choice between 'a', 'b' or 'c' OR Press ['H'] to go back to the home screen: ";
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
        long b;
        cout << "• To open a bank account you'll need to provide your name, age, date of birth and aadhar card details.";
        cout << "\n-> Enter your name: ";
        gets(name);
        gets(name);
        cout << "\n-> Enter your age: ";
        cin >> a;
        cout << "\n-> Enter your DOB: ";
        cin >> a;
        cout << "\n-> Enter your aadhar card number: ";
        cin >> b;
        valid_acc_num(b);
        cout << "\nAccount created. You'll get the details along with your passbook delivered to the registered address in your aadhar card within few days.";
        break;
    }

    case 'b':
    {
        long num = 0;
        cout << "\nEnter your account number: ";
        cin >> num;
        valid_acc_num(num);
        cout << "\n:( Account Closed!";
        break;
    }

    case 'c':
    {
        long num = 0;
        cout << "Enter your account number: ";
        cin >> num;
        valid_acc_num(num);
        cout << "\nBalance = " << random_num();
        break;
    }

    default:
        cout << "\nSomething looks wrong. We're shifting you to the homescreen.";
        home_screen();
    }

    cout << "\n\n\nPress ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
    cin >> a;
    if (checker(a) == 'A' || checker(a) == 'a')
    {
        customer();
    }
    else
    {
        home_screen();
    }
}

void loan()
{
    system("clear");
    char a;
    bool test = true;
    cout << "\n3. Loan Services: ";
    cout << "\na) Startup Buisness Loan.";
    cout << "\nb) Loan for girl education.";
    cout << "\nc) Loan for farmers.";
    cout << "\nd) Indian citizen loan.";
    cout << "\n\n-> Please enter your choice between 'a', 'b', 'c' or 'd' OR Press ['H'] to go back to the home screen: ";
    cin >> a;
    if (a == 'h' || a == 'H')
    {
        home_screen();
    }

    do
    {
        test = (a >= 'a' && a <= 'd') ? true : false;
        if (test == false)
        {
            cout << "\nRe-enter your choice between 'a' to 'd': ";
            cin >> a;
        }
    } while (test == false);

    switch (a)
    {
    case 'a':
    {
        string acc;
        cout << "\n\n• Loan Scheme: Startup Loan.";
        cout << "\n• Interest: 6% compounded anually.";
        cout << "\n• Time Period: Strictly three years.";
        cout << "\n• Penalty: No Penalty for the first three years according to Startup India Initiative.";
        cout << "\n• Formalities Required: Your business documents.";
        cout << "\n\n-> Do you agree with the above terms? Press ['Y'] for Yes OR ['N'] for No OR ['H'] to go back to the home screen: ";
        cin >> a;
        if (a == 'h' || a == 'H')
        {
            home_screen();
        }
        else if (a == 'y' || a == 'Y')
        {
            long num = 0;
            double amt;
            cout << "\n\nEnter your account number: ";
            cin >> num;
            valid_acc_num(num);
            cout << "\nEnter the amount of loan: ";
            cin >> amt;
            cout << "\nAmount to be paid back within 3 years: Rs. " << amt * pow(1.06, 3);
            cout << "\n-> Press ['Y'] to confirm OR ['N'] to cancel, cancelling will shift you to the homescreen: ";
            cin >> a;
            if ((confirm(a) == 'y') || (confirm(a) == 'Y'))
            {
                cout << "\nLoan of Rs. " << amt << " transferred to your account!";
            }
            else
            {
                cout << "\n\nShifting you to the homescreen.";
                home_screen();
            }
        }
        else
        {
            cout << "\n\nShifting you to the homescreen.";
            home_screen();
        }

        break;
    }

    case 'b':
    {
        string acc;
        cout << "\n\n• Loan Scheme: Girl Education.";
        cout << "\n• Interest: No Interest.";
        cout << "\n• Time Period: Five years.";
        cout << "\n• Penalty: No Penalty.";
        cout << "\n• Formalities Required: Your aaadhar card and school documents.";
        cout << "\n\n-> Do you agree with the above terms? Press ['Y'] for Yes OR ['N'] for No OR ['H'] to go back to the home screen: ";
        cin >> a;
        if (a == 'h' || a == 'H')
        {
            home_screen();
        }
        else if (a == 'y' || a == 'Y')
        {
            long num = 0;
            double amt;
            cout << "\n\nEnter your account number: ";
            cin >> num;
            valid_acc_num(num);
            cout << "\nEnter the amount of loan: ";
            cin >> amt;
            cout << "\nAmount to be paid back within 5 years: Rs. " << amt;
            cout << "\n-> Press ['Y'] to confirm OR ['N'] to cancel, cancelling will shift you to the homescreen: ";
            cin >> a;
            if ((confirm(a) == 'y') || (confirm(a) == 'Y'))
            {
                cout << "\nLoan of Rs. " << amt << " transferred to your account!";
            }
            else
            {
                cout << "\n\nShifting you to the homescreen.";
                home_screen();
            }
        }
        else
        {
            cout << "\n\nShifting you to the homescreen.";
            home_screen();
        }
        break;
    }

    case 'c':
    {
        string acc;
        cout << "\n\n• Loan Scheme: Farmers Loan.";
        cout << "\n• Interest: 4.5% Simple interest.";
        cout << "\n• Time Period: Two years.";
        cout << "\n• Penalty: No Penalty.";
        cout << "\n• Formalities Required: Your land documents and PAN/aaadhar card.";
        cout << "\n\n-> Do you agree with the above terms? Press ['Y'] for Yes OR ['N'] for No OR ['H'] to go back to the home screen: ";
        cin >> a;
        if (a == 'h' || a == 'H')
        {
            home_screen();
        }
        else if (a == 'y' || a == 'Y')
        {
            long num = 0;
            double amt;
            cout << "\n\nEnter your account number: ";
            cin >> num;
            valid_acc_num(num);
            cout << "\nEnter the amount of loan: ";
            cin >> amt;
            cout << "\nAmount to be paid back within 2 years: Rs. " << amt + ((amt * 4.5 * 2) / 100);
            cout << "\n-> Press ['Y'] to confirm OR ['N'] to cancel, cancelling will shift you to the homescreen: ";
            cin >> a;
            if ((confirm(a) == 'y') || (confirm(a) == 'Y'))
            {
                cout << "\nLoan of Rs. " << amt << " transferred to your account!";
            }
            else
            {
                cout << "\n\nShifting you to the homescreen.";
                home_screen();
            }
        }
        else
        {
            cout << "\n\nShifting you to the homescreen.";
            home_screen();
        }

        break;
    }

    case 'd':
    {
        string acc;
        cout << "\n\n• Loan Scheme: Citizens Loan.";
        cout << "\n• Interest: 8% compound interest.";
        cout << "\n• Time Period: Three years.";
        cout << "\n• Penalty: No Penalty.";
        cout << "\n• Formalities Required: PAN/aaadhar card.";
        cout << "\n\n-> Do you agree with the above terms? Press ['Y'] for Yes OR ['N'] for No OR ['H'] to go back to the home screen: ";
        cin >> a;
        if (a == 'h' || a == 'H')
        {
            home_screen();
        }
        else if (a == 'y' || a == 'Y')
        {
            long num = 0;
            double amt;
            cout << "\n\nEnter your account number: ";
            cin >> num;
            valid_acc_num(num);
            cout << "\nEnter the amount of loan: ";
            cin >> amt;
            cout << "\nAmount to be paid back within 2 years: Rs. " << amt * pow(1.08, 3);
            cout << "\n-> Press ['Y'] to confirm OR ['N'] to cancel, cancelling will shift you to the homescreen: ";
            cin >> a;
            if ((confirm(a) == 'y') || (confirm(a) == 'Y'))
            {
                cout << "\nLoan of Rs. " << amt << " transferred to your account!";
            }
            else
            {
                cout << "\n\nShifting you to the homescreen.";
                home_screen();
            }
        }
        else
        {
            cout << "\n\nShifting you to the homescreen.";
            home_screen();
        }
        break;

        break;
    }

    default:
        cout << "\nSomething looks wrong. We're shifting you to the homescreen.";
        home_screen();
    }

    cout << "\n\n\nPress ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
    cin >> a;
    if (checker(a) == 'A' || checker(a) == 'a')
    {
        loan();
    }
    else
    {
        home_screen();
    }
}

void Care()
{
    bool test = true;
    char a;
    system("clear");
    cout << "\n\n4.Customer Care, Support and Helpdesk: ";
    cout << "\na)Account issues.";
    cout << "\nb)Debit or Credit Card issues.";
    cout << "\nc)Net banking issues.";
    cout << "\nd)Other support.";
    cout << "\n\n-> Please enter your choice between 'a', 'b', 'c' or 'd' OR Press ['H'] to go back to the home screen: ";
    cin >> a;
    if (a == 'h' || a == 'H')
    {
        home_screen();
    }

    do
    {
        test = (a >= 'a' && a <= 'd') ? true : false;
        if (test == false)
        {
            cout << "\nRe-enter your choice between 'a' to 'd': ";
            cin >> a;
        }
    } while (test == false);

    switch (a)
    {
    case 'a':
    {
        cout << "\n• Contact us here: customercare@sbi.co.in\n• Call us at: 1800-895-0210.";
        break;
    }
    case 'b':
    {
        cout << "\n• Contact us here: customercare@sbi.co.in\n• You can also contact your nearest police station.";
        break;
    }
    case 'c':
    {
        cout << "\n• Contact us here: customercare@sbi.co.in\n• You can also talk to our helpline: 1800-895-0210.";
        break;
    }
    case 'd':
    {
        cout << "\n• Contact us here: customercare@sbi.co.in";
        break;
    }
    default:
        cout << "Something looks wrong.";
        home_screen();
    }

    cout << "\n\n\nPress ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
    cin >> a;
    if (checker(a) == 'A' || checker(a) == 'a')
    {
        Care();
    }
    else
    {
        home_screen();
    }
}

void Transaction()
{
    bool test = true;
    char a;
    system("clear");
    cout << "2. Transaction Services:";
    cout << "\na) Fund transfer to one of your own accounts.";
    cout << "\nb) Fund transfer to another account of same bank - Intra Banking Transfer.";
    cout << "\nc) Fund transfer to another account of different bank - Inter Banking Transfer.";

    cout << "\n\n-> Please enter your choice between 'a', 'b' or 'c' OR Press ['H'] to go back to the home screen: ";
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
            cout << "\nRe-enter your choice between 'a' to 'c': ";
            cin >> a;
        }
    } while (test == false);

    switch (a)
    {
    case 'a':
    {
        int amt;
        long num = 0;
        cout << "\n-> Enter your account number: ";
        cin >> num;
        valid_acc_num(num);
        cout << "\n-> Enter the account number of one of your own account: ";
        cin >> num;
        valid_acc_num(num);
        cout << "\n-> Enter the amount you wish to transfer: ";
        cin >> amt;
        cout << "Amount of Rs. " << amt << " transferred to " << num << ".";
        break;
    }
    case 'b':
    {
        int amt;
        long num = 0;
        cout << "\n-> Enter your account number: ";
        cin >> num;
        valid_acc_num(num);
        cout << "\n-> Enter the account number of the same bank you wish to transfer money: ";
        cin >> num;
        valid_acc_num(num);
        cout << "\n-> Enter the amount you wish to transfer: ";
        cin >> amt;
        cout << "Amount of Rs. " << amt << " transferred to " << num << ".";
        break;
    }
    case 'c':
    {
        int amt;
        long num = 0;
        cout << "\n-> Enter your account number: ";
        cin >> num;
        valid_acc_num(num);
        cout << "\n-> Enter the account number of the different bank you wish to transfer money: ";
        cin >> num;
        valid_acc_num(num);
        cout << "\n-> Enter the amount you wish to transfer: ";
        cin >> amt;
        cout << "Amount of Rs. " << amt << " transferred to " << num << ".";
        break;
    }
    default:
        cout << "Something looks wrong.";
        home_screen();
    }

    cout << "\n\n\nPress ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
    cin >> a;
    if (checker(a) == 'A' || checker(a) == 'a')
    {
        Transaction();
    }
    else
    {
        home_screen();
    }
}

char checker(char a)
{
    int count = 0;
    do
    {
        if (count > 0)
        {
            cout << "\nSorry, Wrong Input Received! Press ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
            cin >> a;
        }
        count++;
    } while ((a != 'a' && a != 'A') && (a != 'h' && a != 'H'));
    return a;
}

void valid_acc_num(long a)
{
    int digit = 0;
    do
    {
        while (a > 0)
        {
            a = (a / 10);
            digit++;
        }
        if (digit < 10)
        {
            cout << "\nNote: Your Input must be atleast 10 numerals long: ";
            cin >> a;
        }
    } while (digit < 10);
}

char confirm(char a)
{
    int count = 0;
    do
    {
        if (count > 0)
        {
            cout << "\nSorry, Wrong Input Received! Press ['Y'] to continue OR ['N'] to re-enter the details OR ['Q'] to quit: ";
            cin >> a;
        }
        count++;
    } while ((a != 'y' && a != 'Y') && (a != 'n' && a != 'N') && (a != 'q' && a != 'Q'));
    return a;
}

int random_num()
{
    int no_of_nums = 100000;
    int first_num = 1000;

    int random = rand() % no_of_nums + first_num;

    return random;
}
