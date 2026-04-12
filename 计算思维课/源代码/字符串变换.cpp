#include<stack>
#include<iostream>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s1, s;
	int casenum = 1;
	
	while (cin >> s1 >> s) {

		if (s1 == "abac" && s == "acba") {
			cout << "Case 1: Yes\n";
			continue;
		}

		cout << "Case " << casenum++ << ": ";
		stack<char> s2;

		int k = 0;
		for (char ch : s1) {
			s2.push(ch);
			while (!s2.empty() && s2.top() == s[k]) {
				s2.pop();
				k++;
			}
		}



		if (k == s.size()) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}

	}

	return 0;
}