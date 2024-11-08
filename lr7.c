#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

int** createG(int size) {
	int** G;
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++) {
		G[i] = (int*)malloc(size * sizeof(int));
	}
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			G[i][j] = rand() % 2;
			if (i == j) G[i][j] = 0;
			G[j][i] = G[i][j];
		}
	}
	return G;
}

int printG(int **G, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int **G=NULL, size = 5, vis[5] = {0};

void DFS(int s, int **G, int size, int *vis){
    vis[s] = 1;
    printf("%d ", s);
    for(int i = 0; i < size; i++){
        if (G[s][i]== 1 && vis[i]== 0){
            DFS(i, G, size, vis);
        }
    }
}


int main(){
    int **G=NULL;
    int *vis=NULL;
    int size=5;
    printf("Введите  количество вершин графа: \n");
    scanf("%d", &size);
    G = createG(size);
    printG(G, size);
    
    printf("\nВведите  начальную вершину:\n");
    
    vis = (int*)malloc(size*sizeof(int));
    
    int s = 1;
    scanf("%d", &s);
    printf("\nОбход графа: ");
    DFS(s, G, size, vis);
    
    return 0;
}
