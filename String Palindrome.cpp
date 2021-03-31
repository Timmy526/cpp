//Program to query the user
//for an string of characters
//to find if the string
//is a palindrome
//Written by Timothy Tu
//Language: C++
//April 10 2020

#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

int main (void){
    //Variables
    stack <char> charStr;
    queue <char> charStrBack;
    string input;
    int length = 0;
    int counter = 0;
    bool palindrome = false;

     //Queries User for a string of characters
    cout << "Enter a string of characters to see if the string is a palindrome " << endl;
    cin >> input;
    cout << endl;

    //Prints out whether the string is a palindrome or not
    cout << "The string of characters " << input;

    //Finds length of string
    length = input.size() / 2;

    //For loop to push each character into the stack and queue
    for (counter = 0; counter < length; counter++){
        charStr.push(input[counter]);
        charStrBack.push(input[counter]);
    }

    //Turns palindrome true to test the input in the for loop
    palindrome = true;

    //For loop to compare the string letters
    for (counter = 1; counter <= length && palindrome; counter++){
        palindrome = charStr.top() == input[input.size() - counter];
        palindrome = charStrBack.front() == input[input.size() - counter];
        charStr.pop();
        charStrBack.pop();
    }

    //Determines if the string is a palindrome or not
    if (!palindrome){
        cout << " is not a palindrome." << endl;
    }
    else {
        cout << " is a palindrome." << endl;
    }

    //Terminates program and returns 0
    return 0;
}













