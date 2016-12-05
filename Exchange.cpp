/*
 * Exchange.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: rocco
 */

#include "Exchange.h"
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

Exchange::Exchange() : price(1000.0), TIME(new fakeTime()), exp(nullptr) {}

Exchange::Exchange(int mov1, int mov2, char expt, int numTests)
{
	price = 1000.0;
	TIME = new fakeTime();
	exp = new ExperimentType(mov1, mov2, expt, numTests);
}

Results Exchange::startSim()
{
	srand(time(NULL));

	// TODO
	// TODO
	// Incorporate the type of trading exp->getType();
	// TODO
	// Store the life cycle of the stock, and save if performance
	// of bot is weak




	//(!yearHasPassed() && !crashed() )
	Queue days1(getExp()->getMov1());
	Queue days2(getExp()->getMov2());

	// sets a default moving avg of 100 dollars
	days1.prepare(); days2.prepare();

	// have the experiment type hold the amount of money
	// the bot is starting with and the saving factor
	//cout << "Starting Monies: " << getExp()->getStartingMonies() << endl;
	Bot trader(getExp()->getStartingMonies(), getExp()->getSavFactor());

	int prevDay=0;

	Queue* pricePerDay = new Queue(); // keeps record of all the prices during the
					   // existence of the stock

	while(!yearHasPassed() && !crashed()) // adjust accordingly depending on type of sim
	{
		// TODO
		// check what kind of experiment to perform

			//printByDay();
			tick(false);

			//assets= numStocks*getPrice();
			//count++;
			//if (count==5000000) { done = true; }

			// TODO
			// Allow stock to develop until an appropriate time for the moving average
			// has occurred


			// updates queue for moving averages on a new day
			if (newDay(prevDay))
			{

				pricePerDay->enqueue(new Node(getPrice(), getTime()->copy()));
				//cout << "Monies: " << monies << " | Assets: " << assets << " | Savings: " << savings << endl;

				trader.updatePPA1(getMovingAvg(days1));
				trader.updatePPA2(getMovingAvg(days2));

				// setup moving avg1
				days1.enqueue(new Node(getPrice(), getTime()->copy()));
				days2.enqueue(new Node(getPrice(), getTime()->copy()));


				trader.updatePPB1(getMovingAvg(days1));
				trader.updatePPB2(getMovingAvg(days2));

				//cout << "Mov1_A: " << pricePointA_days1 << " Mov1_B: " << pricePointB_days1 << endl;

				//cout << "Mov2_A: " << pricePointA_days2 << " Mov2_B: " << pricePointB_days2 << endl;

				prevDay = getTime()->getDay();

				// check signal for buy
				trader.checkForBuySignal(getPrice());



				// check signal for sell
				trader.checkForSellSignal(getPrice());


				// check to save
				trader.checkToSave();


			}


			// let time pass for another second without updating the price
			tick(true);

			// enqueue price depending on test

	}


//	cout << "Moving1: " << endl;
/*
	Node *data = days1.dequeue();
	while(!days1.isEmpty())
	{

		cout << "Price: " << data->getPrice() << " | Time: ";
		if(data->getTime() != nullptr)
			{
				data->getTime()->print();
			}
		else { cout << "NULL" << endl; }
		data = days1.dequeue();
	}
*/
//	cout << "-----------" << endl;
//	cout << "Moving2: " << endl;
/*
	while(!days2.isEmpty())
	{
		data = days2.dequeue();
		cout << "Price: " << data->getPrice() << " | Time: ";
		if(data->getTime() != nullptr)
			{
				data->getTime()->print();
			}
		else { cout << "NULL" << endl; }
	}
	*/
	Results experimentRes(pricePerDay, getPrice(), trader.getMonies(), trader.assetCurrVal(getPrice()),
									trader.getSavings(), trader.getNumStocks());
	double total = trader.getTotalWorth(getPrice());
	cout << "Monies: " << trader.getMonies() << " | Assets: " << trader.assetCurrVal(getPrice()) << " | Savings: " << trader.getSavings() << endl;
	cout << "Ending Price: " << getPrice() << " Total money: " << total << endl;
	cout << "--------" << endl;
	return experimentRes;
}

void Exchange::tick(bool pass)
{
	(*TIME).tick();
	if(!pass) { price = updatePrice(); }
}

ExperimentType* Exchange::getExp() { return exp; }

int Exchange::getCorrespondingPosition(double portfolioVal, int interval, int min)
{
	cout << "Value: " << portfolioVal << " Min: " << min << endl;
	cout << "Subtract: " << portfolioVal-min << endl;
	cout << "Interval: " << interval << endl;
	return floor( ( ((int) portfolioVal) - min ) / interval );
}


void Exchange::printByDay()
{
	//cout << "Sec: " << sec << " | Min: " << min << " | Hour: " << hour << endl;

	//cout << "Day: " << day << endl;

	if ((*TIME).zeros())
	{
		// change back to days
		cout << "Day: " << (*TIME).getDay() << "  Price: " << getPrice() << endl;
	}
}

bool Exchange::crashed() { return price < 0; }

bool Exchange::yearHasPassed()
{
	if ((*TIME).getDay()==0) { return false; }
	return (*TIME).getDay()%365 == 0;
}

double Exchange::getPrice() { return price; }

double Exchange::getMovingAvg(Queue data)
{
	double numDays = data.getSize();
	Node* extracting = nullptr;
	double sum =0;
	for(int k=0; k < numDays; k++)
	{
		extracting = data.dequeue();
		sum+= extracting->getPrice();
	}
	return sum/numDays;
}

fakeTime* Exchange::getTime() { return TIME; }

double Exchange::updatePrice()
{
	double prep = getPrice();
	//cout << "Current Price: " << prep;
	// 1 - poor performance ... 10 - great performance
	int performance = (rand()%50 + 1) + (rand()%50); //rand()%50 + 1) + (rand()%50
	//if (performance == 100) { cout << "100 Check!" << endl; }
	if (performance < 40 && performance > 10) { prep-= (rand()%3 + 1 )*0.014; }
	else if (performance >= 60 && performance < 90) { prep+= (rand()%3 + 1 )*0.015; }
	else if (performance >= 40 && performance <60) { prep+=0.00149; } //0.00149;
	else if (performance < 10)
	{
		if (performance == 1 ) { prep-= (rand()%19 + 3 )*0.123; }
		else { prep-= (rand()%19 + 3 )*0.0123; }
	}

	else
	{
		//if (performance == 100) { prep+= (rand()%19 + 3)*0.123; }
		//else
		{
			prep+= (rand()%5 + 3)*0.0123;
		}
	}
	//prep+=performance;
	//cout << " | + " << prep-getPrice() << " = " << prep << "---" << performance << endl;

	return prep;
}

bool Exchange::newDay(int prevDay)
{
	return getTime()->getDay() != prevDay;
}

Exchange* Exchange::copy() { return new Exchange(getExp()->getMov1(), getExp()->getMov2(), getExp()->getType(), getExp()->getNumTests()); }

Results Exchange::getFitness(int savingFact, double startMon)
{


	Exchange* sim = nullptr;

	// Update exp with the saving factor and starting monies
	//cout << "Passed in Starting Money: " << startMon << endl;
	//exp->setSavingFactor(savingFact);
	//exp->setStartingMonies(startMon);


	//cout << "Set Starting Money: " << getExp()->getStartingMonies() << endl;


	sim = copy();
	sim->getExp()->setSavingFactor(savingFact);
	sim->getExp()->setStartingMonies(startMon);
	string in;
	int count=0;
	bool done = false;
	Results min_max;
	min_max.setMin(10000000.0);
	double maxPrice=0, minPrice=10000000;
	// Change to type Result
	/// prev edit: getExpSize()+1
	Results data[getExp()->getNumTests()+1]; // the last Result type will hold the
								 // min and max performance

	while(!done)
	{
		//cout << "working..." << endl;

		// Store result from startSim in array()
		data[count] = sim->startSim();
		//cout << "Value stored: " << data[count].getTotalValue() << endl;
		if (data[count].getTotalValue() < min_max.getMin()) { min_max.setMin(data[count].getTotalValue()); }
		if (data[count].getTotalValue() > min_max.getMax()) { min_max.setMax(data[count].getTotalValue()); }
		if (data[count].getFinalPrice() > maxPrice) { maxPrice = data[count].getFinalPrice(); }
		if (data[count].getFinalPrice() < minPrice) { minPrice = data[count].getFinalPrice(); }
		// Set max and minimal prices found throughout experiment

		// Result newRes = sim->startSim();
		// Find max and min results;

		// data(of type result) = newRes;
		count++;

		delete sim;
		sim = copy();
		sim->getExp()->setSavingFactor(savingFact);
		sim->getExp()->setStartingMonies(startMon);
		if(count == sim->getExp()->getNumTests()) { done = true; }
	}
	//sim.startSim(10,40);
	double sum=0;
	int min, max, interval, intervalPrice, positionToIncrement; min=max=interval=0;

	// Processing for performance distribution
//	cout << "Pre flooring " << min_max.getMin() << endl;
//	cout << "Pre ceiling " << min_max.getMax() << endl;
	min = floor( ((int)min_max.getMin()) / 100 )*100;
//	cout << "Min: " << min << endl;
	max = ceil( (int)min_max.getMax()/100)*100 + 100;
	//cout << "Max: " << max << endl;
	interval = (max - min)/40;

	min_max.getAttributesForDistr()->setMin(min);
	min_max.getAttributesForDistr()->setMax(max);
	min_max.getAttributesForDistr()->setInterval(interval);

	//cout << "Interval: " << interval << endl;

	// processing for stock price vs. perfomance relation
	// NOTE : min, max, and interval for the price vs performance is denoted
	// with the word "Price" appended to the variable name
	cout << "------ Stock price vs Performance " << endl;
	cout << "Min: " << minPrice << endl << "Max: " << maxPrice << endl;
	minPrice = floor(minPrice/10)*10 - 10;
	maxPrice = ceil(maxPrice/10)*10+50;
	cout << "Min: " << minPrice << endl << "Max: " << maxPrice << endl;
	intervalPrice = (20+maxPrice-minPrice)/40;
	cout << "Interval: " << intervalPrice << endl << endl;
	min_max.getAttributesForPerfVsPrice()->setMin(minPrice);
	min_max.getAttributesForPerfVsPrice()->setMax(maxPrice);
	min_max.getAttributesForPerfVsPrice()->setInterval(intervalPrice);

	for (int j=0; j < getExp()->getNumTests(); j++ )
	{



		// TODO
		// Uncomment the increment distribution function !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		positionToIncrement = getCorrespondingPosition(data[j].getTotalValue(), interval, min);
		//cout << "Postion to increment: " << positionToIncrement << endl;
		min_max.incrementDistributionAt(positionToIncrement);

		positionToIncrement = getCorrespondingPosition(data[j].getFinalPrice(), intervalPrice, minPrice);
		cout << "Position to increment: " << positionToIncrement << endl;
		if (positionToIncrement >= 40) { cout << "Error in getFitness() -- position to increment too high" << endl; }
		else
		{
			min_max.addToPerfVsPrice(positionToIncrement, data[j].getTotalValue());
		}
		// TODO
		// Write all of the stock lifecycles to a file by outputting each queue

		sum+= data[j].getTotalValue();


	}
	//cout << "Sum " << sum << endl;
	//cout << "F: " << sum/getExpSize() << endl;

	//TODO
	// update to subtract by the amount of starting money, getExp().getStartingMonies()
	double fit = (sum/(double)getExp()->getNumTests() - startMon);
	//TODO
	// solve for a more intricate way of calculating the fitness score for perfomance
	cout << "F: " << fit << endl;
	min_max.setTotalVal(fit); // include fitness value into min_max
	//cout << "check if set " << min_max.getTotalValue() << endl;
	data[getExp()->getNumTests()] = min_max;

	//Results* datatemp[getExp()->getNumTests()];
	//*datatemp = data;

	CSVExport(data, getExp()->getNumTests());


	return min_max;
}


void Exchange::CSVExport(Results data[], int size)
{
	// Gives us the number of elements of type Results in the array "data"

	Node* temp = nullptr;
	bool done = false;
	cout << "Number of trials: " << size << endl;
	ofstream Data_File;
	Data_File.open("myStockSimulationData.csv");
	if (Data_File.is_open())
	{
		cout << "Reading file " << endl;
	}
	else
	{
		cout << "Error: could not read file " << endl;
	}
	Data_File << "Stock Final Price,Stock Total Value,Money,Assets,Savings,Number of Stocks, Minimum Performance, Maximum Performance";
	for (int i = 1; i <= size; i++)
	{
		Data_File << ",Trial " << (i);
	}

	Data_File << "\n";

	for (int i = 0; i < size; i++)
	{
		Data_File << data[i].getFinalPrice() << "," << data[i].getTotalValue() << "," << data[i].getMoney()
		<< "," << data[i].getAssets() << "," << data[i].getSavings() << "," << data[i].getNumStocks() << ","
		<< data[i].getMin() << "," << data[i].getMax();

		if (!data[0].getLifeCycle()->isEmpty())
		{
			for (int j = 0; j < size; j++)
			{
				temp = data[j].getLifeCycle()->dequeue();
				Data_File << "," << temp->getPrice();
			}
		}
		Data_File << "\n";
	}

	if (!data[0].getLifeCycle()->isEmpty())
	{
		while (!done)
		{
			Data_File << " " << "," << " " << "," << " "
			<< "," << " "<< "," << " "<< "," << " " << ","
			<< " " << "," << " ";
			for (int j = 0; j < size; j++)
			{
				Data_File << "," << data[j].getLifeCycle()->dequeue()->getPrice();
			}
			Data_File << "\n";
			if (data[0].getLifeCycle()->isEmpty() == true)
			{
				done = true;
			}
		}
	}
	Data_File.close();

	cout << "Graph Perf-vs-Price attr: min - " << data[size].getAttributesForPerfVsPrice()->getMin() << " max - " << data[size].getAttributesForPerfVsPrice()->getMax() << " ";
	cout << "interval - " << data[size].getAttributesForPerfVsPrice()->getInterval() << endl;
	int range1 =data[size].getAttributesForPerfVsPrice()->getMin();

	for (int k=0; k < 40; k++)
	{
		//cout << range1 << " - ";
		range1+=data[size].getAttributesForPerfVsPrice()->getInterval();
		cout << range1 << " : ";

		for (int p=0; p < data[size].getSizeOfListAt(k); p++ )
		{
			cout << " " << data[size].getListAt_PositionAt(k,p) << " ";
		}
		cout << endl;
	}

}




















