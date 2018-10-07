//
// Created by finelifex on 20/09/18.
//

#include <omp.h>
#include <iostream>
using namespace std;

int main() {
    int a[10];
    int b[10];
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
//        cout << a[i] << " " << endl;
    }
    for (int i = 0; i < 10; i++) {
        b[i] = rand() % 100;
//        cout << b[i] << " " << endl;
    }
    int sumA = 0;
    int sumB = 0;
#pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        sumA += a[i];
        sumB += b[i];
    }

    cout << to_string(sumA / 10) << endl;
    cout << to_string(sumB / 10) << endl;
    sumA = 0;
    sumB = 0;
    cout << "for is done" << endl;
#pragma omp parallel reduction(+:sumA, sumB)
    {
        for (int i = 0; i < 10; ++i) {
            sumA += a[i];
            sumB += b[i];
        }
        cout << to_string(sumA / 10) << endl;
        cout << to_string(sumB / 10) << endl;
    };
    cout << "reduction is done" << endl;
}

