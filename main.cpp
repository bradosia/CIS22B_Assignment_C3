/*
Branden Lee
CIS 22B
Fall 2017
Assignment C
Problem C2

Used Microsoft Visual Studio 2017

Car class
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>
using namespace std;

/**************************************************
** global functions, and variables
**************************************************/

void input (string& reportingMarkInit, int& carNumberInit, string& kindInit, bool& loadedInit, string& destinationInit);

/**************************************************
** Car class
**************************************************/
class Car
{
private:
	string reportingMark;
	int carNumber;
	string kind;
	bool loaded;
	string destination;
public:
	Car () { setup ("", 0, "other", false, "NONE"); } //default constructor
	Car (const Car *CarObj) { setup (CarObj->reportingMark, CarObj->carNumber, CarObj->kind, CarObj->loaded, CarObj->destination); } //copy constructor
	Car (string reportingMarkInit, int carNumberInit, string kindInit, bool loadedInit, string destinationInit) { setup (reportingMarkInit, carNumberInit, kindInit, loadedInit, destinationInit); } //other constructor
	~Car () {} // destructor
	void setup (string reportingMarkInit, int carNumberInit, string kindInit, bool loadedInit, string destinationInit);
	void output ();
	friend bool Car::operator==(const Car CarObj1, const Car CarObj2)
	{
		if (CarObj1.reportingMark == CarObj2.reportingMark && CarObj1.carNumber == CarObj2.carNumber&& CarObj1.kind == CarObj2.kind&& CarObj1.loaded == CarObj2.loaded&& CarObj1.destination == CarObj2.destination) { return true; }
		return false;
	}
};

int main ()
{
	Car car1;
	string reportingMark;
	int carNumber;
	string kind;
	bool loaded;
	string destination;
	input (reportingMark, carNumber, kind, loaded, destination);
	car1.setup (reportingMark, carNumber, kind, loaded, destination);
	Car car2 (car1);
	Car car3;
	// cout here because each car object does not know its name: i.e. car1
	cout << endl << "Contents of car1" << endl;
	car1.output ();
	cout << endl << "Contents of car2" << endl;
	car2.output ();
	cout << endl << "Contents of car3" << endl;
	car3.output ();
	cout << endl;
	if (car1 == car2)
		cout << "car1 is the same car as car2\n";
	else
		cout << "car1 is not the same car as car2\n";
	if (car2 == car3)
		cout << "car2 is the same car as car3\n";
	else
		cout << "car2 is not the same car as car3\n";
	system ("pause");
	return 0;
}

/**************************************************
** Car class method definitions
**************************************************/

/******************* Car::setup *******************
** Puts the data into the data structure
** height and radius into a pointer to the Cone
**************************************************/
void Car::setup (string reportingMarkInit, int carNumberInit, string kindInit, bool loadedInit, string destinationInit)
{
	reportingMark = reportingMarkInit;
	carNumber = carNumberInit;
	kind = kindInit;
	loaded = loadedInit;
	destination = destinationInit;
}

/********************* Car::output ****************
** Calls the getVolume function to get the volume
** Prints the height, radius, and volume in a neat
** format
**************************************************/
void Car::output ()
{
	// cout << bool will output an integer
	// we create a temporary string to output the bool
	// std::boolalpha can also be used
	string loadedString = (!loaded) ? "false" : "true";
	cout << setw (16) << left << "reportingMark:" << reportingMark << endl
		<< setw (16) << left << "carNumber: " << carNumber << endl
		<< setw (16) << left << "kind: " << kind << endl
		<< setw (16) << left << "loaded: " << loadedString << endl
		<< setw (16) << left << "destination: " << destination << endl;
}

/**************************************************
** global function definitions
**************************************************/

/********************* input **********************
** Reads the height and radius from the user as
** reference parameters
**************************************************/
void input (string& reportingMarkInit, int& carNumberInit, string& kindInit, bool& loadedInit, string& destinationInit)
{
	string loadedString;
	bool destinationPrompted = false;
	while (reportingMarkInit.empty () || kindInit.empty () || (kindInit != "business" && kindInit != "maintenance" && kindInit != "other"))
	{
		cout << "Enter each value promted for below followed by a hard return: " << endl;
		cin.clear ();
		cout << "reportingMark: ";
		cin >> reportingMarkInit;
		cout << "carNumber: ";
		cin >> carNumberInit;
		cout << "kind: ";
		cin >> kindInit;
		cout << "loaded: ";
		cin >> loadedString;
		cout << endl;
	}
	// cin by default doesn't automatically parse "true" as boolean true
	// we shall temporarily store the bool string and check if its true
	// all other values we will assume are false.
	loadedInit = (loadedString != "true") ? false : true;
	std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n'); //ignore newline
	// user required to enter destination if loaded is true.
	// user is prompted only once for destination if loaded is false
	while (!destinationPrompted || loadedInit && (destinationInit.empty () || destinationInit == "NONE"))
	{
		if (destinationPrompted) cout << "Destination is REQUIRED if car is loaded" << endl;
		destinationPrompted = true;
		cout << "Enter the destination " << endl
			<< "i.e. Salt Lake City" << endl;
		cin.clear ();
		getline (cin, destinationInit);
	}
}

/* Execution results
Enter each value promted for below followed by a hard return:
reportingMark: SP
carNumber: 34567
kind: business
loaded: true

Enter the destination
i.e. Salt Lake City
Salt Lake City

Contents of car1
reportingMark:  SP
carNumber:      34567
kind:           business
loaded:         true
destination:    Salt Lake City

Contents of car2
reportingMark:  SP
carNumber:      34567
kind:           business
loaded:         true
destination:    Salt Lake City

Contents of car3
reportingMark:
carNumber:      0
kind:           other
loaded:         false
destination:    NONE
car1 is the same car as car2
car2 is not the same car as car3
*/