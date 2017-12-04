#include <iostream>

#include <string>

#include <string.h>

#include <vector>

#include <stdlib.h>

#include <unistd.h>

//#include <conio.h>

#include "parkinggarageZahin.h"

#include "ParkingGarageManager.h"




using namespace std;


//constructor for car object
//initiates all variables to null or zero


Car::Car()
{
    
    color = "";
    
    make = "";
    
    model = "";
    
    lpNum = "";
    
    floorNum = 0;
    
    spaceNum = 0;
    
    timePeriod = 0;
    
    moneyOwed = 0;
    
    isOccupied = false;
    
    isVIP = false;
    
    isTowed = false;
    
}



//constructor for manager object
//includes the manager's login information
Manager::Manager(string user)

{
    
    username = user;
    
    //the default password is password for all managers
    password = "password";
    
}




//Manager Setters
//sets the username
void Manager::set_username(string user)

{
    
    username = user;
    
}

//sets the password
void Manager::set_password(string pass)

{
    
    password = pass;
    
}




//Manager Getters
//retrieves the username
string Manager::get_username()

{
    
    return username;
    
}

//retrieves the password
string Manager::get_password()

{
    
    return password;
    
}





//Car Setters
//sets the color of the car
void Car::set_color(string c)

{
    
    color = c;
    
}

//sets the make of the car
//the company, i.e. Honda
void Car::set_make(string m)

{
    
    make = m;
    
}

//sets the model of the car
void Car::set_model(string m)

{
    
    model = m;
    
}

//sets the license plate number as a string
//because it includes numbers and letters
void Car::set_lpNum(string lp)

{
    
    lpNum = lp;
    
}

//sets floor number
void Car::set_floorNum(int fn)

{
    
    floorNum = fn;
    
}

//sets space number
void Car::set_spaceNum(int sn)

{
    
    spaceNum = sn;
    
}

//sets the hours the car will be parked
void Car::set_timePeriod(int tp)

{
    
    timePeriod = tp;
    
}

//sets the money owed from the person parking
void Car::set_moneyOwed(double m)

{
    
    moneyOwed = m;
    
}

//sets the boolean for space being occupied
void Car::set_isOccupied(bool o)

{
    
    isOccupied = o;
    
}

//sets the boolean if the parking type is VIP
void Car::set_isVIP(bool v)

{
    
    isVIP = v;
    
}

//sets the boolean if the car has been towed
void Car::set_isTowed(bool t)

{
    
    isTowed = t;
    
}





//Car Getters
//retrieves the color of the car
string Car::get_color()

{
    
    return color;
    
}

//retrieves the make of the car
string Car::get_make()

{
    
    return make;
    
}

//retrieves the model of the car
string Car::get_model()

{
    
    return model;
    
}

//retrieves the license plate number
string Car::get_lpNum()

{
    
    return lpNum;
    
}

//retrieves the floor number
int Car::get_floorNum()

{
    
    return floorNum;
    
}

//retrieves the space number
int Car::get_spaceNum()

{
    
    return spaceNum;
    
}

//retrieves the time range
int Car::get_timePeriod()

{
    
    return timePeriod;
    
}

//retrieves the money owed
double Car::get_moneyOwed()

{
    
    return moneyOwed;
    
}

//retrieves the answer of whether
//a car occupies the space
bool Car::get_isOccupied()

{
    
    return isOccupied;
    
}

//retrieves VIP parking status
bool Car::get_isVIP()

{
    
    return isVIP;
    
}

//retrieves towing info
bool Car::get_isTowed()

{
    
    return isTowed;
    
}




/*
 *
 *
 *
 *
 *
 *
 *
 * The purpose of the program is to simulate an intelligent parking software system for ZANACH Garage.
 *
 * The garage has the choices of VIP or regular parking.
 * The fares are different, but if the person would like to park on the first floor, they will have to choose VIP.
 *
 * After choosing the type of parking, they have to enter the number of hours they would like to park their car.
 * Those rates increase by the number of hours.
 * No car can be parked overnight. The manager can order a car to be towed.
 *
 * After choosing the hours, the user will then input their car information with the color, make, model, and license
 * plate number. The license plate number is the way the software identifies each car in the garage.
 *
 * After all the information has been put in, the program will then tell where the user can park based upon the first
 * unoccupied space the program finds.
 *
 * When the user would like to retrieve their car, and if they remember the floor and space number, the program will let them
 * checkout.
 * For verification, the user will be prompted to enter their license plate number.
 * The user has the option of paying with cash or card.
 * If payment is done with cash, the user will have to input the amount of money they will insert into the machine, and the correct
 * amount of change will be printed by the program.
 * If payment is done with card, the program will start checking for authorization of the card.
 * The user has the option of getting a printed receipt.
 *
 * If the user has forgotten where they have parked the car, the program will find the car for them.
 * Once the user enters their license plate number, the program will tell them where the car is.
 * However, if the car has been towed by the manager for overnight parking or for a haphazard parking job, the software will the user
 * and redirect them to checkout where they will have to pay an additional $200 due to their car being towed.
 *
 *
 * Along with the people parking, the managers also use the same program to be updated on the garage's current conditions.
 * They have to login with their credentials.
 *
 * The manager has the option of printing all license plates for security purposes.
 *
 * The manager can also see the current status of specific spot in the garage.
 *
 * They can also see the total profit made in the garage.
 * This is based on the cars that have already departed.
 *
 * There is also the option of seeing the projected profit, where the manager can see an accurate prediction of the
 * total amount of money that could be made from the garage.
 * This is based on the cars that have departed as well as the cars still within the garage.
 *
 * As said before, the manager can tow a car, which will then be saved by the program to alert the user when they come to retrieve
 * their towed car.
 *
 * The last option the manager has is to change their password because a generic password has been given to them at the start of the
 * program, but they can change it for future use.
 *
 *
 *
 *
 *
 *
 *
 *
 */




//the main function
int main(int argc, char * argv[])

{
    
    //will take command line arguments and set them to constant
    const int NUM_FLOORS = atoi(argv[1]); //Number of floors
    
    const int NUM_SPACES = atoi(argv[2]); //Number of spaces PER FLOOR
    
    const int SPACES_TOTAL = NUM_FLOORS * NUM_SPACES; //the index
    
    
    //additional variables needed:
    
    int mainMenuChoice, VIPchoice, timeChoice, managerMenuChoice = 0; //used for main menu choices
    
    int floorTemp, spaceTemp; //used when accessing data of cars
    
    int paymentChoice, receiptChoice; //used in case 2
    
    double payment, cash, change; //used in case 2
    
    string makeInput, modelInput, colorInput, lpInput, lpTemp; //entering new information
    
    double fee; //assigning money owed to new car
    
    int quit; // to repeat
    
    
    //needed for counts and other extra functions:
    double realProfit = 0.0, projectedProfit = 0.0; //used in manager functions, sum of all profits
    
    int vipCount = 0, regCount = 0;
    
    unsigned int shortSleep = 1000000; //used for sleep
    
    unsigned int longSleep = 1500000; //used for sleep
    
    int getMoreInfo = 0;
    
    
    //declaring number of floors in the parking garage
    Car ** carsList = new Car*[NUM_FLOORS];
    
    
    //declaring the number of spaces in each floor
    for (int i = 0; i < NUM_FLOORS; i++) {
        
        carsList[i] = new Car[NUM_SPACES];
        
    }
    
    
    //declaring a manager object for each of the writers of the program
    //the usernames for each manager
    Manager* clayton = new Manager("clayton");
    
    Manager* zahin = new Manager("zahin");
    
    Manager* neha = new Manager("neha");
    
    Manager* andrew = new Manager("andrew");
    
    Manager* topher = new Manager("topher");
    
    Manager* harsh = new Manager("harsh");
    
    
    
    
    //greeting and prints main menu
    cout << "Welcome to the Zanach Parking Garage!!\n" << endl;
    
    do {
        
    MainMenuQuestion: //goto for the main menu
        
        //each of these menu options is a case in the large overall switch statement of the program
        cout << "\n\tWhat would you like to do? (Enter a number, or 0 to exit)" << endl;
        
        cout << "\t---------------------------------------------" << endl;
        
        cout << "\n\t1. Park my Car" << endl;
        
        cout << "\t2. Retrieve my car (checkout and pay)" << endl;
        
        cout << "\t3. Find my Car (I lost it!)" << endl;
        
        cout << "\t4. Manager Login" << endl;
        
        cout << "\tChoice: ";
        
        cin >> mainMenuChoice;
        
        
        
        //these while loops are used throughout the program to ensure that the user does not enter anything
        //other than an integer
        while (cin.fail()) {
            
            cin.clear(); //Resets the flags so you can input again
            
            cin.ignore(100, '\n'); //Empty the buffer
            
            cout << "Please enter an integer!\n";
            
            cin >> mainMenuChoice;
            
        }
        
        
        
        //prevents user from entering a non option
        if (mainMenuChoice < 0 || mainMenuChoice > 4)
            
        {
            
            cout << "That wasn't an option, please choose from the options available.\n";
            
            goto MainMenuQuestion;
            
        }
        
        
        
        
        //the large switch statement that controls every option of the main menu
        switch (mainMenuChoice)
        {
                
                //quits the program
            case 0:
                
            {
                
                cout << "\nSee you next time!!\n";
                
                return 0;
                
                break;
                
            }
                
                
                
                //parking a new car: this function finds the first fit depending on the user's choices and changes
                //the values of the already existing car in the previously declared array
            case 1:
                
            {
                
                //declaring a new car object of which all variables
                //are initialized to null or zero
                Car car; //temp car object in order to store values
                
                
                
                //first check if the parking garage is completely full. If so, goes back to main menu
                int spacesFilled = 0;
                
                for (int i = 0; i < NUM_FLOORS; i++){
                    
                    for (int j = 0; j < NUM_SPACES; j++){
                        
                        if (carsList[i][j].get_isOccupied()){
                            
                            spacesFilled++;
                            
                        }
                        
                    }
                    
                }
                
                if (spacesFilled == SPACES_TOTAL){
                    
                    cout << "\nSorry, our parking garage is so popular that it's COMPLETELY FULL!\n";
                    
                    cout << "Try again next time!!\n";
                    
                    goto MainMenuQuestion;
                    
                }
                
                
                
                //starts the options for when a car is arriving to the lot
                cout << "\n--\nThanks for parking your garage in the Zanach Parking Garage."
                << "\nWe promise your car is in pretty good hands for the most part!" << endl;
                
                
                
                //prints out regular rates
                cout << "\n\t Our Regular Rates" << endl;
                
                cout << "\t------------------------" << endl;
                
                cout << "\t|<1 hour: $10\t\t|" << endl;
                
                cout << "\t|1 - 3 hour(s): $12.50\t|" << endl;
                
                cout << "\t|3 - 6 hours: $17.50\t|" << endl;
                
                cout << "\t|6 - 12 hours: $24.50\t|" << endl;
                
                cout << "\t|12 - 24 hours: $34.50\t|" << endl;
                
                cout << "\t------------------------" << endl;
                
                
                
                //prints out VIP rates
                cout << "\n\tOur VIP Rates" << endl;
                
                cout << "\t------------------------" << endl;
                
                cout << "\t|<1 hour: $20\t\t|" << endl;
                
                cout << "\t|1 - 3 hours: $22.50\t|" << endl;
                
                cout << "\t|3 - 6 hours: $27.50\t|" << endl;
                
                cout << "\t|6 - 12 hours: $34.50\t|" << endl;
                
                cout << "\t|12 - 24 hours: $44.50\t|" << endl;
                
                cout << "\t------------------------" << endl << endl;
                
                
                
                
                //asks to pick regular or VIP rates
                
            VIPquestion: //go to for "if you'd like to park vip"
                
                cout << "\tWould you like to park regular or VIP?" << endl;
                
                cout << "\t-----------------------------------" << endl;
                
                cout << "\t1. Regular" << endl;
                
                cout << "\t2. VIP (VIPs get first floor parking!)" << endl;
                
                cout << "\t3. I don't want to park, this garage is too expensive" << endl;
                
                cout << "\tChoice: ";
                
                cin >> VIPchoice;
                
                while (cin.fail()) {
                    
                    cin.clear(); //Resets the flags so you can input again
                    cin.ignore(100, '\n'); //Empty the buffer
                    cout << "Please enter an integer!\n";
                    cin >> VIPchoice;
                    
                }
                
                
                //VIP choice chosen
                switch (VIPchoice)
                {
                        
                        //user chooses regular rates
                    case 1:
                        
                        //first check if regular is full, if so takes them back to VIPquestion
                        for (int i = 1; i < NUM_FLOORS; i++){
                            
                            for (int j = 0; j < NUM_SPACES; j++){
                                
                                if (carsList[i][j].get_isOccupied()){
                                    
                                    regCount++;
                                    
                                }
                                
                            }
                            
                        }
                        
                        
                        //this could occur if the regular parking is full OR if the garage floor number allocated
                        //in the command line is 1
                        if (regCount == ((NUM_FLOORS - 1)*NUM_SPACES)){
                            
                            cout << "\nWe're so sorry, regular is full! Please consider paying more for VIP parking, or leaving.\n";
                            
                            goto VIPquestion;
                            
                        }
                        
                        regCount = 0;
                        
                        //isVIP is initialized to be false so nothing needs to be done
                        break;
                        
                        
                        
                        //user chooses VIP rates
                    case 2:
                        
                        //first checks if VIP is full before continuing
                        for (int i = 0; i < NUM_SPACES; i++){
                            
                            if (carsList[0][i].get_isOccupied()){
                                
                                vipCount++;
                                
                            }
                            
                        }
                        
                        if (vipCount == NUM_SPACES){
                            
                            cout << "\nWe're so sorry, VIP is full! Please consider regular parking.\n";
                            
                            goto VIPquestion;
                            
                        }
                        
                        vipCount = 0;
                        
                        car.set_isVIP(true); //isVIP is set to true
                        
                        break;
                        
                        
                        
                        //user does not want to park
                    case 3:
                        
                        cout << "Sorry if our prices are too high. Please consider reemployment!\n";
                        
                        goto RepeatProgram; //goto RepeatProgram: asks if the user would like to quit or go to main menu
                        
                        break;
                        
                        
                        
                        //user chooses number that was not in menu
                    default:
                        
                        cout << "That wasn't an option, please choose from the given options.\n";
                        
                        goto VIPquestion;
                        
                        break;
                        
                }//end of VIP switch statement
                
                
                //asks which time period they will be paying for
                cout << "\n\tHow long would you like to stay?" << endl;
                
                cout << "\t---------------------------------" << endl;
                
            TimeQuestion: //go to for "how long would you like to stay"
                
                cout << "\t1. <1 hour" << endl;
                
                cout << "\t2. 1 - 3 hours" << endl;
                
                cout << "\t3. 3 - 6 hours" << endl;
                
                cout << "\t4. 6 - 12 hours" << endl;
                
                cout << "\t5. 12 - 24 hours" << endl;
                
                cout << "\tChoice: ";
                
                cin >> timeChoice;
                
                while (cin.fail()) {
                    
                    cin.clear(); //Resets the flags so you can input again
                    
                    cin.ignore(100, '\n'); //Empty the buffer
                    
                    cout << "Please enter an integer!\n";
                    
                    cin >> timeChoice;
                    
                }
                
                
                
                //switch statement for different time periods
                switch (timeChoice) {
                        
                    case 1:
                        
                        //user is parking <1 hr
                        car.set_timePeriod(1);
                        
                        break;
                        
                    case 2:
                        
                        //1-3 hrs
                        car.set_timePeriod(2);
                        
                        break;
                        
                    case 3:
                        
                        //3-6 hrs
                        car.set_timePeriod(3);
                        
                        break;
                        
                    case 4:
                        
                        //6-12 hrs
                        car.set_timePeriod(4);
                        
                        break;
                        
                    case 5:
                        
                        //12-24 hrs
                        car.set_timePeriod(5);
                        
                        break;
                        
                        //user enters number that was not an option
                    default:
                        
                        cout << "That wasn't an option, please choose from the available options.\n\n";
                        
                        goto TimeQuestion;
                        
                        break;
                        
                }//end of time period switch statement
                
                
                //determines the fee that will be paid upon exit
                //checks if user is VIP or regular and then sets moneyOwed
                if (car.get_isVIP() == false) {
                    
                    if (car.get_timePeriod() == 1) {
                        
                        fee = 10;
                        
                        car.set_moneyOwed(fee);
                        
                    }
                    
                    if (car.get_timePeriod() == 2) {
                        
                        fee = 12.5;
                        
                        car.set_moneyOwed(fee);
                        
                    }
                    
                    if (car.get_timePeriod() == 3) {
                        
                        fee = 17.5;
                        
                        car.set_moneyOwed(fee);
                        
                    }
                    
                    if (car.get_timePeriod() == 4) {
                        
                        fee = 24.5;
                        
                        car.set_moneyOwed(fee);
                        
                    }
                    
                    if (car.get_timePeriod() == 5) {
                        
                        fee = 34.5;
                        
                        car.set_moneyOwed(fee);
                        
                    }
                    
                }
                
                else {
                    
                    if (car.get_timePeriod() == 1) {
                        
                        fee = 20;
                        
                        car.set_moneyOwed(fee);
                        
                    }
                    
                    if (car.get_timePeriod() == 2) {
                        
                        fee = 22.5;
                        
                        car.set_moneyOwed(fee);
                        
                    }
                    
                    if (car.get_timePeriod() == 3) {
                        
                        fee = 27.5;
                        
                        car.set_moneyOwed(fee);
                        
                    }
                    
                    if (car.get_timePeriod() == 4) {
                        
                        fee = 34.5;
                        
                        car.set_moneyOwed(fee);
                        
                    }
                    
                    if (car.get_timePeriod() == 5) {
                        
                        fee = 44.5;
                        
                        car.set_moneyOwed(fee);
                        
                    }
                    
                }
                
                
                
                
                //asks for make, model, color, and license plate of vehicle
                cout << "\nPlease enter your vehicle's make: ";
                
                cin >> makeInput;
                
                
                cout << "\nPlease enter your vehicle's model: ";
                
                cin >> modelInput;
                
                
                cout << "\nPlease enter your vehicle's color: ";
                
                cin >> colorInput;
                
                
            EnterLicensePlate:
                
                cout << "\nPlease enter a 6 character license plate number: ";
                
                cin >> lpInput;
                
                
                //checks that the license plate is exactly 6 characters long
                while (lpInput.length() != 6) {
                    
                    cout << "Please enter a 6 character license plate number: ";
                    
                    cin >> lpInput;
                    
                }
                
                
                //checks that each character in the string is either a number or a letter
                for (int i = 0; i < 6; i++)     {
                    
                    if (isalnum(lpInput.at(i)) == false) {
                        
                        cout << "\nYou entered an invalid character."
                        << "\nPlease enter a license plate with only numbers and letters." << endl;
                        
                        cin >> lpInput;
                        
                    }
                    
                }
                
                //checks that there is no repeat license plate, then asks user what they would like to do if there is
                for (int i = 0; i < NUM_FLOORS; i++){
                    
                    for (int j = 0; j < NUM_SPACES; j++) {
                        
                        if (lpInput.compare(carsList[i][j].get_lpNum()) == 0) {
                            
                            int lpMistake = 0;
                            
                            
                            cout << "\nThis car is already parked in the garage, and is located at:\n" <<
                            "\t----------\n" <<
                            "\t| Floor " << carsList[i][j].get_floorNum() << " |\n" <<
                            "\t| Space " << carsList[i][j].get_spaceNum() << " |\n" <<
                            "\t----------\n";
                            
                            
                            
                        lpMistakeQuestion: //goto when default case
                            
                            
                            
                            cout << "\nWould you: \n" <<
                            "1. Like to enter a different license plate number\n"
                            "2. Like to retrieve your already parked car\n" <<
                            "3. Like to find your lost car\n" <<
                            "4. Like to leave the garage (restart the program)";
                            
                            cout << "\nChoice: ";
                            
                            cin >> lpMistake;
                            
                            cout << endl;
                            
                            while (cin.fail()) {
                                
                                cin.clear(); //Resets the flags so you can input again
                                
                                cin.ignore(100, '\n'); //Empty the buffer
                                
                                cout << "Please enter an integer!\n";
                                
                                cin >> lpMistake;
                                
                            }
                            
                            
                            switch (lpMistake) {
                                    
                                case 1:
                                    
                                {
                                    
                                    goto EnterLicensePlate; //restarts the entering of a license plate
                                    
                                    break;
                                    
                                }
                                    
                                case 2:
                                    
                                {
                                    
                                    goto CheckoutProcess; //goes to case 2 of the main menu switch statement, user can recieve their already parked car
                                    
                                    break;
                                    
                                }
                                    
                                case 3:
                                    
                                {
                                    
                                    goto FindLostCar; //goes to case 3 of the main menu switch statement, usr can find their lost car through license
                                    
                                    break;
                                    
                                }
                                    
                                case 4:
                                    
                                {
                                    goto RepeatProgram; //asks use if they'd like to repeat the program or quit
                                    
                                    break;
                                }
                                    
                                    //user picked an optn that was not in menuio
                                default:
                                    
                                {
                                    
                                    cout << "That wasn't an option, please choose from the available options.\n\n";
                                    
                                    goto lpMistakeQuestion; //goto: what the user would like to do after entering a repeat
                                    
                                }
                                    
                                    
                            }
                            
                        }
                        
                    }
                    
                } //end of loop that checks for duplicate license plate
                
                
                
                //if else statement assigns new car object to a place in the carsList 2D array
                
                //VIP cars will only be in the "first floor" or rather the array in index 0 of the 2D array
                if (car.get_isVIP() == true) {
                    
                    for (int j = 0; j < NUM_SPACES; j++) { //sets all the variables of the selected space to the information entered by user
                        
                        if (carsList[0][j].get_isOccupied() == false) {
                            
                            carsList[0][j].set_floorNum(1);
                            
                            carsList[0][j].set_spaceNum(j + 1);
                            
                            carsList[0][j].set_isOccupied(true);
                            
                            carsList[0][j].set_isVIP(true);
                            
                            carsList[0][j].set_make(makeInput);
                            
                            carsList[0][j].set_model(modelInput);
                            
                            carsList[0][j].set_color(colorInput);
                            
                            carsList[0][j].set_lpNum(lpInput);
                            
                            carsList[0][j].set_timePeriod(car.get_timePeriod());
                            
                            carsList[0][j].set_moneyOwed(car.get_moneyOwed());
                            
                            cout << "\nYou have been assigned a VIP space at:\n" <<
                            "\t----------\n" <<
                            "\t| Floor " << carsList[0][j].get_floorNum() << " |\n" <<
                            "\t| Space " << carsList[0][j].get_spaceNum() << " |\n" <<
                            "\t----------" <<
                            "\nHave a great day sir/madame!" << endl;
                            
                            projectedProfit += carsList[0][j].get_moneyOwed(); //used for the manager function to see potential profit (cars parked + cars left)
                            
                            goto successfulPark; //the car is done parking, end of case 1 of the main menu switch statement
                            
                        }
                        
                    }
                    
                }
                
                //Regular cars will be assigned to spots in the second row and up, there for index 1 of the large array and forward
                else {
                    
                regularSpot:
                    
                    for (int i = 1; i < NUM_FLOORS; i++) {
                        
                        for (int j = 0; j < NUM_SPACES; j++) {
                            
                            if (carsList[i][j].get_isOccupied() == false) {
                                
                                //sets all the variables of the selected space to the information entered by user
                                carsList[i][j].set_floorNum(i + 1);
                                
                                carsList[i][j].set_spaceNum(j + 1);
                                
                                carsList[i][j].set_isOccupied(true);
                                
                                carsList[i][j].set_make(makeInput);
                                
                                carsList[i][j].set_model(modelInput);
                                
                                carsList[i][j].set_color(colorInput);
                                
                                carsList[i][j].set_lpNum(lpInput);
                                
                                carsList[i][j].set_timePeriod(car.get_timePeriod());
                                
                                carsList[i][j].set_moneyOwed(car.get_moneyOwed());
                                
                                //used for the manager function to see potential profit (cars parked + cars left)
                                projectedProfit += carsList[i][j].get_moneyOwed();
                                
                                
                                
                                cout << "\nYou have been assigned a regular space at:\n" <<
                                "\t----------\n" <<
                                "\t| Floor " << carsList[i][j].get_floorNum() << " |\n" <<
                                "\t| Space " << carsList[i][j].get_spaceNum() << " |\n" <<
                                "\t----------" <<
                                "\nHave an ok day, regular parker." << endl;
                                
                                goto successfulPark; //case was parked, case 1 over
                                
                            }
                            
                        }
                        
                    }
                    
                } //end of "else, regular spot"
                
            successfulPark: //car was parked, case 1 over
                
                break; //end of the case 1, car arriving in the parking lot
                
            }
                
                //Main menu switch case 2: receiving an already parked car
            case 2:
                
            {
                
            CheckoutProcess:
                
                string temp = ""; //used to verify lp given by user
                string timePeriod = ""; //used to print time period stayed by user
                
                
                cout << "\nCheckout:\n";
                
                //ask the user which car is about to leave the garage
            FloorInputUser:
                
                
                cout << "\nPlease enter your floor number: ";
                
                cin >> floorTemp;
                
                while (cin.fail()) {
                    
                    cin.clear(); //Resets the flags so you can input again
                    
                    cin.ignore(100, '\n'); //Empty the buffer
                    
                    cout << "Please enter an integer!\n";
                    
                    cin >> floorTemp;
                    
                }
                
                if (floorTemp > NUM_FLOORS || floorTemp < 1) {
                    
                    cout << "\nThat is not a valid floor in this garage. Please enter a proper floor." << endl;
                    
                    goto FloorInputUser;
                    
                }
                
            SpaceInputUser:
                
                cout << "\nPlease enter your space number: ";
                
                cin >> spaceTemp;
                
                while (cin.fail()) {
                    
                    cin.clear(); //Resets the flags so you can input again
                    
                    cin.ignore(100, '\n'); //Empty the buffer
                    
                    cout << "Please enter an integer!\n";
                    
                    cin >> spaceTemp;
                    
                }
                
                if (spaceTemp > NUM_SPACES || spaceTemp < 1) {
                    
                    cout << "\nThat is not a valid space in this garage. Please enter a proper space." << endl;
                    
                    goto SpaceInputUser;
                    
                }
                
                
                
                //asks for license plate to verify correct person is taking the car
                if (carsList[floorTemp - 1][spaceTemp - 1].get_isOccupied() == true || carsList[floorTemp - 1][spaceTemp - 1].get_isTowed() == true) {
                    
                    cout << "\nPlease re-enter your license plate number to ensure you receive the correct bill:";
                    
                    cin >> temp;
                    
                    cout << endl;
                    
                    
                    
                    string s = carsList[floorTemp - 1][spaceTemp - 1].get_lpNum();
                    
                    if (carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 1){
                        
                        timePeriod = "less than 1 hour.";
                        
                    }
                    
                    else if (carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 2){
                        
                        timePeriod = "1 - 3 hours.    ";
                        
                    }
                    
                    else if (carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 3){
                        
                        timePeriod = "3 - 6 hours.    ";
                        
                    }
                    
                    else if (carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 4){
                        
                        timePeriod = "6 - 12 hours.    ";
                        
                    }
                    
                    else if (carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 5){
                        
                        timePeriod = "12 - 24 hours.    ";
                        
                    }
                    
                    //checks if entered lpNum matches the one provided during car registration, if so, continues checkout process
                    if (s.compare(temp) == 0) {
                        
                        //if car has been towed, warn the user that their car needs to be retrieved and that a fee will be added to the bill
                        if (carsList[floorTemp - 1][spaceTemp - 1].get_isTowed() == true){
                            
                            cout << "\nWe are very sorry, your " << carsList[floorTemp - 1][spaceTemp - 1].get_color() << " "
                            << carsList[floorTemp - 1][spaceTemp - 1].get_make() << " " << carsList[floorTemp - 1][spaceTemp - 1].get_model()
                            << " has been towed. A $200 charge has been added to your bill. You can contact us at the number on the receipt for steps on retrieving your car." << endl;
                            
                            //carsList[floorTemp - 1][spaceTemp - 1].set_isTowed(false);
                            
                        }
                        
                        //car was not towed, is still in the garage
                        else{
                            
                            cout << "You have parked your " << carsList[floorTemp - 1][spaceTemp - 1].get_color() << " "
                            << carsList[floorTemp - 1][spaceTemp - 1].get_make()
                            << " " << carsList[floorTemp - 1][spaceTemp - 1].get_model() << " for "
                            << timePeriod << endl;
                            
                        }
                        
                        
                        //gets moneyOwed from car
                        cout.precision(2);
                        
                        cout << "\nYour total comes out to $" << fixed << carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed() << endl;
                        
                        
                        //resets the space as empty so another car can be parked there
                        carsList[floorTemp - 1][spaceTemp - 1].set_isOccupied(false);
                        
                        carsList[floorTemp - 1][spaceTemp - 1].set_lpNum("");
                        
                    }
                    
                    //error case - space is occupied but provided license plate doesn't match
                    else {
                        
                        cout << "\nThe license plate number you entered did not match the car space provided."
                        << "\nTo ensure you aren't trying to park-n-dash or steal a car, please try again!" << endl;
                        
                        
                        goto CheckoutProcess; //asks for persons information again
                        
                    }
                    
                    
                }
                //error case - given space isn't occupied - else matches carsList[][].get_isOccupied()
                else {
                    
                    if (carsList[floorTemp - 1][spaceTemp - 1].get_isTowed() == true) { //they space may not be occupied because it was towed
                        
                        cout << "\nWe are very sorry, your " << carsList[floorTemp - 1][spaceTemp - 1].get_color() << " "
                        << carsList[floorTemp - 1][spaceTemp - 1].get_make() << " " << carsList[floorTemp - 1][spaceTemp - 1].get_model()
                        << " has been towed. A $200 charge has been added to your bill. ";
                        
                        cout << "You can contact us at the number on the receipt for steps on retrieving your car." << endl;
                        
                    }
                    
                    else {
                        
                        cout << "\nOops, looks like that space wasn't occupied, please try again!" << endl;
                        
                        
                        goto CheckoutProcess; //asks for users information again
                        
                    }
                    
                }
                
                //Payment options (cash or credit)
                
            PaymentQuestion:
                
                cout << "\n\tHow would you like to pay?" << endl;
                
                cout << "\t-----------------------------" << endl;
                
                cout << "\t1. Cash" << endl;
                
                cout << "\t2. Card" << endl;
                
                cout << "\t Choice: ";
                
                cin >> paymentChoice;
                
                while (cin.fail()) {
                    
                    cin.clear(); //Resets the flags so you can input again
                    
                    cin.ignore(100, '\n'); //Empty the buffer
                    
                    cout << "Please enter an integer!\n";
                    
                    cin >> paymentChoice;
                    
                }
                
                if (paymentChoice < 1 || paymentChoice > 2) { //makes sure user doesn't enter a number that is not an option
                    
                    cout << "That wasn't an option.\n";
                    
                    goto PaymentQuestion; //goes back to asking how they would like to pay
                    
                }
                
                //user chooses to pay in cash
                if (paymentChoice == 1) {
                    
                    bool incorrectPayment = true; //makes sure that the amount is correctly paid - for the do while loop
                    
                    cash = 0;
                    
                    cout << "\nPlease input your cash payment into the machine.\n\n";
                    
                    do {
                        
                        cout << "\n\tCash amount entered: $";
                        
                        cin >> payment;
                        
                        while (cin.fail()) {
                            
                            cin.clear(); //Resets the flags so you can input again
                            
                            cin.ignore(100, '\n'); //Empty the buffer
                            
                            cout << "Please enter a valid cash amount!\n";
                            
                            cin >> payment;
                            
                        }
                        
                        cash += payment;
                        
                        change = cash - carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed(); //change algorithm
                        
                        //user did not input enough cash
                        if (change < 0) {
                            
                            cout << "\nSorry, you have not given enough money. "
                            << "Please input additional cash payment.";
                            
                        } //now we go to the end of the loop where incorrect payment is still false - asks again
                        
                        //user entered exact amount of cash
                        else if (change == 0) {
                            
                            cout << "Your change is $0.00. ";
                            
                            
                            //used for manager function where they ask for the profit made (cars that have already left)
                            realProfit += carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed();
                            
                            
                        ReceiptCashQuestion1: //goto for an invalid option
                            
                            cout << "Would you like a receipt?\n1. Yes\n2. No\n";
                            
                            cin >> receiptChoice;
                            
                            while (cin.fail()) {
                                
                                cin.clear(); //Resets the flags so you can input again
                                
                                cin.ignore(100, '\n'); //Empty the buffer
                                
                                cout << "Please enter an integer!\n";
                                
                                cin >> receiptChoice;
                                
                            }
                            
                            //makes sure user doesn't enter number thats not an option
                            if (receiptChoice < 1 || receiptChoice > 2) {
                                
                                cout << "That wasn't an option. Please select from the options given.\n";
                                
                                goto ReceiptCashQuestion1; //repeats the question of payment type
                                
                            }
                            
                            if (receiptChoice == 1) { //if the user wants a receipt, prints the payment info formatted
                                
                                //gets moneyOwed from car
                                
                                
                                cout << "  ______________________________________________________\n";
                                
                                cout << " |  Thank for for parking at the Zanach Parking Garage\t|\n" <<
                                " |\t\t\t\t\t\t\t|\n";
                                
                                
                                if (carsList[floorTemp - 1][spaceTemp - 1].get_isVIP() == true) {
                                    
                                    cout << " |  You were a VIP today!\t\t\t\t|\n |  You're more important than other people.\t\t|" <<
                                    "\n |\t\t\t\t\t\t\t|\n";
                                    
                                }
                                
                                
                                cout << " |  You parked for " << timePeriod << "\t\t\t|\n" <<
                                " |\t\t\t\t\t\t\t|\n";
                                
                                cout.precision(2);
                                
                                cout << " |  Total: $" << fixed << carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed() << "\t\t\t\t\t|\n";
                                
                                cout << " |  You paid $" << fixed << payment << " in cash.\t\t\t\t|\n";
                                
                                cout << " |  Change: $" << fixed << change << ".\t\t\t\t\t|\n" <<
                                " |\t\t\t\t\t\t\t|\n";
                                
                                cout << " |  ---\t\t\t\t\t\t\t|\n" <<
                                " |\t\t\t\t\t\t\t|\n";
                                
                                cout << " |  Questions, comments, or concerns? \t\t\t|\n";
                                
                                cout << " |  Contact Us: 1-(800)-1-ZANACH\t\t\t|\n";
                                
                                cout << "  ______________________________________________________\n";
                                
                            }
                            
                            cout << "Thank you, and have a great day!";
                            
                            incorrectPayment = false; //payment worked, continue on in checkout
                            
                        }
                        
                        //user entered more than the required amount of cash
                        else {
                            
                            cout.precision(2);
                            
                            cout << "\nYour change is $" << fixed << change << ". ";
                            
                            //used for manager function where they ask for the profit made (cars that have already left)
                            realProfit += carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed();
                            
                        ReceiptCashQuestion2: //goto for invalid option
                            
                            cout << "Would you like a receipt?\n\t1.Yes\n\t2.No\n\tChoice: ";
                            
                            cin >> receiptChoice;
                            
                            while (cin.fail()) {
                                
                                cin.clear(); //Resets the flags so you can input again
                                
                                cin.ignore(100, '\n'); //Empty the buffer
                                
                                cout << "Please enter an integer!\n";
                                
                                cin >> receiptChoice;
                                
                            }
                            
                            //makes sure user doesn't enter number thats not an option
                            if (receiptChoice < 1 || receiptChoice > 2) {
                                
                                cout << "That wasn't an option. Please select from the options given.\n";
                                
                                goto ReceiptCashQuestion2; //asks again if you'd like a receipt
                                
                            }
                            
                            if (receiptChoice == 1) { //if the user wants a receipt, prints the payment info formatted
                                
                                cout << "  ______________________________________________________\n";
                                
                                cout << " |  Thank for for parking at the Zanach Parking Garage\t|\n" <<
                                " |\t\t\t\t\t\t\t|\n";
                                
                                
                                
                                if (carsList[floorTemp - 1][spaceTemp - 1].get_isVIP() == true) {
                                    
                                    cout << " |  You were a VIP today!\t\t\t\t|\n |  You're more important than other people.\t\t|" <<
                                    "\n |\t\t\t\t\t\t\t|\n";
                                    
                                }
                                
                                
                                
                                cout << " |  You parked for " << timePeriod << "\t\t\t|\n" <<
                                " |\t\t\t\t\t\t\t|\n";
                                
                                cout.precision(2);
                                
                                cout << " |  Total: $" << fixed << carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed() << "\t\t\t\t\t|\n";
                                
                                cout << " |  You paid $" << fixed << payment << " in cash.\t\t\t\t|\n";
                                
                                cout << " |  Change: $" << fixed << change  << "\t\t\t\t\t|\n" <<
                                " |\t\t\t\t\t\t\t|\n";
                                
                                cout << " |  ---\t\t\t\t\t\t\t|\n" <<
                                " |\t\t\t\t\t\t\t|\n";
                                
                                cout << " |  Questions, comments, or concerns? \t\t\t|\n";
                                
                                cout << " |  Contact Us: 1-(800)-1-ZANACH\t\t\t|\n";
                                
                                cout << "  ______________________________________________________\n";
                                
                            }
                            
                            cout << "\nPlease take your change and have a great day!" << endl;
                            
                            incorrectPayment = false; //payment worked, continue on in checkout
                            
                        }
                        
                    } while (incorrectPayment == true); //will repeat asking for cash until payment is fulfilled
                    
                }
                
                else if (paymentChoice == 2)
                    
                {
                    
                    cout << "Please insert your card.\n";
                    
                    usleep(1200000); //usleeps to give the illusion of the processing card
                    
                    cout << "Authorizing";
                    
                    usleep(1000000);
                    
                    cout << ".";
                    
                    usleep(1000000);
                    
                    cout << ".";
                    
                    usleep(1000000);
                    
                    cout << ".";
                    
                    usleep(1000000);
                    
                    cout << "\nAccepted. \n";
                    
                    usleep(500000);
                    
                    //used for manager function where they ask for the profit made (cars that have already left)
                    realProfit += carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed();
                    
                ReceiptCardQuestion: //goto for invalid option
                    
                    cout << "Would you like a receipt?\n1.Yes\n2.No\n";
                    
                    cin >> receiptChoice;
                    
                    while (cin.fail()) {
                        
                        cin.clear(); //Resets the flags so you can input again
                        
                        cin.ignore(100, '\n'); //Empty the buffer
                        
                        cout << "Please enter an integer!\n";
                        
                        cin >> receiptChoice;
                        
                    }
                    
                    //makes sure user doesn't enter number thats not an option
                    if (receiptChoice < 1 || receiptChoice > 2) {
                        
                        cout << "That wasn't an option.\n";
                        
                        goto ReceiptCardQuestion;
                        
                    }
                    
                    if (receiptChoice == 1) { //if the user wants a receipt, prints the payment info formatted
                        
                        
                        //gets moneyOwed from car
                        
                        
                        cout << "  ______________________________________________________\n";
                        
                        cout << " |  Thank for for parking at the Zanach Parking Garage\t|\n" <<
                        " |\t\t\t\t\t\t\t|\n";
                        
                        
                        
                        if (carsList[floorTemp - 1][spaceTemp - 1].get_isVIP() == true) {
                            
                            cout << " |  You were a VIP today!\t\t\t\t|\n |  You're more important than other people.\t\t|" <<
                            "\n |\t\t\t\t\t\t\t|\n";
                            
                        }
                        
                        
                        
                        cout << " |  You parked for " << timePeriod << "\t\t\t|\n" <<
                        " |\t\t\t\t\t\t\t|\n";
                        
                        cout.precision(2);
                        
                        cout << " |  Total: $" << fixed << carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed()<< "\t\t\t\t\t|\n";
                        
                        cout << " |  You paid with card **** **** **** 3503\t\t|\n" <<
                        " |\t\t\t\t\t\t\t|\n";
                        
                        cout << " |  ---\t\t\t\t\t\t\t|\n" <<
                        " |\t\t\t\t\t\t\t|\n";
                        
                        cout << " |  Questions, comments, or concerns? \t\t\t|\n";
                        
                        cout << " |  Contact Us: 1-(800)-1-ZANACH\t\t\t|\n";
                        
                        cout << "  ______________________________________________________\n";
                        
                    }
                    
                    cout << "Have a great day!" << endl; //payment automatically works with card
                    
                }
                
                break;
                
            } //end of case 2, main menu
                
                
            case 3: //find car function from main menu
                
            {
                
                //user does not know their space, so they can enter their license plate to find their car
                
            FindLostCar:
                
                //used to access elemtns of the carsList array
                int floorNum = 1;
                
                int spaceNum = 1;
                
                
                //asks user for license plate number to locate correct car object
                cout << "Please enter your license plate number: ";
                
                cin >> lpTemp;
                
                cout << endl;
                
                
                //need to loop through arrays to find car object with given license plate number
                //get floorNum and spaceNum when correct object is found and display them to the user
                for (int i = 0; i < NUM_FLOORS; i++) {
                    
                    for (int j = 0; j < NUM_SPACES; j++) {
                        
                        if (lpTemp.compare(carsList[i][j].get_lpNum()) == 0) {
                            
                            floorNum = i + 1; //arrays start at 0, but parking garages don't!
                            
                            spaceNum = j + 1;
                            
                            goto FoundCar; //car was found, goes to displaying information
                            
                        }
                        
                    }
                    
                } goto DidNotFindCar; //if the loop is never quit midway, the car was never found, and the user is asked if they'd like to try again
                
            FoundCar:
                
                if (carsList[floorNum - 1][spaceNum - 1].get_isTowed() == true) { //if the car was towed the user must go retrieve it
                    
                    cout << "We are very sorry, your " << carsList[floorNum - 1][spaceNum - 1].get_color() << " "
                    << carsList[floorNum - 1][spaceNum - 1].get_make() << " " << carsList[floorNum - 1][spaceNum - 1].get_model()
                    << " that was parked on floor " << floorNum << " in space " << spaceNum << " has been towed. "
                    << "A $200 charge has been added to your bill. You can contact us at the number on the receipt for steps on retrieving your car."
                    << " Please hold while you are sent to the checkout process." << endl;
                    
                    
                    usleep(500000); //waits for a moment before going to the checkout process
                    
                    goto CheckoutProcess; //takes user to case 2 to pay for their towed car
                    
                }
                
                else { //if license plate exists, shows where the car is
                    
                    cout << "Your " << carsList[floorNum - 1][spaceNum - 1].get_color() << " " << carsList[floorNum - 1][spaceNum - 1].get_make() << " "
                    << carsList[floorNum - 1][spaceNum - 1].get_model() << " is located at:\n" <<
                    "\t----------\n" <<
                    "\t| Floor " << carsList[floorNum - 1][spaceNum - 1].get_floorNum() << " |\n" <<
                    "\t| Space " << carsList[floorNum - 1][spaceNum - 1].get_spaceNum() << " |\n" <<
                    "\t----------\n";
                    
                }
                
                goto EndFindCar;
                
            DidNotFindCar:
                
                int retry; //choice int for retrying to find car
                
                cout << "Your car is not in this lot! Better go find it!\n";
                
            LicenseRetry:
                
                cout << "\nWould you like to retry a different license plate number?\n" <<
                "1. Yes\n"
                "2. No\n";
                
                cout << "\nChoice: ";
                
                cin >> retry;
                
                while (cin.fail()) {
                    
                    cin.clear(); //Resets the flags so you can input again
                    
                    cin.ignore(100, '\n'); //Empty the buffer
                    
                    cout << "Please enter an integer!\n";
                    
                    cin >> retry;
                    
                }
                
                //switch for what to do when user is asked to retry
                switch (retry)
                {
                        
                    case 1:
                        
                    {
                        
                        goto FindLostCar; //will go back to asking for more information
                        
                        break;
                        
                    }
                        
                    case 2:
                        
                    {
                        
                        cout << "\nGood luck finding your car!!\n"; //leaves and will end up asking for main menu continuation
                        
                        break;
                        
                    }
                        
                    default:
                        
                    {
                        
                        cout<<"That was not an option, please choose from the available options"; //makes sure user enters a valid option
                        
                        goto LicenseRetry; //goes back to asking for an option
                        
                        break;
                        
                    }
                        
                }
                
            EndFindCar:
                
                break;
                
            } //end of case 3
                
            case 4: //manager menu option from main menu
                
            {
                
                //usernames are first names and password is set to "password" by default
                //but can be changed. Once logged on, manager gains access to manager menu.
                
                //Functions include finding license plates, space information, current and
                //projected profit, towing cars, and changing passwords
                
                //input variables from the user
                string username = "";
                
                string password = "";
                
                
            managerMenu:
                
                cout << "\n\tLogin" << endl;
                
                cout << "\t------" << endl;
                
                cout << "\tManager Username: ";
                
                cin >> username;
                
                //incorrect password inputs get sent here
            incorrectPass:
                
                cout << "\tManager Password: ";
                
                cin >> password;
                
                
                
                
                //series of if else statements that checks the login for managers
                //if an incorrect username or password is entered, the program asks again
                //uses username and password to find correct manager login
                
                //Clayton manager
                if (username.compare(clayton->get_username()) == 0) {
                    
                    if (password.compare(clayton->get_password()) == 0) {
                        
                        goto next;
                        
                    }
                    
                    //if password is incorrect for the user, returns to password and asks again
                    else {
                        
                        cout << "\nIncorrect Password, please try again.\n" << endl;
                        
                        goto incorrectPass;
                        
                    }
                    
                }
                
                
                
                //Zahin manager
                if (username.compare(zahin->get_username()) == 0) {
                    
                    if (password.compare(zahin->get_password()) == 0) {
                        
                        goto next;
                        
                    }
                    
                    else {
                        
                        cout << "\nIncorrect Password, please try again.\n" << endl;
                        
                        goto incorrectPass;
                        
                    }
                    
                }
                
                
                
                //Neha Manager
                if (username.compare(neha->get_username()) == 0) {
                    
                    if (password.compare(neha->get_password()) == 0) {
                        
                        goto next;
                        
                    }
                    
                    else {
                        
                        cout << "\nIncorrect Password, please try again.\n" << endl;
                        
                        goto incorrectPass;
                        
                    }
                    
                }
                
                
                
                //Andrew Manager
                if (username.compare(andrew->get_username()) == 0) {
                    
                    if (password.compare(andrew->get_password()) == 0) {
                        
                        goto next;
                        
                    }
                    
                    else {
                        
                        cout << "\nIncorrect Password, please try again.\n" << endl;
                        
                        goto incorrectPass;
                        
                    }
                    
                }
                
                
                
                
                //Christopher manager
                if (username.compare(topher->get_username()) == 0) {
                    
                    if (password.compare(topher->get_password()) == 0) {
                        
                        goto next;
                        
                    }
                    
                    else {
                        
                        cout << "\nIncorrect Password, please try again.\n" << endl;
                        
                        goto incorrectPass;
                        
                    }
                    
                }
                
                
                
                
                //Harsh manager
                if (username.compare(harsh->get_username()) == 0) {
                    
                    if (password.compare(harsh->get_password()) == 0) {
                        
                        goto next;
                        
                    }
                    
                    else {
                        
                        cout << "\nIncorrect Password, please try again.\n" << endl;
                        
                        goto incorrectPass;
                        
                    }
                    
                }
                
                //not recognized username input, retries asking for username
                cout << "\nUsername not recognized, try again.\n" << endl;
                
                goto managerMenu;
                
                
                //only reaches this point after successful login
            next:
                
                cout << "\n\tSuccessful Login!\n" << endl;
                
                //while loop variable
                int quitManager = 1;
                
                //while loop for manager menu
                while (quitManager == 1) {
                    
                ManagerMenu:
                    
                    cout << "\n\tMANAGER MENU (Or 0 to exit to Main Menu)" << endl;
                    
                    cout << "\t---------------" << endl;
                    
                    //prints a list of the current license plates in the garage
                    
                    cout << "\n\t1. Print All License Plates" << endl;
                    
                    
                    
                    //prints out all details associated with a particular space
                    //isOccupied == true, then prints all details
                    //if false, informs user that the space is empty
                    cout << "\t2. Print Space Info" << endl;
                    
                    
                    
                    //Prints total of all money paid today
                    cout << "\t3. Print Current Profit" << endl;
                    
                    
                    
                    //prints projected profit
                    cout << "\t4. Projected Profit" << endl;
                    
                    
                    
                    //gives user the choice to change password
                    cout << "\t5. Tow errant car" << endl;
                    
                    
                    
                    //ability for a manager to change their password
                    cout << "\t6. Change Password" << endl;
                    
                    
                    
                    cout << "\tChoice: ";
                    
                    cin >> managerMenuChoice;
                    
                    
                    while (cin.fail()) {
                        
                        cin.clear(); //Resets the flags so you can input again
                        
                        cin.ignore(100, '\n'); //Empty the buffer
                        
                        cout << "Please enter an integer!\n";
                        
                        cin >> managerMenuChoice;
                        
                    }
                    
                    
                    //switch case for manager menu
                    switch (managerMenuChoice)
                    
                    {
                            
                            //Breaks out of manager menu, returns to main menu to continue running code
                        case 0:
                            
                        {
                            
                            //sends up to main menu print out
                            goto MainMenuQuestion;
                            
                            break;
                            
                        }
                            
                            //LICENSE PLATE manager function
                            //    prints the license plates of all cars in garage.
                        case 1:
                            
                        {
                            
                            cout << "\nCurrent License Plates in the Garage:\n\n";
                            
                            cout << "Floor\tSpace\tLicense Plate #\t\n";
                            
                            for (int i = 0; i < NUM_FLOORS; i++) {
                                
                                for (int j = 0; j < NUM_SPACES; j++) {
                                    
                                    if (carsList[i][j].get_lpNum().empty() == false) {
                                        
                                        cout <<
                                        "------------------------------------\n" <<
                                        carsList[i][j].get_floorNum() << "\t" <<
                                        carsList[i][j].get_spaceNum() << "\t" <<
                                        carsList[i][j].get_lpNum() << "\t\n" << endl;
                                        
                                    }
                                    
                                }
                                
                            }
                            
                            cout << "------------------------------------\n";
                            
                            break;
                            
                        }
                            
                            //SPACE INFO manager function
                            //prints out any space at the user's request, if it contains a car, prints car info as well
                        case 2:
                            
                        {
                            
                        GetSpaceInfo:
                            
                            //temp inputs for car location
                            int temp1 = 0;//floor
                            
                            int temp2 = 0;//space
                            
                        FloorInputManager:
                            
                            cout << "\nFloor Number: ";
                            
                            cin >> temp1;
                            
                            while (cin.fail()) {
                                
                                cin.clear(); //Resets the flags so you can input again
                                
                                cin.ignore(100, '\n'); //Empty the buffer
                                
                                cout << "Please enter an integer!\n";
                                
                                cin >> temp1;
                                
                            }
                            
                            if (temp1 > NUM_FLOORS || temp1 < 1) {
                                
                                cout << "\nThat is not a valid floor in this garage. Please enter a proper floor." << endl;
                                
                                goto FloorInputManager;
                                
                            }
                            
                        SpaceInputManager:
                            
                            cout << "\nSpace Number: ";
                            
                            cin >> temp2;
                            
                            while (cin.fail()) {
                                
                                cin.clear(); //Resets the flags so you can input again
                                
                                cin.ignore(100, '\n'); //Empty the buffer
                                
                                cout << "Please enter an integer!\n";
                                
                                cin >> temp2;
                                
                            }
                            
                            if (temp2 > NUM_SPACES || temp2 < 1) {
                                
                                cout << "\nThat is not a valid space in this garage. Please enter a proper space." << endl;
                                
                                goto SpaceInputManager;
                                
                            }
                            
                            //checks if a car is parked in the given space
                            
                            if (carsList[temp1 - 1][temp2 - 1].get_isOccupied() == true) {
                                
                                //if one is, obtain car information and print
                                cout << "\nFloor "  << temp1 << ", Space " << temp2 << " Info:" << endl;
                                
                                cout << "----------------------------" << endl;
                                
                                //VIP yes or no
                                if (carsList[temp1 - 1][temp2 - 1].get_isVIP() == true) {
                                    
                                    cout << "\tVIP: Y" << endl;
                                    
                                }
                                
                                else {
                                    
                                    cout << "\tVIP: N" << endl;
                                    
                                }
                                
                                //other car info
                                cout << "\tLicense Plate: " << carsList[temp1 - 1][temp2 - 1].get_lpNum() << endl;
                                
                                cout << "\tColor: " << carsList[temp1 - 1][temp2 - 1].get_color() << endl;
                                
                                cout << "\tMake: " << carsList[temp1 - 1][temp2 - 1].get_make() << endl;
                                
                                cout << "\tModel: " << carsList[temp1 - 1][temp2 - 1].get_model() << endl;
                                
                            }
                            
                            //if no car, print:
                            else {
                                
                                cout << "\nThat space is empty." << endl;
                                
                                //asks user to repeat process for another space, if answer is no, breaks out (no code needed)
                            DifferentSpaceInfo:
                                
                                cout << "\nGet info for a different space?\n\t1.Yes\n\t2.No\n";
                                
                                cout << "Choice: ";
                                
                                cin >> getMoreInfo;
                                
                                while (cin.fail()) {
                                    
                                    cin.clear(); //Resets the flags so you can input again
                                    
                                    cin.ignore(100, '\n'); //Empty the buffer
                                    
                                    cout << "Please enter an integer!\n";
                                    
                                    cin >> getMoreInfo;
                                    
                                }
                                
                                //sends up to restart case
                                if (getMoreInfo == 1){
                                    
                                    goto GetSpaceInfo;
                                    
                                }
                                
                                //if integer but not an option, re-ask
                                else if (getMoreInfo < 1 || getMoreInfo > 2){
                                    
                                    cout << "\nThat wasn't an option, please select from the options";
                                    
                                    goto DifferentSpaceInfo;
                                    
                                }
                                
                            }
                            
                            break;
                            
                            
                            
                        }//end of Space Info (case 2)
                            
                            //Today's profit manager function
                            //    prints out the total profit earned from the current session,
                            //    i.e money from all the cars that have left the garage up until this point
                        case 3:
                            
                        {
                            
                            //sets output to print ".00"
                            cout.precision(2);
                            
                            cout << "The total profit made today: $" << fixed << realProfit << endl;
                            
                            
                            break;
                            
                        }
                            
                            //projected money manager function
                            //    prints out the money that would be earned from every car CURRENTLY parked in the garage at this time
                        case 4:
                            
                        {
                            
                            //sets output to print ".00"
                            cout.precision(2);
                            
                            cout << "The total projected profit for today is: $" << fixed << projectedProfit << endl;
                            
                            break;
                            
                        }
                            
                            //TOW CAR manager function case
                            //gives manager the ability to remove a car from the garage. Frees up space and adds a fee to owner
                        case 5:
                            
                        {
                            
                            //temp inputs for car location
                            int temp1 = 0;//floor
                            
                            int temp2 = 0;//space
                            
                            int choice;
                            
                            //goto sends here if user wants to retry towing a car
                        TowCarQuestion:
                            
                            cout << "\nWhich floor is the car that needs to be towed on? ";
                            
                            cin >> temp1;
                            
                            while (cin.fail()) {
                                
                                cin.clear(); //Resets the flags so you can input again
                                
                                cin.ignore(100, '\n'); //Empty the buffer
                                
                                cout << "Please enter an integer!\n";
                                
                                cin >> temp1;
                                
                            }
                            
                            if (temp1 > NUM_FLOORS || temp1 < 1) {
                                
                                cout << "\nThat is not a valid floor in this garage. Please enter a proper floor." << endl;
                                
                                goto TowCarQuestion;
                                
                            }
                            
                        SpaceInputTow:
                            
                            cout << "\nWhich space Number? ";
                            
                            cin >> temp2;
                            
                            while (cin.fail()) {
                                
                                cin.clear(); //Resets the flags so you can input again
                                
                                cin.ignore(100, '\n'); //Empty the buffer
                                
                                cout << "Please enter an integer!\n";
                                
                                cin >> temp2;
                                
                            }
                            
                            if (temp2 > NUM_SPACES || temp2 < 1) {
                                
                                cout << "\nThat is not a valid space in this garage. Please enter a proper space." << endl;
                                
                                goto SpaceInputTow;
                                
                            }
                            
                            //checks if a car is parked in the given space
                            //if a car is there, prints out its information to confirm car
                            if (carsList[temp1 - 1][temp2 - 1].get_isOccupied() == true) {
                                
                                cout << "\nCar information:" << endl;
                                
                                //VIP print
                                if (carsList[temp1 - 1][temp2 - 1].get_isVIP() == true) {
                                    
                                    cout << "\tVIP: Y" << endl;
                                    
                                }
                                
                                else {
                                    
                                    cout << "\tVIP: N" << endl;
                                    
                                }
                                
                                //other car info
                                cout << "\tLicense Plate: " << carsList[temp1 - 1][temp2 - 1].get_lpNum() << endl;
                                
                                cout << "\tColor: " << carsList[temp1 - 1][temp2 - 1].get_color() << endl;
                                
                                cout << "\tMake: " << carsList[temp1 - 1][temp2 - 1].get_make() << endl;
                                
                                cout << "\tModel: " << carsList[temp1 - 1][temp2 - 1].get_model() << endl;
                                
                                //goto to make sure user inputs the right integer choice
                            CorrectCarQuestion:
                                
                                cout << "\nIs this the correct car?\n\t1. Yes\n\t2. No" << endl;
                                
                                cout << "Choice: ";
                                
                                cin >> choice;
                                
                                while (cin.fail()) {
                                    
                                    cin.clear(); //Resets the flags so you can input again
                                    
                                    cin.ignore(100, '\n'); //Empty the buffer
                                    
                                    cout << "Please enter an integer!\n";
                                    
                                    cin >> temp2;
                                    
                                }
                                
                                //Checks to make sure user inputs one of the options; if not, notify and ask again
                                if (choice < 1 || choice > 2) {
                                    
                                    cout << "That wasn't an option.\n";
                                    
                                    goto CorrectCarQuestion;
                                    
                                }
                                
                                switch (choice){
                                        
                                        //this is the correct car to tow; prints out to confirm
                                        //sets appropriate variables 'isTowed' to true and 'isOccupied to false
                                        //adds fee to moneyOwed
                                    case 1:
                                        
                                    {
                                        
                                        cout << "\nThe " << carsList[temp1 - 1][temp2 - 1].get_color() << " "
                                        << carsList[temp1 - 1][temp2 - 1].get_make() << " " << carsList[temp1 - 1][temp2 - 1].get_model()
                                        << " will be towed. Owner will be notified and a fee will be added to their bill. " << endl;
                                        
                                        carsList[temp1 - 1][temp2 - 1].set_isTowed(true);
                                        
                                        carsList[temp1 - 1][temp2 - 1].set_isOccupied(false);
                                        
                                        carsList[temp1 - 1][temp2 - 1].set_moneyOwed(carsList[temp1 - 1][temp2 - 1].get_moneyOwed() + 200.0);
                                        
                                        break;
                                        
                                    }
                                        
                                        //this is the incorrect car; asks tow car question to re-enter info or quit (no code needed)
                                    case 2:
                                        
                                    {
                                        
                                    TowReturnQuestion:
                                        
                                        cout << "Would you like to re-enter the information?" << endl;
                                        
                                        cout << "\t1. Yes" << endl;
                                        
                                        cout << "\t2. No" << endl;
                                        
                                        cout << "\tChoice: ";
                                        
                                        cin >> choice;
                                        
                                        while (cin.fail()) {
                                            
                                            cin.clear(); //Resets the flags so you can input again
                                            
                                            cin.ignore(100, '\n'); //Empty the buffer
                                            
                                            cout << "Please enter an integer!\n";
                                            
                                            cin >> temp2;
                                            
                                        }
                                        
                                        //integer but not option check
                                        if (choice < 1 || choice > 2) {
                                            
                                            cout << "That wasn't an option. Please choose from one of the available options.\n";
                                            
                                            goto TowReturnQuestion;
                                            
                                        }
                                        
                                        //user wants to retry towing a car
                                        else if (choice == 1) {
                                            
                                            goto TowCarQuestion;
                                            
                                        }
                                        
                                        break;
                                        
                                    }
                                        
                                }//end of correct car question switch
                                
                            }
                            
                            //if the requested space is empty, prints cout and returns to asking about re-entering info
                            else {
                                
                                cout << "\nThat space is empty." << endl;
                                
                                //asks user to repeat process for another space, if answer is no, breaks out (no code needed)
                            DifferentTowInfo:
                                
                                cout << "\nFind location for a different car to tow?\n\t1.Yes\n\t2.No\n";
                                
                                cout << "Choice: ";
                                
                                cin >> choice;
                                
                                while (cin.fail()) {
                                    
                                    cin.clear(); //Resets the flags so you can input again
                                    
                                    cin.ignore(100, '\n'); //Empty the buffer
                                    
                                    cout << "Please enter an integer!\n";
                                    
                                    cin >> choice;
                                    
                                }
                                
                                //sends up to restart case
                                if (choice == 1){
                                    
                                    goto TowCarQuestion;
                                    
                                }
                                
                                //if integer but not an option, re-ask
                                else if (choice < 1 || choice > 2){
                                    
                                    cout << "\nThat wasn't an option, please select from the options";
                                    
                                    goto DifferentTowInfo;
                                    
                                }
                                
                            }
                            
                            break;
                            
                        } //end of case 5
                            
                            //CHANGE PASSWORD case
                            //asks for user, current password, then new password
                            
                        case 6:
                        {
                            
                            //temp variables for changing passwords
                            string currentPass = "";
                            
                            string currentUser = "";
                            
                            string newPass = "";
                            
                            //wrong username sends here
                        passwordMenu:
                            
                            cout << "\n\tLogin" << endl;
                            
                            cout << "\t------" << endl;
                            
                            cout << "Username: ";
                            
                            cin >> currentUser;
                            
                            //goto sends here if current password is not recognized
                        takeTwo:
                            
                            cout << "Current Password: ";
                            
                            cin >> currentPass;
                            
                            
                            //checks who wants to change their password
                            //must enter current password first, then can change it
                            
                            
                            
                            //Clayton Manager
                            //checks for viable username
                            if (currentUser.compare(clayton->get_username()) == 0) {
                                
                                //checks for Clayton's viable password
                                if (currentPass.compare(clayton->get_password()) == 0) {
                                    
                                    cout << "New Password: ";
                                    
                                    cin >> newPass;
                                    
                                    //sets new password, then exits all the user ifs
                                    clayton->set_password(newPass);
                                    
                                    goto success;
                                    
                                }
                                
                                else {
                                    
                                    //wrong password, sends up to "current password"
                                    cout << "\nIncorrect Password, please try again.\n" << endl;
                                    
                                    goto takeTwo;
                                    
                                }
                                
                            }
                            
                            
                            
                            //Zahin Manager
                            if (currentUser.compare(zahin->get_username()) == 0) {
                                
                                if (currentPass.compare(zahin->get_password()) == 0) {
                                    
                                    cout << "New Password: ";
                                    
                                    cin >> newPass;
                                    
                                    //sets new password, then exits all the user ifs
                                    zahin->set_password(newPass);
                                    
                                    goto success;
                                    
                                }
                                
                                
                                
                                else {
                                    
                                    //wrong password, sends up to "current password"
                                    cout << "\nIncorrect Password, please try again.\n" << endl;
                                    
                                    goto takeTwo;
                                    
                                }
                                
                            }
                            
                            
                            
                            
                            //Neha Manager
                            if (currentUser.compare(neha->get_username()) == 0) {
                                
                                if (currentPass.compare(neha->get_password()) == 0) {
                                    
                                    cout << "New Password: ";
                                    
                                    cin >> newPass;
                                    
                                    //sets new password, then exits all the user conditions
                                    neha->set_password(newPass);
                                    
                                    goto success;
                                    
                                }
                                
                                
                                
                                else {
                                    
                                    //wrong password, sends up to "current password"
                                    cout << "\nIncorrect Password, please try again.\n" << endl;
                                    
                                    goto takeTwo;
                                    
                                    
                                }
                                
                            }
                            
                            
                            
                            
                            //Andrew Manager
                            if (currentUser.compare(andrew->get_username()) == 0) {
                                
                                if (currentPass.compare(andrew->get_password()) == 0) {
                                    
                                    cout << "New Password: ";
                                    
                                    cin >> newPass;
                                    
                                    //sets new password, then exits all the user ifs
                                    andrew->set_password(newPass);
                                    
                                    goto success;
                                    
                                }
                                
                                else {
                                    
                                    //wrong password, sends up to "current password"
                                    cout << "\nIncorrect Password, please try again.\n" << endl;
                                    
                                    goto takeTwo;
                                    
                                }
                                
                            }
                            
                            
                            
                            
                            
                            //Christopher Manager
                            if (currentUser.compare(topher->get_username()) == 0) {
                                
                                if (currentPass.compare(topher->get_password()) == 0) {
                                    
                                    cout << "New Password: ";
                                    
                                    cin >> newPass;
                                    
                                    //sets new password, then exits all the user ifs
                                    topher->set_password(newPass);
                                    
                                    goto success;
                                    
                                }
                                
                                else {
                                    
                                    //wrong password, sends up to "current password"
                                    cout << "\nIncorrect Password, please try again.\n" << endl;
                                    
                                    goto takeTwo;
                                    
                                }
                                
                            }
                            
                            
                            
                            
                            
                            //Harsh Manager
                            if (currentUser.compare(harsh->get_username()) == 0) {
                                
                                if (currentPass.compare(harsh->get_password()) == 0) {
                                    
                                    cout << "New Password: ";
                                    
                                    cin >> newPass;
                                    
                                    //sets new password, then exits all the user ifs
                                    harsh->set_password(newPass);
                                    
                                    goto success;
                                    
                                }
                                
                                else {
                                    
                                    //wrong password, sends up to "current password"
                                    cout << "\nIncorrect Password, please try again.\n" << endl;
                                    
                                    goto takeTwo;
                                    
                                }
                                
                            }
                            
                            //If username doesn't match, sends up to try another username
                            cout << "\nUsername not recognized, try again.\n" << endl;
                            
                            goto passwordMenu;
                            
                            //Successful password change; goto's go here
                        success:
                            
                            cout << "New password confirmed!\n";
                            
                            break;
                            
                        }
                            
                        default:
                            
                            //if an integer was chosen but it wasn't one from the list, default is utilized to return
                            cout << "That wasn't an option. Please choose from one of the given options.\n";
                            
                            goto ManagerMenu;
                            
                            break;
                            
                    }//end of manager switch statement
                    
                    //Manager menu quit or continue statement
                    cout << "Enter 1 to continue to Manager Menu, anything else to go to Main Menu: ";
                    
                    cin >> quitManager;
                }
                
            }//end of main menu manager (case 4)
                
            default:
                
                break;
                
        }//end of big switch statement
        
        //main menu quit or continue statement
    RepeatProgram:
        
        cout << "\nEnter 1 to Continue to Main Menu, 0 to Exit: ";
        
        cin >> quit;
        
    } while (quit == 1);//end of the do-while loop that loop the entire program.
    
}
//end of main
