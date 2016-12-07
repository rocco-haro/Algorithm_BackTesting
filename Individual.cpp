/*
 * Individual.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: rocco
 */

#include "Individual.h"

Individual::Individual() : fitnessValue(1), startMonies(10000),
 														numExperiments(100) { setUpAttributes(); }



void Individual::setUpAttributes()
{
	for (int j=0; j<3; j++)
	{
		attributes[j] = 0;
	}
}

void Individual::setAttributeAt( int pos, double setThis)
{
//  cout << "Attribute# " << pos << " setting to: " << setThis << endl;
	if (pos >= 0 && pos < 3) {  attributes[pos] = setThis; }
	else { cout << "Error: Cannot add at this position for the individual." << endl; }
}

void Individual::setFitnessValue(double newFit) { fitnessValue = newFit; }

void Individual::runFitnessAlg()
{

	// set the fitness value returned from exchange
	Exchange * exch = new Exchange(getAttributeAt(0), getAttributeAt(1), 'A', getExp());
	resultsFromExp = exch->getFitness(getAttributeAt(2), getStartingMonies());

	setFitnessValue(resultsFromExp.getTotalValue());
	delete exch;

}

void Individual::setExp(int in) { numExperiments = in; }

void Individual::setMon(double in ) { startMonies = in; }

int Individual::getExp() { return numExperiments; }

double Individual::getStartingMonies() { return startMonies; }

double Individual::getFitnessValue()
{
	return fitnessValue;
}

double Individual::getAttributeAt(int pos) { return attributes[pos]; }

Results Individual::getResults() { return resultsFromExp; }
