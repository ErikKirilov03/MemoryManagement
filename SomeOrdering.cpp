#include <iostream>
#include <string>
using namespace std;

char* Transform(const char* ptr, const size_t& n, char(*transformTo)(const char&)) {
    char* buffer = new char[n];

    for (size_t i = 0; i < n; i++) {
        buffer[i] = transformTo(ptr[i]);
    }
    return buffer;
}

char ToLower(const char& symbol) {
    if (65 <= symbol && symbol <= 90) {
        return symbol + 32;
    }
    return symbol;
}

char ToUpper(const char& symbol) {
    if (97 <= symbol && symbol <= 122) {
        return symbol - 32;
    }
    return symbol;
}

int main()
{
    string input;
    getline(cin, input);

    char* output1 = Transform(input.c_str(), input.length() + 1, ToLower);
    cout << output1 << endl;
    delete[] output1;

    char* output2 = Transform(input.c_str(), input.length() + 1, ToUpper);
    cout << output2 << endl;
    delete[] output2;
}