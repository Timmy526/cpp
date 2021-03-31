//Program to find a number in a matrix
//Creates a matrix using random numbers
//Queries user to enter an integer to see if
//it is in the matrix
//Written by Timothy Tu
//January 2 2020
//Language: C++

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main (void){
    int matrix[3][3];
    int row;
    int col;
    int userGuess;
    srand(time(NULL));

    //Uses srandom to fill matrix with random numbers from 1 to 100
    for (row = 0; row < 3; row++){
        for (col = 0; col < 3; col++){
            matrix[row][col] = rand() % 100 + 1;
        }
    }

    //Displays matrix of numbers
    for (row = 0; row < 3; row++){
        for (col = 0; col < 3; col++){
            cout << " " << matrix[row][col];
        }
        cout << endl;
    }

    //Prompts user for an integer
    cout << "Enter a positive integer from 1 to 100\n";
    cout << "to see if it is inside the matrix: ";
    cin >> userGuess;

    //Finds whether or not the number is in the matrix
    for (row = 0; row < 3; row++){
        for (col = 0 ; col < 3; col++){
            if (matrix[row][col] == userGuess){
                //Terminates function if number is in the matrix
                cout << "The integer is in the matrix!";
                return 0;
            }
        }
    }
    //Terminates function saying the number is not in the matrix
    cout << "The integer is not in the matrix.";
    return 0;
}
