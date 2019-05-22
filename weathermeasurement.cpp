// Kyle Phillips


#include "pch.h"
#include "weathermeasurement.h"

void weathermeasurement::getWeatherMeasurement() {
	temperature.getTemperature();
	wind.getWind();
}

void weathermeasurement::printWeatherMeasurement() {
	temperature.printTemperature();
	wind.printWind();
}
