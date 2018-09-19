//
// Created by User on 13.09.2018.
//
#include <omp.h>
#include <iostream>

using namespace std;

int main()
{
#pragma omp parallel num_threads(8)
    {
        cout << "Thread number " + to_string(omp_get_thread_num()) + ". Total threads " + to_string(omp_get_num_threads()) + "Hello, world!" + "\n";
    }
}

