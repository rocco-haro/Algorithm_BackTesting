/*
 * Individual.h
 *
 *  Created on: Dec 3, 2016
 *      Author: rocco
 */

#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_
#include <string>

using namespace std;

class Individual {
public:
	Individual();

	void setUpAttributes();

	void setAttributeAt(string setThis, int pos);
	string getAttributeAt(int pos);

private:
	string attributes[3]; // mov1, mov2, saving Factor
};


#endif /* INDIVIDUAL_H_ */
