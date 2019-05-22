// Kyle Phillips


#include "pch.h"
#include "wind.h"
#include <iostream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

//Method to get the wind speed. Takes a user input and checks it with the regex. Returns currentWindSpeed if past the test
int getWindSpeed() {
	
	int currentWindSpeed = 0;
	string userInput;
	regex rInt("[0-9]{0,3}");
	regex rNInt("[0-9]{0,3}");
	regex rDir("[n,s,e,w,nw,ne,sw,se,N,S,E,W,NW,NE,SW,SE ]{1,2}");
	smatch matches;

	while (currentWindSpeed == 0) {
		cout << "Enter your wind speed in MPH " << endl;
		cin >> userInput;

		if (regex_match(userInput, matches, rInt)) {
			stringstream(userInput) >> currentWindSpeed;
			break;
		}
		else {
			cout << "Enter a valid windspeed please!" << endl;
		}
	}
	return currentWindSpeed;
}
//getDirection method that takes a user input and compares it to the regex. 
string getDirection() {
	
	string windDirection;
	string userInput;
	regex rDir("[n,s,e,w,nw,ne,sw,se,N,S,E,W,NW,NE,SW,SE]{1,2}");
	smatch matches;

	while (windDirection == "") {
		cout << "Input the wind direction (N, NE, E, SE, S, SW, W, NW)" << endl;
		cin >> userInput;
		if (regex_match(userInput, matches, rDir)) {
			stringstream(userInput) >> windDirection;
			break;
		}
		else {
			cout << "Please enter a valid direction!" << endl;
		}
	}
	return windDirection;

}

void wind::getWind() {
	speed = getWindSpeed();
	direction = getDirection();
}

void wind::printWind() {
	cout << speed << " MPH " << direction << endl;
}

