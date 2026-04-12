#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int n, w;
	while (cin >> n >> w) {

		vector<string> files(n);
		int length = 0;

		for (int i = 0; i < n; i++) {
			cin >> files[i];
			length = max(length, (int)files[i].size());
		}
		sort(files.begin(), files.end());

		cout << string(w, '-') << endl;

		int c = (w + 2) / (length + 2);
		c = min(c, n);

		int r = (n + c - 1) / c;

		vector<vector<string>> cols(c);

		int base = n / c;
		int extra = n % c;

		int pos = 0;
		for (int j = 0; j < c; j++) {
			int len = (j < extra) ? base + 1 : base;
			for (int k = 0; k < len; k++) {
				cols[j].push_back(files[pos++]);
			}
		}

		for (int i = 0; i < r; i++) {
			bool first = true;
			for (int j = 0; j < c; j++) {
				if (i >= (int)cols[j].size())continue;

				if (!first)cout << "  ";
				cout << left << setw(length) << cols[j][i];
				first = false;
			}
			cout << endl;
		}

		
	}
	return 0;
}