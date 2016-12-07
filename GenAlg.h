/*
 * GenAlg.h
 *
 *  Created on: Dec 3, 2016
 *      Author: rocco
 */

#ifndef GENALG_H_
#define GENALG_H_
#include "Population.h"
#include "Exchange.h"
#include <fstream>

class GenAlg {
public:
	GenAlg();
	void runGA(double startingMon, int numExp); // Initial starting monies
	void incrementGen();

	int getGeneration();

private:
	Population* population;
	int generationNum;
};


#endif /* GENALG_H_ */
