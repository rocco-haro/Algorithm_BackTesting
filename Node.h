/*
 * Node.h
 *
 *  Created on: Nov 19, 2016
 *      Author: rocco
 */

#ifndef NODE_H_
#define NODE_H_
#include "fakeTime.h"

class Node {

public:
	Node();
	Node(double priceIn, fakeTime* timeIn);

	void setNext(Node* nextIn);
	void setPos(int posIn);
	Node* getNext();

	double getPrice();
	fakeTime* getTime();
	int getPos();
	~Node();

private:
	double valueInMonies;
	fakeTime* timeStamp;
	Node* next;
	int pos;
};

#endif /* NODE_H_ */
