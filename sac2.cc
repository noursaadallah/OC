#include "sac2.h"
#include <vector>
#include <algorithm>
using namespace std;

struct ValueWeight
{
	double v;
	int w;
};

bool cmp(const ValueWeight& a, const ValueWeight& b)
{
	double r1 = a.v / a.w;
	double r2 = b.v / b.w;
	return r1 > r2;
};

double Sac2(int C, const vector<int>& p, const vector<double>& v){

	vector<ValueWeight> v_p(p.size());

	for(int i = 0 ; i < v_p.size() ; i++){
		v_p[i] = {v[i] , p[i]};
	}

	std::sort(v_p.begin() , v_p.end() , cmp );
	
	int total_weight = 0;
	double total_value = 0.0;
	
   for (int i = 0; i < v_p.size(); i++)
    {
        if (total_weight + v_p[i].w <= C)
        {
            total_weight += v_p[i].w;
            total_value += v_p[i].v;
        }
        else
        {
            int remain = C - total_weight;
            total_value += v_p[i].v * ((double) remain / v_p[i].w);
            break;
        }
    }
	return total_value;
}