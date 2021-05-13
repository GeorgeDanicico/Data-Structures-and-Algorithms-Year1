#include "SetIterator.h"
#include "Set.h"

#include <iostream>

SetIterator::SetIterator(const Set& m) : set(m)
{
	this->current_index = 0;
	// After initializing the current index with 0, we also check if the value of the element on position 0 is either NULL_TELEM
    // or DEL_TELEM, because in that case we have to find the first position that contains a number.
	while(this->valid() && this->set.elements[current_index] <= NULL_TELEM)
        this->current_index ++;
}
// Best case: theta(1) -> when there is an element on the first position of the hash table
// Worst case: theta(n) -> when the only element is on the last position of the hash table or there are no elements.
// Total complexity: O(n)

void SetIterator::first() {
	this->current_index = 0;
	while(this->valid() && this->set.elements[current_index] <= NULL_TELEM)
        this->current_index ++;
}
// Best case: theta(1) -> when there is an element on the first position of the hash table
// Worst case: theta(n) -> when the only element is on the last position of the hash table or there are no elements.
// Total complexity: O(n)

void SetIterator::next() {

    if(this->valid()){
        this->current_index++;
	    while(this->valid() && this->set.elements[current_index] <= NULL_TELEM)
            this->current_index ++;
	}
	else{
	    throw exception();
	}
}
// Best case: theta(1) -> when there is a number on the position this->current_index + 1
// Worst case: theta(n) -> when there is only a number on the first position of the hash table and the next one is on the last position
// Total complexity: O(n)


TElem SetIterator::getCurrent()
{
	if(this->valid())
	    return this->set.elements[this->current_index];
	else{
	    throw exception();
	}
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)

bool SetIterator::valid() const {
	if(this->set.size() == 0 || this->current_index >= this->set.capacity)
	    return false;
	return true;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)


