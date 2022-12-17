#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Vector **createField(unsigned int m, unsigned int n, Vector v) {
    // Write your code here


    Vector **v_return = new Vector*[m];

    for (int i = 0; i < n; ++i) {
        v_return[i] = new Vector[n];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            v_return[i][j].x = v.x;
            v_return[i][j].y = v.y;
        }
    }


    return v_return;
}

// Task 1(b).  Implement this function
void displayField(Vector **A, unsigned int m, unsigned int n) {
    // Write your code here

    for (int i = 0; i < m; ++i) {

        for (int j = 0; j < n; ++j) {

            Vector curr = A[i][j];
            cout << "(" << curr.x << "," << curr.y << ") ";
        }
        cout << endl;
    }

}

// Task 1(c).  Implement this function
void addFields(Vector **A, Vector **B, Vector **C, unsigned int m, unsigned int n) {
    // Write your code here


    for (int i = 0; i < m; ++i) {

        for (int j = 0; j < n; ++j) {

            Vector currA = A[i][j];
            Vector currB = B[i][j];

            int val_x = currA.x + currB.x;
            int val_y = currA.y + currB.y;

            C[i][j].x = val_x;
            C[i][j].y = val_y;

        }
    }




}

// Task 1(d).  Implement this function
void scaleField(Vector **A, double c, unsigned int m, unsigned int n) {
    // Write your code here


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {

            A[i][j].x *= c;
            A[i][j].y *= c;
        }
    }

}

// Do not modify
void deleteField(Vector **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; ++i) {
        delete[] A[i];
    }
    delete[] A;
}
