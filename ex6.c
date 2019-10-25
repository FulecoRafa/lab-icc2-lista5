#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Coloque o heap sort aqui
*/

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