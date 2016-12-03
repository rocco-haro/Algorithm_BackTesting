/*
 * ExperimentType.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: rocco
 */

#include "ExperimentType.h"

ExperimentType::ExperimentType() : mov1(0), mov2(0), type('a') {}

ExperimentType::ExperimentType(int m1, int m2, char t, int numTests)
								: mov1(m1), mov2(m2), type(t), numTest(numTests),
									savingFactor(100), beginningMonies(10000) {}

int ExperimentType::getMov1() { return mov1; }

int ExperimentType::getMov2() { return mov2; }

int ExperimentType::getNumTests() { return numTest; }

int ExperimentType::getSavFactor() { return savingFactor; }

char ExperimentType::getType() { return type; }

double ExperimentType::getStartingMonies() { return beginningMonies; }

void ExperimentType::setSavingFactor(int in) { savingFactor = in; }

void ExperimentType::setStartingMonies(double in) { beginningMonies = in; }
