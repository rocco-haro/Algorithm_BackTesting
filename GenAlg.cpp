/*
 * GenAlg.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: rocco
 */

#include "GenAlg.h"

GenAlg::GenAlg() : population(nullptr), generationNum(0) {}

void GenAlg::incrementGen() { generationNum++; }

int GenAlg::getGeneration() { return generationNum; }

void GenAlg::runGA(double startingMon, int numExp)
{
  srand(time(NULL));
  Population population(startingMon, numExp);
  Population newPopulation(startingMon, numExp); //= new Population(startingMon, numExp);
  Individual father;// = new Individual();
  Individual mother; // = new Individual();
  bool done = false;
  population.generateGeneration0();
  cout << "Running Ga" << endl;
  while  (!done)
  {
    cout << "Gen# " << getGeneration() << endl;

    //newPopulation.resetGen();
    cout << "Running all fitness functions..." << endl;
    population.runIndividualFitnessAlgorithm();
    cout << "Previous Population: " << endl;
    population.printPop();
    for(int k=0; k < population.getSize(); k++)
    {
      father = population.randomlySelectFromPop();
      mother = population.randomlySelectFromPop();
      Individual child = population.reproduce(father, mother);
      if (((double) rand() /  (RAND_MAX)) > (0.90))
      {
    //    cout << "Mutated child" << endl;
        child = population.mutate(child);
      }
  //    cout << "Now adding child to newPopulation" << endl;
      newPopulation.addChildToPos(k, child);
//      cout << "Child added" << endl;
    }
    cout << "New population: " << endl;
    newPopulation.printPop();
    population.copy(newPopulation);
    cout << "Population updated: " << endl;
    population.printPop();
    incrementGen();
    if (getGeneration() == 3) { done = true; population.runIndividualFitnessAlgorithm(); }
  }
  cout << "Final Generation: " << endl;
  population.printPop();

  // Find highest fit individual, and her data to file
  Individual bestIndividual = population.getHighestIndividual();
  Results bestData = bestIndividual.getResults();

  cout << "best fitness: " << bestIndividual.getFitnessValue() << endl;

  ofstream Data_File;
	Data_File.open("DistributionPerformance.csv");

  int num=0;
  Data_File << "Distribution performance " << "\n";
  int range = bestData.getAttributesForDistr()->getMin();
  for (int j=0; j < 40; j++)
  {
    Data_File << range << ",";
    range+= bestData.getAttributesForDistr()->getInterval();
  //  cout << range << " : ";
    num = bestData.getNumberOfOccurencesAt(j);
    Data_File << num;
    Data_File << "\n"; // "/n"
  }
  //delete temp;

  Data_File.close();
	Data_File.open("Perf_vs_Price.csv");


  Data_File << "Graph Perf-vs-Price attr: min - " << bestData.getAttributesForPerfVsPrice()->getMin() << " max - " << bestData.getAttributesForPerfVsPrice()->getMax() << " ";
  Data_File << "interval - " << bestData.getAttributesForPerfVsPrice()->getInterval() << endl;
  int range1 =bestData.getAttributesForPerfVsPrice()->getMin();

  for (int k=0; k < 40; k++)
  {
    Data_File << range1 << "";
    range1+=bestData.getAttributesForPerfVsPrice()->getInterval();
  //  cout << range1 << " : ";

    for (int p=0; p < bestData.getSizeOfListAt(k); p++ )
    {
      Data_File << "," << bestData.getListAt_PositionAt(k,p) << " ";
    }
    Data_File << "\n"; // "/n"
  }

  Data_File.close();
}
/*
{
	repeat
		newPop = {}
		pop.runIndividualFitnessAlg(startingMon);
		for (i=1 to population.size())
		{
			father = randomSelect(population, exchange);
			mother = "                             ";
			child = reproduce(father, mother)
			if (small probability) { child = mutate(child); }
			add child to newPop;
		}
		population = newPop;
	until 24 hours have passed

	return best(population)
}
*/
