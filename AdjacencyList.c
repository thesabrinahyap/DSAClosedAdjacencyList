#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "AdjacencyList.h"


void initList(AdjacencyList* list){
	int ctr;
	for(ctr=0; ctr<ALPHABET_MAX; ctr++){
		strcpy(list->List[ctr].key, EMPTY);
	}
}
ArrayList initializeValue(int max){
	ArrayList A;
	A.data = malloc(max * sizeof(String));
	A.count = 0;
	A.max = max;
	
	return A;
}
int getHash (String key, int ndx){
	return (toupper(key[0])-'A' + ndx) % ALPHABET_MAX;
}

bool addVertex(AdjacencyList *A, String elem){
	int ndx= getHash(elem, 0);
	int ctr = 0;
	
	while(strcmp(A->List[ndx].key, elem) != 0){
		if(A->List[ndx].status != EMPTY && A->List[ndx].status != DELETED){
			ndx = getHash(elem, ++ctr) % ALPHABET_MAX;
		}
		else{
			A->List[ndx].value = initializeValue(ALPHABET_MAX);
			strcpy(A->List[ndx].key, elem);
			A->List[ndx].status = OCCUPIED;
			return true;
		}
	}
	return false;
}
bool addEdge(AdjacencyList *A, String vertex, String edge){
	int ctr = 0;
	bool vertexState = false;
	int vNdx = getHash(vertex, 0);
	
	while(strcmp(A->List[vNdx].key, vertex) != 0 && A->List[vNdx].status != EMPTY){
		vNdx = getHash(vertex, ++ctr) % ALPHABET_MAX;
		if(strcmp(A->List[vNdx].key, vertex) == 0){
			vertexState = true;
			break;
		}
	}
	if(vertexState == true){
		strcpy(A->List[vNdx].value.data[A->List[vNdx].value.count], edge);
		A->List[vNdx].value.count++;
		return true;
	}
	return false;
}
bool deleteVertex(AdjacencyList* A, String elem);
bool deleteEdge(AdjacencyList* A, String vertex, String edge);
void displayList(AdjacencyList A){
	int x, y;
	for(x = 0; x<ALPHABET_MAX; x++){
		if(A.List[x].status!= EMPTY && A.List[x].status != DELETED){
			printf("Vertex: %10s | Edges: ", A.List[x].key);
			for(y = 0; y<A.List[x].value.count; y++){
				printf("%s ",A.List[x].value.data[y]);
			}
			printf("\n");
		}
	}
}


