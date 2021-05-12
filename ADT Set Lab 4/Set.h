#pragma once
#include <vector>
#include <bitset>
#include <cstring>
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111
#define DEL_TELEM -111112
typedef int TElem;

class SetIterator;

using namespace std;

class Set {
	//DO NOT CHANGE THIS PART
	friend class SetIterator;

    private:
		//TODO - Representation
		TElem* elements;
		int capacity; // the capacity
		int current_size;
        bitset<1000000> prime_numbers;


		void resize_rehash(); // the function for resizing and rehashing the hash table
		int hash_function(TElem k, int i) const; // the hash function
		void generatePrimes();
    public:
        //implicit constructor
        Set();

        //adds an element to the set
		//returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
        bool add(TElem e);

        //removes an element from the set
		//returns true if e was removed, false otherwise
        bool remove(TElem e);

        //checks whether an element belongs to the set or not
        bool search(TElem elem) const;

        //returns the number of elements;
        int size() const;

        //check whether the set is empty or not;
        bool isEmpty() const;

        //return an iterator for the set
        SetIterator iterator() const;

        // destructor
        ~Set();

};





