#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void troca(int *a , int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

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

int* intercala(int *v1 , int max1 , int *v2 , int max2){
	int i = 0;
    int j = 0;
	int k = 0;
    int *vet;
	vet = (int *) malloc(sizeof(int) * (max1+max2));
    while (i < max1 && j < max2){ //compara qual dos dois é maior e atribui ao vetor que os originou em ordem
        if (v1[i] <= v2[j]){
            vet[k] = v1[i];
            i++;
        }
        else{
            vet[k] = v2[j];
            j++;
        }
        k++;
    }
 
    while (i < max1){ //atribui os elementos que faltaram do vetor da esquerda
        vet[k] = v1[i];
        i++;
        k++;
    }
 
    while (j < max2){ //atribui os elementos que faltaram do vetor da direita
        vet[k] = v2[j];
        j++;
        k++;
    }
	return vet;
}

int generate_random_number(int max){
    return(rand() % (max+1) + 1);
}

void print_vet(int* v , int size , char* s){
    printf("[Vetor %s] -> " , s);
    for(int i = 0 ; i < size ; i++){
        printf("%d " , v[i]);
    }
	printf("\n");
}

int main(void){
    srand(time(NULL));
    int **v;
	int *index;
    int n = 0;
	int k , size;
    char str[12];
    k = generate_random_number(10);
    printf("K = %d\n" , k);
    v = (int **) malloc(sizeof(int *) * k);
	index = (int *) malloc(sizeof(int) * k);
    for(int i = 0 ;  i < k ; i ++){
        size = generate_random_number(10);
        v[i] = (int*) malloc(sizeof(int) * size);
		index[i] = size;
		n += size;
        for(int j = 0 ; j < size ; j++){
            v[i][j] = generate_random_number(100);
        }
        sprintf(str , "%d" , i);
        print_vet(v[i] , size , str);
		heapsort(v[i] , size);
		strcat(str , " ordenado");
		print_vet(v[i] , size , str);
    }
	int *final;
	final = (int *) malloc(sizeof(int) * n);
	n = 0;
	for(int i = 0 ; i < k ; i++){
		n += index[i];
		final = intercala(v[i] , index[i] , final , n);
	}
	strcpy(str , "final");
    print_vet(final , n , str);
;
    for(int i = 0 ; i < k ; i++){
        free(v[i]);
    }
    free(v);
	free(index);

    return 0;
}
