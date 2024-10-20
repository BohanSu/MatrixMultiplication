#include <iostream>
#include <fstream>

using namespace std;

void multiplyMatricesModulo3(int** a, int** b, int** result, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= 3; // ȡģ3
            }
        }
    }
}

int main() {
    ifstream infile("in.txt");
    int n;
    infile >> n;

    int** a = new int* [n];
    int** b = new int* [n];
    int** result = new int* [n];

    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
        b[i] = new int[n];
        result[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            infile >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            infile >> b[i][j];
        }
    }

    multiplyMatricesModulo3(a, b, result, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] a[i];
        delete[] b[i];
        delete[] result[i];
    }
    delete[] a;
    delete[] b;
    delete[] result;

    infile.close();
    return 0;
}
