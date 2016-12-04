/*
 * Individual.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: rocco
 */

#include "Individual.h"

Individual::Individual() : fitnessValue(1) { setUpAttributes(); }

void Individual::setUpAttributes()
{
	for (int j=0; j<3; j++)
	{
		attributes[j] = 0;
	}
}

void Individual::setAttributeAt( int pos, double setThis)
{
	if (pos >= 0 && pos < 3) {  attributes[pos] = setThis; }
	else { cout << "Error: Cannot add at this position for the individual." << endl; }
}

void Individual::setFitnessValue(double newFit) { fitnessValue = newFit; }

double Individual::getFitnessValue() { return fitnessValue; }

double Individual::getAttributeAt(int pos) { return attributes[pos]; }
