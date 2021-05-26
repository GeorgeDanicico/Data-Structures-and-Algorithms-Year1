#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"
#include "NewTest.h"

int main(){
    testAll();
	testAllExtended();
	NewTest::newTest();

    std::cout<<"Finished SMM Tests!"<<std::endl;
	system("pause");
}
