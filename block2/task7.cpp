//
// Created by finelifex on 02/10/18.
//

#include <omp.h>
#include <iostream>
using namespace std;

int main() {
    int a[12];
    int b[12];
    int c[12];
    omp_set_num_threads(3);
#pragma omp parallel for schedule(static, 4)
    for (int i = 0; i < 12; i++) {
        a[i] = rand() % 100;
        cout << "Thread " + to_string(omp_get_thread_num())
                + ". Total threads " + to_string(omp_get_num_threads())
                + ". a[" + to_string(i) + "] = " + to_string(a[i]) << endl;
        b[i] = rand() % 100;
        cout << "Thread " + to_string(omp_get_thread_num())
            + ". Total threads " + to_string(omp_get_num_threads())
            + ". b[" + to_string(i) + "] = " + to_string(b[i]) << endl;
    }

    cout << "End of region 1" << endl;

    omp_set_num_threads(4);
#pragma omp parallel for schedule(dynamic, 3)
    for (int i = 0; i < 12; i++) {
        c[i] = a[i] + b[i];
        cout << "Thread " + to_string(omp_get_thread_num())
                + ". Total threads " + to_string(omp_get_num_threads())
                + ". c[" + to_string(i) + "] = " + to_string(c[i]) << endl;
    }
}

