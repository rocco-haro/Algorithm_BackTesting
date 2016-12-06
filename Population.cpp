/*
 * Population.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: rocco
 */

#include "Population.h"

Population::Population()
{
	setGen();
	srand(time(NULL));
	numExperiments=1;
}

Population::Population(double setMonies, int numExp)
{
	setGen();
	srand(time(NULL));
	startMonies = setMonies;
	numExperiments = numExp;
}

Population::~Population()
{
	for (int j=0; j < getSize(); j++)
		{

			delete Gen0[j];
		}
}

void Population::setGen()
{
	for (int j=0; j < getSize(); j++)
	{

		Gen0[j] = new Individual();
	}
}

void *individualRun(void *threadArg)
{
	//runFitnessAlg
	Individual* currInd;
	currInd = (Individual *) threadArg;

	// run experiment
	currInd->runFitnessAlg();


}

void Population::runIndividualFitnessAlgorithm()
{
	// Set this up to run as a thread

	// Use startMonies in this class to initiliaze the amount of starting money
	// do runFitnessAlg(int numExp) for each individual

	const int NUM_THREADS = 10; // change for a larger population
	pthread_t threads[NUM_THREADS];
	int errorCatch;

	/*
	non-threading
	for (int j=0; j < 10; j++)
	{
		Gen0[j]->setMon(getStartingMonies());
		Gen0[j]->setExp(getNumExp());
		Gen0[j]->runFitnessAlg();
	}
	*/

	for (int j=0; j < NUM_THREADS; j++)
	{
		Gen0[j]->setMon(getStartingMonies());
		Gen0[j]->setExp(getNumExp());
		errorCatch = pthread_create(&threads[j], NULL, individualRun, (void*)Gen0[j]);
		if (errorCatch) { cout << "Error in thread " << errorCatch << endl; exit(-1); }

	}

	// Wait for threads to finish
	for(int L=0; L < NUM_THREADS; L++)
	{
	pthread_join(threads[L],NULL);
	}

}


void Population::generateGeneration0()
{
	// moving averages can vary from 1 - 200 days
	// saving factor can vary from 50 - 5000
	//srand(time(NULL));
	double mov1, mov2, savingFactor;
	for(int k=0; k < getSize(); k++)
	{
		mov1 = (rand()%200) +1;
		mov2 = (rand()%200) +1;
		savingFactor = (rand()%4950) +50;

		Gen0[k]->setAttributeAt(0,mov1);
		Gen0[k]->setAttributeAt(1,mov2);
		Gen0[k]->setAttributeAt(2,savingFactor);
	}


}

void Population::printPop()
{
	for (int k=0; k < getSize(); k++)
	{
		cout << k << " : Moving1 = " << Gen0[k]->getAttributeAt(0) << " ";
		cout << "Moving2 = " << Gen0[k]->getAttributeAt(1) << " ";
		cout << "Saving Factor = " << Gen0[k]->getAttributeAt(2);
		cout << "Fitness: " << Gen0[k]->getFitnessValue() << endl;
	}
}

void Population::addChildToPos(int pos, Individual thisChild)
{
	delete Gen0[pos];
	Gen0[pos] = new Individual();
	for (int k=0; k < 3; k++)
	{
		Gen0[pos]->setAttributeAt(k, thisChild.getAttributeAt(k));
	}
}

int Population::getSize() { return sizeOfPop; }

int Population::getNumExp() { return numExperiments; }

Individual Population::randomlySelectFromPop()
{
	// build roullete wheel based off of their fitness values
	//srand(time(NULL));
	double randNum = 0; // random number from 0 - 1
	randNum = ((double) rand() /  (RAND_MAX));

	double summationOfFitnessInPop = getTotalFitnessFromPop(); // summation of all the fitness values in the population
	double sumOfCheckedInd = 0;								   // summation of all the fitness values that have been traversed thus far
	bool done = false;

	if (summationOfFitnessInPop < 1) { cout << "ERROR!!"; exit(1); } // function called before setting population

	Individual prev = *Gen0[0];
	Individual curr = *Gen0[1];
	int counter = 2;

	// check starting case
	if (randNum > 0 && randNum < (prev.getFitnessValue()/summationOfFitnessInPop))
	{
		return prev;
	}

	sumOfCheckedInd = prev.getFitnessValue();
	while (!done)
	{

		if (sumOfCheckedInd/summationOfFitnessInPop < randNum &&
				randNum <= (sumOfCheckedInd + curr.getFitnessValue())/summationOfFitnessInPop)
		{
			return curr;
		}
		else
		{
			sumOfCheckedInd+=curr.getFitnessValue();
			//prev = curr;a
			curr = *Gen0[counter];
			counter++;
			if (counter == 100) { done = true; } // avoid from accessing out of bounds. Should never happen though
		}
	}
}

Individual Population::reproduce(Individual father, Individual mother)
{
	//srand(time(NULL));
	int chooseFromFatherOrMother = ( rand() % 2) + 1;
	int numAttributesToCopy = ( rand() % 2) + 1;
	int whichAttributeToCopy1 = ( rand() % 3) + 1;
	int whichAttributeToCopy2 = ( rand() % 3) + 1;

	while(whichAttributeToCopy1 == whichAttributeToCopy2) // ensure unique attributes are copied
	{
		whichAttributeToCopy2 = ( rand() % 3) + 1;
	}

	double childMov1, childMov2, childSavingFactor;
	childMov1 = childMov2 = childSavingFactor = -1; // flag that is has not yet been updated

	if (chooseFromFatherOrMother == 1) // get attributes from mother first
	{
		cout << "Choosing from mother first..." << endl;
		if (numAttributesToCopy == 2)
		{
			cout << "Copying attr1: " << whichAttributeToCopy1 << endl;
			if (whichAttributeToCopy1 == 1) { childMov1 = mother.getAttributeAt(0); }
			else if (whichAttributeToCopy1 == 2) { childMov2 = mother.getAttributeAt(1); }
			else { childSavingFactor = mother.getAttributeAt(2); }
			cout << "Copying attr2: " << whichAttributeToCopy2 << endl;
			if (whichAttributeToCopy2 == 1) { childMov1 = mother.getAttributeAt(0); }
			else if (whichAttributeToCopy2 == 2) { childMov2 = mother.getAttributeAt(1); }
			else { childSavingFactor = mother.getAttributeAt(2); }

		}
		else
		{
			cout << "Copying attr1: " << whichAttributeToCopy1 << endl;
			if (whichAttributeToCopy1 == 1) { childMov1 = mother.getAttributeAt(0); }
			else if (whichAttributeToCopy1 == 2) { childMov2 = mother.getAttributeAt(1); }
			else { childSavingFactor = mother.getAttributeAt(2); }
		}

		// Identify which attribute has not yet been inherited and get from father
		if (childMov1 == -1) { childMov1 = father.getAttributeAt(0); }
		if (childMov2 == -1) { childMov2 = father.getAttributeAt(1); }
		if (childSavingFactor == -1) { childSavingFactor = father.getAttributeAt(2); }

	}
	else // get attributes from father
	{
		cout << "Choosing from Father first..." << endl;
		if (numAttributesToCopy == 2)
		{
			cout << "Copying attr1: " << whichAttributeToCopy1 << endl;
			if (whichAttributeToCopy1 == 1) { childMov1 = father.getAttributeAt(0); }
			else if (whichAttributeToCopy1 == 2) { childMov2 = father.getAttributeAt(1); }
			else { childSavingFactor = father.getAttributeAt(2); }

			cout << "Copying attr2: " << whichAttributeToCopy2 << endl;
			if (whichAttributeToCopy2 == 1) { childMov1 = father.getAttributeAt(0); }
			else if (whichAttributeToCopy2 == 2) { childMov2 = father.getAttributeAt(1); }
			else { childSavingFactor = father.getAttributeAt(2); }

		}
		else
		{
			cout << "Copying attr1: " << whichAttributeToCopy1 << endl;
			if (whichAttributeToCopy1 == 1) { childMov1 = father.getAttributeAt(0); }
			else if (whichAttributeToCopy1 == 2) { childMov2 = father.getAttributeAt(1); }
			else { childSavingFactor = father.getAttributeAt(2); }
		}

		// Identify which attribute has not yet been inherited and get from Mother
		if (childMov1 == -1) { childMov1 = mother.getAttributeAt(0); }
		if (childMov2 == -1) { childMov2 = mother.getAttributeAt(1); }
		if (childSavingFactor == -1) { childSavingFactor = mother.getAttributeAt(2); }
	}

	Individual child; child.setAttributeAt(0, childMov1); child.setAttributeAt(1, childMov2);
	child.setAttributeAt(2, childSavingFactor);
	return child;

}

double Population::getStartingMonies() { return startMonies; }

double Population::getTotalFitnessFromPop()
{
	double sum;
	for (int j = 0; j < getSize(); j++)
	{
		sum += Gen0[j]->getFitnessValue();
	}
	return sum;
}
