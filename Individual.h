/*
 * Individual.h
 *
 *  Created on: Dec 3, 2016
 *      Author: rocco
 */

#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_
#include <iostream>
#include <string>

using namespace std;

class Individual {
public:
	Individual();

	void setUpAttributes();
	void setAttributeAt( int pos, double setThis);
	void setFitnessValue(double newFit);

	double getFitnessValue();
	double getAttributeAt(int pos);

private:
	double attributes[3]; // mov1, mov2, saving Factor
	double fitnessValue;
};


#endif /* INDIVIDUAL_H_ */
