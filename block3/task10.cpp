//
// Created by finelifex on 05/10/18.
//

#include <omp.h>
#include <iostream>
using namespace std;

int main() {
    int a[30], i, j, count;
    count = 0;
    for (i = 0; i < 30; i++) {
        a[i] = rand() % 100;
        printf("%d  ", a[i]);
    }
    printf("\n");
    omp_set_num_threads(4);
    #pragma omp parallel for private(j) schedule(static, 5)
    for (j = 0; j < 30; j++) {
        printf("Thread %d \n", omp_get_thread_num());
        if (a[j] % 9 == 0) {
            #pragma omp atomic
            count++;
        }
    }

    printf("\n");
    printf("%d", count);
}