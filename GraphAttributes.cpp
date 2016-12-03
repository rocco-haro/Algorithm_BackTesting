/*
 * GraphAttributes.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: rocco
 */

#include "GraphAttributes.h"

GraphAttributes::GraphAttributes() : min(0), max(0), interval(0) {}

void GraphAttributes::setMin(int minIn) { min = minIn; }

void GraphAttributes::setMax(int maxIn) { max = maxIn; }

void GraphAttributes::setInterval(int intvIn) { interval = intvIn; }

int GraphAttributes::getMin() { return min; }

int GraphAttributes::getMax() { return max; }

int GraphAttributes::getInterval() { return interval; }
