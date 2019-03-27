#pragma once
class Edge {
public:
	Edge();
	Edge(int v1, int v2, int cost);

	int v1;		// from edge
	int v2;		// to edge
	int cost; //cost
};