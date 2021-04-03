#include "SortedMap.h"
#include <iostream>
#include <cassert>

using namespace std;

bool increasing11(TKey c1, TKey c2) {
	if (c1 <= c2) {
		return true;
	}
	else {
		return false;
	}
}

bool condition(TKey key) {
	if (key % 2 == 1)
		return true;
	return false;
}

void test_filter() {

	SortedMap sm{ increasing11 };

	TKey key1 = 1;
	TKey key2 = 2;
	TKey key3 = 3;
	TKey key4 = 4;
	TKey key5 = 5;
	TValue value = 10;

	sm.add(key1, value);
	sm.add(key2, value);
	sm.add(key3, value);
	sm.add(key4, value);
	sm.add(key5, value);

	assert(sm.size() == 5);
	sm.filter(condition);
	assert(sm.size() == 3);

	sm.filter(condition);
	assert(sm.size() == 3);

	cout << "Test filter\n";

}