#pragma once
#include<iostream>
#include"Graph.h"

using namespace std;



void TopoSort_test();

template <class T, class E>
void TopologicalSort(Graph<T, E>& G);

int main() {
	TopoSort_test();
	return 0;
}

void TopoSort_test() {
	int n; //numofVertexes
	cin >> n;
	Graphmtx<int, int> G1(n);
	TopologicalSort(G1);
	G1.~Graphmtx();
	return;
}