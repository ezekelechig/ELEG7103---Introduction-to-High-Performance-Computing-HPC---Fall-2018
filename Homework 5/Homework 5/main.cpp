//
//  main.cpp
//  Homework 5
//
//  Created by Kelechi Eze on 10/13/2018.
//

#include <iostream>
#include  <ctime>
#include <omp.h>

using namespace std;
static long num_steps = 500000;
#define N 4
double step;
int main()
{
    long start_s = clock();
    double pi, sum = 0.0;
    step = 1.0 / (double)num_steps;
#pragma omp parallel num_threads(N)
    {
    int n_threads = omp_get_num_threads();
    cout << "Number of threads is :" << n_threads << endl;
    int i, ID; double x, psum = 0.0;
    ID = omp_get_thread_num();
    for (i = ID; i <= num_steps; i += n_threads)
    {
        x = (i + 0.5) * step;
        psum += (4.0 / (1.0 + x * x));
        

    }
    cout << "psum is " << psum << endl;;
#pragma omp critical
    sum = sum += psum;
    cout << "sum is " << sum << endl;;
    cout << "step " << step << endl;;

    }

    pi = step * sum;

    cout << "Value of pi is " << pi << endl;
    //cout<<"elapsed time is " << elapsed_seconds.count()
        long stop_s = clock();
        cout << "execution time" << double(stop_s - start_s) / CLOCKS_PER_SEC <<"seconds" <<endl;
    cin.get();
    

    return 0;


}


