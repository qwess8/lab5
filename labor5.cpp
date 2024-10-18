// labor5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <malloc.h>
#include <random>


int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10, **G = NULL, count=0, *deg = NULL, *loop = NULL;

	printf("N = ");
	scanf("%d",&n);

	G = (int**)malloc(n * sizeof(int*));
	deg = (int*)malloc(n * sizeof(int));
	loop = (int*)malloc(n * sizeof(int));

	for(int i = 0;i<n;i++){
		deg[i] = 0;
		loop[i] = 0;
		G[i] = (int*)malloc(n * sizeof(int));
	}

	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			G[i][j] = rand()%2;
			G[j][i] = G[i][j];
			count+= G[i][j];
		}
	}

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i==j){
				loop[i] += 2 * G[j][i];
				deg[i] += 2 * G[j][i];
			}
			else{
				deg[i] += G[j][i];
			}
		}
	}

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}

	printf("\nRazmer = %d\n\n", count);


	for(int i = 0;i<n;i++){
		if(deg[i] - loop[i] == 0) printf("Ver %d - izol\n", i);
		if(deg[i] - loop[i] == 1) printf("Ver %d - konc\n", i);
		if(deg[i] - loop[i] == n) printf("Ver %d - dom\n", i);
	}
	getchar();
	getchar();
	return 0;
}

