#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<vector>
#include<limits>

#include "sortingAlgo.h"
using namespace std;

void SortingAlgorithm::swap(elem a, elem b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void SortingAlgorithm::print(list &l) {
	for(elem i = l.begin(); i != l.end(); ++i)
		cout << *i << " ";

	cout << endl;
}

int SortingAlgorithm::run(int argc, char* argv[]) {
	if(argc < 2) {
		cout << "Usage executable LIST_SIZE A1 A1 A3 ..." << endl;
		return 1;
	}

	int listSize = atoi(argv[1]);

	if(listSize < 0) {
		cout << "List size must be >= 0" << endl;
		return 2;
	}

	if(argc != listSize + 2) {
		cout << "Exactly " << listSize << " elements must be provided." << endl;
		return 3;
	}

	list l = vector<int>();

	for(size_t ind = 0; ind < listSize; ind++) {
		l.push_back(atoi(argv[ind+2]));
	}

	this->sort(l);
	this->print(l);
	return 0;
}


