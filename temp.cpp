// Kyle Phillips


#include "pch.h"
#include "temperature.h"
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
using namespace std;

//getTemp method that takes a user input and compares it to the regexs then returns the inputed temp if it passes the test. 
int getTemp() {

	int currentTemp = 0;
	string userInput;
	regex rInt("[0-9]{0,3}");
	regex rNInt("[0-9]{0,3}");
	smatch matches;

	while (currentTemp == 0) {
		cout << "Input the temperature: " << endl;
		cin >> userInput;

		if (regex_match(userInput, matches, rInt) || regex_match(userInput, matches, rNInt))
		{
			stringstream(userInput) >> currentTemp;
			break;
		}
		else
		{
			cout << "Please enter a valid temperature!" << endl;
		}
	}
	return currentTemp;
}

void temperature::getTemperature() {
	temp = getTemp();
}

void temperature::printTemperature() {

	cout << temp << " Degrees Fahrenheit" << endl;

}




