#include "prim.h"
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int Prim(int N, const vector<Edge>& edges) {
  if (N <= 1) return 0;
  vector<vector<const Edge*>> adj(N);
  for (const Edge& e : edges) {
    adj[e.node1].push_back(&e);
    adj[e.node2].push_back(&e);
  }
  vector<bool> connected(N, false);
  vector<int> dist(N, INT_MAX);
  int total = 0;
  auto comp = [&dist](int i, int j) { return dist[i] > dist[j]; };
  priority_queue<int, vector<int>, decltype(comp)> pq(comp);
  dist[0] = 0;
  pq.push(0);
  while (!pq.empty()) {
    const int node = pq.top();
    pq.pop();
    if (connected[node]) continue;
    connected[node] = true;
    total += dist[node];
    for (const Edge* e : adj[node]) {
      const int other = e->node1 == node ? e->node2 : e->node1;
      if (!connected[other] && e->weight < dist[other]) {
        dist[other] = e->weight;
        pq.push(other);
      }
    }
  }
  return total;
}
