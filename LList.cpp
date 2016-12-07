/*
 * LList.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: rocco
 */

#include "LList.h"

LList::LList() : head(nullptr), sizeOfList(0) {}

void LList::add(double dataIn)
{
	if (head == nullptr)
	{
		head = new Node(dataIn, nullptr);
		head->setPos(0);
		head->setNext(nullptr);
	}
	else
	{
		Node* prev = head;
		Node* curr = head->getNext();
		while(curr != nullptr)
		{
			prev = curr;
			curr = curr->getNext();
		}
		curr = new Node(dataIn, nullptr);
		int setPos = prev->getPos();
		curr->setPos(++setPos);
		prev->setNext(curr);

	}

	sizeOfList++;
}

double LList::getDataAt(int pos)
{
	if (pos < 0 && pos > getSize()) { return -100; } // out of bounds access
	else
	{
		bool done = false;
		Node* temp = head;
		while(!done && temp != nullptr)
		{
			if (temp->getPos() == pos) { done = true; }
			else { temp = temp->getNext(); }
		}
		return temp->getPrice();
	}
}

int LList::getSize() { return sizeOfList; }

LList::~LList() { delete head; }
