#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int n; // number of elements in the vectors
    int scalar; // scalar value
    int* vector1, * vector2; // pointers to the vectors

    // get input from user
    cout << "Enter the number of elements in the vectors: ";
    cin >> n;
    cout << "Enter the scalar value: ";
    cin >> scalar;

    // allocate memory for the vectors
    vector1 = new int[n];
    vector2 = new int[n];

    // get input for vector1
    cout << "Enter the elements of vector1: ";
    for (int i = 0; i < n; i++) {
        cin >> vector1[i];
    }

    // get input for vector2
    cout << "Enter the elements of vector2: ";
    for (int i = 0; i < n; i++) {
        cin >> vector2[i];
    }

    // perform scalar vector multiplication using OpenMP
#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        vector2[i] = scalar * vector1[i];
    }

    // print the result
    cout << "The result of scalar vector multiplication is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << vector2[i] << " ";
    }
    cout << endl;

    // free memory
    delete[] vector1;
    delete[] vector2;

    return 0;
}
