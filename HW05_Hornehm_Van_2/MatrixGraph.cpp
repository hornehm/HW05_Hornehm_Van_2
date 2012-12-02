#include "MatrixGraph.h"

//I'm sort of guessing at what this needs to be for now
MatrixGraph::MatrixGraph(unsigned num_nodes){
	M.resize(num_nodes);
	num_edges = 0;
}

/*
   * Add a weighted, undirected edge between nodes u and v.
   * 
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   *     u != v
   *     There is no edge between u and v.
   *     weight > 0
   */
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	if(0<= u < M.size() && 0 <= v < M.size()){
		if(u != v){
			if(weight > 0 ){
				if(M[u][v] == M[v][u]){
					return false;
				}
				else{
				M[u][v] = weight;
				M[v][u] = weight;
				num_edges++;
				}
			}
		}
	}
}


EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	return M[u][v];
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{

	
}

unsigned MatrixGraph::degree(NodeID u) const{
	return M[u].size();
}

//Again, guessing
unsigned MatrixGraph::size() const{
	return M.size();
}

//guessing again
unsigned MatrixGraph::numEdges() const{
	return num_edges;
}
