/*
 * Node.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: rocco
 */

#include "Node.h"
#include <stdlib.h>

Node::Node() : stockPrice(0.0), timeStamp(nullptr), next(nullptr) {}

Node::~Node()
{
	delete timeStamp;
	delete next;
}

Node::Node(double priceIn, fakeTime* timeIn)
{
	stockPrice = priceIn;
	timeStamp = timeIn;
	next = nullptr;
}

void Node::setNext(Node* nextIn)
{
	next = nextIn;
}

Node* Node::getNext()
{
	return next;
}

double Node::getPrice() { return stockPrice; }

fakeTime* Node::getTime() { return timeStamp; }
