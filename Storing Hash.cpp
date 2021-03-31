//Program to store 10 words
//using a hash technique it prints
//the word into a position in the array.
//Also can check to see if words are in the
//hash or not
//Written by Timothy Tu
//Language: C++
//May 7 2020


#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Hash{
	public:
		Hash() : wordarray(15){
			for(i = 0; i < 15; i++){
                wordarray.at(i) = "0";
			}

        }

    //This takes the first letter and last letter to mod it for the position
    void hashWord(char first, char last, string word){
        sum  = (first + last) % 15;
        //If the position is empty place the word there
        if (wordarray.at(sum) == "0"){
            wordarray.at(sum) = word;
        }
        //Else you increment i until you get to an empty space
        else if(wordarray.at(sum) != "0"){
            do{
                i = 0;
                if (sum > 14){
                    sum = 0;
                }
                else{
                    sum++;
                }
                if (wordarray.at(sum) == "0"){
                    wordarray.at(sum) = word;
                    i++;
                }
            }while (i != 1);
        }
    }

    //Looks for the word in the hash
    void checkHash(char first, char last, string word){
        sum = (first + last) % 15;
        //Checks if it is in the sum position
        if (wordarray.at(sum) == "0"){
            cout << word << " is not here" <<endl;
        }
        //Checks to see if the word is in another area
        else if(wordarray.at(sum) != "0"){
            if (wordarray.at(sum) == word){
                cout << word << " is in room " << sum + 1 << endl;
            }
            else {
                check = 0;
                do {
                    i = 0;
                    if (sum > 13 && check == 0){
                        sum = 0;
                        check = 1;
                    }
                    else{
                        sum++;
                    }
                    if (sum > 13 && check == 1){
                        cout << word << " is not here" << endl;
                        sum = 0;
                        i++;
                    }
                    if (wordarray.at(sum) == word){
                        cout << word << " is in room " << sum + 1 << endl;
                        i++;
                    }
                }while (i != 1);
            }

        }

    }

    //Display the words
    void displayWords(){
		for(i = 0; i < 15; i++)
		if (wordarray.at(i) == "0")
			cout << "Room " << i + 1 << " has no word" << endl;
		else
			cout << "Room " << i + 1 << " has the word " << wordarray.at(i)<< endl;
	}

    //Class Variables
    protected:
		vector<string> wordarray;
		int sum, i, check;
		string word;
		char first, last;

};

int main(void){
    //Variables
    Hash hash;
    char firstletter;
    char lastletter;
    int length;
    int i;
    string word;

    //Takes each hash word and runs it through the program
    cout<<"Enter 10 words to hash them. (All Lowercase)" <<endl;
    for (i = 0; i < 10; i++){
        cout << "Word " << i + 1 << " : ";
        cin >> word;
        firstletter = word.at(0);
        length = word.length();
        lastletter = word.at(length - 1);
        hash.hashWord(firstletter, lastletter, word);
	}

    hash.displayWords();

    cout << endl;
    cout << "Enter a word to see if it is the hash. (Type '1' when you are done)" << endl;

    //Checks to see if the word is 1, so we can stop the program
    //Else it runs to find the hash word
    do{
        i = 0;
        cout << "Enter word: ";
        cin >> word;
        if (word != "1"){
            firstletter = word.at(0);
            length = word.length();
            lastletter = word.at(length - 1);
            hash.checkHash(firstletter, lastletter, word);
        }
        else{
            i++;
        }

    }while (i != 1);

    //Terminates program and returns 0
    return 0;
}









