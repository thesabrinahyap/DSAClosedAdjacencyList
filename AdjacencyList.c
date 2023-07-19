#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "AdjacencyList.h"

#define EMPTY " "
void initList(AdjacencyList list){
	int ctr;
	for(ctr=0; ctr<ALPHABET_MAX; ctr++){
		strcpy(list[ctr].key, EMPTY);
	}
}
ArrayList initializeValue(int max){
	ArrayList A;
	A.data = malloc(sizeof(String));
	A.count = 0;
	A.max = max;
	
	return A;
}
int getHash (String key){
	return (toupper(key[0])-'A') % ALPHABET_MAX;
}
bool addVertex(AdjacencyList *A, String elem){
	int ndx= getHash(elem);
	
	while(strcmp(A->List[ndx].key, elem) != 0){
		if(strcmp(A->List[ndx].key , "EMPTY" != 0 || A->List[ndx].key == "DELETED")){
			ndx = getHash(++elem) % SIZE;
		}
		else{
			if(strcmp(A->List[ndx].key , "EMPTY" == 0){
				strcpy(A->List[ndx].key, elem);
				A->list[ndx].value.status = "OCCUPIED";
				return true;
			}
		}
	}
	return false;
}
bool addEdge(AdjacencyList *A, String vertex, String edge){
	int ctr;
	bool vertexState = true, edgeState = true;
	int vNdx = getHash(vertex);
	int eNdx = getHash(edge);
	int flagHash;
	
	while(strcmp(A->List[vNdx].key, vertex) != 0 && A->List[vNdx].value.status < "EMPTY"){
		vNdx = (vNdx+1) % SIZE;
		if(strcmp(A->List[vNdx].key, vertex) == 0){
			vertexState = true;
			break;
		}
		vertexState = false;
	}
	if(strcmp(A->List[vNdx].key, vertex) == 0){
			vertexState = true;
		}
}
bool deleteVertex(AdjacencyList A, String elem);
bool deleteVertex(AdjacencyList A, String vertex, String edge);
void displayList(AdjacencyList A);


