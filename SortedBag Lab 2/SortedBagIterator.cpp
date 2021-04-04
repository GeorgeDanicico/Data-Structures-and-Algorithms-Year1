#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>
#include<iostream>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	//TODO - Implementation
	this->start = b.SLL.head;
	this->current = start;
	this->current_freq = 1;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)

TComp SortedBagIterator::getCurrent() {
    if(this->valid())
        return this->current->info;
    else
        throw exception();
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)

bool SortedBagIterator::valid() {
	if(this->current == NULL)
	    return false;
	return true;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)

void SortedBagIterator::next() {
    if(this->valid()) {
        if (this->current_freq == this->current->freq) {
            this->current = this->current->next;
            this->current_freq = 1;
        } else {
            this->current_freq++;
        }
    }
    else
        throw exception();
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)

void SortedBagIterator::first() {
	this->current = this->start;
	this->current_freq = 1;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)
