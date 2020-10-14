#include <stdio.h> 
#include <stdlib.h> 
int main(void){

		int n;
		int N;
		int p;

		int i, j;
		printf("graphs vertex: ");
		scanf("%d", &N);
		printf("graphs edge : ");
		scanf("%d", &n);
		p = 0.5 * (N - 1) * (N - 2);
		if (n > p) {
			printf("Graph connected\n");
		}
		if (n <= p) {
			printf("Graph not connected\n");
		}
		int** A = (int**)malloc(N * sizeof(int*));
		for (int i = 0; i < N; i++) 
			A[i] = (int*)malloc(N * sizeof(int));

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) 
				scanf("%d", &A[i][j]);
		FILE* s;
		s = fopen("graph.dot", "w");
		fprintf(s, "digraph G {\n");
			
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) {
				if (A[i][j] != 0){
                                     while(A[i][j]>=1){
					fprintf(s, "%d -> %d; \n", i + 1, j + 1);
                                        A[i][j]--;
                                        }
				}
			}
		fprintf(s, "}");

		fclose(s);
		for (int i = 0; i < N; i++) {
            
			free(A[i]);
		}
		free(A);
        system("dot -Tpng graph.dot -o graph.png");
        system("graph.png");

		return 0;
}
