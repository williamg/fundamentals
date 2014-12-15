#include<iostream>
#include<assert.h>

#include "linkedlist.h"
using namespace std;

int main() {
	LinkedList l;

	int a = 1, b = 2, c = 3, d = 4, e = 5;

	assert(!l.contains(&a));
	l.insert(&a);
	assert(l.contains(&a));
	l.remove(&a);
	assert(!l.contains(&a));

	l.insert(&a);
	l.insert(&b);
	l.insert(&c);

	assert(l.contains(&a));
	assert(l.contains(&b));
	assert(l.contains(&c));

	l.remove(&c);
	assert(!l.contains(&c));

	l.insert(&e);
	l.insert(&d);
	l.remove(&a);

	assert(!l.contains(&a));
	assert(l.contains(&b));
	assert(!l.contains(&c));
	assert(l.contains(&d));
	assert(l.contains(&e));

	cout << "All tests passed!" << endl;
	return 0;
}
