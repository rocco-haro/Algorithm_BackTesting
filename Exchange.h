/*
 * Exchange.h
 *
 *  Created on: Nov 19, 2016
 *      Author: rocco
 */

#ifndef EXCHANGE_H_
#define EXCHANGE_H_
#include <iostream>
#include "fakeTime.h"
#include "Queue.h"
#include "ExperimentType.h"
#include "Results.h"
#include "Bot.h"
#include <fstream>
#include <time.h>
#include <pthread.h>
using namespace std;


class Exchange {

public:
	Exchange();
	Exchange(int mov1, int mov2, char expt, int numTests);
	Results startSim();
	Results getFitness(int savingFact, double startMon); // change to return a "Result" object
	void printByDay();
	void tick(bool pass);
	void CSVExport(Results data[], int size);
	ExperimentType* getExp();

	int getCorrespondingPosition(double portfolioVal, int interval, int min); // O(1) !!!!!!!!!!!!!!!!!!!!!!!!!!


	Exchange* copy();
	bool crashed();
	bool yearHasPassed();
	double getPrice();
	double getMovingAvg(Queue data);
	fakeTime* getTime();
private:

	ExperimentType* exp;
	double price;
	fakeTime* TIME;
	double updatePrice();
	bool newDay(int prevDay);


};




#endif /* EXCHANGE_H_ */
