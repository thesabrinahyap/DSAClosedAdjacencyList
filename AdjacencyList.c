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
	
	while(A->List[vNdx].status != EMPTY){
		if(strcmp(A->List[vNdx].key, vertex) == 0){
			vertexState = true;
			break;
		}else{
			vNdx = getHash(vertex, ++ctr) % ALPHABET_MAX;
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
	
	while(A->List[vNdx].status != EMPTY){
		if(strcmp(A->List[vNdx].key, vertex) == 0){
			state = true;
			break;
		}else{
			vNdx = getHash(vertex, ++hashCtr) % ALPHABET_MAX;
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
void DFS(AdjacencyList A, String vertex, ResultsList *R){
	int hashCtr = 0, resultsCtr = 0, listCtr = 0;
	int vNdx = getHash(vertex, hashCtr);
	int state = false;
	
	while(A.List[vNdx].status != EMPTY){
		if(strcmp(A.List[vNdx].key, vertex) == 0){
			state = true;
			break;
		}else{
			vNdx = getHash(vertex, ++hashCtr) % ALPHABET_MAX;
		}
	}
	//if vertex is empty
	if(state == false){
		printf("here");
		return;	
	}
	
	// add vertex to results list
	strcpy(R->elems[R->count], vertex);
	printf("%s ", R->elems[R->count]);
	R->count++;

	//look through each neighbor in vertex's neighbors
	while(listCtr < A.List[vNdx].value.count){
		//need to re-initizalize because this is recursive and these variables shouldn't be retained
		//kumbaga everytime this is called, these should be balik sugod~~
		bool flag = false;
		resultsCtr = 0;
		
		while(resultsCtr < R->count){
			//if neighbor is not visited
			if(strcmp(A.List[vNdx].value.data[listCtr], R->elems[resultsCtr]) == 0){
				flag = true;
				break;
			} 
			resultsCtr++;
		}
		if(flag == false){
			DFS(A, A.List[vNdx].value.data[listCtr], R);
		}
		listCtr++;
	}	
	
	
//    if vertex is empty
//        return (this is base case)
//    add vertex to results list
//    mark vertex as visited
//    for each neighbor in vertex's neighbors:
//       if neighbor is not visited:
//          recursively call DFS on neighbor

}
Queue newQueue(){
	Queue q;
	q.front = -1;
	q.end = -1;
	
	return q;
}

bool isEmpty(Queue *q){
	return q->end == -1;
}
bool isFull(Queue *q){
	return q->end == ALPHABET_MAX-1;
}
void enqueue(Queue *q, String vertex){
	if(!isFull(q)){
		if(q->front == -1){
			q->front = 0;
		}
		q->end++;
		strcpy(q->elems[q->end], vertex);
	}
}
char* dequeue(Queue *q){
	char* word = malloc(sizeof(String));
	if(!isEmpty(q)){
		strcpy(word,q->elems[q->front]);
		q->front++;
		if(q->front > q->end){
			q->front = q->end = -1;
		}
	}
	return word;
}
void BFS(AdjacencyList A, String vertex, ResultsList *R){
	int state = false;
	int resultsCtr = 0;
	Queue q = newQueue();
	
	enqueue(&q, vertex);
	//placing the starting index in the queue
	strcpy(R->elems[R->count], vertex);
	printf("%s ",R->elems[R->count]);
	R->count++;
	
	strcpy(R->elems[R->count], vertex);
	//loop as long as there is anything in the queue
	while(!isEmpty(&q)){
		int hashCtr = 0, listCtr = 0;
		resultsCtr = 0;
		//remove the first vertex from the queue and push it into the array that stores visited
		vertex = dequeue(&q);
		
		int vNdx = getHash(vertex, hashCtr);
		while(A.List[vNdx].status != EMPTY){
			if(strcmp(A.List[vNdx].key, vertex) == 0){
				state = true;
				break;
			}else{
				vNdx = getHash(vertex, ++hashCtr) % ALPHABET_MAX;
			}
		}	
		
		while(listCtr < A.List[vNdx].value.count){
			bool flag = false;
			resultsCtr = 0;
			
			while(resultsCtr < R->count){
				//if neighbor is not visited
				if(strcmp(A.List[vNdx].value.data[listCtr], R->elems[resultsCtr]) == 0){
					flag = true;
					break;
				} 
				resultsCtr++;
			}
			//enqueue end marked as visited
			if(flag == false){
				enqueue(&q,A.List[vNdx].value.data[listCtr]);
				strcpy(R->elems[R->count], A.List[vNdx].value.data[listCtr]);
				printf("%s ",R->elems[R->count]);
				R->count++;
			}
			listCtr++;
		}	
	}
}

