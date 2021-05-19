#include "Set.h"
#include "SetIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <stack>
#include <iostream>
#include "tests.h"
using namespace std;




int main() {

	testAll();
	testAllExtended();
    tests::test_functionality();

	cout << "That's all!" << endl;
	system("pause");

}



