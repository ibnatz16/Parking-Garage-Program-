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
    int mainMenuChoice, VIPchoice, timeChoice;
    
    cout << "Welcome to the Zanach Parking Garage!!" << endl;
    cout << "What would you like to do? (Enter the number of your choice): " << endl;
    
    cout << "\n1. Park my car" << endl;
    cout << "2. Retrieve my car (checkout and pay)" << endl;
    cout << "3. Find my car (I lost it!)" << endl;
    
    cout << "Choice: ";
    cin >> mainMenuChoice;
    while(cin.fail()){
        cin.clear(); //Resets the flags so you can input again
        cin.ignore(100, '\n'); //Empty the buffer
        cout << "Please enter an integer!\n";
        cin >> mainMenuChoice;
    }
    switch (mainMenuChoice) {
            //parking the car, car is arriving
        case 1:
            //declaring a new car object
            
            
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
            
            
            //asking for VIP
            
            //bool VIP = false;
            
            cout << "Would you like to park regular or VIP?" << endl;
            
            cout << "1. Regular" << endl;
            cout << "2. VIP" << endl;
            cout << "3. JK I don't want to park you guys are too expensive" << endl;
            cout << "Choice: ";
            
            cin >> VIPchoice;
            
            
            switch (VIPchoice) {
                case 1:
                    //VIP = false;
                    //car.isVIP = false or whatever
                    break;
                case 2:
                    //VIP = true;
                    //car.isVIP = true or whatever
                    break;
                case 3:
                    cout << "goodbye, thanks for nothing";
                    //return 0;
                    break;
            }//end of VIP switch statement
            
            //if car.isVIP cout "you are a VIP!"
            //else if they are not
            
            cout << "How long would you like to stay?" << endl;
            cout << "<1 hour" << endl;
            cout << "1 - 3 hours" << endl;
            cout << "3 - 6 hours" << endl;
            cout << "6 - 12 hours" << endl;
            cout << "12 - 24 hours" << endl;
            
            cout << "Choice: " << endl;
            cin >> timeChoice;
            while (cin.fail()) {
                cin.clear(); //Resets the flags so you can input again
                cin.ignore(100, '\n'); //Empty the buffer
                cout << "Please enter an integer!\n";
                cin >> timeChoice;
            }
            
            //if statements to add money to the car object for the time choice
            break; //end of the case 1, car arriving in the parking lot
        case 2:
            cout<<"You have chosen to retrieve your car. Please enter your license plate number: "<<endl;
            //User inputs the license plate number linked to their car object.
            //A while loop will prevent the user from inputing more than 6 characters for the license plate number.
            //if the plate number cannot be found:
            cout<<"Sorry! The license plate number cannot be found in our system. Please try again."<<endl;
            //a while loop will keep prompting the user to enter a valid license plate number.
            
            //if the license plate number exists:
            cout<<"You have parked your ... for "<<timeChoice<<". Your total comes out to "<<endl;
            //the amount the user has to pay is linked to the timeChoice, which is linked to their specific car.
            cout<<"Thanks for parking your garage in the Zanach Parking Garage. Have a nice day!"<<endl;
            break;
        case 3: break;
        default:
            cout << "That wasn't an option. Goodbye";
            break;
            
            
    }//end of big switch statement
    
}

