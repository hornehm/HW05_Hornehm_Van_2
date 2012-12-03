#include "GraphAlgs.h"


/*
 * Solves the Traveling Salesperson Problem: finding the shortest cycle through a graph that 
 * vists every node exactly once (with exception of the first node, which is repeated as the 
 * last node in the cycle.)
 * 
 * Return value: Return a pair, with the first element being a vector of length n listing the 
 *  order of the nodes in the cycle (do NOT list the start node twice), and the second element
 *  being the length of that path (do NOT forget to include the edge from the last node back to
 *  the start node in the total length.
 *
 * Preconditions: 
 *     G is undirected.
 *     Every pair of nodes u,v  (u != v) has an edge connecting the of weight > 0.
 */

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	std::vector<NodeID> cur;
	return tour(cur.resize(G->size()), cur.size(), 0, G);
}

//The following code was implemented from Brinkman's CSE 274 class
std::pair<std::vector<NodeID>, EdgeWeight> tour(std::vector<NodeID> cur, int n, int startingPt, Graph* G){
	if(n-startingPt == 1){
		for(int i = 0; i < n; i++){
			currentTourLength += G->weight(cur[i], cur[i+1]);
		}
		if(currentTourLength < bestTourLength){
			bestTourLength = currentTourLength;
			bestTour = cur;
		}
	}
	else{
		for(int i = 0; i < n; i++){
			swap(cur, cur[startingPt], cur[i]);
			tour(cur, n, startingPt+1);
			swap(cur, cur[startingPt], cur[i]);
		}
	}
	return NWPair(bestTour, bestTourLength);
}

void swap(std::vector<NodeID> cur, int a, int b){
	int tmp = cur[a];
	cur[a] = cur[b];
	cur[b] = tmp;

}