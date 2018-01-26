#include "graph.h"

// An undirected graph is just like a directed graph, but arcs are called
// "edges" and they don't have a direction: an edge (a, b) is present both
// in the adjacency list of a and the adjacency list of b.
class UndirectedGraph {
 public:
  explicit UndirectedGraph(int num_nodes);
  void AddEdge(int a, int b);

  int NumNodes() const;
  int NumEdges() const;
  int Degree(int node) const;
  const vector<int>& Neighbors(int node) const;

 private:
  DirectedGraph dg_;
};
