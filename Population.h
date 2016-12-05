/*
 * Population.h
 *
 *  Created on: Dec 3, 2016
 *      Author: rocco
 */

#ifndef POPULATION_H_
#define POPULATION_H_
#include "Individual.h"
#include <stdlib.h>
#include <time.h>

class Population {

public:
	Population();
	int getSize();

	Individual randomlySelectFromPop();
	Individual reproduce(Individual father, Individual mother);
	Individual mutate(Individual preMutant);

	double getTotalFitnessFromPop();

	void generateGeneration0();
	void getPopulationsFitnessValues();
	void addChildToPos(int pos, Individual thisChild);
	void printPop();
	void setGen();

	~Population();
private:

	const int sizeOfPop = 10; // size of population
	Individual* Gen0[10];
};


#endif /* POPULATION_H_ */


// LEFT OFF HERE
