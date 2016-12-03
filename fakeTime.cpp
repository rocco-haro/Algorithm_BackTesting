/*
 * fakeTime.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: rocco
 */

#include "fakeTime.h"

fakeTime::fakeTime() : sec(0), min(0), hour(0), day(0) {}

fakeTime::fakeTime(int secIn, int minIn, int hourIn, int dayIn) :
		sec(secIn), min(minIn), hour(hourIn), day(dayIn) {}

bool fakeTime::zeros() {  return sec==0 && min==0 && hour==0; }

int fakeTime::getSec() { return sec; }
int fakeTime::getMin() { return min; }
int fakeTime::getHour(){ return hour;}
int fakeTime::getDay() { return day; }

void fakeTime::reset()
{
	sec=0; min=0; hour=0; day=0;
}

void fakeTime::tick()
{
	sec++;
	if(sec > 59)
	{
		sec=0;
		min++;
	}
	if(min > 59)
	{
		min=0;
		hour++;
	}
	if (hour > 23)
	{
		hour=0;
		day++;
	}
}

void fakeTime::print()
{
	cout << "Day: " << getDay();
	cout << " Hour: " << getHour();
	cout << " Min: " << getMin();
	cout << " Sec: " << getSec() << endl;
}

fakeTime* fakeTime::copy()
{
	return new fakeTime(getSec(), getMin(), getHour(), getDay());
}

