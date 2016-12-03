/*
 * Node.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: rocco
 */

#include "Node.h"
#include <stdlib.h>

Node::Node() : valueInMonies(0.0), timeStamp(nullptr), next(nullptr), pos(0) {}

Node::~Node()
{
	delete timeStamp;
	delete next;
}

Node::Node(double priceIn, fakeTime* timeIn)
{
	valueInMonies = priceIn;
	timeStamp = timeIn;
	next = nullptr;
	pos = 0;
}

void Node::setNext(Node* nextIn)
{
	next = nextIn;
}

void Node::setPos(int posIn)
{
	pos = posIn;
}

int Node::getPos() { return pos; }

Node* Node::getNext()
{
	return next;
}

double Node::getPrice() { return valueInMonies; }

fakeTime* Node::getTime() { return timeStamp; }
