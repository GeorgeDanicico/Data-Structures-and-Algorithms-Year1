#include "SMIterator.h"
#include "SortedMap.h"
#include <exception> 
using namespace std;

SortedMap::SortedMap(Relation r) {
	
	this->elements = new TElem[4];
	this->length = 0;
	this->capacity = 4;
	this->relation = r;

	// best case: theta(1)
	// worst case: theta(1)   => total complexity theta(1)
}

void SortedMap::resize() {

	TElem* new_elements = new TElem[2 * this->capacity];
	for (int index = 0; index < this->capacity; index++) {
		new_elements[index] = this->elements[index]; 
	}
	this->capacity = 2 * this->capacity;
	delete[] this->elements;
	this->elements = new_elements;
}
// best case: theta(length)
// worst case: theta(length) we will always parse through the entire array
// total complexity: theta(length)

TValue SortedMap::add(TKey k, TValue v) {
	
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
	// best case: theta(1) -> If the elements with the given key is on the first position, we just replace the value and return the old value
	// worst case: theta(length) -> The worst case is met when we have to perform a resize, and besides that, also to shift the elements.
	// final complexity: theta(length)
}

TValue SortedMap::search(TKey k) const {
	
	for (int index = 0; index < this->length; index++) {
		if (this->elements[index].first == k) {
			return this->elements[index].second;
		}
	}
	return NULL_TVALUE;
}
// best case: theta(1)
// worst case: theta(length)
// total complexity: O(length)

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

}
// best case: theta(length) // if the element is on the first position, then we will still have to 
// shift all the other elements;
// worst case: theta(length)
// total complexity: theta(length)

int SortedMap::size() const {

	return this->length;
}
// best case: theta(1)
// worst case: theta(1)
// total complexity: theta(1)

bool SortedMap::isEmpty() const {
	
	return (this->length == 0);
}
// best case: theta(1)
// worst case: theta(1)
// total complexity: theta(1)

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}
// best case: theta(1)
// worst case: theta(1)
// total complexity: theta(1)

void SortedMap::filter(Condition cond) {

	int map_size = this->size();
	int index = 0;
	TValue value;

	while (index < map_size) {

		if (!cond(this->elements[index].first)) {
			value = this->remove(this->elements[index].first);
			map_size--;
		}
		else
			index++;
	}
}
// Best case: Theta(n): When there is a no key that satisfy the condition
// Worst case: Theta(n^2): When we have to delete all the keys from the SortedMap
// Total Complexity: O(n^2)

SortedMap::~SortedMap() {
	
	delete[] this->elements;
}
// best case: theta(1)
// worst case: theta(1)
// total complexity: theta(1)
