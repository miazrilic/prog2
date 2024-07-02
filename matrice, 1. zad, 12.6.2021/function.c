#include<stdio.h>
#include<stdlib.h>
#include "header.h"

MATRICA* alokacija(int n, int m)
{
    int i,j;
    MATRICA* M;
    M= (MATRICA*)malloc(sizeof(MATRICA));
    
    M->n=n;
    M->m=m;
    
    M->mat=(int**)malloc(sizeof(int*)*n);
    
    if(M->mat== NULL){
    	printf("greska alokacije");
    	return NULL;
	}
    for(i=0;i<n;i++)
    {
        M->mat[i]=(int*)malloc(sizeof(int)*m);
        if(M->mat[i]== NULL){
    		printf("greska alokacije stupca");
    		return NULL;
   		}
	}
        
    return M;
}

void unos_elemenata(MATRICA* M){
	int i,j;
	printf("ucitaj elemente matrice:\n");
   
    for(i=0;i<M->n;i++)
    {
        for(j=0;j<M->m;j++)
        {
            scanf("%d",&M->mat[i][j]);
        }
    }	
}
void print(MATRICA* M)
{
    int i,j;
    for(i=0;i<M->n;i++)
    {
        for(j=0;j<M->m;j++)
        {
            printf("%d ",M->mat[i][j]);
        }
    printf("\n");
    }
}


MATRICA* Oslobadjanje(MATRICA* M) {
	
	int i;
	for(i = 0; i < M->n; i++){
	    free(M->mat[i]);
	}
	free(M->mat);
	return NULL;
	
}
void najveci(MATRICA*M, MATRICA *B){
    int i, j;
    int sumaIndeksa;

  for (i = 0; i < M->n; i++){
      int maxRow=M->mat[i][0];
      sumaIndeksa=1;
     for (j = 0; j < M->m; j++) {
            if (M->mat[i][j] > maxRow) {
                maxRow = M->mat[i][j];
                sumaIndeksa = i + j;
            }
        }

        // Populate the corresponding row in matrix B
        for (j = 0; j < M->m; j++) {
            B->mat[i][j] = M->mat[i][j] * sumaIndeksa;
        }
    }
}
