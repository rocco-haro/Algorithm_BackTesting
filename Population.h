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

	void copy(Population thisPop);
	Individual randomlySelectFromPop();
	Individual reproduce(Individual father, Individual mother);
	Individual mutate(Individual preMutant);
	Individual getHighestIndividual();
	Individual* getIndividualAt(int pos);
	double getTotalFitnessFromPop();
	double getStartingMonies();

	int getNumExp();

	void runIndividualFitnessAlgorithm();
	void generateGeneration0();
	void getPopulationsFitnessValues();
	void addChildToPos(int pos, Individual thisChild);
	void printPop();
	void resetGen();
	void setGen();

//	void *individualRun(void *threadArg);


	~Population();
private:

 int sizeOfPop = 50; // change size here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Individual* Gen0[50]; // change size here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	double startMonies;
	int numExperiments;
};


#endif /* POPULATION_H_ */


// LEFT OFF HERE
