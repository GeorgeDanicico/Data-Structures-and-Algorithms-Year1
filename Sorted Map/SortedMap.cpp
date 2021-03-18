#include "SMIterator.h"
#include "SortedMap.h"
#include <exception> 
using namespace std;

SortedMap::SortedMap(Relation r) {
	//TODO - Implementation
	this->elements = new TElem[4];
	this->length = 0;
	this->capacity = 4;
	this->relation = r;

	// theta(1)
}

void SortedMap::resize() {
	//TODO - Implementation
	//
	TElem* new_elements = new TElem[2 * this->capacity];
	for (int index = 0; index < this->capacity; index++) {
		new_elements[index] = this->elements[index]; 
	}
	this->capacity = 2 * this->capacity;
	delete[] this->elements;
	this->elements = new_elements;
}
//theta(length)

TValue SortedMap::add(TKey k, TValue v) {
	//TODO - Implementation
	// If there are no empty spots left, we resize the Dynamic Array.
	if (this->capacity == this->length)
		this->resize();
	// the elements in the array are sorted. 
	// So we will check for the right position of the key
	
	//The position is set to this->length, because if we do not find the key, and they 
	// respect the order, it means that the new position of the element will be the last in the array.
	int position = this->length;
	for (int index = 0; index < this->length; index++) {
		
		if (this->elements[index].first == k) {
			TValue old_value = this->elements[index].second;
			this->elements[index].second = v;
			return old_value;
		}
		else {
			TKey key1 = this->elements[index].first;
			if (this->relation(key1, k) == false) {
				position = index;
				break;
			}
		}
	}

	//Copy the elements before adding the new one
	for (int index = this->length; index > position; index--) {
		this->elements[index] = this->elements[index - 1];
	}

	TElem newPair(k, v);
	this->elements[position] = newPair;
	this->length++;

	return NULL_TVALUE;
	// O(length)
}

TValue SortedMap::search(TKey k) const {
	//TODO - Implementation
	for (int index = 0; index < this->length; index++) {
		if (this->elements[index].first == k) {
			return this->elements[index].second;
		}
	}
	// O(length)
	return NULL_TVALUE;
}

TValue SortedMap::remove(TKey k) {
	//TODO - Implementation

	int index;
	for (index = 0; index < this->length && this->elements[index].first != k; index++);

	// if index == this->length it means that we did not find the key in the array.
	if (index == this->length) {
		return NULL_TVALUE;
	}
	TElem copy = this->elements[index];
	for (int i = index; i < this->length - 1; i++) {
		this->elements[i] = this->elements[i + 1];
	}

	this->length--;
	return copy.second;

	//theta(length)
}

int SortedMap::size() const {
	//TODO - Implementation

	return this->length;
	//theta(1)
}

bool SortedMap::isEmpty() const {
	//TODO - Implementation
	return (this->length == 0);
	//theta(1)
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}
//theta(1)

SortedMap::~SortedMap() {
	//TODO - Implementation
	delete[] this->elements;
}
// theta(1)
