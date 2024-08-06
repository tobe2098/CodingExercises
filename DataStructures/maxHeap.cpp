#include "maxHeap.hpp"

void maxHeapify(std::vector<int>& v, int index, int n) {
	int val{ v[index] };
	int first{ 2 * index + 1 };
	while (first < n) {
		if (first<n-1 && v[first+1] >= v[first]) first++;
		if (val > v[first]) break;
		else {
			v[(first - 1) / 2] = v[first];
			first =2*first+1;
		}
	}
	v[(first - 1) / 2] = val;
	return;
}

void makeMaxHeap(std::vector<int>& v,int n){
	for (int i = n / 2 -1; i >= 0; i--) {
		maxHeapify(v, i,n);
	}
}
