#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "test_function.h"

using namespace std;

int main() {
	testAll();
	testAllExtended();
	test_function();

	
	cout << "Test over" << endl;
	system("pause");
}
