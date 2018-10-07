//
// Created by finelifex on 07/10/18.
//

#include <omp.h>
#include <iostream>
using namespace std;

int main() {
    int array[20];
    int max = 0;
    omp_set_num_threads(4);
    for (int i = 0; i < 20; i++) {
        array[i] = rand() % 100;
        printf("%d  ", array[i]);
    }
    printf("\n");

    #pragma omp parallel for schedule(dynamic, 3)
    for (int j = 0; j < 20; j++) {
        printf("Thread %d \n", omp_get_thread_num());
        #pragma omp critical
        if ((array[j] > max) && (array[j] % 7 == 0)) {
            max = array[j];
        }
    }

    printf("Result is %d.", max);
}