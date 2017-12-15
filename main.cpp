using namespace std;

//Included files
#include <iostream>
#include <string>

//structures and objects
struct profile_details
{
    string username;
    string pass;
    string email;
}profile;

//function declarations
void welcome_screen(profile_details profile);
void main_screen(profile_details profile);

//start main()
int main()
{
    cout<<"\t\t\t\t\t\t\t\t\t Welcome!\n\t\t\t\t\t\t\t\tBanking Humantics Version 1.0";
    welcome_screen(profile);
    main_screen(profile);
    return 0;
}

//welcome screen
void welcome_screen(profile_details profile)
{
    int count = 0;
    cout<<"\n------------";    
    cout<<"\nInstructions:";
    cout<<"\n------------";
    cout<<"\n-> Here, you'll be setting up your profile as a banking officer.\n-> Your username can consist of alphanumeric characters and your Password must be atleast 6 characters long.\n-> Fields marked with '*' are necessary.";
    cout<<"\n\n\n1. Enter Your Username*: ";cin>>profile.username;
    cout<<"\n2. Enter Your Password*: ";

    do
    {
        if(count > 0)
        {
            cout<<":( Sorry! Your Password must be atleast six characters, please try again: ";
        }
        cin>>profile.pass;
        count++;
    }
    while(profile.pass.length() < 6);

    cout<<"\n3. Enter Your Email Address*: ";cin>>profile.email;
    cout<<"\n\nVerifying details...Now, you're ready to go! Please, Press 'Enter' to continue.";
    cin.ignore(); cin.ignore();
}

//main_screen function
void main_screen(profile_details profile)
{
    cout<<"\n------------";    
    cout<<"\nInstructions:";
    cout<<"\n------------";
    cout<<"\n-> This is your Home Screen where you'll be carrying out all your work.\n-> .\n-> Fields marked with '*' are necessary.";
}






