/*
 * Results.h
 *
 *  Created on: Nov 22, 2016
 *      Author: rocco
 */

#ifndef RESULTS_H_
#define RESULTS_H_
#include "Queue.h"
#include "GraphAttributes.h"
#include "LList.h"

class Results {
public:
	Results();
	Results(Queue life, double price, double moneyIn, double assetsIn, double savingsIn, double numS);

	Queue getLifeCycle();
	double getTotalValue();
	double getFinalPrice();
	double getMoney();
	double getAssets();
	double getSavings();
	double getNumStocks();
	double getMin();
	double getMax();

	GraphAttributes* getAttributesForDistr();
	int getNumberOfOccurencesAt(int position);
	void incrementDistributionAt(int position);

	GraphAttributes* getAttributesForPerfVsPrice();
	void addToPerfVsPrice(int pos, double data);
	void setUpPerfVsPrice();

	void setMin(double minIn);
	void setMax(double maxIn);
	void setTotalVal(double valIn);

	//~Results();

private:

	void setUpDistributionSet();

	// Possibly hold the life cycle
	Queue lifeCycle;
	double stockFinalPrice;
	double totalValue;
	double money;
	double assets;
	double savings;
	double numStocks;
	double minPerf; // worst performance
	double maxPerf; // inverse


	int distribution[40]; // holds all performance values
	GraphAttributes* parametersForDistr;

	LList performanceVsPrice[40];
	GraphAttributes* parametersForPerfVsPrice;

	int volatilityFactor; // TODO Calculate a volatility factor
};



#endif /* RESULTS_H_ */
