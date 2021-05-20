#include <assert.h>
#include <iostream>
#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);
	assert(smm.size() == 0);
	assert(smm.isEmpty());
    smm.add(1,2);
    smm.add(1,3);
    assert(smm.size() == 2);
    assert(!smm.isEmpty());
    vector<TValue> v= smm.search(1);
    assert(v.size()==2);
    v= smm.search(3);
    assert(v.size()==0);
    SMMIterator it = smm.iterator();
    it.first();
    while (it.valid()){
    	TElem e = it.getCurrent();
    	it.next();
    }
    assert(smm.remove(1, 2) == true);
    assert(smm.size() == 1);
    v = smm.search(1);
    assert(v.size() == 1);
    assert(smm.remove(1, 3) == true);
    assert(smm.remove(2, 1) == false);

    assert(smm.isEmpty());

    smm.add(11, 1);
    smm.add(7, 1);
    smm.add(2, 1);
    smm.add(4, 1);
    smm.add(9, 1);
    smm.add(20, 1);
    smm.add(19, 1);
    smm.add(25, 1);
    smm.add(15, 1);
    smm.add(13, 1);
    smm.add(17, 1);
    smm.add(14, 1);

    assert(smm.size() == 12);
    assert(smm.remove(11, 1) == true);
    assert(smm.size() == 11);
    //assert(smm.remove(11, 1) == false);
    assert(smm.remove(20, 1) == true);


}

