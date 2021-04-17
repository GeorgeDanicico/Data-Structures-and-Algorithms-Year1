#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIteratedList::SortedIteratedList(Relation r) {
	//TODO - Implementation
	this->r = r;
	this->capacity = 4;
	this->head = -1;
	this->elems = new TComp(this->capacity);
	this->next = new int(this->capacity);
	this->Size = 0;
	for(int i = 0; i < this->capacity - 1; i++)
	    this->next[i] = i + 1;
	this->next[this->capacity - 1] = -1;
	this->firstEmpty = 0;
}

void SortedIteratedList::resize() {
    int* new_next = new int(this->capacity * 2);
    TComp* new_elems = new TComp(this->capacity * 2);
    //copying the elements
    for(int i = 0; i < this->capacity; i++) {
        new_next[i] = this->next[i];
        new_elems[i] = this->elems[i];
    }
    // setting the new empty nexts.
    for(int i = this->capacity; i < 2*this->capacity - 1; i++)
        new_next[i] = i + 1;
    // freeing the memory
    new_next[2*this->capacity - 1] = -1;
    delete this->next;
    delete this->elems;

    // updating the elements;
    this->next = new_next;
    this->elems = new_elems;
    this->firstEmpty = this->capacity;
    this->capacity *= 2;
}

int SortedIteratedList::size() const {
	//TODO - Implementation
	return this->Size;
	return 0;
}
// Best case: theta(1)
// Worst Case: theta(1)
// Total complexity: theta(1)

bool SortedIteratedList::isEmpty() const {
	return this->Size == 0;
}
// Best case: theta(1)
// Worst Case: theta(1)
// Total complexity: theta(1)

ListIterator SortedIteratedList::first() const {
	//TODO - Implementation
	return ListIterator(*this);
}

TComp SortedIteratedList::getElement(ListIterator poz) const {
	//TODO - Implementation
	return NULL_TCOMP;
}

TComp SortedIteratedList::remove(ListIterator& poz) {
	//TODO - Implementation
	return NULL_TCOMP;
}

ListIterator SortedIteratedList::search(TComp e) const{
	//TODO - Implementation
	return ListIterator(*this);
}

void SortedIteratedList::add(TComp e) {
	//TODO - Implementation
	if(this->firstEmpty == -1)
	    this->resize();

	int current = this->head;
	// we check if the list is empty
	if(current == -1){
	    this->head = 0;
	    this->elems[0] = e;
	    this->firstEmpty = this->next[this->firstEmpty];
	    this->next[0] = -1;
	    this->Size ++;
	    return;
	}
	// if the element we want to insert should on the first position
	if(!this->r(this->elems[current], e)){
	    //
	    int pos = this->firstEmpty;
	    this->elems[pos] = e;
        this->firstEmpty = this->next[firstEmpty];
	    this->next[pos] = this->head;
	    this->head = pos;
	    return;
	}
    int previous = -1;
	while(current != -1 && this->r(this->elems[current], e)){
	    previous = current;
	    current = next[current];
	}

    int pos = this->firstEmpty;
    this->elems[pos] = e;
    this->firstEmpty = this->next[firstEmpty];
    next[previous] = pos;
    next[pos] = current;
    this->Size ++;

}

SortedIteratedList::~SortedIteratedList() {
	//TODO - Implementation
}

