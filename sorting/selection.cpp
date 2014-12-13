#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<vector>
#include<limits>

#include "sortingAlgo.h"
using namespace std;

class SelectionSort : public SortingAlgorithm {
	protected:
		void sort(list &l);
};

// Selection sort
void SelectionSort::sort(list &l) {
	for(elem i = l.begin(); i != l.end(); ++i) {
		elem min = i;
		
		for(elem j = i; j != l.end(); ++j) {
			if (*j < *min)
				min = j;
		}

		int tmp = *i;
		*i = *min;
		*min = tmp;
	}
}

int main(int argc, char* argv[]) {
	SelectionSort ss;
	return ss.run(argc, argv);
}


