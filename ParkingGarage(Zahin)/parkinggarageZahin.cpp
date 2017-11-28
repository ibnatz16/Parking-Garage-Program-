/*
 * parkinggarageZahin.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: ibnatz16
 */

#include "parkinggarageZahin.h"
using namespace std;
#include <vector>
#include <iostream>

void arrivingGreeting() {
    
    cout << "--\nThanks for parking your garage in the Zanach Parking Garage. \nWe promise your car is in pretty good hands for the most part!" << endl;
    cout << "\nOur Regular Rates:" << endl;
    cout << "\t<1 hour: $10" << endl;
    cout << "\t1 - 3 hour(s): $12.50" << endl;
    cout << "\t3 - 6 hours: $17.50" << endl;
    cout << "\t6 - 12 hours: $24.50" << endl;
    cout << "\t12 - 24 hours: $34.50" << endl;
    
    cout << "\nOur VIP Rates:" << endl;
    cout << "\t<1 hour: $20" << endl;
    cout << "\t1 - 3 hours: $22.50" << endl;
    cout << "\t3 - 6 hours: $27.50" << endl;
    cout << "\t6 - 12 hours: $34.50" << endl;
    cout << "\t12 - 24 hours: $44.50" << endl;
    
}


int main() {
    int menuChoice;
    
    cout << "Welcome to the Zanach Parking Garage!!" << endl;
    cout << "What would you like to do? (Enter the number of your choice): " << endl;
    
    cout << "\n1. Park my car" << endl;
    cout << "2. Retrieve my car (checkout and pay)" << endl;
    cout << "3. Find my car (I lost it!)" << endl;
    
    cout << "Choice: ";
    cin>>menuChoice;
    while(cin.fail()){
        cin.clear(); //Resets the flags so you can input again
        cin.ignore(100, '\n'); //Empty the buffer
        cout << "Please enter an integer!\n";
        cin >> menuChoice;
    }
    
    
    
    switch (menuChoice) {
        case 1:
            arrivingGreeting();
            break;
    }
    
