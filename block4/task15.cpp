//
// Created by finelifex on 07/10/18.
//

#include <omp.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int number_frst, number_lst, count;
    cin >> number_frst;
    cin >> number_lst;

    omp_set_num_threads(8);

    #pragma omp parallel for private(count) schedule(dynamic, 5)
    for (int i = number_frst; i < number_lst + 1; i++) {
        count = 0;
        for (int j = 2; j < sqrt(i); j++) {
            if (i % j == 0) {
                count++;
            }
            if (count > 0)
                break;
        }
        if (count == 0) {
            printf("%d  ", i);
        }
    }
}