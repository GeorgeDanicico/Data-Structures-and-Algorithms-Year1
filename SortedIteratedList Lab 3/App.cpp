#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"
#include "test_function.h"

int main(){
    testAll();
    testAllExtended();
    test_function();
    std::cout<<"Finished IL Tests!"<<std::endl;
	system("pause");
}