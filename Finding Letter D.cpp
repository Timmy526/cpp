//Program to query the user for a file of words
//Counts the amount of words without the letter D
//at the start of the time
//Written by Timothy Tu
//March 5 2020
//Language: C++

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;

int main (void){
    //Variables
    string lineWord;
    string fileName;
    int wordCount = 0;
    char word;
    ifstream file;

    //Query User for file of words
    cout << "We are going to find the number of words without the letter 'D'." << endl;
    cout << "Please enter a text file with a list of words: ";
    cin >> fileName;
    cout << endl;

    //Opens files
    file.open(fileName.data());
    assert(file.is_open());

    //Loops through each line of the file
    while (!(file.eof())){
        file >> lineWord;
        //If the word starts with D it keeps going with the loop
        if (lineWord.at(0) == 'd' || lineWord.at(0) == 'D'){
            continue;
        }
        //If the word doesn't start with a D it iterates wordCount
        else{
            wordCount = wordCount + 1;
        }
    }

    //Tells the user how many words there was that doesn't start with the letter D
    cout << "The number of words you have that doesn't start with 'D' is "<< wordCount << endl;

    return 0;

}
