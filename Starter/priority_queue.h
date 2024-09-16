/**************************************************
*				priority_queue.h
* This class is used to represent the priority
* queue data structure used with the graph to
* determine the MST with Prim's algorithm.
***************************************************/

#pragma once
#include <iostream>

using namespace std;

class PriorityQueue {
private:
	pair<int, double>* H;
	int* idx_map;
	int cap;
	int total;
	
	int parent(int i);
	int left(int i);
	int right(int i);

	void insert(int idx, double val);
	void heapifyUp(int i);
	void heapifyDown(int i);
public:
	PriorityQueue(int v, double c[]);
	~PriorityQueue();
	
	bool isEmpty();
	bool inQueue(int v);

	int deleteMin();
	
	void decreaseKey(int v, double new_val);
	void printQueue();
};