//
// Created by finelifex on 07/10/18.
//

#include <omp.h>
#include <iostream>
using namespace std;

int main() {
    int num = 210;
    int part = 1;
    int result = 0;
    #pragma omp parallel for shared(part, result) schedule(dynamic)
    for (int i = 1; i < num + 1; i++) {
        #pragma omp critical
        result += part;
        #pragma omp atomic
        part += 2;
        printf("Thread number %d, result = %d. \n", omp_get_thread_num(), result);
    }
    printf("Result is %d", result);
}