#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "AdjacencyList.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	AdjacencyList arr;
	initList(&arr);
	bool state;
	int i, j;
	ResultsList r;

	r.count = 0;
	
	state = addVertex(&arr, "Tokyo");
	state = addVertex(&arr, "Taiwan");
	state = addVertex(&arr, "Chile");
	state = addVertex(&arr, "Cebu");
	state = addVertex(&arr, "Cthullu");
	state = addVertex(&arr, "Manila");
	state = addVertex(&arr, "Mandaue");
	state = addVertex(&arr, "Marinduque");

	displayList(arr);

	state = addEdge(&arr, "Tokyo", "Manila");
	state = addEdge(&arr, "Cebu", "Tokyo");
	state = addEdge(&arr, "Cebu", "Cthullu");
	state = addEdge(&arr, "Tokyo", "Cthullu");
	state = addEdge(&arr, "Mandaue", "Cebu");
	state = addEdge(&arr, "Chile", "Cthullu");
	state = addEdge(&arr, "Marinduque", "Chile");
	state = addEdge(&arr, "Tokyo", "Marinduque");

	
	
	printf("\nWITH EDGES \n\n");
	displayList(arr);
	
//	printf("\n\nREMOVE EDGE\n\n");
//	state = deleteEdge(&arr, "Mandaue", "Cebu");
//	displayList(arr);
//	
//	printf("\n\nREMOVE VERTEX\n\n");
//	state = addEdge(&arr, "Cebu", "Marinduque");
//	displayList(arr);
//	printf("\n");
//	state = deleteVertex(&arr, "Cebu");
//	displayList(arr);
//	return 0;
	
	printf("\n\n DEPTH FIRST SEARCH\n\n");
	DFS(arr, "Cebu", &r);
}
