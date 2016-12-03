/*
 * Results.cpp
 *
 *  Created on: Nov 22, 2016
 *      Author: rocco
 */

#include "Results.h"

Results::Results() :  stockFinalPrice(0), money(0), assets(0),
						savings(0), numStocks(0) , minPerf(0), maxPerf(0)
							{setUpDistributionSet(); parametersForDistr=new GraphAttributes();
								parametersForPerfVsPrice=new GraphAttributes();
									setUpPerfVsPrice(); }

Results::Results(Queue life, double price, double moneyIn, double assetsIn,
					double savingsIn, double numS) :
						lifeCycle(life), stockFinalPrice(price), money(moneyIn),
							assets(assetsIn), savings(savingsIn), numStocks(numS),
								minPerf(0), maxPerf(0) {setUpDistributionSet();
								parametersForDistr=new GraphAttributes(); setUpPerfVsPrice();
									parametersForPerfVsPrice=new GraphAttributes();}

Queue Results::getLifeCycle() { return lifeCycle; }

double Results::getTotalValue()
{
	double totalVal = getMoney() + getAssets() + getSavings();
	if (totalVal > 1) return totalVal;
	else return totalValue;
}

double Results::getFinalPrice() { return stockFinalPrice; }

double Results::getMoney() { return money; }

double Results::getAssets() { return assets; }

double Results::getSavings() { return savings; }

double Results::getNumStocks() { return numStocks; }

double Results::getMin() { return minPerf; }

double Results::getMax() { return maxPerf; }

int Results::getNumberOfOccurencesAt(int position)
{
	if (position < 40 && position > -1) { return distribution[position]; }
	else { return -100; } // denotes an error
}

void Results::setMin(double minIn) { minPerf = minIn; }

void Results::setMax(double maxIn) { maxPerf = maxIn; }

void Results::setTotalVal(double valIn) { totalValue = valIn; }

void Results::incrementDistributionAt(int position)
{
	distribution[position]+=1;
}

void Results::setUpDistributionSet()
{
	for (int j=0; j < 40; j++)
	{
		distribution[j]=0;
	}
}

void Results::setUpPerfVsPrice()
{
	LList initializer;
	for (int j=0; j < 40; j++)
	{
		performanceVsPrice[j] = initializer;
	}
}

GraphAttributes* Results::getAttributesForDistr() { return parametersForDistr; }

GraphAttributes* Results::getAttributesForPerfVsPrice() { return parametersForPerfVsPrice; }

//Results::~Results() { delete parameters; }

// TODO add performance methods
