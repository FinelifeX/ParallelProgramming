//
// Created by User on 17.09.2018.
//

#include <omp.h>
#include <iostream>
using namespace std;

int min(const int* array, const int size) {
    int minimum = array [0];
    for (int i = 1; i < size; ++i) {
        if (array[i] < minimum) {
            minimum = array[i];
        }
    }
    return minimum;
}

int max(const int* array, const int size) {
    int maximum = array [0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {11, 12, 13, 14, 16, 15, 18, 19, 20, 17};
    omp_set_num_threads(2);
#pragma omp parallel
    {
        if (omp_get_thread_num() == 0) {
            int result = min(a, 10);
            cout << "Result of thread " + to_string(omp_get_thread_num()) + " is " + to_string(result) << endl;
        }
        else if (omp_get_thread_num() == 1) {
            int result = max(b, 10);
            cout << "Result of thread " + to_string(omp_get_thread_num()) + " is " + to_string(result) << endl;
        }
    }
}
