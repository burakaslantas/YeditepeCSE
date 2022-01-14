#include <iostream>
using namespace std;

#include "intSLList.h"

int main() {

	IntSLList list, list2;

	for (int i = 0; i < 6; i++) {
		list.addToHead(i);
	}
		
    list.printAll();
    list2 = list.sort_list();
	list2.printAll();
	list2.swap_nodes(4);
	list2.printAll();
	
}
