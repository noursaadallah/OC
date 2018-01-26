#include "ugraph.h"

UndirectedGraph::UndirectedGraph(int num_nodes) : dg_(num_nodes) {
}

void UndirectedGraph::AddEdge(int a, int b) {
  dg_.AddArc(a, b);
  dg_.AddArc(b, a);
}

int UndirectedGraph::NumNodes() const {
  return dg_.NumNodes();
}

int UndirectedGraph::NumEdges() const {
  return dg_.NumArcs() / 2;
}

int UndirectedGraph::Degree(int node) const {
  return dg_.OutDegree(node);
}

const vector<int>& UndirectedGraph::Neighbors(int node) const {
  return dg_.Neighbors(node);
}
