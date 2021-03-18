#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	
	this->current = 0;
}
// best case: theta(1)
// worst case: theta(1)
// total complexity: theta(1)

void SMIterator::first(){
	
	this->current = 0;
}
// best case: theta(1)
// worst case: theta(1)
// total complexity: theta(1)

void SMIterator::next(){
	
	if (this->valid() == false) {
		throw exception();
	}
	else {
		this->current++;
	}

}
// best case: theta(1)
// worst case: theta(1)
// total complexity: theta(1)

bool SMIterator::valid() const{
	
	if (this->current == this->map.length)
		return false;
	return true;

	return false;
}
// best case: theta(1)
// worst case: theta(1)
// total complexity: theta(1)

TElem SMIterator::getCurrent() const{
	if (this->valid() == false) {
		throw exception();
	}
	return this->map.elements[this->current];
}
// best case: theta(1)
// worst case: theta(1)
// total complexity: theta(1)
