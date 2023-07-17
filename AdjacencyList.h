#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include<stdbool.h>

#define ALPHABET_MAX 26

typedef char String[20];
typedef struct{
	String* data;
	int count;
	int max;
}ArrayList;

typedef struct{
	String key;
	ArrayList value;
}ListType;

typedef ListType AdjacencyList[ALPHABET_MAX];

void initList(AdjacencyList *list);
ArrayList initializeValue(int max);
int getHash(String key);
bool addVertex(AdjacencyList A, String elem);
bool addEdge(AdjacencyList A, String firstElem, String secondElem);
//to add delete edge and delete vertex

#endif
