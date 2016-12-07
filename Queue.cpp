/*
 * Queue.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: rocco
 */

#include "Queue.h"

Queue::Queue() : first(nullptr), last(nullptr), MAX_SIZE(10000), currSize(0) {}

Queue::Queue(int sizeIn) : first(nullptr), last(nullptr), MAX_SIZE(sizeIn), currSize(0) {}

void Queue::enqueue(Node* lastIn)
{
	if (isEmpty())
	{
		first = lastIn;
		last = lastIn;

		currSize++;
	}
	else
	{
		if (currSize == MAX_SIZE)
		{
			last->setNext(lastIn);
			last = lastIn;
			dequeue();
		}
		else
		{
			last->setNext(lastIn);
			last = lastIn;
			currSize++;
		}
	}
}

void Queue::prepare()
{
	for(int j=0; j<MAX_SIZE;j++)
	{
		enqueue(new Node(100, nullptr));
	}
}

Node* Queue::dequeue()
{
	if (isEmpty()) { return nullptr; }
	else
	{
		Node* data = first;
		//delete first;
		first = first->getNext();
		return data;
	}
}

int Queue::getSize() { return MAX_SIZE; }
void Queue::reset()
{
	while(!isEmpty())
	{
		Node * temp = first->getNext();
		delete first;
		first = temp;
	}
}
bool Queue::isEmpty() { return first == nullptr; }
