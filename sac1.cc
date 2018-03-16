#include "sac1.h"
#include <vector>
#include <algorithm>
using namespace std;


int Sac1(int C, const vector<int>& p){

	vector<int> _p = p;
	std::sort(_p.begin() , _p.end());
	
	int total_weight = 0;
	int i = 0;
	
	while(total_weight <= C && i < _p.size() ){
		total_weight += _p[i];
		i++;
	}
	
	if (total_weight > C) return i-1;
	else return i;
}