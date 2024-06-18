#include <iostream>
#include <string>
using namespace std;

void incrementAdjacentCells(int** matrix, const int& Row, const int& Col, const int& currRow, const int& currColIdx) {
    for (int r = max(currRow - 1, 0); r <= min(currRow + 1, Row - 1); r++) {
        for (int c = max(currColIdx - 1, 0); c <= min(currColIdx + 1, Col - 1); c++) {
            matrix[r][c]++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m >> ws;

    int** matrix = new int* [n];
    for (int r = 0; r < n; r++) {
        matrix[r] = new int[m] {};
    }

    for (int r = 0; r < n; r++) {
        string search;
        getline(cin, search);
        for (int c = 0; c < m; c++) {
            if (search[c] != '!') {
                continue;
            }
            else {
                incrementAdjacentCells(matrix, n, m, r, c);
            }
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cout << matrix[r][c];
        }
        cout << endl;
    }

    for (int r = 0; r < n; r++) {
        delete[] matrix[r];
    }
    delete[] matrix;
}