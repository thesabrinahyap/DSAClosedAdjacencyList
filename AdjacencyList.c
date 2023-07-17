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
	
	if(strcmp(A[ndx]->key, EMPTY) == 0){
		strcpy(A[ndx]->key, elem);
	}
}
bool addEdge(AdjacencyList *A, String firstElem, String secondElem);


