/*
 * Bot.h
 *
 *  Created on: Nov 20, 2016
 *      Author: rocco
 */

#ifndef BOT_H_
#define BOT_H_
#include <cmath>
class Bot {
public:
	Bot();
	Bot(double startMonies, int newSavingFactor);

	void updateMonies(double monIn);
	void updateAssets(double asIn);
	void updateSavings(double savIn);

	void updatePPA1(double in);
	void updatePPB1(double in);
	void updatePPA2(double in);
	void updatePPB2(double in);

	void updateNumStocks(double in);

	double getMonies();
	double getAssets();
	double getSavings();
	double assetCurrVal(double currPrice);
	double getInitialMoneyCount();
	double getTotalWorth(double currPrice);

	double getPPA1();
	double getPPB1();
	double getPPA2();
	double getPPB2();

	int getSavingFactor();
	int getNumStocks();

	void checkForBuySignal(double currPrice);
	void checkForSellSignal(double currPrice);
	void checkToSave();

private:
	double monies;
	double assets; // price when purchased
	double savings;
	double assetValAtCurrentPrice;
	double startingMonies;
	double totalWorth;

	double pricePointA_Mov1;
	double pricePointB_Mov1;
	double pricePointA_Mov2;
	double pricePointB_Mov2;

	int savingFactor;
	int numStocks;
	// move things from exchange to the bot
};

#endif /* BOT_H_ */
