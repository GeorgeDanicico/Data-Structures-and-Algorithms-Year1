#include "NewTest.h"
#include <cassert>
#include <iostream>

bool rel(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void NewTest::newTest()
{
	SortedMultiMap smm = SortedMultiMap(rel);
	assert(smm.size() == 0);
	
	int kMin = 0;
	int kMax = 10;
	for (int i = kMin; i <= kMax; i++) {
		smm.add(i, i + 1);
		smm.add(i, i + 2);
		smm.add(i, i + 3);
	}

	vector<TValue> v = smm.removeKey(9);
	assert(v.size() == 3);
	assert(smm.size() == 30);

	v = smm.removeKey(20);
	assert(v.size() == 0);
	assert(smm.size() == 30);

	for (int i = 0; i < 3; i++) {
		v = smm.removeKey(i);
		assert(v.size() == 3);
		assert(smm.size() == 30 - (i+1)*3);
	}

	std::cout << "Test Remove Key" << endl;
}
