//Program to create a static matrix
//and display magic square using a
//positive odd value queried by the user
//Written by Timothy Tu
//February 13 2020
//Language: C++

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Prototypes
void magicSquare(int num);

int main(void){
    int userNum;

    //Prompts user for an odd positive value
    cout << "Please input a positive odd value from 1 to 49 for the magic square size" << endl;
    cin >> userNum;

    //If the input is not odd, it tells the user it is not odd
    if (userNum % 2 == 0){
        cout << "You did not input a positive odd value" << endl;
    }
    //Else it starts the function to create the magic square
    else{
        magicSquare(userNum);
    }
    return 0;
}

void magicSquare(int num){
    int row;
    int col;
    int counter;
    int matrix[49][49];

    //Set up matrix
    for (row = 0; row < num; row++){
        for (col = 0; col < num; col++){
            matrix[row][col] = 0;
        }
    }

    //Sets up the number to be in the middle first row
    row = 0;
    col = ((num / 2));

    //Refills the matrix with numbers
    for (counter = 1; counter <= (num * num); counter++){
        //If the next number would be out of the upper
        //right-hand square then it puts it below it
        if (row == -1 && col == num){
            row = row + 2;
            col = col - 1;
        }
        else{
            //If the row is above the top row it resets it to the bottom row
            if (row == -1){
                row = num - 1;
            }
            //If the column is at the right most then it resets to the left
            if (col == num){
                col = 0;
            }
        }
        //If the square is already filled move the number below it
        if (matrix[row][col]){
            row = row + 2;
            col = col - 1;
        }

        //Sets the matrix spot with the next number
        matrix[row][col] = counter;

        //Decreases the row, adds the column
        row--;
        col++;
    }

    //Displays the matrix
    for (row = 0; row < num; row++){
        for (col = 0; col < num; col++){
            cout << matrix[row][col];
            cout << " ";
        }
        cout << endl;
    }

}

