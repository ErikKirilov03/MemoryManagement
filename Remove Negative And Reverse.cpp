#include <iostream>
#include <string>
#include <sstream>
#include <memory>
using namespace std;

const int maxLength = 1000;

int ReadNumbers(const unique_ptr<int[]>& buffer) {
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

void Swap(const unique_ptr<int[]>& ptr, const int& n1, const int& n2) {
    int temp = ptr[n1];
    ptr[n1] = ptr[n2];
    ptr[n2] = temp;
}

int RemoveNumbers(const unique_ptr<int[]>& buffer, const int& n, bool(*refFunction)(const int&)) {
    int negativeCount = 0;

    for (int i = 0; i < n; i++) {
        if (refFunction(buffer[i])) {
            negativeCount++;
            buffer[i] = 0;
        }
        else if (negativeCount > 0) {
            Swap(buffer, i, i - negativeCount);
        }
    }
    return negativeCount;
}

void ReverseAllNumbers(const unique_ptr<int[]>& buffer, const int& n) {
    for (int i = 0; i < n / 2; i++) {
        Swap(buffer, i, n - (i + 1));
    }
}

bool IsNegative(const int& n) {
    return n < 0;
}

int main()
{
    unique_ptr<int[]> buffer = make_unique<int[]>(maxLength);

    int n = ReadNumbers(buffer);
    n -= RemoveNumbers(buffer, n, IsNegative);

    if (n == 0) {
        cout << "empty";
    }
    else {
        ReverseAllNumbers(buffer, n);

        for (int i = 0; i < n; i++) {
            cout << buffer[i] << ' ';
        }
    }
}