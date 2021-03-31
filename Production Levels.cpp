//Program to query user for dooflingies
//produced each day, finds the highest,
//lowest, average, how much the production
//rose or fell each day and
//displays total number of dooflingies produced
//up to that day
//Written by Timothy Tu
//Language: C++
//May 1 2020

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(void){
    //Variables
    int dooflingies[10];
    int productions[10];
    int dailyProduction[10];
    double average = 0;
    int i = 0;
    int input = 0;
    int maximum = 0;
    int minimum = 0;
    int maxArray = 0;
    int minArray = 0;



    //Queries User for the amount of dooflingies produced from Day 1 to Day 10
    for (i = 0 ; i < 10 ; i++){
        cout << "Enter the amount of dooflingies produced on day " << i + 1 << ": ";
        cin >> dooflingies[i];
        cout << endl;
    }
    //Fills vector with the inputs for dooflingies
    vector<int> calc(dooflingies, dooflingies + 10);

    //Finds the minimum dooflingies produced
    vector<int>::iterator minResult;
    minResult = min_element(calc.begin(), calc.end());
    minArray = distance(calc.begin(), minResult);
    minimum = calc[minArray];
    cout << "Minimum is " << minimum << " produced dooflingies on day " << minArray + 1<< endl;

    cout << endl;

    //Finds the maximum dooflingies produced
    vector<int>::iterator maxResult;
    maxResult = max_element(calc.begin(), calc.end());
    maxArray = distance(calc.begin(), maxResult);
    maximum = calc[maxArray];
    cout << "Maximum is " << maximum << " produced dooflingies on day " << maxArray + 1<< endl;


    cout << endl;

    //Finds the average dooflingies produced
    average = accumulate(calc.begin(), calc.end(), 0);
    average = average / 10;
    cout << "Average is " << average << " dooflingies a day" << endl;

    cout << endl;

    //Find production levels of each day.
    adjacent_difference(calc.begin(), calc.end(), productions);
    for (i = 0; i < 9; i++){
         if (productions[i] > 0){
             cout << "Day " << i << " production to day " << i + 1 << " rose by " << productions[i] << " dooflingies" << endl;
        }
        else if (productions[i] < 0){
            cout << "Day " << i << " production to day " << i + 1 << " went down by " << productions[i] << " dooflingies" << endl;
        }
        else{
            cout << "Day " << i << " production to day " << i + 1 << " had no change. " << endl;
        }
    }
    cout << endl;

    //Show number of dooflingies produced that day including total.
    partial_sum(calc.begin(), calc.end(), dailyProduction);
    for (i = 0 ; i < 10 ; i++){
        cout << "Day " << i + 1 << " produced " << calc.at(i) << " dooflingies " << endl;
        cout << "Total number of dooflingies produced to date is " << dailyProduction[i] << " dooflingies" << endl;
    }

    //Terminates program and returns 0
    return 0;
}









