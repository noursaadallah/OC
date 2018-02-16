#include <vector>
#include <algorithm>
#include "parcel.h"

using namespace std;

int MaxGain(const vector<int>& gain){
	int max1 = 0;
	int max2 = 0;

	for(int i : gain){
		int _max = max(max1+i , max2);
		max1 = max2;
		max2 = _max;
	}
	return max2;
}