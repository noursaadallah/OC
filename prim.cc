#include "prim.h"
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int minEdge(int N , const vector<Edge>& edges , const vector<bool>& connected){
	int _min =INT_MAX;
	int nextNode=-1;

	for(int i = 0 ; i < N ; i++){
		for(e:edges){
			if(!visited[e.node1] || !visited[e.node1]){
				if(e.weight < _min){
					_min = e.weight;
					nextNode = (i==e.node1) ? node1 : node2;
				}
			}
		}
	}
	return nextNode;
}

int Prim(int N, const vector<Edge>& edges){

}