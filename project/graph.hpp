#ifndef GRAPH_HPP
#define GRAPH_HPP

class Graph
{
	public:
		Graph();
		Graph(int v);
		void addEdge(int i, int j);
		void removeEdge(int i, int j);
		int getEdge(int i, int j);
		void printGraph();

	private:
		void setEdge(int i, int j, int e);
		int **adjMatrix;
		int size;

};

#endif