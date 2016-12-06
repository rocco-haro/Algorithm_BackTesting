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

class GenAlg {
public:
	GenAlg();
	void runGA(double startingMon); // Initial starting monies

private:
	Population* population;

};


#endif /* GENALG_H_ */
