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
	isTowed = false;
}

Manager::Manager(string user) {
	username = user;
	password = "password";
}

//Manager Setters
void Manager::set_username(string user)
{
	username = user;
}

void Manager::set_password(string pass)
{
	password = pass;
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
void Car::set_isTowed(bool t) {
	isTowed = t;
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
bool Car::get_isTowed() {
	return isTowed;
}

int main(int argc, char * argv[]) {

	const int NUM_FLOORS = atoi(argv[1]); //Number of floors
	const int NUM_SPACES = atoi(argv[2]); //Number of spaces PER FLOOR
	const int SPACES_TOTAL = NUM_FLOORS * NUM_SPACES;

	int mainMenuChoice, VIPchoice, timeChoice, managerMenuChoice = 0; //used for main menu choices
	int floorTemp, spaceTemp; //austin
	int paymentChoice, receiptChoice;
	double payment, cash, change;
	string makeInput, modelInput, colorInput, lpInput, lpTemp; //austin
	double fee; //austin
	int quit;
	double realProfit = 0, projectedProfit = 0;
	double vipCount = 0.0, regularCount = 0.0, totalProjected = 0.0, profitCount = 0.0;

	//declaring number of floors in the parking garage
	Car ** carsList = new Car*[NUM_FLOORS];

	//declaring the number of spaces in each floor
	for (int i = 0; i < NUM_FLOORS; i++) {
		carsList[i] = new Car[NUM_SPACES];
	}

	Manager* clayton = new Manager("clayton");
	Manager* zahin = new Manager("zahin");
	Manager* neha = new Manager("neha");
	Manager* andrew = new Manager("andrew");
	Manager* topher = new Manager("topher");
	Manager* harsh = new Manager("harsh");


	//greeting and prints main menu
	cout << "Welcome to the Zanach Parking Garage!!\n" << endl;

	do {

	MainMenuQuestion:
	
		cout << "\n\tWhat would you like to do? (Enter a number, or 0 to exit)" << endl;
		cout << "\t---------------------------------------------" << endl;
		cout << "\n\t1. Park my Car" << endl;
		cout << "\t2. Retrieve my car (checkout and pay)" << endl;
		cout << "\t3. Find my Car (I lost it!)" << endl;
		cout << "\t4. Manager Login" << endl;

		cout << "\tChoice: ";

		cin >> mainMenuChoice;
		while (cin.fail()) {
			cin.clear(); //Resets the flags so you can input again
			cin.ignore(100, '\n'); //Empty the buffer
			cout << "Please enter an integer!\n";
			cin >> mainMenuChoice;
		}

		if (mainMenuChoice < 0 || mainMenuChoice > 4) {
			cout << "That wasn't an option.\n";
			goto MainMenuQuestion;
		}

		switch (mainMenuChoice) {

			//Parking a new car
		case 0: {
			cout << "\nSee you next time!!\n";
			return 0;
		}
		case 1:
		{

			//declaring a new car object of which all variables
			//are initialized to null or zero
			Car car;

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
			//if vip is full, say sorry, only regular spaces available
		VIPquestion:
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
			cout << "\n\tHow long would you like to stay?" << endl;
			cout << "\t---------------------------------" << endl;
			
		TimeQuestion:
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
			cout << "\nPlease enter your vehicle's make: ";
			cin >> makeInput;
			cout << endl;

			cout << "Please enter your vehicle's model: ";
			cin >> modelInput;
			cout << endl;

			cout << "Please enter your vehicle's color: ";
			cin >> colorInput;
			cout << endl;

			EnterLicensePlate:
			cout << "Please enter a 6 character license plate number: ";
			cin >> lpInput;

			//checks that the license plate is exactly 6 characters long
			while (lpInput.length() != 6) {
				cout << "Please enter a 6 character license plate number: ";
				cin >> lpInput;
			}

			for (int i = 0; i < NUM_FLOORS; i++){
				for (int j = 0; j < NUM_SPACES; j++) {
					if (lpInput.compare(carsList[i][j].get_lpNum()) == 0) {
						int lpMistake = 0;
						cout << "\nThis car is already parked in the garage, and is located at:\n" <<
							"\t----------\n" <<
							"\t| Floor " << carsList[i][j].get_floorNum() << " |\n" <<
							"\t| Space " << carsList[i][j].get_spaceNum() << " |\n" <<
							"\t----------\n";

						lpMistakeQuestion:
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
			} //end of loop tbat checks for duplicate license plate


			//checks that each character in the string is either a number or a letter
			for (int i = 0; i < 6; i++) {
				if (isalnum(lpInput.at(i)) == false) {
					cout << "\nYou entered an invalid character. "
						<< "\nPlease enter a license plate with only numbers and letters." << endl;
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
							cout << "\nYou have been assigned a VIP space at:\n" <<
								"\t----------\n" <<
								"\t| Floor " << carsList[i][j].get_floorNum() << " |\n" <<
								"\t| Space " << carsList[i][j].get_spaceNum() << " |\n" <<
								"\t----------" << 
								"\nHave a great day sir/madame!" << endl;
							projectedProfit += carsList[i][j].get_moneyOwed();
							goto successfulPark;
						}
					}


					//VIP floor is full, user picks between exiting or Regular Parking
					if (i == 0) {
						int temp = 0;
						cout << "\nI'm sorry, VIP parking is full. You may either\n1. Use Regular Parking\n2. Exit" << endl;
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
							projectedProfit += carsList[i][j].get_moneyOwed();
							cout << "\nYou have been assigned a regular space at:\n" <<
								"\t----------\n" <<
								"\t| Floor " << carsList[i][j].get_floorNum() << " |\n" <<
								"\t| Space " << carsList[i][j].get_spaceNum() << " |\n" <<
								"\t----------" <<
								"\nHave an ok day, regular parker." << endl; 
							goto successfulPark;
						}
					}
				}
			} //end of "else, regular spot"

		successfulPark:

			break; //end of the case 1, car arriving in the parkinglot
		}

		case 2:
		{
			CheckoutProcess:
			RetrieveCar:
			string temp = "";
			string timePeriod = "";

			//checkout and pay

		
			cout << "\nPlease enter your floor number: ";
			cin >> floorTemp;
			while (cin.fail()) {
				cin.clear(); //Resets the flags so you can input again
				cin.ignore(100, '\n'); //Empty the buffer
				cout << "Please enter an integer!\n";
				cin >> floorTemp;
			}
			cout << "Please enter your space number: ";
			cin >> spaceTemp;
			while (cin.fail()) {
				cin.clear(); //Resets the flags so you can input again
				cin.ignore(100, '\n'); //Empty the buffer
				cout << "Please enter an integer!\n";
				cin >> spaceTemp;
			}

			//checks if a car is parked in the given space
			if (carsList[floorTemp - 1][spaceTemp - 1].get_isOccupied() == true) {
				cout << "\nPlease re-enter your license plate number to ensure you receive the correct bill:";
				cin >> temp;
				cout << endl;
				string s = carsList[floorTemp - 1][spaceTemp - 1].get_lpNum();

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


					if (carsList[floorTemp - 1][spaceTemp - 1].get_isTowed() == true) {
						cout << "We are very sorry, your " << carsList[floorTemp - 1][spaceTemp - 1].get_color() << " "
							<< carsList[floorTemp - 1][spaceTemp - 1].get_make() << " " << carsList[floorTemp - 1][spaceTemp - 1].get_model()
							<< " has been towed. A $200 charge has been added to your bill. You can contact us at the number on the receipt for steps on retrieving your car." << endl;
						//carsList[floorTemp - 1][spaceTemp - 1].set_isTowed(false);
					}

					else {
						cout << "You have parked your " << carsList[floorTemp - 1][spaceTemp - 1].get_color() << " "
							<< carsList[floorTemp - 1][spaceTemp - 1].get_make()
							<< " " << carsList[floorTemp - 1][spaceTemp - 1].get_model() << " for "
							<< timePeriod << endl;
					}

					string money;
					//gets moneyOwed from car if it is parked there and asks the user for payment
					(carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 1 ? money = ".00." : money = "0.");
					cout << "\nYour total comes out to $" << carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed() << money << endl;


					//resets the space as empty so another car can be parked there
					carsList[floorTemp - 1][spaceTemp - 1].set_isOccupied(false);
					carsList[floorTemp - 1][spaceTemp - 1].set_lpNum("");
				}
				//error case - space is occupied but provided license plate doesn't match
				else {
					cout << "\nThe license plate number you entered did not match the car space provided."
						<< "\nTo ensure you aren't trying to park-n-dash or steal a car, please try again!" << endl;
					goto CheckoutProcess;
				}
				

			}
			else {//error case - given space isn't occupied
				if (carsList[floorTemp - 1][spaceTemp - 1].get_isTowed() == true) {
					cout << "We are very sorry, your " << carsList[floorTemp - 1][spaceTemp - 1].get_color() << " "
						<< carsList[floorTemp - 1][spaceTemp - 1].get_make() << " " << carsList[floorTemp - 1][spaceTemp - 1].get_model()
						<< " has been towed. A $200 charge has been added to your bill. You can contact us at the number on the receipt for steps on retrieving your car." << endl;
					//carsList[floorTemp - 1][spaceTemp - 1].set_isTowed(false);
				}
				else {
					cout << "\nOops, looks like that space wasn't occupied, please try again!" << endl;
					goto CheckoutProcess;
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
			if (paymentChoice < 1 || paymentChoice > 2) {
				cout << "That wasn't an option.\n";
				goto PaymentQuestion;
			}

			if (paymentChoice == 1) {
				bool incorrectPayment = true;
				cash = 0;
				cout << "\nPlease input your cash payment into the machine.\n";

				do {
					cout << "\tAmount entered: $";
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
						realProfit += carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed();
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

					cout << "Thank you, and have a great day!";
						incorrectPayment = false;
					}
					else {

						string money;
						(carsList[floorTemp - 1][spaceTemp - 1].get_timePeriod() == 1 ? money = ".00. " : money = "0. ");

						cout << "\nYour change is $" << change << money;
						realProfit += carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed();

					ReceiptCashQuestion2:
						cout << "Would you like a receipt?\n\t1.Yes\n\t2.No\n\tChoice: ";
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
							cout << " |  Change: $" << change << money << "\t\t\t\t\t|\n" <<
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
				realProfit += carsList[floorTemp - 1][spaceTemp - 1].get_moneyOwed();
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
		} //end of case 2, main menu


		case 3:
		{
			FindLostCar:
			int floorNum = 1;
			int spaceNum = 1;

			//asks user for license plate number to locate correct car object
			cout << "Please enter your license plate number: ";
			cin >> lpTemp;
			cout << endl;

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

			if (carsList[floorNum - 1][spaceNum - 1].get_isTowed() == true) {
				cout << "We are very sorry, your " << carsList[floorNum - 1][spaceNum - 1].get_color() << " "
					<< carsList[floorNum - 1][spaceNum - 1].get_make() << " " << carsList[floorNum - 1][spaceNum - 1].get_model()
					<< ", that was parked on floor " << floorNum << " in space " << spaceNum << ", has been towed. "
					<< "A $200 charge has been added to your bill. You can contact us at the number on the receipt for steps on retrieving your car."
					<< "Please hold while you are sent to the checkout process." << endl;
				Sleep(1000);
				
				goto CheckoutProcess;
			}

			else {
				cout << "Your " << carsList[floorNum - 1][spaceNum - 1].get_color() << " " << carsList[floorNum - 1][spaceNum - 1].get_make() << " "
					<< carsList[floorNum - 1][spaceNum - 1].get_model() << " is located at:\n" <<
					"\t----------\n" <<
					"\t| Floor " << carsList[floorNum - 1][spaceNum - 1].get_floorNum() << " |\n" <<
					"\t| Space " << carsList[floorNum - 1][spaceNum - 1].get_spaceNum() << " |\n" <<
					"\t----------\n";
			}
			
			break;
		} //end of case 3

		case 4:
		{
			//managers initialized
			//usernames are first names and password is set to "password" by default
			//but can be changed
		

			//input variables from the user
			string username = "";
			string password = "";


		managerMenu:
			cout << "\n\tLogin" << endl;
			cout << "\t------" << endl;
			cout << "\tManager Username: ";
			cin >> username;

		incorrectPass:
			cout << "\tManager Password: ";
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
			cout << "\n\tSuccessful Login!\n" << endl;

			int quitManager = 1;

			//while loop for manager menu
			while (quitManager == 1) {

			ManagerMenu:	
				cout << "\n\tMANAGER MENU" << endl;
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
				switch (managerMenuChoice) {

					//Printing license plates
				case 1:
				{
					
					cout << "Current License Plates in the Garage:\n ";
					for (int i = 0; i < NUM_FLOORS; i++) {
						for (int j = 0; j < NUM_SPACES; j++) {
							if (carsList[i][j].get_lpNum().empty() == false) {
								cout << carsList[i][j].get_lpNum() << "\n" << endl;
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
					cout << "The total profit made today: $" << realProfit << endl;
					break;
				}

				//prints projected money
				case 4:
				{
					cout << "The total projected profit for today is : $" << projectedProfit << endl;
					
					break;
				}

				case 5: {
					//temp inputs for car location
					int temp1 = 0;
					int temp2 = 0;
					int choice;
				TowCarQuestion:
					cout << "\n\ttWhich floor is the car that needs to be towed on?: ";
					cin >> temp1;

					while (cin.fail()) {
						cin.clear(); //Resets the flags so you can input again
						cin.ignore(100, '\n'); //Empty the buffer
						cout << "Please enter an integer!\n";
						cin >> temp1;
					}

					cout << "\n\tWhich space Number?: ";
					cin >> temp2;

					while (cin.fail()) {
						cin.clear(); //Resets the flags so you can input again
						cin.ignore(100, '\n'); //Empty the buffer
						cout << "Please enter an integer!\n";
						cin >> temp2;
					}

					//checks if a car is parked in the given space
					cout << "\nCar information:" << endl;

					if (carsList[temp1 - 1][temp2 - 1].get_isOccupied() == true) {

						if (carsList[temp1 - 1][temp2 - 1].get_isVIP() == true) {
							cout << "\tVIP: Y" << endl;
						}
						else {
							cout << "\tVIP: N" << endl;
						}

						cout << "\tLicense Plate: " << carsList[temp1 - 1][temp2 - 1].get_lpNum() << endl;
						cout << "\tColor: " << carsList[temp1 - 1][temp2 - 1].get_color() << endl;
						cout << "\tMake: " << carsList[temp1 - 1][temp2 - 1].get_make() << endl;
						cout << "\tModel: " << carsList[temp1 - 1][temp2 - 1].get_model() << endl;
						cout << "\tFee: $" << carsList[temp1 - 1][temp2 - 1].get_moneyOwed() << "0" << endl;
					CorrectCarQuestion:
						cout << "\nIs this the correct car?\n1. Yes\n2. No" << endl;
						cout << "Choice: "; 
						cin >> choice;

						while (cin.fail()) {
							cin.clear(); //Resets the flags so you can input again
							cin.ignore(100, '\n'); //Empty the buffer
							cout << "Please enter an integer!\n";
							cin >> temp2;
						}
						if (choice < 1 || choice > 2) {
							cout << "That wasn't an option.\n";
							goto CorrectCarQuestion;
						}

						switch (choice)
						{
						case 1:
						{
							cout << "The " << carsList[temp1 - 1][temp2 - 1].get_color() << " "
								<< carsList[temp1 - 1][temp2 - 1].get_make() << " " << carsList[temp1 - 1][temp2 - 1].get_model()
								<< " will be towed. Owner will be notified and a fee will be added to their bill. " << endl;
							carsList[temp1 - 1][temp2 - 1].set_isTowed(true);
							carsList[temp1 - 1][temp2 - 1].set_isOccupied(false);
							carsList[temp1 - 1][temp2 - 1].set_moneyOwed(carsList[temp1 - 1][temp2 - 1].get_moneyOwed() + 200.0);

						}
						break;
						case 2:
						{
						TowReturnQuestion:
							cout << "Would you like to renter the information?" << endl;
							cout << "1. Yes" << endl;
							cout << "2. No" << endl;
							cin >> choice;

							while (cin.fail()) {
								cin.clear(); //Resets the flags so you can input again
								cin.ignore(100, '\n'); //Empty the buffer
								cout << "Please enter an integer!\n";
								cin >> temp2;
							}
							if (choice < 1 || choice > 2) {
								cout << "That wasn't an option. Please choose from one of the available options.\n";
								goto TowReturnQuestion;
							}
							else if (choice = 1)
								goto TowCarQuestion;
								break;
						}

						}

					}
					else {
						cout << "That space is empty." << endl;
						goto TowCarQuestion;
					}

					break;
				} //end of case 5

				//change password
				
				case 6:
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
			//cout << "That wasn't an option. Goodbye";
			break;

		}//end of big switch statement


		RepeatProgram:
		cout << "\nEnter 1 to Continue to Main Menu, 0 to Exit: \n";
		cin >> quit;
	} while (quit == 1);

}