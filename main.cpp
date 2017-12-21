using namespace std;

//Header files
#include <iostream> //For basic input output.
#include <string>   //For functions related to string eg. getline(cin, string)
#include <cstdlib>  //For exit() function
#include <cmath>    //For pow(base, power) function

//Structures for Initializing datamembers
struct ProfileDetails
{
    string username; //Bank operator's name
    string pass;     //Bank operator's password
    string email;    //Bank operator's email
} Profile;

//Global datamembers
char Input = 0;                  //For Accepting user input used throughout the code.
int Counter = 0;                 //Act as a counter of loops.
unsigned long AccountNumber = 0; //For Accepting account number used throughout the code.
float amount = 0;

/* Dependencies arrays for InputManager() */
char YesNo[] = {'y', 'n'};
char MenuOptions[] = {'a', 'b', 'c', 'h'};
char HomeReload[] = {'a', 'h'};

//Function declarations
void WelcomeScreen(ProfileDetails Profile);
void HomeScreen();
void Customer();
void Transaction();
void Loan();
void Care();

int RandomBalance();                                 //Random balance generator
char InputManager(char GetInput[], int InputLength); //It tackles user input and validation of it.
void ValidAccNum(unsigned long GetAccNum);           //Account number and aadhar card validator

/* Start of main() */
int main()
{
    system("clear");
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
    cout << "\n• Here, you'll be setting up your profile as a banking officer.\n• Your username can consist of alphanumeric characters and your Password must be atleast 6 characters long.\n• Fields marked with '*' are necessary. \n• IMPORTANT: Strictly Follow the ethics of datatypes. For Example, Account Number should be strictly 10 numerals wrong otherwise you'll be punished with a crash of the whole system.";
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
    cout << "\n-> You won't be able to change the user name or password later due to security reasons corporated by SBI systems. Are you sure you want to continue? Press ['Y'] to continue OR ['N'] to re-enter the details: ";

    //Validating user input.
    if (InputManager(YesNo, 2) == 'y')
    {
        cout << "\nYou're ready to go :) \n-> Press ['Enter'] to continue.";
        cin.ignore();
        cin.ignore();
    }
    else
    {
        WelcomeScreen(Profile);
    }
}

//HomeScreen function()
void HomeScreen()
{
    system("clear");
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
    cout << "\n\n-> Please enter your choice between ['1'] to ['4'] OR ['Q'] to Quit: ";

    char expectedInput[] = {'1', '2', '3', '4', 'q'};
    //Corresponding cases based on user's input for shifting them to the asked screen.
    switch (InputManager(expectedInput, 5))
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
    } //The program is so robust that default case never gets executed ;) - Vivek Agrawal.
}

//Fucntion for customer centric services.
void Customer()
{
    system("clear");
    cout << "1. Customer Centric Services: ";
    cout << "\na) Open an bank account.";
    cout << "\nb) Close a bank account.";
    cout << "\nc) Get your Account statement or balance.";
    cout << "\n\n-> Please enter your choice between 'a', 'b' or 'c' OR Press ['H'] to go back to the home screen: ";

    switch (InputManager(MenuOptions, 4))
    {
    case 'h':
    {
        HomeScreen();
    }
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
        cout << "\n-> Enter your account number: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n:( Account Closed!";
        break;
    }
    case 'c':
    {
        cout << "-> Enter your account number: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\nBalance = " << RandomBalance();
        break;
    }
    }

    cout << "\n\n\n-> Press ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
    (InputManager(HomeReload, 2) == 'a') ? Customer() : HomeScreen();
}

//Fucntion for loan centric services.
void Loan()
{
    amount = 0;
    system("clear");
    cout << "\n3. Loan Services: ";
    cout << "\na) Startup Buisness Loan.";
    cout << "\nb) Loan for girl education.";
    cout << "\nc) Loan for farmers.";
    cout << "\n\n-> Please enter your choice between 'a', 'b' or 'c' OR Press ['H'] to go back to the home screen: ";

    switch (InputManager(MenuOptions, 4))
    {
    case 'h':
    {
        HomeScreen();
    }
    case 'a':
    {
        cout << "\n\n• Loan Scheme: Startup Loan.";
        cout << "\n• Interest: 6% compounded anually.";
        cout << "\n• Time Period: Strictly three years.";
        cout << "\n• Penalty: No Penalty for the first three years according to Startup India Initiative.";
        cout << "\n• Formalities Required: Your business documents.";
        cout << "\n\n-> Do you agree with the above terms? Press ['Y'] for Yes OR ['N']: ";
        if (InputManager(YesNo, 2) == 'y')
        {
            cout << "\n\n-> Enter your account number: ";
            cin >> AccountNumber;
            ValidAccNum(AccountNumber);
            cout << "\n-> Enter the amount of loan: ";
            cin >> amount;
            cout << "\nAmount to be paid back within 3 years: Rs. " << amount * pow(1.06, 3);
            cout << "\n-> Press ['Y'] to Confirm OR ['N'] to cancel, cancelling will shift you to the homescreen: ";
            if (InputManager(YesNo, 2) == 'y')
            {
                cout << "\nLoan of Rs. " << amount << " transferred to your account!";
            }
            else
            {
                HomeScreen();
            }
        }
        else
        {
            Loan();
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
        cout << "\n\n-> Do you agree with the above terms? Press ['Y'] for Yes OR ['N']: ";
        if (InputManager(YesNo, 2) == 'y')
        {
            cout << "\n\n-> Enter your account number: ";
            cin >> AccountNumber;
            ValidAccNum(AccountNumber);
            cout << "\n-> Enter the amount of loan: ";
            cin >> amount;
            cout << "\nAmount to be paid back within 5 years: Rs. " << amount;
            cout << "\n-> Press ['Y'] to confirm OR ['N'] to cancel, cancelling will shift you to the homescreen: ";
            if (InputManager(YesNo, 2) == 'y')
            {
                cout << "\nLoan of Rs. " << amount << " transferred to your account!";
            }
            else
            {
                HomeScreen();
            }
        }
        else
        {
            Loan();
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
        cout << "\n\n-> Do you agree with the above terms? Press ['Y'] for Yes OR ['N'] for No: ";
        if (InputManager(YesNo, 2) == 'y')
        {
            cout << "\n\n-> Enter your account number: ";
            cin >> AccountNumber;
            ValidAccNum(AccountNumber);
            cout << "\n-> Enter the amount of loan: ";
            cin >> amount;
            cout << "\nAmount to be paid back within 2 years: Rs. " << amount + ((amount * 4.5 * 2) / 100);
            cout << "\n-> Press ['Y'] to confirm OR ['N'] to cancel, cancelling will shift you to the homescreen: ";
            if (InputManager(YesNo, 2) == 'y')
            {
                cout << "\nLoan of Rs. " << amount << " transferred to your account!";
            }
            else
            {
                HomeScreen();
            }
        }
        else
        {
            Loan();
        }
        break;
    }
    }
    cout << "\n\n\n-> Press ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
    (InputManager(HomeReload, 2) == 'a') ? Loan() : HomeScreen();
}

//Function for customer care section.
void Care()
{
    system("clear");
    cout << "\n\n4. Customer Care, Support and Helpdesk: ";
    cout << "\na) Account issues.";
    cout << "\nb) Debit or Credit Card issues.";
    cout << "\nc) Net banking issues.";
    cout << "\n\n-> Please enter your choice between 'a', 'b' or 'c' OR Press ['H'] to go back to the home screen: ";

    switch (InputManager(MenuOptions, 4))
    {
    case 'h':
    {
        HomeScreen();
    }
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
    }
    cout << "\n\n\n-> Press ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
    (InputManager(HomeReload, 2) == 'a') ? Care() : HomeScreen();
}

//Function for transction section.
void Transaction()
{
    amount = 0;
    system("clear");
    cout << "2. Transaction Services:";
    cout << "\na) Fund transfer to one of your own accounts.";
    cout << "\nb) Fund transfer to another account of same bank - Intra Banking Transfer.";
    cout << "\nc) Fund transfer to another account of different bank - Inter Banking Transfer.";
    cout << "\n\n-> Please enter your choice between 'a', 'b' or 'c' OR Press ['H'] to go back to the home screen: ";
    switch (InputManager(MenuOptions, 4))
    {
    case 'h':
    {
        HomeScreen();
    }
    case 'a':
    {
        cout << "\n-> Enter your account number: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n-> Enter the account number of one of your own account: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n-> Enter the amount you wish to transfer: ";
        cin >> amount;
        cout << "Amount of Rs. " << amount << " transferred to " << AccountNumber << ".";
        break;
    }
    case 'b':
    {
        cout << "\n-> Enter your account number: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n-> Enter the account number of the same bank you wish to transfer money: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n-> Enter the amount you wish to transfer: ";
        cin >> amount;
        cout << "Amount of Rs. " << amount << " transferred to " << AccountNumber << ".";
        break;
    }
    case 'c':
    {
        cout << "\n-> Enter your account number: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n-> Enter the account number of the different bank you wish to transfer money: ";
        cin >> AccountNumber;
        ValidAccNum(AccountNumber);
        cout << "\n-> Enter the amount you wish to transfer: ";
        cin >> amount;
        cout << "Amount of Rs. " << amount << " transferred to " << AccountNumber << ".";
        break;
    }
    }
    cout << "\n\n\n-> Press ['H'] to go back to the home screen OR ['A'] to load the screen again: ";
    (InputManager(HomeReload, 2) == 'a') ? Care() : HomeScreen();
}

//This function manages all Input related tasks such as taking an Input and validating it according to users needs.
char InputManager(char GetInput[], int InputLength)
{
    char userInput;
    cin >> userInput;
    for (int i = 0; i < InputLength; i++)
    {
        if (GetInput[i] == tolower(userInput))
        {
            break;
        }

        else if (i == (InputLength - 1))
        {
            i = -1;
            cout << "\n-> Sorry, we received a wrong input, please re-enter your choice: ";
            cin >> userInput;
        }
        else
        {
            continue;
        }
    }
    return tolower(userInput);
}

//This Function validates account number and aadar card.
void ValidAccNum(unsigned long GetAccNum)
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
            cout << "\n-> Your Input must be *EXACTLY* 10 numerals long: ";
            cin >> GetAccNum;
        }
    } while (digit < 10);
}

//This function generates random balance.
int RandomBalance()
{
    int no_of_nums = 100000;
    int first_num = 1000;
    int random = rand() % no_of_nums + first_num;
    return random;
}
