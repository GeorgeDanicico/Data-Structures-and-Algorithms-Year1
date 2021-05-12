#include "SetIterator.h"
#include "Set.h"

#include <iostream>

SetIterator::SetIterator(const Set& m) : set(m)
{
	this->current_index = 0;
    while(this->valid() && this->set.elements[current_index] <= NULL_TELEM)
        this->current_index ++;
}


void SetIterator::first() {
	this->current_index = 0;
	while(this->valid() && this->set.elements[current_index] <= NULL_TELEM)
        this->current_index ++;

}


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


TElem SetIterator::getCurrent()
{
	if(this->valid())
	    return this->set.elements[this->current_index];
	else{
	    throw exception();
	}
}

bool SetIterator::valid() const {
	if(this->set.size() == 0 || this->current_index >= this->set.capacity)
	    return false;
	return true;
}



