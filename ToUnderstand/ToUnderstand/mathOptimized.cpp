#include "mathOptimized.hpp"


int getMedian(int a, int b, int c){
	if (a > b) {
		if (c > a) return a;
		else if (c > b) return c;
		else return b;
	}
	else {
		if (c > b) return b;
		else if (c > a) return c;
		else return a;
	}
}

int getMedianIndex(int a, int aIdx, int b, int bIdx, int c, int cIdx) {
	if ((a < b && b < c) || (c < b && b < a)) return bIdx;
	if ((b < a && a < c) || (c < a && a < b)) return aIdx;
	return cIdx;
}