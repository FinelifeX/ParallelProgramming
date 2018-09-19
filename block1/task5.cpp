//
// Created by finelifex on 20/09/18.
//

#include <omp.h>
#include <iostream>
using namespace std;

int min(int array[6][8]) {
    int min = array[0][0];
    for (int i = 1; i < 6; ++i) {
        for (int j = 1; j < 8; ++j) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
        }
    }
    return min;
}

int max(int array[6][8]) {
    int max = array[0][0];
    for (int i = 1; i < 6; ++i) {
        for (int j = 1; j < 8; ++j) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    return max;
}

double average(int array[6][8]) {
    int sum = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            sum += array[i][j];
        }
    }
    return sum / (6*8);
}

int div3(int array[6][8]) {
    int counter = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (array[i][j] % 3 == 0) {
                counter += 1;
            }
        }
    }
    return counter;
}

int main() {
    const int x = 6;
    const int y = 8;
    int d[x][y];
    int result1;
    double result2;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            d[i][j] = rand() % 100;
        }
    }
    #pragma omp sections
    {
        #pragma omp section
        {
            result2 = average(d);
            cout << "Thread number " + to_string(omp_get_thread_num()) + ". Average is " + to_string(result2) + " \n";
        }
        #pragma omp section
        {
            result1 = min(d);
            cout << "Thread number " + to_string(omp_get_thread_num()) + ". Minimum is " + to_string(result1) + " \n";
            result1 = max(d);
            cout << "Thread number " + to_string(omp_get_thread_num()) + ". Maximum is " + to_string(result1) + " \n";
        }
        #pragma omp section
        {
            result1 = div3(d);
            cout << "Thread number " + to_string(omp_get_thread_num()) + ". Number of div3 numbers is " +
                    to_string(result1) + " \n";
        }
    };
}