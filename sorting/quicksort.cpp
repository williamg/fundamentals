#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<vector>
#include<limits>

#include "sortingAlgo.h"
using namespace std;

class Quicksort : public SortingAlgorithm {
	protected:
		void sort(list &l);
		void quicksort(list &l, elem lo, elem hi);
		elem partition(list &l, elem lo, elem hi);
		elem choosePivot(list &l, elem lo, elem hi);
};

// Use the median of lo, hi, and (lo + hi) / 2 as pivot point
elem Quicksort::choosePivot(list &l, elem lo, elem hi) {
	int dist = distance(lo, hi) / 2;
	elem mid = lo;
	advance(mid, dist);

	if(*mid > *lo) {
		if(*hi > *mid)
			return mid;
		else if(*hi < *lo)
			return lo;
		return hi;
	} else {
		if(*hi < *mid)
			return mid;
		else if(*hi > *lo)
			return lo;
		return hi;
	}
}

elem Quicksort::partition(list &l, elem lo, elem hi) {
	elem pivot = choosePivot(l, lo, hi-1);
	
	int pval = *pivot;
	swap(lo, pivot);

	elem left = lo + 1;
	elem right = hi;

	while(left < right) {
		if(*left <= pval) {
			left++;
		} else {
			swap(left, right-1);
			right--;
		}
	}

	// When the above finishes, left = right = first element > pivot
	swap(lo, left-1);
	return left-1;
}

void Quicksort::quicksort(list &l, elem lo, elem hi) {
	if(lo < hi) {
		elem p = this->partition(l, lo, hi);
		quicksort(l, lo, p);
		quicksort(l, p+1, hi);
	}
}

// Quicksort
void Quicksort::sort(list &l) {
	quicksort(l, l.begin(), l.end());
}

int main(int argc, char* argv[]) {
	Quicksort qs;
	return qs.run(argc, argv);
}


