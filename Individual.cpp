/*
 * Individual.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: rocco
 */

#include "Individual.h"

Individual::Individual() { setUpAttributes(); }

void Individual::setUpAttributes()
{
	for (int j=0; j<3; j++)
	{
		attributes[j] = "";
	}
}

void Individual::setAttributeAt(string setThis, int pos)
{
	attributes[pos] = setThis;
}

string Individual::getAttributeAt(int pos) { return attributes[pos]; }
