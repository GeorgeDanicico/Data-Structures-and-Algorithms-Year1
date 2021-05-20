#pragma once

#include "SortedMultiMap.h"


class SMMIterator{
	friend class SortedMultiMap;
private:
	//DO NOT CHANGE THIS PART
	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map);

	//TODO - Representation
	BSTNode* current_node;
	BSTNode** stack;
	int current_size, stack_size;

public:
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
	~SMMIterator();
};

