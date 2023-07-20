#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "AdjacencyList.h"


void initList(AdjacencyList* list){
	int ctr;
	for(ctr=0; ctr<ALPHABET_MAX; ctr++){
		list->List[ctr].status = EMPTY;
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
bool deleteVertex(AdjacencyList* A, String elem){
	int hashCtr = 0, x = 0, y;
	int vNdx = 0;
	bool state = false;
	
	while(vNdx < ALPHABET_MAX){
		if(A->List[vNdx].status != EMPTY && A->List[vNdx].status != DELETED){
			if(strcmp(A->List[vNdx].key, elem) == 0){
				A->List[vNdx].status = DELETED;
				A->List[vNdx].value.count = 0;
			}else{
				deleteEdge(A, A->List[vNdx].key, elem);
			}
		}
		vNdx++;
	}
}
bool deleteEdge(AdjacencyList* A, String vertex, String edge){
	int hashCtr = 0, x = 0, y;
	int vNdx = getHash(vertex, hashCtr);
	int state = false;
	
	while(strcmp(A->List[vNdx].key, vertex)!= 0){
		vNdx = getHash(vertex, ++hashCtr) % ALPHABET_MAX;
		if (strcmp(A->List[vNdx].key, vertex)== 0){
			state = true;
			break;
		}
	}
	if(state == true){
		while(x<A->List[vNdx].value.count){
			if(strcmp(A->List[vNdx].value.data[x], edge) == 0){
				A->List[vNdx].value.count--;
				for(y=x; x<A->List[vNdx].value.count; x++){
					strcpy(A->List[vNdx].value.data[y], A->List[vNdx].value.data[y+1]);
				}
				state = true;
			}
			x++;
		}
	}
	return state;
}

//bool deleteEdge(AdjacencyList *A, int ndx, String edge){
//	int x = 0, y;
//	int hashCtr = 0;
//	bool state = false;
//	int eNdx = getHash(edge, hashCtr);
//	
//	while(x<ALPHABET_MAX){
//		y = x;
//		if(strcmp(A->List[ndx].value.data, edge) == 0){
//			do{
//				strcpy(A->List[ndx].value.data[y], A->List[ndx].value.data[y+1]);
//				y++;
//			} while (A->List[ndx].value.data[y]!= EMPTY);
//			
//			A->List[ndx].value.count = A->List[ndx].value.count-1;
//			state = true;
//		}
//		++x;
//	}
//	return state;
//}
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


