#include <iostream>
#include <sstream>
using namespace std;

bool Lexicographical(const string& a, const string& b) {
	return a < b;
}

bool Shortest(const string& a, const string& b) {
	return a.length() < b.length();
}

bool Longest(const string& a, const string& b) {
	return a.length() > b.length();
}


int main()
{
	string text;
	getline(cin, text);
	stringstream ss(text);
	string currWord;
	string result;
	int condition;
	cin >> condition;

	bool (*ptr)(const string&, const string&) = NULL;
	if (condition == 1) {
		ptr = Lexicographical;
	}
	else if (condition == 2) {
		ptr = Shortest;
	}
	else if (condition == 3) {
		ptr = Longest;
	}

	bool check = true;
	while (ss >> currWord) {
		if (check || ptr(currWord, result)) {
			result = currWord;
		}
		if (check) {
			check = false;
		}
	}
	cout << result;
}