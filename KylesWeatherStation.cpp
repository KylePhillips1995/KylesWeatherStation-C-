 // Kyle Phillips
//Weather Station
//This application creates a menu that allows the user to input weather info and print it. Also stores history

#include "pch.h"
#include "weathermeasurement.h"
#include <iostream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

//Variables used
string myWeatherStation;
string userInput;
string userResponse;
int currentTemp;
int currentWindSpeed;
string windDirection;
int MEMORY = 0;
int counter = 0;

//regexs used to restrict user input
regex rString("[a-zA-Z]");
regex rInt("[0-9]{0,3}");
regex rNInt("[0-9]{0,3}");
regex rDir("[n,s,e,w,nw,ne,sw,se,N,S,E,W,NW,NE,SW,SE]{1,2}");
regex rCharLimit("[a-zA-Z0-9 ]{1,100}");
regex rResponse("[1,2,3,4]{1}");
regex rHistory("[1-9][0-9]*");
smatch matches;

//GetWeatherName method to get a user inputted name. If the name is improper based on our regex will prompt user again
string getWeatherName() {

		cout << "Input your desired weather station name: " << endl;
		getline(cin, userInput);

		if (regex_match(userInput, matches, rCharLimit)) {
			myWeatherStation = userInput;
		}
		else {
			cout << "That is not a valid weather station name! Please Reenter!" << endl;
		}

	return myWeatherStation;
}
//Prompts user for a history length and sets our memory equal to it.
int getMemoryLength() {
	
		cout << "Welcome! Enter your desired History Length!" << endl;
		getline(cin, userInput);

		if (regex_match(userInput, matches, rHistory)) {
			stringstream(userInput) >> MEMORY;
		}
		else {
			cout << "That is not a valid histroy length! Please Re-enter!" << endl;
		}
	
	return MEMORY;
}

//command function that is used to take user input and compare it to the regex rResponse. Will prompt user again
string command() {
	
		cin >> userInput;
		if (regex_match(userInput, matches, rResponse)) {
			stringstream(userInput) >> userResponse;
		}
		else {
			cout << "Enter a valid input! " << endl;
		}
	return userResponse;
}

//Stores History using our arrays and a simple counter 
void storeWeatherHistory(weathermeasurement now, weathermeasurement *history) {

		now.getWeatherMeasurement();
		counter++;
		for (int i = MEMORY - 1; i > 0; i--) {
			history[i] = history[i - 1];
		}
		history[0] = now;
}

//Main console to the application
void weatherInfo() {
	cout << "Welcome to " << myWeatherStation << endl;
	cout << "Enter the number for your desired task: " << endl;
	cout << "1. Enter Your Temperature Readings" << endl;
	cout << "2. Print Current Weather Info" << endl;
	cout << "3. Print Weather History" << endl;
	cout << "4. Exit" << endl;
}

//main where all the magic happens and the program is implemented. Takes 4 cases
int main() {
	//Loops to check if memory is set. If not takes memory from user and sets it in our pointer arrays
	while(MEMORY == 0) {
		getMemoryLength();
		weathermeasurement now;
		weathermeasurement * history = new weathermeasurement[MEMORY];
		while (MEMORY != 0) {
			while (myWeatherStation == "") {
				getWeatherName();
				while (myWeatherStation != "") {
					weatherInfo();
					command();
					while (userResponse != "") {
						if (userResponse == "1") {
							storeWeatherHistory(now, history);
							counter++;
							system("CLS");
							break;
						}
						else if (userResponse == "2") {
							history[0].printWeatherMeasurement();
							break;
						}
						else if (userResponse == "3")
						{
							for (int i = MEMORY -1; i >= 0; i--) {
								history[i].printWeatherMeasurement();
							}
							break;
						}
						else if (userResponse == "4") {
							exit(0);
						}

					}

				}
			}
		}
	}
}


//Prints the current weather station information that is stored. *NOT HISTORY*
//void printCurrentWeather() {

	//if (counter == 0) {
			//Creates a problem
		//cout << "Nothing to print! Please enter some data! " << endl;
	//}
	//else{
		//cout << "Your Weather Station Variables: " << myWeatherStation << endl;
		//cout << "Entered Temperature: " << now[0].curTemp.curTemp << "F"  << endl;
		//cout << "Entered Wind Speed: " << now[0].wind.winSpeed << "MPH" << now[0].wind.winDirection << endl;

//	}
//}

//prints all the weather history that has been stored within the arrays by incrementing through a for loop until reach memory max
//void weatherHistoryPrint() {

	//for (int i = MEMORY - 1; i >= 0; i--) {
		//cout << "Most Recent Entry Top Down:" << endl;
		//print(myWeatherStation, tempArray[i], windSpeedArray[i], windDir[i]);
//	}

//}