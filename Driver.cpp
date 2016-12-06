/*
 * Driver.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: rocco
 */

#include "Driver.h"
#include "Exchange.h"
#include "GenAlg.h"
#include <iostream>
#include <string>
#include <stdlib.h>

void printX(int num)
{
	for (int k=0; k < num; k++)
	{
		cout << "x";
	}
}

int main()
{
	//TODO
	// Call GA here
	// Make into a multithreaded Genetic Algorithm

	// Each exchange object will hold two moving average lengths,
	// the type of moving averge 'D' (day) 'H' (hour) 'M' (min),
	// and the number of experiments

	Exchange* temp = new Exchange(10,40,'A',2);
	Results data;
	cout <<"Done .1.." << endl;


	 //Testing Population class
	Population test(10000, 5);
	test.generateGeneration0();
	test.printPop();
	test.runIndividualFitnessAlgorithm();
	test.printPop();
	Individual father = test.randomlySelectFromPop();
	Individual mother = test.randomlySelectFromPop();
	Individual child;
	cout << "Father: " << "Mov1: " << father.getAttributeAt(0) << " Mov2: " << father.getAttributeAt(1) <<  " SF: " << father.getAttributeAt(2) << endl ;
	cout << "Mother: " << "Mov1: " << mother.getAttributeAt(0) << " Mov2: " << mother.getAttributeAt(1)<<  " SF: " << mother.getAttributeAt(2) << endl ;
	child = test.reproduce(father, mother);
	cout << "Child: " << "Mov1: " << child.getAttributeAt(0) << " Mov2: " << child.getAttributeAt(1) << " SF: " << child.getAttributeAt(2) << endl ;
	test.addChildToPos(0, child);
	cout << "Adding child..." << endl;
	test.printPop();
	cout << "Testing fitness function" << endl;
//	test.runIndividualFitnessAlgorithm();



//	data = temp->getFitness(100,10000);
	// Within each exchange, a series of different tests will be performed
	// that will vary the savings Factor and the initial starting money

	// Savings factor will vary from 2% to 50% of initial starting money
	// whereas initial starting money will be either 10k, 50k, 100k, 500k
	//data = temp->getFitness(200, 10000);
	// TODO
	// Keep track of the range of perfomance for those with high
	// fitness values, update results.h with an int array that holds
	// how many occurrences of a certain range

	//TODO
	// Wrap the data from a set of experiments so that it contains:
	// the distribution[], starting Money,


//	cout <<"Done .2.." << endl;
//	cout << "Fitness: " << data.getTotalValue() << endl; // access the fitness value

//	cout << "Min: " << data.getMin() << " | Max: " << data.getMax() << endl;

//	cout << "Graph attr: min - " << data.getAttributesForDistr()->getMin() << " max - " << data.getAttributesForDistr()->getMax() << " ";
//	cout << "interval - " << data.getAttributesForDistr()->getInterval() << endl;
	// Only access the distrubtion graph if it is one of the chosen individuals
	// from the population
	/*
	int num=0;
	cout << "Distribution performance " << endl;
	int range = data.getAttributesForDistr()->getMin();
	for (int j=0; j < 40; j++)
	{
		cout << range << " - ";
		range+= data.getAttributesForDistr()->getInterval();
		cout << range << " : ";
		num = data.getNumberOfOccurencesAt(j);
		printX(num);
		cout << endl;
	}
	//delete temp;
	*/
//	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

/*
	cout << "Graph Perf-vs-Price attr: min - " << data.getAttributesForPerfVsPrice()->getMin() << " max - " << data.getAttributesForPerfVsPrice()->getMax() << " ";
	cout << "interval - " << data.getAttributesForPerfVsPrice()->getInterval() << endl;
	int range1 =data.getAttributesForPerfVsPrice()->getMin();

	for (int k=0; k < 40; k++)
	{
		//cout << range1 << " - ";
		range1+=data.getAttributesForPerfVsPrice()->getInterval();
		//cout << range1 << " : ";

		for (int p=0; p < data.getSizeOfListAt(k); p++ )
		{
			//cout << " " << data.getListAt_PositionAt(k,p) << " ";
		}
		//cout << endl;
	}
*/






	//tempF = temp->getFitness(20,5,10);
	//	cout << "Fitness: " << tempF << endl;
	return 0;


}
