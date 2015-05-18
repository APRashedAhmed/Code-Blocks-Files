#include <iostream>

using namespace std;

//Interactive Calculator

int main()
{
    double FirstArg, SecondArg, answer;

    string m = "multiply";
    string d = "divide";
    string a = "add";
    string s = "subtract";

    string operation;
    string response = "yes";
    string repeat = "yes";

    cout << "Hello! This is a simple calculator!\n";
    cout << "It can add, subtract, multiply or divide any two numbers of your choosing!";
    cout << "\n\nTo begin, enter the first number of the operation you want to perform below:\n";

    while(response == repeat)
    {
        cout << "NOTE: If you want decimal points in your answer then you need to input numbers \nwith decimal points!\n\n        ";

            cin >> FirstArg;

        cout << "\n\nNow the second:\n\n        ";

            cin >> SecondArg;

        cout << "\n\nGreat! \nNow which operation would you like to perform?";
        cout << "\nPlease enter 'add', 'subtract', 'multiply', or 'divide' \n\n        ";

        cin >> operation;

        if (operation==m)
        {
            answer = FirstArg*SecondArg;
        }

        else if (operation==d)
        {
            answer = FirstArg/SecondArg;
        }

        else if (operation==s)
        {
            answer = FirstArg-SecondArg;
        }

        else if (operation==a)
        {
            answer = FirstArg+SecondArg;
        }

        cout << "\n\nThen the answer is: " << answer;
        cout << "\n\nWould you like to perform another calculation?\n";
        cout << "Please enter 'yes' or 'no':\n\n        ";

            cin >> response;

        if(response == repeat)
        {
            cout << "\n\nOk, let's do another calculation then!\n";
            cout << "Enter the first number in the operation you want to perform below:";
        }
    }

    cout << "\nThanks for using the simple calculator!\n";
}
