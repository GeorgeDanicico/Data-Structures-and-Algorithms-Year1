//
// Created by georg on 4/28/2021.
//

#include "test_function.h"
#include <assert.h>
#include <iostream>

using namespace std;

bool increasing(TComp c1, TComp c2) {
    if (c1 <= c2) {
        return true;
    } else {
        return false;
    }
}

void test_function(){
    SortedIteratedList list = SortedIteratedList(increasing);
    TComp e = 1;
    list.add(e); e=2;
    list.add(e); e=3;
    list.add(e); e=4;
    list.add(e); e=5;
    list.add(e); e=6;
    list.add(e); e=7;
    list.add(e); e=8;
    list.add(e);
    assert(list.size() == 8);
    ListIterator it = list.first();
    assert(it.getCurrent() == 1);

    // go 4 steps forward with the iterator
    for(int i = 0 ; i < 4; i++)
        it.next();

    assert(it.getCurrent() == 5);
    it.previous();
    assert(it.getCurrent() == 4);
    for(int i = 0 ; i < 3; i++)
        it.previous();
    // after this execution, the iterator will be on the first position
    try{
        // one more step and the iterator will be invalid.
        it.previous();
        // the iterator is invalid.
        it.previous();
    }catch(exception &e){

    }
    cout << "Test bidirectional iterator.\n";
}