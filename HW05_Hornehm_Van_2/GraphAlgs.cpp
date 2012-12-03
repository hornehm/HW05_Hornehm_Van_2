#include "GraphAlgs.h"

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){

}

//The following code was implemented from Brinkman's CSE 274 class
int* bestTour;
float* bestTourLength;

tour(int* arr, int n, int startingPt){
	if(n-startingPt == 1){
		
	}
	else{
		for(int i = 0; i < n; i++){
		swap(arr[startingPt], arr[i]);
		tour(arr, n, startingPt+1);
		swap(arr[startingPt, arr[i]);
		}
	}
}

void swap(int* arr, int a, int b){
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;

}