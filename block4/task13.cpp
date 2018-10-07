//
// Created by finelifex on 07/10/18.
//

#include <omp.h>
#include <iostream>
using namespace std;

int main() {
    int a[30] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1};
    int i, degree;
    int result = 0;
    int length = sizeof(a) / sizeof(*a);
    #pragma omp parallel for private(degree) schedule(dynamic)
    for (i = 0; i < length; ++i) {
        degree = 1;
        for (int j = 0; j < i; j++) {
            degree *= 2;
        }
        #pragma omp critical
        {
            result += a[length - 1 - i] * degree;
        }
    }
    printf("Result is %d.", result);
}