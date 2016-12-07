/*
 * Individual.h
 *
 *  Created on: Dec 3, 2016
 *      Author: rocco
 */

#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_
#include "Exchange.h"
#include <iostream>
#include <string>

using namespace std;

class Individual {
public:
	Individual();

	void setUpAttributes();
	void setAttributeAt( int pos, double setThis);
	void setFitnessValue(double newFit);
	void runFitnessAlg();
	void setExp(int in);
	void setMon(double in);

	int getExp();
	double getStartingMonies();

	double getFitnessValue();
	double getAttributeAt(int pos);

	Results getResults();

private:
	double attributes[3]; // mov1, mov2, saving Factor
	double fitnessValue;
	Results resultsFromExp;
	double startMonies;
	int numExperiments;
};


#endif /* INDIVIDUAL_H_ */
