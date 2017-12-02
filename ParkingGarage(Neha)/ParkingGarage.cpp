#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <stdlib.h>
//#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include "parkingGarage.h"
#include "manager.h"

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

Manager::Manager(string user) {
	username = user;
	password = "password";
}

//Manager Setters
void Manager::set_username(string user)
{
	user = username;
}

void Manager::set_password(string pass)
{
	pass = password;
}

//Manager Getters
string Manager::get_username()
{
	return username;
}

string Manager::get_password()
{
	return password;
}

//Car Setters
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

/*int Car::findCar(int spaces, int floors, string lpNum) {
int spot = 0;
for (int i = 0; i < floors; i++) {
for (int j = 0; j < spaces; j++) {

}
}
return floorNum, spaceNum;
}*/

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

int main(int argc, char * argv[]) {

	const int NUM_FLOORS = atoi(argv[1]); //Number of floors
	const int NUM_SPACES = atoi(argv[2]); //Number of spaces PER FLOOR
	const int SPACES_TOTAL = NUM_FLOORS * NUM_SPACES;

	int mainMenuChoice, VIPchoice, timeChoice, managerMenuChoice = 0; //neha
	int floorTemp, spaceTemp; //austin
	int paymentChoice, receiptChoice;
	double payment, cash, change;
	string makeInput, modelInput, colorInput, lpInput, lpTemp; //austin
	double fee; //austin
	int quit;
	double vipCount = 0.0, regularCount = 0.0, totalProjected = 0.0, profitCount = 0.0;

	//declaring number of floors in the parking garage
	Car ** carsList = new Car*[NUM_FLOORS];

	//declaring the number of spaces in each floor
	for (int i = 0; i < NUM_FLOORS; i++) {
		carsList[i] = new Car[NUM_SPACES];
	}


	//greeting and prints main menu
	cout << "Welcome to the Zanach Parking Garage!!" << endl;

	do {
		cout << "What would you like to do? (Enter the number of your choice): " << endl;

	MainMenuQuestion:
		cout << "\n1. Park my Car" << endl;
		cout << "2. Retrieve my car (checkout and pay)" << endl;
		cout << "3. Find my Car (I lost it!)" << endl;
		cout << "4. Manager Login" << endl;

		cout << "Choice: ";
		cin >> mainMenuChoice;
		while (cin.fail()) {
			cin.clear(); //Resets the flags so you can input again
			cin.ignore(100, '\n'); //Empty the buffer
			cout << "Please enter an integer!\n";
			cin >> mainMenuChoice;
		}

		if (mainMenuChoice < 1 || mainMenuChoice > 4) {
			cout << "That wasn't an option.\n";
			goto MainMenuQuestion;
		}

		switch (mainMenuChoice) {

			//Parking a new car
		case 1:
		{

			//declaring a new car object of which all variables
			//are initialized to null or zero
			Car car;

			cout << "--\nThanks for parking your garage in the Zanach Parking Garage."
				<< "\nWe promise your car is in pretty good hands for the most part!" << endl;

			//prints out regular rates
			cout << "\nOur Regular Rates:" << endl;
			cout << "\--------------------" << endl;
			cout << "\t<1 hour: $10" << endl;
			cout << "\t1 - 3 hour(s): $12.50" << endl;
			cout << "\t3 - 6 hours: $17.50" << endl;
			cout << "\t6 - 12 hours: $24.50" << endl;
			cout << "\t12 - 24 hours: $34.50" << endl;

			//prints out VIP rates
			cout << "\nOur VIP Rates:" << endl;
			cout << "\--------------------" << endl;
			cout << "\t<1 hour: $20" << endl;
			cout << "\t1 - 3 hours: $22.50" << endl;
			cout << "\t3 - 6 hours: $27.50" << endl;
			cout << "\t6 - 12 hours: $34.50" << endl;
			cout << "\t12 - 24 hours: $44.50" << endl << endl;


			//asks to pick regular or VIP rates
			//if vip is full, say sorry, only regular spaces available
		VIPquestion:
			cout << "Would you like to park regular or VIP?" << endl;
			cout << "\--------------------" << endl;
		
			cout << "1. Regular" << endl;
			cout << "2. VIP (VIPs get first floor parking!)" << endl;
			cout << "3. I don't want to park, this garage is too expensive" << endl;
			cout << "Choice: ";

			cin >> VIPchoice;
			while (cin.fail()) {
				cin.clear(); //Resets the flags so you can input again
				cin.ignore(100, '\n'); //Empty the buffer
				cout << "Please enter an integer!\n";
				cin >> VIPchoice;
			}

			if (VIPchoice != 1 && VIPchoice != 2 && VIPchoice != 3) {
				cout << "That wasn't an option, please choose from the given options.\n";
				goto VIPquestion;
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
				cout << "Sorry if our prices are too high. Please consider reemployment!\n";
				goto RepeatProgram;
				break;
			default:
				cout << "If you see this message, something is broken.";
				break;
			}//end of VIP switch statement

			 //asks which time period they will be paying for
			cout << "How long would you like to stay?" << endl;
			cout << "\--------------------" << endl;
			
		TimeQuestion:
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

			if (timeChoice < 1 || timeChoice > 5) {
				cout << "That wasn't an option, please choose from the available options.\n\n";
				goto TimeQuestion;
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
				cout << "If you see this message something is broken.";
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
			cout << "Please enter your vehicle's make:" << endl;
			cin >> makeInput;
			//car.set_make(makeInput);

			cout << "Please enter your vehicle's model:" << endl;
			cin >> modelInput;
			//car.set_model(modelInput);

			cout << "Please enter your vehicle's color:" << endl;
			cin >> colorInput;
			//car.set_color(colorInput);

			EnterLicensePlate:
			cout << "Please enter a 6 character license plate number:" << endl;
			cin >> lpInput;

			//checks that the license plate is exactly 6 characters long
			while (lpInput.length() != 6) {
				cout << "Please enter a 6 character license plate number:";
				cin >> lpInput;
			}

			for (int i = 0; i < NUM_FLOORS; i++){
				for (int j = 0; j < NUM_SPACES; j++) {
					if (lpInput.compare(carsList[i][j].get_lpNum()) == 0) {
						int lpMistake = 0;
						cout << "\nThis car is already parked in the garage, and is located at:" <<
							"\nFloor " << carsList[i][j].get_floorNum() <<
							"\nSpace " << carsList[i][j].get_spaceNum();

						lpMistakeQuestion:
						cout << "\nWould you \n" <<
							"1. Like to enter a different license plate number\n"
							"2. Like to retrieve your already parked car\n" <<
							"3. Like to find your lost car\n" <<
							"4. Like to leave the garage (restart the program)";

						cin >> lpMistake;
						while (cin.fail()) {
							cin.clear(); //Resets the flags so you can input again
							cin.ignore(100, '\n'); //Empty the buffer
							cout << "Please enter an integer!\n";
							cin >> lpMistake;
						}

						if (lpMistake < 1 || lpMistake > 4) {
							cout << "That wasn't an option, please choose from the available options.\n\n";
							goto lpMistakeQuestion;
						}
						
						switch (lpMistake) {
							case 1: {
								goto EnterLicensePlate;
								break;
							}
							case 2: {
								goto RetrieveCar;
								break;
							}
							case 3: {
								goto FindLostCar;
								break;
							}
							case 4: {
								goto RepeatProgram;
								break;
							}
							default: {
								cout << "If you see this message something is broken.";
								break;
							}

						}
					}
				}
			}



			//checks that each character in the string is either a number or a letter
			for (int i = 0; i < 6; i++) {
				if (isalnum(lpInput.at(i)) == false) {
					cout << "You entered an invalid character. "
						<< "Please enter a license plate with only numbers and letters." << endl;
					cin >> lpInput;
				}
			}


			//assigns new car object to a place in the carsList 2d array
			if (car.get_isVIP() == true) {
				for (int i = 0; i < NUM_FLOORS; i++) {
					for (int j = 0; j < NUM_SPACES; j++) {
						if (carsList[i][j].get_isOccupied() == false) {
							carsList[i][j].set_floorNum(i + 1);
							carsList[i][j].set_spaceNum(j + 1);
							carsList[i][j].set_isOccupied(true);
							carsList[i][j].set_isVIP(true);
							carsList[i][j].set_make(makeInput);
							carsList[i][j].set_model(modelInput);
							carsList[i][j].set_color(colorInput);
							carsList[i][j].set_lpNum(lpInput);
							carsList[i][j].set_timePeriod(car.get_timePeriod());
							carsList[i][j].set_moneyOwed(car.get_moneyOwed());
							cout << "You have been assigned a VIP space on floor " << carsList[i][j].get_floorNum()
								<< ", space " << carsList[i][j].get_spaceNum() << ". Have a great day sir/madame!" << endl;
							goto successfulPark;
						}
					}
					//VIP floor is full, user picks between exiting or Regular Parking
					if (i == 0) {
						int temp = 0;
						cout << "I'm sorry, VIP parking is full. You may either\n1. Use Regular Parking\n2. Exit" << endl;
						cin >> temp;

						if (temp == 1) {
							//resets isVIP to false because first floor is full
							car.set_isVIP(false);
							goto regularSpot;
						}
						else {
							//exits program
							return 0;
						}


					}
				}

			}
			else {
			regularSpot:
				for (int i = 1; i < NUM_FLOORS; i++) {
					for (int j = 0; j < NUM_SPACES; j++) {
						if (carsList[i][j].get_isOccupied() == false) {
							carsList[i][j].set_floorNum(i + 1);
							carsList[i][j].set_spaceNum(j + 1);
							carsList[i][j].set_isOccupied(true);
							carsList[i][j].set_make(makeInput);
							carsList[i][j].set_model(modelInput);
							carsList[i][j].set_color(colorInput);
							carsList[i][j].set_lpNum(lpInput);
							carsList[i][j].set_timePeriod(car.get_timePeriod());
							carsList[i][j].set_moneyOwed(car.get_moneyOwed());
							cout << "You have been assigned a regular space on floor " << carsList[i][j].get_floorNum()
								<< ", space " << carsList[i][j].get_spaceNum() << ". Have a good day." << endl;
							goto successfulPark;
						}
					}
				}

			}

		successfulPark:


			break; //end of the case 1, car arriving in the parkinglot
		}
		case 2:
		{
			RetrieveCar:
			string temp = "";
			string timePeriod = "";

			//checkout and pay

			cout << "Thank you for parking with Zanach!" << endl;

		checkoutProcess:
			cout << "Please enter your floor number:" << endl;
			cin >> floorTemp;
			while (cin.fail()) {
				cin.clear(); //Resets the flags so you can input again
				cin.ignore(100, '\n'); //Empty the buffer
				cout << "Please enter an integer!\n";
				cin >> floorTemp;
			}
			cout << "Please enter your space number:" << endl;
			cin >> spaceTemp;
			while (cin.fail()) {
				cin.clear(); //Resets the flags so you can input again
				cin.ignore(100, '\n'); //Empty the buffer
				cout << "Please enter an integer!\n";
				cin >> spaceTemp;
			}

			//checks if a car is parked in the given space
			if (carsList[floorTemp - 1][spaceTemp - 1].get_isOccupied() == true) {
				cout << "Please re-enter your license plate number to ensure you receive the correct bill:" << endl;
				cin >> temp;
				string s = carsList[floorTemp - 1][spaceTemp - 1].get_lpNum();
				cout << s;

				//checks if entered lpNum matches the one provided during car registration
				if (s.compare(temp) == 0) {

					if (carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 1) {
						timePeriod = "less than 1 hour.";
					}
					else if (carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 2) {
						timePeriod = "1 - 3 hours.    ";
					}
					else if (carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 3) {
						timePeriod = "3 - 6 hours.    ";
					}
					else if (carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 4) {
						timePeriod = "6 - 12 hours.    ";
					}
					else if (carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 5) {
						timePeriod = "12 - 24 hours.    ";
					}

					cout << "You have parked your " << carsList[floorTemp - 1][spaceTemp - 1].get_color() << " "
						<< carsList[floorTemp - 1][spaceTemp - 1].get_make()
						<< " " << carsList[floorTemp - 1][spaceTemp - 1].get_model() << " for "
						<< timePeriod << endl;

					string money;
					//gets moneyOwed from car if it is parked there and asks the user for payment
					(carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 1 ? money = ".00." : money = "0.");
					cout << "\nYour total comes out to $" << carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed() << money << endl;


					//resets the space as empty so another car can be parked there
					carsList[floorTemp - 1][spaceTemp - 1].set_isOccupied(false);
				}
				//error case - space is occupied but provided license plate doesn't match
				else {
					cout << "The license plate number you entered did not match the car space provided."
						<< "\nTo ensure you aren't trying to park-n-dash or steal a car, please try again!" << endl;
					goto checkoutProcess;
				}



			}
			else {//error case - given space isn't occupied
				cout << "Oops, looks like that space wasn't occupied, please try again!" << endl;
				goto checkoutProcess;
			}

			//Payment options (cash or credit)
		PaymentQuestion:
			cout << "Would you like to pay with\n1. Cash\n2. Card" << endl;
			cin >> paymentChoice;
			while (cin.fail()) {
				cin.clear(); //Resets the flags so you can input again
				cin.ignore(100, '\n'); //Empty the buffer
				cout << "Please enter an integer!\n";
				cin >> paymentChoice;
			}
			if (paymentChoice < 1 || paymentChoice > 2) {
				cout << "That wasn't an option.\n";
				goto PaymentQuestion;
			}

			if (paymentChoice == 1) {
				bool incorrectPayment = true;
				cash = 0;
				cout << "Please input your cash payment into the machine.";

				do {
					cout << "How much did you put in?";
					cin >> payment;
					while (cin.fail()) {
						cin.clear(); //Resets the flags so you can input again
						cin.ignore(100, '\n'); //Empty the buffer
						cout << "Please enter a valid cash amount!\n";
						cin >> payment;
					}
					cash += payment;
					change = cash - carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed();

					if (change < 0) {
						cout << "Sorry, you have not given enough money."
							<< "Please input additional cash payment.";
					}
					else if (change == 0) {
						cout << "Your change is $0.00. ";
					ReceiptCashQuestion1:
						cout << "Would you like a receipt?\n1. Yes\n2. No\n";
						cin >> receiptChoice;
						while (cin.fail()) {
							cin.clear(); //Resets the flags so you can input again
							cin.ignore(100, '\n'); //Empty the buffer
							cout << "Please enter an integer!\n";
							cin >> receiptChoice;
						}
						if (receiptChoice < 1 || receiptChoice > 2) {
							cout << "That wasn't an option.\n";
							goto ReceiptCashQuestion1;
						}
						else if (receiptChoice == 1) {
							//printReceipt()
						}
						cout << "Thank you, and have a great day!";
						incorrectPayment = false;
					}
					else {

						string money;
						(carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 1 ? money = ".00." : money = "0.");

						cout << "Your change is $" << change << money << ". ";
					ReceiptCashQuestion2:
						cout << "Would you like a receipt?\n1.Yes\n2.No\n";
						cin >> receiptChoice;
						while (cin.fail()) {
							cin.clear(); //Resets the flags so you can input again
							cin.ignore(100, '\n'); //Empty the buffer
							cout << "Please enter an integer!\n";
							cin >> receiptChoice;
						}
						if (receiptChoice < 1 || receiptChoice > 2) {
							cout << "That wasn't an option.\n";
							goto ReceiptCashQuestion2;
						}
						else if (receiptChoice == 1) {

							string money;
							//gets moneyOwed from car if it is parked there and asks the user for payment
							(carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 1 ? money = ".00." : money = "0.");

							cout << "  ______________________________________________________\n";
							cout << " |  Thank for for parking at the Zanach Parking Garage\t|\n" <<
								" |\t\t\t\t\t\t\t|\n";
							if (carsList[floorTemp - 1][spaceTemp - 1].get_isVIP() == true) {
								cout << " |  You were a VIP today!\t\t\t\t|\n |  You're more important than other people.\t\t|" <<
									"\n |\t\t\t\t\t\t\t|\n";
							}
							cout << " |  You parked for " << timePeriod << "\t\t\t|\n" <<
								" |\t\t\t\t\t\t\t|\n";
							cout << " |  Total: $" << carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed() << money << "\t\t\t\t\t|\n";
							cout << " |  You paid $" << payment << ".00 in cash\t\t\t\t|\n";
							cout << " |  Change: $" << change << "0.\t\t\t\t\t|\n" <<
								" |\t\t\t\t\t\t\t|\n";
							cout << " |  ---\t\t\t\t\t\t\t|\n" <<
								" |\t\t\t\t\t\t\t|\n";
							cout << " |  Questions, comments, or concerns? \t\t\t|\n";
							cout << " |  Contact Us: 1-(800)-1-ZANACH\t\t\t|\n";
							cout << "  ______________________________________________________\n";

						}
						cout << "\nPlease take your change and have a great day!" << endl;
						incorrectPayment = false;
					}
				} while (incorrectPayment == true);
			}
			if (paymentChoice == 2) {

				cout << "Please insert your card.\n";
				Sleep(1500);
				cout << "Authorizing";
				Sleep(1000);
				cout << ".";
				Sleep(1000);
				cout << ".";
				Sleep(1000);
				cout << ".\n"
					<< "Accepted. ";
			ReceiptCardQuestion:
				cout << "Would you like a receipt?\n1.Yes\n2.No\n";
				cin >> receiptChoice;
				while (cin.fail()) {
					cin.clear(); //Resets the flags so you can input again
					cin.ignore(100, '\n'); //Empty the buffer
					cout << "Please enter an integer!\n";
					cin >> receiptChoice;
				}
				if (receiptChoice < 1 || receiptChoice > 2) {
					cout << "That wasn't an option.\n";
					goto ReceiptCardQuestion;
				}
				else if (receiptChoice == 1) {
					//printReceipt()
					string money;
					//gets moneyOwed from car if it is parked there and asks the user for payment
					(carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 1 ? money = ".00." : money = "0.");

					cout << "  ______________________________________________________\n";
					cout << " |  Thank for for parking at the Zanach Parking Garage\t|\n" <<
						" |\t\t\t\t\t\t\t|\n";
					if (carsList[floorTemp - 1][spaceTemp - 1].get_isVIP() == true) {
						cout << " |  You were a VIP today!\t\t\t\t|\n |  You're more important than other people.\t\t|" <<
							"\n |\t\t\t\t\t\t\t|\n";
					}
					cout << " |  You parked for " << timePeriod << "\t\t\t|\n" <<
						" |\t\t\t\t\t\t\t|\n";
					cout << " |  Total: $" << carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed() << money << "\t\t\t\t\t|\n";
					cout << " |  You paid with card **** **** **** 3503\t\t|\n" <<
						" |\t\t\t\t\t\t\t|\n";
					cout << " |  ---\t\t\t\t\t\t\t|\n" <<
						" |\t\t\t\t\t\t\t|\n";
					cout << " |  Questions, comments, or concerns? \t\t\t|\n";
					cout << " |  Contact Us: 1-(800)-1-ZANACH\t\t\t|\n";
					cout << "  ______________________________________________________\n";


				}
				cout << "Have a great day!" << endl;
			}


			break;
		}
		case 3:
		{
			FindLostCar:
			int floorNum = 1;
			int spaceNum = 1;

			//asks user for license plate number to locate correct car object
			cout << "Please enter your license plate number:" << endl;
			cin >> lpTemp;

			//car.findCar(NUM_SPACES, NUM_FLOORS, lpTemp);
			//code to locate correct car object
			//need to loop through vector to find car object with given license plate number
			//get floorNum and spaceNum when correct object is found and display them to the user
			for (int i = 0; i < NUM_FLOORS; i++) {
				for (int j = 0; j < NUM_SPACES; j++) {
					if (lpTemp.compare(carsList[i][j].get_lpNum()) == 0) {
						floorNum = i + 1; //arrays start at 0, but parking garages don't!
						spaceNum = j + 1;
						goto FoundCar;
					}
				}
			}

		FoundCar:
			cout << "Your " << carsList[floorNum - 1][spaceNum - 1].get_color() << " " << carsList[floorNum - 1][spaceNum - 1].get_make() << " "
				<< carsList[floorNum - 1][spaceNum - 1].get_model() << " is located on floor " << floorNum << " in space " << spaceNum << "." << endl;

			break;
		}

		case 4:
		{
			//managers initialized
			//usernames are first names and password is set to "password" by default
			//but can be changed
			Manager* clayton = new Manager("clayton");
			Manager* zahin = new Manager("zahin");
			Manager* neha = new Manager("neha");
			Manager* andrew = new Manager("andrew");
			Manager* topher = new Manager("topher");
			Manager* harsh = new Manager("harsh");

			//input variables from the user
			string username = "";
			string password = "";


		managerMenu:
			cout << "~Login~" << endl;
			cout << "Manager Username: " << endl;
			cin >> username;

		incorrectPass:
			cout << "Manager Password: " << endl;
			cin >> password;


			//series of if else statements that checks the login for managers
			//if an incorrect username or password is entered, the program asks again
			if (username.compare(clayton->get_username()) == 0) {
				if (password.compare(clayton->get_password()) == 0) {
					goto next;
				}
				else {
					cout << "\nIncorrect Password, please try again.\n" << endl;
					goto incorrectPass;
				}
			}


			if (username.compare(zahin->get_username()) == 0) {
				if (password.compare(zahin->get_password()) == 0) {
					goto next;
				}
				else {
					cout << "\nIncorrect Password, please try again.\n" << endl;
					goto incorrectPass;
				}
			}



			if (username.compare(neha->get_username()) == 0) {
				if (password.compare(neha->get_password()) == 0) {
					goto next;
				}
				else {
					cout << "\nIncorrect Password, please try again.\n" << endl;
					goto incorrectPass;
				}
			}



			if (username.compare(andrew->get_username()) == 0) {
				if (password.compare(andrew->get_password()) == 0) {
					goto next;
				}
				else {
					cout << "\nIncorrect Password, please try again.\n" << endl;
					goto incorrectPass;
				}
			}


			if (username.compare(topher->get_username()) == 0) {
				if (password.compare(topher->get_password()) == 0) {
					goto next;
				}
				else {
					cout << "\nIncorrect Password, please try again.\n" << endl;
					goto incorrectPass;
				}
			}



			if (username.compare(harsh->get_username()) == 0) {
				if (password.compare(harsh->get_password()) == 0) {
					goto next;
				}
				else {
					cout << "\nIncorrect Password, please try again.\n" << endl;
					goto incorrectPass;
				}
			}


			cout << "\nUsername not recognized, try again.\n" << endl;
			goto managerMenu;


			//only reaches this point after successful login
		next:
			cout << "Successful Login\n" << endl;

			int quitManager = 1;

			//while loop for manager menu
			while (quitManager == 1) {

				cout << "MANAGER MENU:\n" << endl;

				//prints a list of the current license plates in the garage
				cout << "1. Print All License Plates" << endl;

				//prints out all details associated with a particular space
				//isOccupied == true, then prints all details
				//if false, informs user that the space is empty
				cout << "2. Print Space Info" << endl;

				//Prints total of all money paid today
				cout << "3. Print Current Profit" << endl;

				//prints projected profit
				cout << "4. Projected Profit" << endl;

				//gives user the choice to change password
				cout << "5. Change Password" << endl;




				cout << "Choice: ";
				cin >> managerMenuChoice;


				while (cin.fail()) {
					cin.clear(); //Resets the flags so you can input again
					cin.ignore(100, '\n'); //Empty the buffer
					cout << "Please enter an integer!\n";
					cin >> managerMenuChoice;
				}


				//switch case for manager menu
				switch (managerMenuChoice) {

					//Printing license plates
				case 1:
				{
					for (int i = 0; i < NUM_FLOORS; i++) {
						for (int j = 0; i < NUM_SPACES; j++) {
							if (carsList[i][j].get_lpNum().empty() == false) {
								cout << "Current License Plates in the Garage:\n " << carsList[i][j].get_lpNum() << "\n" << endl;
							}
						}
					}

					break;
				}


				//Prints space info
				case 2:
				{
					//temp inputs for car location
					int temp1 = 0;
					int temp2 = 0;

					cout << "Floor Number: " << endl;
					cin >> temp1;

					while (cin.fail()) {
						cin.clear(); //Resets the flags so you can input again
						cin.ignore(100, '\n'); //Empty the buffer
						cout << "Please enter an integer!\n";
						cin >> temp1;
					}

					cout << "Space Number:" << endl;
					cin >> temp2;

					while (cin.fail()) {
						cin.clear(); //Resets the flags so you can input again
						cin.ignore(100, '\n'); //Empty the buffer
						cout << "Please enter an integer!\n";
						cin >> temp2;
					}

					//checks if a car is parked in the given space
					cout << "\nSpace " << temp1 << "-" << temp2 << " Information:" << endl;

					if (carsList[temp1 - 1][temp2 - 1].get_isOccupied() == true) {

						if (carsList[temp1 - 1][temp2 - 1].get_isVIP() == true) {
							cout << "VIP: Y" << endl;
						}
						else {
							cout << "VIP: N" << endl;
						}

						cout << "License Plate: " << carsList[temp1 - 1][temp2 - 1].get_lpNum() << endl;
						cout << "Color: " << carsList[temp1 - 1][temp2 - 1].get_color() << endl;
						cout << "Make: " << carsList[temp1 - 1][temp2 - 1].get_make() << endl;
						cout << "Model: " << carsList[temp1 - 1][temp2 - 1].get_model() << endl;
						cout << "Fee: " << carsList[temp1 - 1][temp2 - 1].get_moneyOwed() << endl;


					}
					else {
						cout << "That space is empty." << endl;
					}


					break;
				}

				//print today's profit
				case 3:
				{
					cout << "The total profit made today: $";
					cin >> profitCount;
					break;
				}

				//prints projected money
				case 4:
				{
					totalProjected = vipCount + regularCount;

					cout << "The total projected profit for today is : $";
					cin >> totalProjected;

					break;
				}

				//change password
				case 5:
				{
					string currentPass = "";
					string currentUser = "";
					string newPass = "";

				passwordMenu:
					cout << "Username: " << endl;
					cin >> currentUser;

				takeTwo:
					cout << "Current Password: ";
					cin >> currentPass;


					//checks who wants to change their password
					//must enter current password first, then can change it
					if (currentUser.compare(clayton->get_username()) == 0) {
						if (currentPass.compare(clayton->get_password()) == 0) {
							cout << "New Password: " << endl;
							cin >> newPass;

							clayton->set_password(newPass);
							goto success;

						}
						else {
							cout << "\nIncorrect Password, please try again.\n" << endl;
							goto takeTwo;
						}
					}


					if (currentUser.compare(zahin->get_username()) == 0) {
						if (currentPass.compare(zahin->get_password()) == 0) {
							cout << "New Password: " << endl;
							cin >> newPass;

							zahin->set_password(newPass);
							goto success;

						}
						else {
							cout << "\nIncorrect Password, please try again.\n" << endl;
							goto takeTwo;
						}
					}

					if (currentUser.compare(neha->get_username()) == 0) {
						if (currentPass.compare(neha->get_password()) == 0) {
							cout << "New Password: " << endl;
							cin >> newPass;

							neha->set_password(newPass);
							goto success;

						}
						else {
							cout << "\nIncorrect Password, please try again.\n" << endl;
							goto takeTwo;
						}
					}

					if (currentUser.compare(andrew->get_username()) == 0) {
						if (currentPass.compare(andrew->get_password()) == 0) {
							cout << "New Password: " << endl;
							cin >> newPass;

							andrew->set_password(newPass);
							goto success;

						}
						else {
							cout << "\nIncorrect Password, please try again.\n" << endl;
							goto takeTwo;
						}
					}

					if (currentUser.compare(topher->get_username()) == 0) {
						if (currentPass.compare(topher->get_password()) == 0) {
							cout << "New Password: " << endl;
							cin >> newPass;

							topher->set_password(newPass);
							goto success;

						}
						else {
							cout << "\nIncorrect Password, please try again.\n" << endl;
							goto takeTwo;
						}
					}

					if (currentUser.compare(harsh->get_username()) == 0) {
						if (currentPass.compare(harsh->get_password()) == 0) {
							cout << "New Password: " << endl;
							cin >> newPass;

							harsh->set_password(newPass);
							goto success;

						}
						else {
							cout << "\nIncorrect Password, please try again.\n" << endl;
							goto takeTwo;
						}
					}


					cout << "\nUsername not recognized, try again.\n" << endl;
					goto passwordMenu;


				success:


					break;
				}


				break;
				}

			
				cout << "Enter 1 to continue to Manager Menu, 0 to Exit:";
				cin >> quitManager;
			}

		}

		default:
			cout << "That wasn't an option. Goodbye";
			break;

		}//end of big switch statement

		RepeatProgram:
		cout << "Enter 1 to Continue to Main Menu, 0 to Exit: \n";
		cin >> quit;
	} while (quit == 1);

}