#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int maxLength = 1000;

int ReadNumbers(int*& buffer) {
    string input;
    getline(cin, input);
    istringstream iss(input);

    int number, index = 0;
    while (iss >> number) {
        buffer[index] = number;
        index++;
    }
    if (index == maxLength) {
        throw logic_error("Too many numbers entered");
    }
    return index;
}

int main()
{
    int* buffer = new int(maxLength);
    int n = ReadNumbers(buffer);

    for (int i = 0; i < n / 2; i++) {
        buffer[i] += buffer[n - (i + 1)];
    }

    for (int i = 0; i < n / 2; i++) {
        cout << buffer[i] << ' ';
    }

    if (n % 2 != 0) {
        cout << buffer[(n - 1) / 2] << ' ';
    }
    cout << endl;

    delete[] buffer;
}