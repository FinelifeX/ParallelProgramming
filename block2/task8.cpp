//
// Created by finelifex on 04/10/18.
//

#include <omp.h>
#include <iostream>
using namespace std;

int main() {

//  init data
    int matrix[5][5], vector[5], result[5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
//          init matrix vector
            matrix[i][j] = rand() % 10;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
//      init resulting vector values
        result[i] = 0;
    }

    printf("\n");

//  init vector values
    for (int i = 0; i < 5; i++) {
        vector[i] = rand() % 10;
        printf("%d \n", vector[i]);
    }

    int i,j;
#pragma omp parallel private(i)
    {
#pragma omp for private(j)
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                result[i] += matrix[i][j] * vector[j];
            }
        }
    }

    printf("\n");
    for (int k = 0; k < 5; k++) {
        printf("%d \n", result[k]);
    }
}