#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);

	//TODO - Representation
	sllnode* start;
	sllnode* current;
	int current_freq;

public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};

