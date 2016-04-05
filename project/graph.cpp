#include <stdio.h>
#include "graph.hpp"

Graph::Graph()
{
	//default constructor
}

Graph::Graph(int v)
{
	size = v;
	adjMatrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		adjMatrix[i] = new int [size];
		for (int j = 0; j < size; j++)
		{
			adjMatrix[i][j] = 0;
		}
	}
}

void Graph::addEdge(int i, int j)
{
	setEdge(i,j,1);
}

void Graph::removeEdge(int i, int j)
{
	setEdge(i,j,0);
}

int Graph::getEdge(int i, int j)
{
	return adjMatrix[i][j];
}

void Graph::printGraph()
{
	printf("The Matrix rep of the graph is \n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d ", adjMatrix[i][j]);
		}
		printf("\n");
	}
}

//private

void Graph::setEdge(int i, int j, int e)
{
	if (i >= 0 && j >= 0 && i < size && j < size && (e == 0 || e == 1))
	{
		adjMatrix[i][j] = e;
	}
}
