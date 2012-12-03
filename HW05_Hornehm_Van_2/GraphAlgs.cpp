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

int* bestTour;
std::vector<NodeID> bestTourVec;
double bestTourLength;
EdgeWeight currentTourLength;

	


std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	bestTour = new int[G->size()];
	for(int i = 0;i<G->size();i++){
		//Implemented from HW05Gaydads @gaydads
		bestTour[i] = i;
		bestTourVec.push_back(i);
	}
	tour(bestTour, G->size(), 0, G);
	return std::pair<std::vector<NodeID>,EdgeWeight> (bestTourVec,bestTourLength);
}

//The following code was implemented from Brinkman's CSE 274 class
void tour(int* cur, int n, int startingPt, Graph* G){
	
	if(n-startingPt == 1){
		currentTourLength = 0;
		for(int i = 0; i < n-1; i++){
			currentTourLength += G->weight(cur[i], cur[i+1]);
		}
		if(currentTourLength < bestTourLength){
			bestTourLength = currentTourLength;
			for(int i = 0; i < n; i++){
				bestTourVec[i] = cur[i];
			}
		}
	}
	else{
		currentTourLength = 0;
		for(int i = 0; i < n-1;i++){
			currentTourLength += G->weight(cur[i], cur[i+1]);
		}
		if(currentTourLength < bestTourLength){
			bestTourLength = currentTourLength;
			for(int i = 0; i < n; i++){
				bestTourVec[i] = cur[i];
			}
		}
		for(int i = startingPt; i < n; i++){
			swap(cur, cur[startingPt], cur[i]);
			tour(cur, n, startingPt+1, G);
			swap(cur, cur[startingPt], cur[i]);
		}
}
}


void swap(int* cur, int a, int b){
	int temp = cur[a];
	cur[a] = cur[b];
	cur[b] = cur[a];
}