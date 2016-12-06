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
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

class Population {

public:
	Population();
	Population(double setMonies, int numExp);
	int getSize();

	Individual randomlySelectFromPop();
	Individual reproduce(Individual father, Individual mother);
	Individual mutate(Individual preMutant);

	double getTotalFitnessFromPop();
	double getStartingMonies();

	int getNumExp();

	void runIndividualFitnessAlgorithm();
	void generateGeneration0();
	void getPopulationsFitnessValues();
	void addChildToPos(int pos, Individual thisChild);
	void printPop();
	void setGen();

//	void *individualRun(void *threadArg);


	~Population();
private:

	const int sizeOfPop = 10; // size of population
	Individual* Gen0[10];
	double startMonies;
	int numExperiments;
};


#endif /* POPULATION_H_ */


// LEFT OFF HERE
