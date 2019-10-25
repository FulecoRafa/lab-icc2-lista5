#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int* v, int n) {
	int pai; int filho;
	for (int i = 0; i < n; i++) {
		filho = i;
		pai = (filho - 1)/2;
		
		while (pai >= 0 && v[filho] > v[pai]) {
			troca(v + pai, v + filho);
			filho = pai;
			pai = (pai - 1)/2;
		}
	}
}

int heapsort(int* v, int n) {
	heapify(v, n);
	int fim = n - 1;

	int fimHeap = fim;
	int pai;
	int filho;

	for (int i = 0; i < fim; i++) {
		troca(v, v + fim - i);
		pai = 0;
		filho = 1;
		fimHeap--;
		while (filho <= fimHeap) {
			if (filho < fimHeap && v[filho + 1] > v[filho]) filho++;
			if (v[filho] > v[pai]) {
				troca(v + pai, v + filho);
				pai = filho;
				filho = 2*pai + 1;
			}
			else {
				break;
			}
		}
	}
}

int generate_random_number(int max){
    return(rand() % (max+1) + 1);
}

void print_vet(int* v , int size , char* s){
    printf("[Vetor %s] -> " , s);
    for(int i = 0 ; i < size ; i++){
        printf("%d " , v[i]);
    }
}

int main(void){
    srand(time(void));
    int **v;
    int k , size;
    char str[12];
    k = generate_random_number(10);
    printc("K = %d" , k);
    v = (int **) malloc(sizeof(int *) * k);
    for(int i = 0 ;  i < k ; i ++){
        size = generate_random_number(10);
        v[i] = (int*) malloc(sizeof(int) * size);
        for(int j = 0 ; j < size ; j++){
            v[i][j] = generate_random_number(100);
        }
        sprintf(str , "%d" , i);
        print_vet(v[i] , size , str);
    }

    /*
        Faça as chamadas do heap sort e a geração do novo vetor aqui. Printar o vetor tbm.
    */

    for(int i = 0 ; i < k ; i++){
        free(v[i]);
    }
    free(v);

    return 0;
}
