#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string line;
	while (getline(cin, line)) {
		istringstream iss(line);
		string token;
		long long sum = 0;
		while (iss >> token) {
			sum += stoll(token, nullptr, 16);
		}
		cout << sum << endl;
	}
	return 0;
}