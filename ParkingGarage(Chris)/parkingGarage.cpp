#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "parkingGarage.h"

using namespace std;


//constructor for car object
//initiates all variables to null or zero
Car::Car() {
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
}

//Setters
void Car::set_color(string c)
{
	color = c;
}

void Car::set_make(string m)
{
	make = m;
}

void Car::set_model(string m)
{
	model = m;
}

void Car::set_lpNum(string lp)
{
	lpNum = lp;
}

void Car::set_floorNum(int fn)
{
	floorNum = fn;
}

void Car::set_spaceNum(int sn)
{
	spaceNum = sn;
}

void Car::set_timePeriod(int tp)
{
	timePeriod = tp;
}

void Car::set_moneyOwed(double m)
{
	moneyOwed = m;
}

void Car::set_isOccupied(bool o)
{
	isOccupied = o;
}

void Car::set_isVIP(bool v)
{
	isVIP = v;
}


//Getters
string Car::get_color()
{
	return color;
}

string Car::get_make()
{
	return make;
}

string Car::get_model()
{
	return model;
}

string Car::get_lpNum()
{
	return lpNum;
}

int Car::get_floorNum()
{
	return floorNum;
}

int Car::get_spaceNum()
{
	return spaceNum;
}

int Car::get_timePeriod()
{
	return timePeriod;
}

double Car::get_moneyOwed()
{
	return moneyOwed;
}

bool Car::get_isOccupied()
{
	return isOccupied;
}

bool Car::get_isVIP()
{
	return isVIP;
}





int main(int argc, int argv[]) {

	const int NUM_FLOORS = argv[0]; //Number of floors
	const int NUM_SPACES = argv[1]; //Number of spaces PER FLOOR
	const int SPACES_TOTAL = NUM_FLOORS * NUM_SPACES;

	int mainMenuChoice = 0, VIPchoice = 0, timeChoice = 0; //neha
	int floorTemp, spaceTemp, paymentChoice; //austin
	string makeInput, modelInput, colorInput, lpInput, lpTemp; //austin
	double fee; //austin

				//greeting and prints main menu
	cout << "Welcome to the Zanach Parking Garage!!" << endl;
	cout << "What would you like to do? (Enter the number of your choice): " << endl;

	cout << "\n1. Park my Car" << endl;
	cout << "2. Checkout and Pay" << endl;
	cout << "3. Find my Car (I lost it!)" << endl;

	cout << "Choice: ";
	cin >> mainMenuChoice;
	while (cin.fail()) {
		cin.clear(); //Resets the flags so you can input again
		cin.ignore(100, '\n'); //Empty the buffer
		cout << "Please enter an integer!\n";
		cin >> mainMenuChoice;
	}

	Car temp;


	switch (mainMenuChoice) {

		//Parking a new car
	case 1:

		//declaring a new car object of which all variables
		//are initialized to null or zero
		Car car;

		cout << "--\nThanks for parking your garage in the Zanach Parking Garage."
			<< "\nWe promise your car is in pretty good hands for the most part!" << endl;

		//prints out regular rates
		cout << "\nOur Regular Rates:" << endl;
		cout << "\t<1 hour: $10" << endl;
		cout << "\t1 - 3 hour(s): $12.50" << endl;
		cout << "\t3 - 6 hours: $17.50" << endl;
		cout << "\t6 - 12 hours: $24.50" << endl;
		cout << "\t12 - 24 hours: $34.50" << endl;

		//prints out VIP rates
		cout << "\nOur VIP Rates:" << endl;
		cout << "\t<1 hour: $20" << endl;
		cout << "\t1 - 3 hours: $22.50" << endl;
		cout << "\t3 - 6 hours: $27.50" << endl;
		cout << "\t6 - 12 hours: $34.50" << endl;
		cout << "\t12 - 24 hours: $44.50" << endl;


		//asks to pick regular or VIP rates
		cout << "Would you like to park regular or VIP?" << endl;

		cout << "1. Regular" << endl;
		cout << "2. VIP" << endl;
		cout << "3. JK I don't want to park you guys are too expensive" << endl;
		cout << "Choice: ";

		cin >> VIPchoice;
		while (cin.fail()) {
			cin.clear(); //Resets the flags so you can input again
			cin.ignore(100, '\n'); //Empty the buffer
			cout << "Please enter an integer!\n";
			cin >> VIPchoice;
		}


		switch (VIPchoice) {
			//user chooses regular rates
		case 1:
			//isVIP is initialized to be false so nothing needs to be done
			break;
		case 2:
			//isVIP is set to true
			car.set_isVIP(true);
			break;
		case 3:
			cout << "goodbye, thanks for nothing";
			//return 0;
			break;
		default:
			cout << "That wasn't an option. Goodbye";
			break;
		}//end of VIP switch statement


		 //asks which time period they will be paying for
		cout << "How long would you like to stay?" << endl;
		cout << "1. <1 hour" << endl;
		cout << "2. 1 - 3 hours" << endl;
		cout << "3. 3 - 6 hours" << endl;
		cout << "4. 6 - 12 hours" << endl;
		cout << "5. 12 - 24 hours" << endl;

		cout << "Choice: " << endl;
		cin >> timeChoice;
		while (cin.fail()) {
			cin.clear(); //Resets the flags so you can input again
			cin.ignore(100, '\n'); //Empty the buffer
			cout << "Please enter an integer!\n";
			cin >> timeChoice;
		}

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
		default:
			cout << "That wasn't an option. Goodbye";
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
				car.set_moneyOwed(fee) :
			}
			if (car.get_timePeriod() == 3) {
				fee = 17.5;
				car.set_moneyOwed(fee) :
			}
			if (car.get_timePeriod() == 4) {
				fee = 24.5;
				car.set_moneyOwed(fee) :
			}
			if (car.get_timePeriod() == 5) {
				fee = 34.5;
				car.set_moneyOwed(fee) :
			}

		}
		else {
			if (car.get_timePeriod() == 1) {
				fee = 20;
				car.set_moneyOwed(fee);
			}
			if (car.get_timePeriod() == 2) {
				fee = 22.5;
				car.set_moneyOwed(fee) :
			}
			if (car.get_timePeriod() == 3) {
				fee = 27.5;
				car.set_moneyOwed(fee) :
			}
			if (car.get_timePeriod() == 4) {
				fee = 34.5;
				car.set_moneyOwed(fee) :
			}
			if (car.get_timePeriod() == 5) {
				fee = 44.5;
				car.set_moneyOwed(fee) :
			}
		}

		//asks for make, model, color, and license plate of vehicle
		cout << "Please enter your vehicle's make:" << endl;
		cin >> makeInput;
		car.set_make(makeInput);

		cout << "Please enter your vehicle's model:" << endl;
		cin >> modelInput;
		car.set_model(modelInput);

		cout << "Please enter your vehicle's color:" << endl;
		cin >> colorInput;
		car.set_color(colorInput);

		cout << "Please enter a 6 character license plate number:" << endl;
		cin >> lpInput;

		//checks that the license plate is exactly 6 characters long
		while (lpInput.length() != 6) {
			cout << "Please enter a 6 character license plate number:"
				cin >> lpInput;
		}
		//checks that each character in the string is either a number or a letter
		for (int i = 0; i < 6; i++) {
			if (isalnum(lpInput.charAt(i)) == false) {
				cout << "You entered an invalid character."
					<< "Please enter a license plate with only numbers and letters." << endl;
				cin << lpInput;
			}
		}
		car.set_lpNum(lpInput);

		//now the car needs to be assigned to a spot
		//using first fit logic

		break; //end of the case 1, car arriving in the parkinglot
	case 2:

		Car car = temp;

		//checkout and pay

		cout << "Thank you for parking with Zanach!" << endl;
		cout << "Please enter your floor number:" << endl;
		cin >> floorTemp;
		cout << "Please enter your space number:" << endl;
		cin >> spaceTemp;

		//code that finds which car object is at that space
		//and then calls the get_moneyOwed() method for that object
		//amount of money owed is then displayed to the user

		cout << "You owe $" + car.get_moneyOwed() "." << endl;

		cout << "Would you like to pay with/n1. Cash/n2. Card" << endl;
		cin >> paymentChoice;

		if (paymentChoice == 1) {
			cout << "Please take your change and have a great day!" << endl;
		}
		if (paymentChoice == 2) {
			cout << "Please insert your card.n/Authorizing...n/"
				+ "Please take your receipt and have a great day!" << endl;
		}


		break;
	case 3:

		Car car = temp;
		//This is Chris, I'm messing with this.
		//asks user for license plate number to locate correct car object
		cout << "Please enter your license plate number:" << endl;
		cin >> lpTemp;
		findCar(NUM_SPACES, NUM_FLOORS, lpTemp);
		//code to locate correct car object
		//need to loop through vector to find car object with given license plate number
		//get floorNum and spaceNum when correct object is found and display them to the user

		cout << "Your " + car.get_color() + " " + car.get_make() + " " + car.get_model() +
			" is located on floor " + car.get_floorNum() + " in space " + car.get_spaceNum() + "." << endl;

		break;
	default:
		cout << "That wasn't an option. Goodbye";
		break;


	}//end of big switch statement

}

void findCar(int spaces, int floors, string plate){
	int spot = 0;
	for (int i = 0; i < floors; i++) {
		for (int j = 0; j < spaces; j++) {

		}
	}


}
