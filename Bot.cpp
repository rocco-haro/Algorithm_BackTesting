/*
 * Bot.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: rocco
 */

#include "Bot.h"

Bot::Bot() : startingMonies(10000), monies(10000), assets(0), savings(0), totalWorth(0),
				pricePointA_Mov1(0), assetValAtCurrentPrice(0) , pricePointB_Mov1(0),
					pricePointA_Mov2(0), pricePointB_Mov2(0), numStocks(0), savingFactor(100) {}

Bot::Bot(double startMonies, int newSavingFactor) : startingMonies(startMonies), monies(startMonies), totalWorth(0),
				assets(0), savings(0), pricePointA_Mov1(0), assetValAtCurrentPrice(0) , pricePointB_Mov1(0),
					pricePointA_Mov2(0), pricePointB_Mov2(0), numStocks(0), savingFactor(newSavingFactor) {}

void Bot::updateMonies(double monIn) { monies = monIn; }

void Bot::updateAssets(double asIn) { assets = asIn; }

void Bot::updateSavings(double savIn) { savings = savIn; }

void Bot::updatePPA1(double in) { pricePointA_Mov1 = in; }

void Bot::updatePPB1(double in) { pricePointB_Mov1 = in; }

void Bot::updatePPA2(double in) { pricePointA_Mov2 = in; }

void Bot::updatePPB2(double in) { pricePointB_Mov2 = in; }

void Bot::updateNumStocks(double in) { numStocks = in; }

double Bot::getMonies() { return monies; }

double Bot::getAssets() { return assets; }

double Bot::getSavings() { return savings; }

double Bot::assetCurrVal(double currPrice)
{ return getNumStocks()*currPrice; }

double Bot::getInitialMoneyCount() { return startingMonies; }

double Bot::getTotalWorth(double currPrice) { return getMonies()+assetCurrVal(currPrice)+getSavings(); }

double Bot::getPPA1() { return pricePointA_Mov1; }

double Bot::getPPB1() { return pricePointB_Mov1; }

double Bot::getPPA2() { return pricePointA_Mov2; }

double Bot::getPPB2() { return pricePointB_Mov2; }

int Bot::getSavingFactor() { return savingFactor; }

int Bot::getNumStocks() { return numStocks; }

void Bot::checkForBuySignal(double currPrice)
{
	// moving averages have been crossed
	if ((getPPA2() >= getPPA1()) && getPPB1() > getPPB2())
	{
		if(getMonies() > currPrice) // can afford?
		{
			int monInt = (int) getMonies();
			int price = (int) currPrice;updateNumStocks(floor(monInt/price)-1);

			updateMonies(getMonies()-(getNumStocks()*currPrice));
			updateAssets(getAssets() +(getNumStocks()*currPrice));
		}
	}
}

void Bot::checkForSellSignal(double currPrice)
{
	if ((getPPA1() >= getPPA2()) && getPPB2() > getPPB1())
	{
		if (getNumStocks() > 0)
		{
			updateMonies(getMonies()+(getNumStocks()*currPrice));
			updateNumStocks(0);
			updateAssets(0);
		}
	}
}

void Bot::checkToSave()
{
	if (getMonies() > getInitialMoneyCount()+getSavingFactor() )
	{
		updateSavings(getSavings()+getSavingFactor());
		updateMonies(getMonies()-getSavingFactor());
	}
}



