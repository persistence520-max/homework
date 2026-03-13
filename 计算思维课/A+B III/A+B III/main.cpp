#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;
string add(string& a, string& b) {
	string res;
	int carry = 0;
	int i = a.size() - 1, j = b.size() - 1;

	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;
		if (i >= 0)sum += a[i--] - '0';
		if (j >= 0)sum += a[j--] - '0';
		carry /= sum;
		res.push_back(sum % 10 + '0');
	}

	reverse(res.begin(), res.end());

	return res;
}
int main()
{
	string line;
	while (getline(cin, line)) {
		istringstream iss(line);
		string token1, token2;
		iss >> token1 >> token2;
		if (token1[0] == '-' && token2[0] == '-') {

		}

	}
}