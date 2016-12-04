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

void Population::generateGeneration0()
{
	// moving averages can vary from 1 - 200 days
	// saving factor can vary from 50 - 5000
	srand(time(NULL));
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
		cout << "Saving Factor = " << Gen0[k]->getAttributeAt(2) << endl;
	}
}

void Population::addChildToPos(int pos, Individual thisChild)
{
	// Be sure to deallocate the memory of that position !!!!!!!!!!!!!!!!!!!!!!!!

}

int Population::getSize() { return sizeOfPop; }

Individual Population::randomlySelectFromPop()
{
	// build roullete wheel based off of their fitness values
	srand(time(NULL));
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
	srand(time(NULL));
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
		if (numAttributesToCopy == 2)
		{
			if (whichAttributeToCopy1 == 1) { childMov1 = mother.getAttributeAt(1); }
			else if (whichAttributeToCopy1 == 2) { childMov2 = mother.getAttributeAt(2); }
			else { childSavingFactor = mother.getAttributeAt(3); }

			if (whichAttributeToCopy2 == 1) { childMov1 = mother.getAttributeAt(1); }
			else if (whichAttributeToCopy2 == 2) { childMov2 = mother.getAttributeAt(2); }
			else { childSavingFactor = mother.getAttributeAt(3); }

		}
		else
		{
			if (whichAttributeToCopy1 == 1) { childMov1 = mother.getAttributeAt(1); }
			else if (whichAttributeToCopy1 == 2) { childMov2 = mother.getAttributeAt(2); }
			else { childSavingFactor = mother.getAttributeAt(3); }
		}

		// Identify which attribute has not yet been inherited and get from father
		if (childMov1 == -1) { childMov1 = father.getAttributeAt(1); }
		if (childMov2 == -1) { childMov2 = father.getAttributeAt(2); }
		if (childSavingFactor == -1) { childSavingFactor = father.getAttributeAt(3); }

	}
	else // get attributes from mother
	{
		if (numAttributesToCopy == 2)
		{
			if (whichAttributeToCopy1 == 1) { childMov1 = father.getAttributeAt(1); }
			else if (whichAttributeToCopy1 == 2) { childMov2 = father.getAttributeAt(2); }
			else { childSavingFactor = father.getAttributeAt(3); }

			if (whichAttributeToCopy2 == 1) { childMov1 = father.getAttributeAt(1); }
			else if (whichAttributeToCopy2 == 2) { childMov2 = father.getAttributeAt(2); }
			else { childSavingFactor = father.getAttributeAt(3); }

		}
		else
		{
			if (whichAttributeToCopy1 == 1) { childMov1 = father.getAttributeAt(1); }
			else if (whichAttributeToCopy1 == 2) { childMov2 = father.getAttributeAt(2); }
			else { childSavingFactor = father.getAttributeAt(3); }
		}

		// Identify which attribute has not yet been inherited and get from Mother
		if (childMov1 == -1) { childMov1 = mother.getAttributeAt(1); }
		if (childMov2 == -1) { childMov2 = mother.getAttributeAt(2); }
		if (childSavingFactor == -1) { childSavingFactor = mother.getAttributeAt(3); }
	}

	Individual child; child.setAttributeAt(0, childMov1); child.setAttributeAt(1, childMov2);
	child.setAttributeAt(2, childSavingFactor);
	return child;

}

double Population::getTotalFitnessFromPop()
{
	double sum;
	for (int j = 0; j < getSize(); j++)
	{
		sum += Gen0[j]->getFitnessValue();
	}
	return sum;
}


