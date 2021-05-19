//
// Created by georg on 5/19/2021.
//

#include "tests.h"
#include <cassert>
#include <iostream>

void tests::test_functionality() {

    Set set;
    for (int i = 0; i < 30; i++) {
        set.add(i);
    }

    assert(set.size() == 30);
    set.empty();

    assert(set.size() == 0);

    for (int i = 0; i < 100; i++) {
        set.add(i);
    }

    assert(set.size() == 100);
    set.empty();
    assert(set.size() == 0);

    set.empty();
    assert(set.size() == 0);

    for (int i = 0; i < 1000; i++) {
        set.add(i);
    }


    assert(set.size() == 1000);
    set.empty();
    assert(set.size() == 0);
    std::cout<< "Test new functionality.\n";

}
