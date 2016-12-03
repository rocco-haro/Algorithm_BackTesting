/*
 * fakeTime.h
 *
 *  Created on: Nov 19, 2016
 *      Author: rocco
 */

#ifndef FAKETIME_H_
#define FAKETIME_H_
#include <iostream>
using namespace std;

class fakeTime {

public:
	fakeTime();
	fakeTime(int secIn, int minIn, int hourIn, int dayIn);
	bool zeros(); // sec=min=hour == 0

	// accessor methods
	int getSec();
	int getMin();
	int getHour();
	int getDay();

	void reset();
	void tick();
	void adopt(const fakeTime &copy);
	void print();

	fakeTime* copy();

private:
	int sec;
	int min;
	int hour;
	int day;
};


#endif /* FAKETIME_H_ */
