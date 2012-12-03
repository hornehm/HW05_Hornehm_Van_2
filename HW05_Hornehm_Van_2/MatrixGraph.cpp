#include "MatrixGraph.h"

//Need to assign values to each node in the vector of vectors. Making the value 0 means there is no edge.
MatrixGraph::MatrixGraph(unsigned num_nodes){
	M.resize(num_nodes);
	for(int i = 0; i < num_nodes; i++){
		M[i].resize(num_nodes);
		for(int j = 0; j<num_nodes; j++){
			M[i][j] = 0;
		}
	}
	num_edges = 0;
}

//Destructor for MatrixGraph
MatrixGraph::~MatrixGraph(){

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
	if(0<= u && u < M.size() && 0 <= v && v < M.size()){
		if(u != v){
			if(weight > 0 ){
				if(M[u][v] == M[v][u]){
					return;
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

/*
*Finds adjacents to the certain node, u
*
*
*/
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	std::list<NWPair> adj;
	for(int i = 0; i < M[u].size();i++){
		if(M[u][i] != 0){
			adj.push_back(NWPair(i, M[u][i]));
		}
	}
	return adj;
	
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
