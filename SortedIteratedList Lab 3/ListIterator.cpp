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

void ListIterator::previous() {
    if(this->valid()){
        // Check if the current element is the head (is the first element).
        if(current == list.head) {
            // make the iterator invalid
            current = -1;
            return;
        }

        int new_current = list.head;
        int prev = -1;
        // find the previous element.
        while(new_current != -1 && new_current != current){
            prev = new_current;
            new_current = list.next[new_current];
        }
        // set the current to the previous one.
        current = prev;

    }
    else{
        // if the iterator is not valid, throw exception
        throw exception();
    }
}
// Best case: theta(1)  -> When the iterator is on the first element of the list.
// Worst case: theta(n) -> When the iterator is on the last position, we have to parse the entire list in order
//                      to get the previous of the last element.
// Total complexity: O(n)


