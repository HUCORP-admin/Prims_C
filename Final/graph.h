/**************************************************
*					graph.h
* This class is used to represent all the nodes
* and edges present in the graph through an
* adjacency matrix.
***************************************************/

#pragma once
#include <vector>
#include <limits>
#include "priority_queue.h"

using namespace std;

class Graph {
private:
	int numVertices;
	int numEdges;

	vector<vector<double>> adjMatrix;
public:
	Graph();

	void initialize(int m);
	
	bool addEdge(int u, int v, double w);
	bool eraseEdge(int u, int v);
	bool isEdge(int u, int v, double w);
	
	int degree(int u);
	int edge_count();
	
	void clear();
	void print();
	
	double mst(int u);
};