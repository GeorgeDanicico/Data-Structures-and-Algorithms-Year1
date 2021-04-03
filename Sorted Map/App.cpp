#include "ExtendedTest.h"
#include "ShortTest.h"

#include "SortedMap.h"
#include "test_filter.h"

#include <iostream>
using namespace std;


int main() {

	testAll();
	testAllExtended();
	test_filter();
	cout << "That's all!" << endl;
	system("pause");
	return 0;
}


