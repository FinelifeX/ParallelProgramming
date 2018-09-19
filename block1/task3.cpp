//
// Created by User on 13.09.2018.
//

#include <omp.h>
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 8;

//    printf("Before region 1 a = %d, b = %d.", a, b);
    cout << "Before region 1 a = " + to_string(a) + ", b = " + to_string(b)<< endl;
#pragma omp parallel num_threads(2) private(a) firstprivate(b)
    {
        a += omp_get_thread_num();
        b += omp_get_thread_num();
        cout << "For thread " + to_string(omp_get_thread_num()) + " Inside region 1 a = " + to_string(a) + ", b = " + to_string(b)<< endl;
    }
    cout << "After region 1 a = " + to_string(a) + ", b = " + to_string(b)<< endl;

    a = 5;
    b = 8;
    cout <<"Before region 2 a = " + to_string(a) + ", b = " + to_string(b)<< endl;
#pragma omp parallel num_threads(4) shared(a) private(b)
    {
        a -= omp_get_thread_num();
        b -= omp_get_thread_num();
        cout << "For thread " + to_string(omp_get_thread_num()) + " Inside region 2 a = " + to_string(a) + ", b = " + to_string(b)<< endl;
    }
    cout <<"After region 2 a = " + to_string(a) + ", b = " + to_string(b)<< endl;
}

