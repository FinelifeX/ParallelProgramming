//
// Created by User on 13.09.2018.
//

#include <omp.h>
#include <iostream>
using namespace std;

int main() {
    int num_threads = 3;
    omp_set_num_threads(num_threads);
    #pragma omp parallel if(num_threads >  1)
    {
//        cout <<"Region 1. Thread number "
//        + to_string(omp_get_thread_num())
//        + ". Total threads "
//        + to_string(omp_get_num_threads()) + "\n";
        printf("Region 1. Thread number %d. Total threads - %d. \n", omp_get_thread_num(), omp_get_num_threads());
    }
    num_threads = 1;
    omp_set_num_threads(num_threads);
    #pragma omp parallel if(num_threads > 1)
    {
//        cout <<"Region 2. Thread number "
//        + to_string(omp_get_thread_num())
//        + ". Total threads "
//        + to_string(omp_get_num_threads()) + "\n";
        printf("Region 2. Thread number %d. Total threads - %d. \n", omp_get_thread_num(), omp_get_num_threads());
    }
}
