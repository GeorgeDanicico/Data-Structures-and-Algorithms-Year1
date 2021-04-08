#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>

SortedBag::SortedBag(Relation r) {
	//TODO - Implementation
	this->SLL.head = nullptr;
	this->rel = r;
	this->length = 0;
}
// Best Case: theta(1)
// Worst Case: theta(1).
// Total complexity: theta(1)

void SortedBag::add(TComp e) {
	//TODO - Implementation
	sllnode* current = this->SLL.head;
    // if the list is empty, we have to add the element on the first position
    if(current == nullptr){
        sllnode* new_node = new sllnode;
        new_node->info = e;
        new_node->freq = 1;
        new_node->next = nullptr;
        this->SLL.head = new_node;
        this->length ++;
        return;
    }
    // If the elements needs to be added on the first position, we change the head.
    if(!this->rel(current->info, e)){
        sllnode* new_node = new sllnode;
        new_node->info = e;
        new_node->freq = 1;
        new_node->next = current;
        this->SLL.head = new_node;
        this->length ++;
        return;
    }
	// We do a search through the list to check if there is the element we want to add.
	while(current->next != nullptr && this->rel(current->next->info, e))
	    current = current->next;

    // There are 2 cases: if the element is not in the list or it is.
    // If it is in the list, than we have to change its frequency, else we have to add him.

    if(current->info == e){
        current->freq ++;
        this->length ++;
    }
    else {
        auto *new_node = new sllnode;
        new_node->info = e;
        new_node->freq = 1;
        new_node->next = current->next;
        current->next = new_node;
        this->length ++;
    }
}
// Best case: theta(1) - This case happens when the list is empty or the element we want to add is on the first position.
// Worst case: theta(n) - This case happens when the element we are looking for in the list is on the last position, or is not in the list.
// Total complexity: O(n).


bool SortedBag::remove(TComp e) {
    sllnode* current = this->SLL.head;

    // if the list is empty there is nothing we can remove
    if(current == nullptr)
        return false;

    // If the relation between the first element and the searched element is false, it means that the searched element is not
    // in the list
    if(!this->rel(current->info, e))
        return false;

    if(current->info == e){
        if(current->freq > 1)
            current->freq--, this->length --;
        else{
            this->SLL.head = current->next;
            current->next = nullptr;
            this->length --;
            delete current;
        }
        return true;
    }

    sllnode* previous = nullptr;
    while(current->next != nullptr && this->rel(current->next->info, e)) {
        previous = current;
        current = current->next;
    }
    // If the element is not in the list, we return false
    // If it is in the list we check the following:
    //  - if its frequency is  > 1 then we just decrement it.
    //  - if its frequency is 1, we have to delete the element properly.
    if(current->info != e)
        return false;
    else {
        if(current->freq > 1)
            current->freq --, this->length --;
        else{
            previous->next = current->next;
            current->next = nullptr;
            this->length --;
            delete current;
        }
        return true;
    }
}
// Best case: theta(1) - This case is when the element we have to delete is on the first position.
// Worst case: theta(n) - This case is when the element we have to delete is on the last position.
// Total complexity: O(n).


bool SortedBag::search(TComp elem) const {
    sllnode* current = this->SLL.head;

    while(current != nullptr && current->info != elem)
        current = current->next;
    // If the element is not in the list we return false.
    // Otherwise we return true.
    if(current == nullptr)
        return false;
    else return true;
}
// Best case: theta(1) - This case is when the element is the first in the list.
// Worst case: theta(n) - This case is when the element is the last in the list
// Total complexity: O(n).

int SortedBag::nrOccurrences(TComp elem) const {
	sllnode* current = this->SLL.head;

	while(current != nullptr && current->info != elem)
	    current = current->next;
	// If the element is not in the list we return null.
	// Otherwise we return the frequence of the required element.
	if(current == nullptr)
	    return 0;
	else return current->freq;
}
// Best case: theta(1) - This case is when the element is the first in the list.
// Worst case: theta(n) - This case is when the element is the last in the list
// Total complexity: O(n).


int SortedBag::size() const {
	return this->length;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)


bool SortedBag::isEmpty() const {
	if (this->SLL.head == nullptr)
	    return true;
	return false;
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}
// Best case: theta(1)
// Worst case: theta(1)
// Total complexity: theta(1)

SortedBag::~SortedBag() {
	//TODO - Implementation
	while(this->SLL.head != nullptr){
        sllnode* current = this->SLL.head;
	    this->SLL.head = current->next;
	    delete current;
	}
}
// Best case: theta(n)
// Worst case: theta(n) In all case we have to go through all the elements in the list.
// Total complexity: theta(n)
