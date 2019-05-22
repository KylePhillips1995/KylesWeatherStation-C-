// Kyle Phillips


#include "wind.h"
#include "temperature.h"


struct weathermeasurement {

	temperature temperature;
	wind wind;

public: 
	void getWeatherMeasurement();

	void printWeatherMeasurement();

	void copyWeatherMeasurement();



};
#pragma once
