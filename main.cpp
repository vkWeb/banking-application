using namespace std;

/*
Date: 20/12/17.

            OBJECTIVES                                                        STATUS

1. Refactor the whole source code.                                    On the way - 20% Done.
2. Document the code.                                                 On the way - 10% Done.
3. Resolve homescreen bug.                                                  Not Started.
4. Changing the whole Input mechanism.                                    Not Started.
5. Add password protection in transactions.                               Not Started.
*/

//Header files
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

//Structures for Initializing datamembers
struct ProfileDetails
{
    string username; //Bank operator's name
    string pass;     //Bank operator's password
    string email;    //Bank operator's email
} Profile;

//Global datamembers
char Input;         //For Accepting user input used throughout the code.
int Counter;        //Act as a counter of loops.
long AccountNumber; //For Accepting account number used throughout the code.

//Function declarations
void WelcomeScreen(ProfileDetails Profile);
void HomeScreen();
void Customer();
void Transaction();
void Loan();
void Care();

int RandomBalance();              //Random balance generator
char Confirm(char GetInput);      //Confirmation screen for yes, no, quit and home.
char BackCheck(char GetInput);    //Back button checker for quit and home only.
void ValidAccNum(long GetAccNum); //Account number validator

/* Start of main() */
int main()
{
    system("clear");

    //Initializing datamembers to zero for reducing chances of bugs.
    Counter = Input = AccountNumber = 0;

    WelcomeScreen(Profile);
    HomeScreen();
    return 0;
}

//Welcome Screen - The screen user interacts with for the first time.
void WelcomeScreen(ProfileDetails Profile)
{
    system("clear");
    cout << "\t\t\t\t\t\t\t\t\tWelcome Employee!\n\t\t\t\t\t\tBanking Humantics Version 1.0 By Yash, Sukhprit Paaji and Vivek.";
    cout << "\n------------";
    cout << "\nInstructions:";
    cout << "\n------------";
    cout << "\n• Here, you'll be setting up your profile as a banking officer.\n• Your username can consist of alphanumeric characters and your Password must be atleast 6 characters long.\n• Fields marked with '*' are necessary. \n• IMPORTANT: Strictly Follow the ethics of datatypes otherwise you'll be punished with a crash of the whole system.";
    cout << "\n\n-> Enter Username*: ";
    cin >> Profile.username;
    cout << "-> Enter Password*: ";

    //Password validator - makes sure that there are six characters in the password.
    do
    {
        if (Counter > 0)
        {
            cout << ":( Sorry! Your Password must be atleast six characters, please try again: ";
        }
        cin >> Profile.pass;
        Counter++;
    } while (Profile.pass.length() < 6);
    Counter = 0;

    cout << "-> Enter Email Address*: ";
    cin >> Profile.email;
    cout << "\n-> You won't be able to change the user name or password later due to security reasons corporated by SBI systems. Are you sure you want to continue? Press ['Y'] to continue OR ['N'] to re-enter the details OR ['Q'] to quit: ";
    cin >> Input;

    //Validating user input.
    if ((Confirm(Input) == 'y') || (Confirm(Input) == 'Y'))
    {
        cout << "\nYou're ready to go :) \n-> Press ['Enter'] to continue.";
        cin.ignore();
        cin.ignore();
    }
    else if ((Confirm(Input) == 'n') || (Confirm(Input) == 'N'))
    {
        WelcomeScreen(Profile);
    }
    else
    {
        exit(0);
    }
}

//HomeScreen function()
void HomeScreen()
{
    system("clear");

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

    cout << "\n\n3. Loan Services: \t\t\t\t4. Customer Care, Support and Helpdesk: ";
    cout << "\na) Startup Buisness Loan.\t\t\ta) Account issues.";
    cout << "\nb) Loan for girl education.\t\t\tb) Debit or Credit Card issues.";
    cout << "\nc) Loan for farmers. \t\t\t\tc) Net banking issues.";
    cout << "\nd) Indian citizen loan. \t\t\td) Other support.";
    cout << "\n\n-> Please enter your choice between ['1'] to ['4'] OR ['Q'] to Quit: ";

    //Validating user input and prompting if input is wrong.
    do
    {
        cin >> Input;

        test = (((Input == 'q') || (Input == 'Q')) || ((Input >= '1') && (Input <= '4'))) ? true : false;
        if (test == false)
        {
            cout << "-> Wrong Input Received! Please Re-enter your choice between ['1'] to ['4'] OR ['Q'] to Quit:";
        }
    } while (test == false);

    switch (Input)
    {
    case '1':
    {
        Customer();
        break;
    }
    case '2':
    {
        Transaction();
        break;
    }
    case '3':
    {
        Loan();
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
        HomeScreen();
    }
}

void Customer()
{
    system("clear");
    bool test = true;
    cout << "1. Customer Centric Services: ";
    cout << "\na) Open an bank account.";
    cout << "\nb) Close a bank account.";
    cout << "\nc) Get your Account statement or balance.";
    cout << "\n\n-> Please enter your choice between 'a', 'b' or 'c' OR Press ['H'] to go back to the home screen: ";
    cin >> Input;
    if (Input == 'h' || Input == 'H')
    {
        HomeScreen();
    }

    do
    {
        test = (Input >= 'a' && Input <= 'c') ? true : false;
        if (test == false)
        {
            cout << "Re-enter your choice between 'a' to 'c': ";
            cin >> Input;
        }
    } while (test == false);

    switch (Input)
    {
    case 'a':
    {
        string name; //customer's name
        cout << "• To open a bank account you'll need to provide your name, age, date of birth and aadhar card details.";
        cout << "\n-> Enter your name: ";
        getline(cin, name);
        cout << "\n-> Enter your age: ";
        cin >> Input;
        cout << "\n-> Enter your DOB: ";
        cin >> Input;
        cout << "\n-> Enter your aadhar card number: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\nAccount created. You'll get the details along with your passbook delivered to the registered address in your aadhar card within few days.";
        break;
    }

    case 'b':
    {
        cout << "\nEnter your account number: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n:( Account Closed!";
        break;
    }

    case 'c':
    {
        cout << "Enter your account number: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\nBalance = " << RandomBalance();
        break;
    }

    default:
        cout << "\nSomething looks wrong. We're shifting you to the homescreen.";
        HomeScreen();
    }

    cout << "\n\n\nPress ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
    cin >> Input;
    if (BackCheck(Input) == 'A' || BackCheck(Input) == 'a')
    {
        Customer();
    }
    else
    {
        HomeScreen();
    }
}

void Loan()
{
    system("clear");
    bool test = true;
    cout << "\n3. Loan Services: ";
    cout << "\na) Startup Buisness Loan.";
    cout << "\nb) Loan for girl education.";
    cout << "\nc) Loan for farmers.";
    cout << "\nd) Indian citizen loan.";
    cout << "\n\n-> Please enter your choice between 'a', 'b', 'c' or 'd' OR Press ['H'] to go back to the home screen: ";
    cin >> Input;
    if (Input == 'h' || Input == 'H')
    {
        HomeScreen();
    }

    do
    {
        test = (Input >= 'a' && Input <= 'd') ? true : false;
        if (test == false)
        {
            cout << "\nRe-enter your choice between 'a' to 'd': ";
            cin >> Input;
        }
    } while (test == false);

    switch (Input)
    {
    case 'a':
    {
        cout << "\n\n• Loan Scheme: Startup Loan.";
        cout << "\n• Interest: 6% compounded anually.";
        cout << "\n• Time Period: Strictly three years.";
        cout << "\n• Penalty: No Penalty for the first three years according to Startup India Initiative.";
        cout << "\n• Formalities Required: Your business documents.";
        cout << "\n\n-> Do you agree with the above terms? Press ['Y'] for Yes OR ['N'] for No OR ['H'] to go back to the home screen: ";
        cin >> Input;
        if (Confirm(Input) == 'n' || Confirm(Input) == 'N')
        {
            Loan();
        }
        else if (Confirm(Input) == 'y' || Confirm(Input) == 'Y')
        {
            double amt;
            cout << "\n\nEnter your account number: ";
            cin >> AccountNumber;
            ValidAccNum(AccountNumber);
            cout << "\nEnter the amount of loan: ";
            cin >> amt;
            cout << "\nAmount to be paid back within 3 years: Rs. " << amt * pow(1.06, 3);
            cout << "\n-> Press ['Y'] to Confirm OR ['N'] to cancel, cancelling will shift you to the homescreen: ";
            cin >> Input;
            if ((Confirm(Input) == 'y') || (Confirm(Input) == 'Y'))
            {
                cout << "\nLoan of Rs. " << amt << " transferred to your account!";
            }
            else
            {
                cout << "\n\nShifting you to the homescreen.";
                HomeScreen();
            }
        }
        else
        {
            cout << "\n\nShifting you to the homescreen.";
            HomeScreen();
        }

        break;
    }

    case 'b':
    {
        cout << "\n\n• Loan Scheme: Girl Education.";
        cout << "\n• Interest: No Interest.";
        cout << "\n• Time Period: Five years.";
        cout << "\n• Penalty: No Penalty.";
        cout << "\n• Formalities Required: Your aaadhar card and school documents.";
        cout << "\n\n-> Do you agree with the above terms? Press ['Y'] for Yes OR ['N'] for No OR ['H'] to go back to the home screen: ";
        cin >> Input;
        if (Confirm(Input) == 'n' || Confirm(Input) == 'N')
        {
            Loan();
        }
        else if (Confirm(Input) == 'y' || Confirm(Input) == 'Y')
        {
            double amt;
            cout << "\n\nEnter your account number: ";
            cin >> AccountNumber;
            ValidAccNum(AccountNumber);
            cout << "\nEnter the amount of loan: ";
            cin >> amt;
            cout << "\nAmount to be paid back within 5 years: Rs. " << amt;
            cout << "\n-> Press ['Y'] to confirm OR ['N'] to cancel, cancelling will shift you to the homescreen: ";
            cin >> Input;
            if ((Confirm(Input) == 'y') || (Confirm(Input) == 'Y'))
            {
                cout << "\nLoan of Rs. " << amt << " transferred to your account!";
            }
            else
            {
                cout << "\n\nShifting you to the homescreen.";
                HomeScreen();
            }
        }
        else
        {
            cout << "\n\nShifting you to the homescreen.";
            HomeScreen();
        }
        break;
    }

    case 'c':
    {
        cout << "\n\n• Loan Scheme: Farmers Loan.";
        cout << "\n• Interest: 4.5% Simple interest.";
        cout << "\n• Time Period: Two years.";
        cout << "\n• Penalty: No Penalty.";
        cout << "\n• Formalities Required: Your land documents and PAN/aaadhar card.";
        cout << "\n\n-> Do you agree with the above terms? Press ['Y'] for Yes OR ['N'] for No OR ['H'] to go back to the home screen: ";
        cin >> Input;
        if (Confirm(Input) == 'n' || Confirm(Input) == 'N')
        {
            Loan();
        }
        else if (Confirm(Input) == 'y' || Confirm(Input) == 'Y')
        {
            double amt;
            cout << "\n\nEnter your account number: ";
            cin >> AccountNumber;
            ValidAccNum(AccountNumber);
            cout << "\nEnter the amount of loan: ";
            cin >> amt;
            cout << "\nAmount to be paid back within 2 years: Rs. " << amt + ((amt * 4.5 * 2) / 100);
            cout << "\n-> Press ['Y'] to confirm OR ['N'] to cancel, cancelling will shift you to the homescreen: ";
            cin >> Input;
            if ((Confirm(Input) == 'y') || (Confirm(Input) == 'Y'))
            {
                cout << "\nLoan of Rs. " << amt << " transferred to your account!";
            }
            else
            {
                cout << "\n\nShifting you to the homescreen.";
                HomeScreen();
            }
        }
        else
        {
            cout << "\n\nShifting you to the homescreen.";
            HomeScreen();
        }

        break;
    }

    case 'd':
    {
        int years = 0;
        cout << "Enter the time period of the loan (in years): ";
        cin >> years;
        do
        {
            if (Counter > 0)
            {
                cout << "Sorry! The time period exceeded the limit of 8 years, please re-enter: ";
                cin >> years;
            }
            Counter++;
        } while (years > 8);
        Counter = 0;
        cout << "\n\n• Loan Scheme: Citizens Loan.";
        cout << "\n• Interest: 8% compound interest.";
        cout << "\n• Time Period: " << years << " years.";
        cout << "\n• Penalty: Property will be mortgaged.";
        cout << "\n• Formalities Required: PAN/aaadhar card.";
        cout << "\n\n-> Do you agree with the above terms? Press ['Y'] for Yes OR ['N'] for No OR ['H'] to go back to the home screen: ";
        cin >> Input;
        if (Confirm(Input) == 'n' || Confirm(Input) == 'N')
        {
            Loan();
        }
        else if (Confirm(Input) == 'y' || Confirm(Input) == 'Y')
        {
            double amt;
            cout << "\n\nEnter your account number: ";
            cin >> AccountNumber;
            ValidAccNum(AccountNumber);
            cout << "\nEnter the amount of loan: ";
            cin >> amt;
            cout << "\nAmount to be paid back within 2 years: Rs. " << amt * pow(1.08, years);
            cout << "\n-> Press ['Y'] to confirm OR ['N'] to cancel, cancelling will shift you to the homescreen: ";
            cin >> Input;
            if ((Confirm(Input) == 'y') || (Confirm(Input) == 'Y'))
            {
                cout << "\nLoan of Rs. " << amt << " transferred to your account!";
            }
            else
            {
                cout << "\n\nShifting you to the homescreen.";
                HomeScreen();
            }
        }
        else
        {
            cout << "\n\nShifting you to the homescreen.";
            HomeScreen();
        }
        break;

        break;
    }

    default:
        cout << "\nSomething looks wrong. We're shifting you to the homescreen.";
        HomeScreen();
    }

    cout << "\n\n\nPress ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
    cin >> Input;
    if (BackCheck(Input) == 'A' || BackCheck(Input) == 'a')
    {
        Loan();
    }
    else
    {
        HomeScreen();
    }
}

void Care()
{
    bool test = true;
    system("clear");
    cout << "\n\n4. Customer Care, Support and Helpdesk: ";
    cout << "\na) Account issues.";
    cout << "\nb) Debit or Credit Card issues.";
    cout << "\nc) Net banking issues.";
    cout << "\nd) Other support.";
    cout << "\n\n-> Please enter your choice between 'a', 'b', 'c' or 'd' OR Press ['H'] to go back to the home screen: ";
    cin >> Input;
    if (Input == 'h' || Input == 'H')
    {
        HomeScreen();
    }

    do
    {
        test = (Input >= 'a' && Input <= 'd') ? true : false;
        if (test == false)
        {
            cout << "\nRe-enter your choice between 'a' to 'd': ";
            cin >> Input;
        }
    } while (test == false);

    switch (Input)
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
        HomeScreen();
    }

    cout << "\n\n\nPress ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
    cin >> Input;
    if (BackCheck(Input) == 'A' || BackCheck(Input) == 'a')
    {
        Care();
    }
    else
    {
        HomeScreen();
    }
}

void Transaction()
{
    bool test = true;
    system("clear");
    cout << "2. Transaction Services:";
    cout << "\na) Fund transfer to one of your own accounts.";
    cout << "\nb) Fund transfer to another account of same bank - Intra Banking Transfer.";
    cout << "\nc) Fund transfer to another account of different bank - Inter Banking Transfer.";

    cout << "\n\n-> Please enter your choice between 'a', 'b' or 'c' OR Press ['H'] to go back to the home screen: ";
    cin >> Input;
    if (Input == 'h' || Input == 'H')
    {
        HomeScreen();
    }

    do
    {
        test = (Input >= 'a' && Input <= 'c') ? true : false;
        if (test == false)
        {
            cout << "\nRe-enter your choice between 'a' to 'c': ";
            cin >> Input;
        }
    } while (test == false);

    switch (Input)
    {
    case 'a':
    {
        int amt;
        cout << "\n-> Enter your account number: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n-> Enter the account number of one of your own account: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n-> Enter the amount you wish to transfer: ";
        cin >> amt;
        cout << "Amount of Rs. " << amt << " transferred to " << AccountNumber << ".";
        break;
    }
    case 'b':
    {
        int amt;
        cout << "\n-> Enter your account number: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n-> Enter the account number of the same bank you wish to transfer money: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n-> Enter the amount you wish to transfer: ";
        cin >> amt;
        cout << "Amount of Rs. " << amt << " transferred to " << AccountNumber << ".";
        break;
    }
    case 'c':
    {
        int amt;
        cout << "\n-> Enter your account number: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n-> Enter the account number of the different bank you wish to transfer money: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n-> Enter the amount you wish to transfer: ";
        cin >> amt;
        cout << "Amount of Rs. " << amt << " transferred to " << AccountNumber << ".";
        break;
    }
    default:
        cout << "Something looks wrong.";
        HomeScreen();
    }

    cout << "\n\n\nPress ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
    cin >> Input;
    if (BackCheck(Input) == 'A' || BackCheck(Input) == 'a')
    {
        Transaction();
    }
    else
    {
        HomeScreen();
    }
}

char BackCheck(char GetInput)
{
    do
    {
        if (Counter > 0)
        {
            cout << "\nSorry, Wrong Input Received! Press ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
            cin >> GetInput;
        }
        Counter++;
    } while ((GetInput != 'a' && GetInput != 'A') && (GetInput != 'h' && GetInput != 'H'));
    Counter = 0;
    return GetInput;
}

void ValidAccNum(long GetAccNum)
{
    int digit = 0;
    do
    {
        while (GetAccNum > 0)
        {
            GetAccNum = (GetAccNum / 10);
            digit++;
        }
        if (digit < 10)
        {
            cout << "\nYour Input must be *EXACTLY* 10 numerals long otherwise you'll be severely punished with a System crash: ";
            cin >> GetAccNum;
        }
    } while (digit < 10);
}

char Confirm(char GetInput)
{
    do
    {
        if (Counter > 0)
        {
            cout << "\nSorry, Wrong Input Received!: ";
            cin >> GetInput;
        }
        Counter++;
    } while ((GetInput != 'y' && GetInput != 'Y') && (GetInput != 'n' && GetInput != 'N') && (GetInput != 'q' && GetInput != 'Q') && (GetInput != 'h' && GetInput != 'H'));
    Counter = 0;
    return GetInput;
}

int RandomBalance()
{
    int no_of_nums = 100000;
    int first_num = 1000;

    int random = rand() % no_of_nums + first_num;

    return random;
}
