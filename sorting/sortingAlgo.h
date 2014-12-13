#ifndef SORTING_ALGO_H
#define SORTING_ALGO_H

#include<vector>
using namespace std;

typedef vector<int> list;
typedef vector<int>::iterator elem;

class SortingAlgorithm {
	public:
		static void swap(elem a, elem b);
		int run(int argc, char* argv[]);
	protected:
		virtual void sort(list &l) = 0;
		void print(list &l);
};

#endif
