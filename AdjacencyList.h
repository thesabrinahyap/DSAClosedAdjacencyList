#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include<stdbool.h>

#define ALPHABET_MAX 26

typedef char String[20];
typedef enum{EMPTY, OCCUPIED, DELETED} hashStatus;

typedef struct{
	String* data;
	int count;
	int max;
}ArrayList;

typedef struct{
	String key;
	hashStatus status;
	ArrayList value;
}ListType;

typedef struct{
	ListType List[ALPHABET_MAX];
}AdjacencyList;

typedef struct{
	String elems[ALPHABET_MAX];
	int count;
}ResultsList;

//traversal data structure

typedef struct{
	String elems[ALPHABET_MAX];
	int front;
	int end;
}Queue;

//typedef ListType AdjacencyList[ALPHABET_MAX];

void initList(AdjacencyList *list);
ArrayList initializeValue(int max);
int getHash(String key, int ndx);
bool addVertex(AdjacencyList* A, String elem);
bool addEdge(AdjacencyList* A, String vertex, String edge);
bool deleteVertex(AdjacencyList* A, String elem);
bool deleteEdge(AdjacencyList* A, String vertex, String edge);
void displayList(AdjacencyList A);

//queue functions
Queue newQueue();
bool isEmpty(Queue *q);
bool isFull(Queue *q);
void enqueue(Queue *q, String vertex);
char* dequeue(Queue *q);


//traversals
void DFS(AdjacencyList A, String vertex, ResultsList *R);
void BFS(AdjacencyList A, String vertex, ResultsList *R);

#endif
