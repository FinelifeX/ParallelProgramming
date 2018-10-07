//
// Created by finelifex on 05/10/18.
//

#include <omp.h>
#include <iostream>
using namespace std;

int main() {
    int d[6][8], i, j;
    for (i = 0; i < 6 ; i++) {
        for (j = 0; j < 8; j++) {
            d[i][j] = rand() % 50;
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    int min = d[0][0];
    int max = d[0][0];
    omp_set_num_threads(4);
#pragma omp parallel for private(i,j)
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 8; j++) {
            #pragma omp critical (first)
            {
                if (d[i][j] < min) {
                    min = d[i][j];
                    cout << "Thread " + to_string(omp_get_thread_num()) + ". Find minimum. " + to_string(omp_get_wtime()) << endl;
                }

            }
            #pragma omp critical (second)
            {
                if (d[i][j] > max) {
                    max = d[i][j];
                    cout << "Thread " + to_string(omp_get_thread_num()) + ". Find maximum. " + to_string(omp_get_wtime()) << endl;
                }
            }
        }
    }

    printf("Max = %d. Min = %d.", max, min);
}

