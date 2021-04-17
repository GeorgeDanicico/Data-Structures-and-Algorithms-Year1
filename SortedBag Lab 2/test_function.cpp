//
// Created by georg on 4/14/2021.
//

#include "SortedBag.h"
#include <assert.h>
#include <iostream>
using namespace std;


bool relation22(TComp r1, TComp r2) {
    return r1 <= r2;
}

bool relation33(TComp r1, TComp r2) {
    return r1 >= r2;
}

void test_function(){

    SortedBag sb(relation22);
    sb.add(5);
    sb.add(6);
    sb.add(0);
    sb.add(5);
    sb.add(10);
    sb.add(8);
    sb.addOccurrences(23, 1);
    assert(sb.nrOccurrences(1) ==23);
    try {
        sb.addOccurrences(-23, 1);
    }
    catch(std::exception& e){
    }
    cout << "Test add occurences\n";
}