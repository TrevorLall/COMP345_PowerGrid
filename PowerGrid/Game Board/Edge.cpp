#include "Edge.h"

Edge::Edge()
{
	v1 = 0;
	v2 = 0;
	cost = 0;
}

Edge::Edge(int edge1, int edge2, int costs){
	v1 = edge1;
	v2 = edge2;
	cost = costs;
}
