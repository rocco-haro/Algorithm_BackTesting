/*
 * LList.h
 *
 *  Created on: Dec 3, 2016
 *      Author: rocco
 */

#ifndef LLIST_H_
#define LLIST_H_
#include "Node.h"

class LList {
public:
	LList();

	void add(double dataIn);
	double getDataAt(int pos);
	int getSize();

	~LList();

private:
	Node* head;
	int sizeOfList;
};


#endif /* LLIST_H_ */
