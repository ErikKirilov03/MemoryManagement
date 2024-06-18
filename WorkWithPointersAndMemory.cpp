#include <iostream>
#include<sstream>
using namespace std;

int main()
{
    char* dataStart = NULL;
    char* dataEnd = NULL;

    string input;

    while (getline(cin, input) && input != "end") {
        stringstream ss(input);

        string name;
        int id;
        ss >> id >> name;

        size_t requiredMemorySize = sizeof(char*) + sizeof(int) + (name.length() + 1);
        char* currentBlock = new char[requiredMemorySize];

        if (!dataStart) {
            dataStart = currentBlock;
        }
        else {
            char** prevToCurrentPtr = reinterpret_cast<char**>(dataEnd);
            *prevToCurrentPtr = currentBlock;
        }

        char** nextPtr = reinterpret_cast<char**>(currentBlock);
        *nextPtr = NULL;

        int* idPtr = reinterpret_cast<int*>(currentBlock + sizeof(char*));
        *idPtr = id;

        char* namePtr = currentBlock + sizeof(char*) + sizeof(int);
        copy(name.begin(), name.end(), namePtr);
        namePtr[name.length()] = NULL;

        dataEnd = currentBlock;
    }
}