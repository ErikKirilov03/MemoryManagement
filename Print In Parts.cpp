#include <iostream>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;

    int totalSpaces = row * col;

    int* flatMatrix = new int[totalSpaces];

    for (int r = 0; r < totalSpaces; r++) {
        cin >> flatMatrix[r];
    }

    int rowsToPrint, colsToPrint;
    cin >> rowsToPrint >> colsToPrint;

    for (int r = 0; r < rowsToPrint; r++) {
        for (int c = 0; c < colsToPrint; c++) {
            cout << flatMatrix[r * col + c] << ' ';
        }
        cout << endl;
    }

    delete[] flatMatrix;
}