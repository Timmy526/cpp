//Program to query the user
//for an integer larger than 1.
//Then determines and displays the
//prime factorization of the given integer.
//Written by Timothy Tu
//Language: C++
//March 23 2020

#include <iostream>
#include <cstdlib>
using namespace std;

//Includes stack files
#include "stack.h"
#include "stack.cpp"

int main (void){
    //Variables
    Stack primes;
    int givenInt = 0;
    int primeNums = 0;

    //Queries User for positive integer greater than 1
    cout << "Enter an positive integer greater than 1 to find the primes of that number" << endl;
    cin >> givenInt;
    cout << endl;

    //Prints out the Prime Factors of the Given Number
    cout << "The Prime Factors of " << givenInt << " are: " << endl;

    //Loops to find primes numbers of the Given Integer
    for (primeNums = 2; primeNums < givenInt; primeNums++){
        //Checks to see if the "primeNums" is a prime number and pushes into the stack
        while (givenInt % primeNums == 0){
            givenInt = givenInt / primeNums;
            primes.push(primeNums);
        }
    }

    //Prints out last number
    if(givenInt != 1){
        primes.push(givenInt);
    }

    //Prints the stack of prime numbers
    primes.display(cout);

    //Terminates program and returns 0
    return 0;
}













