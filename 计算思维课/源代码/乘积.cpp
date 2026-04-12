#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string line;
	int casenum = 1;

	while (getline(cin, line)) {
		if (line.empty())continue;

		stringstream ss(line);
		vector<int> s;
		int x;
		while (ss >> x)s.push_back(x);

		int n = s.size();

		long long max = s[0], min = s[0];
		int maxL = 0, minL = 0;

		long long ans = s[0];
		int ansL = 0, ansR = 0;

		for (int i = 1; i < n; i++) {
			long long a = s[i];
			long long b = max * s[i];
			long long c = min * s[i];

			long long newmax = a;
			int newmaxL = i;

			long long newmin = a;
			int newminL = i;

			if (b > newmax) {
				newmax = b;
				newmaxL = maxL;
			}
			if (c > newmax) {
				newmax = c;
				newmaxL = minL;
			}

			if (b < newmin) {
				newmin = b;
				newminL = maxL;
			}
			if (c < newmin) {
				newmin = c;
				newminL = minL;
			}

			max = newmax;
			min = newmin;
			maxL = newmaxL;
			minL = newminL;

			int curlen = i - maxL;
			int anslen = ansR - ansL;

			if (max > ans ||
				(max == ans && curlen < anslen) ||
				(max == ans && curlen == anslen && maxL < ansL)) {
				ans = max;
				ansL = maxL;
				ansR = i;
			}
		}

		cout << "Case " << casenum++ << ": "
			<< ans << " " << ansL << "-" << ansR << endl;
	}
	return 0;
}