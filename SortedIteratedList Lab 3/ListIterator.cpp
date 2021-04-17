#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
	this->current = list.head;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)

void ListIterator::first(){
    this->current = list.head;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)

void ListIterator::next(){
	if(this->valid()){
	    this->current = list.next[current];
	}
    else{
        throw exception();
    }
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)

bool ListIterator::valid() const{
	if(this->current == -1)
	    return false;
	return true;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)

TComp ListIterator::getCurrent() const{
	if(this->valid()) {
        return list.elems[current];
    }
    else{
        throw exception();
    }
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)


