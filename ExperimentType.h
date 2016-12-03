/*
 * ExperimentType.h
 *
 *  Created on: Nov 21, 2016
 *      Author: rocco
 */

#ifndef EXPERIMENTTYPE_H_
#define EXPERIMENTTYPE_H_


class ExperimentType {
public:
	ExperimentType();
	ExperimentType(int m1, int m2, char t, int numTests);
	int getMov1();
	int getMov2();
	int getNumTests();
	int getSavFactor();

	char getType();

	double getStartingMonies();

	void setSavingFactor(int in);
	void setStartingMonies(double in);

private:
	int mov1;
	int mov2;
	int numTest;
	char type; // "s" - seconds | "m" - min ... "d" - days

	double beginningMonies;
	int savingFactor;

};


#endif /* EXPERIMENTTYPE_H_ */
