#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	//TODO - Implementation
	this->current = 0;
}
//theta(1)

void SMIterator::first(){
	//TODO - Implementation
	this->current = 0;
}
//theta(1)

void SMIterator::next(){
	//TODO - Implementation
	if (this->valid() == false) {
		throw exception();
	}
	else {
		this->current++;
	}

}
//theta(1)

bool SMIterator::valid() const{
	//TODO - Implementation
	if (this->current == this->map.length)
		return false;
	return true;

	return false;
}
//theta(1)

TElem SMIterator::getCurrent() const{
	if (this->valid() == false) {
		throw exception();
	}
	return this->map.elements[this->current];
}
//theta(1)

