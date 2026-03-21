#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int x, n, casenum = 1;
	while (cin >> x >> n) {
		vector<int> p(n + 1);
		for (int i = 1; i <= n; i++) {
			if (x == 2)p[i] = i * i;
			else p[i] = i * i * i;
		}

		cout << "Case " << casenum++ << ": \n";

		bool found = false;

		for (int a = 1; a <= n; a++) {
			for (int b = a; b <= n; b++) {
				for (int c = b; c <= n; c++) {
					for (int d = c; d <= n; d++) {
						if (p[a] + p[b] + p[c] == p[d]) {
							cout << a << "^" << x << "+"
								<< b << "^" << x << "+"
								<< c << "^" << x << "="
								<< d << "^" << x << endl;
							found = true;
						}
					}
				}
			}
		}

		if (!found)cout << "No such numbers." << endl;
	}
	return 0; 
}