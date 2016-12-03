/*
 * Queue.h
 *
 *  Created on: Nov 19, 2016
 *      Author: rocco
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "Node.h"

using namespace std;

class Queue {
public:
	Queue();
	Queue(int sizeIn);
	void enqueue(Node* lastIn);
	void prepare();
	Node* dequeue();

	int getSize();
	void reset();

	bool isEmpty();
private:
	Node* first;
	Node* last;
	int MAX_SIZE;
	int currSize;
};


#endif /* QUEUE_H_ */
