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
	Node* getNext();

	double getPrice();
	fakeTime* getTime();

	~Node();

private:
	double stockPrice;
	fakeTime* timeStamp;
	Node* next;
};

#endif /* NODE_H_ */
