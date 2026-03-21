#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string x;
	map<string, int> freq;

	while (cin >> x) {

		string tmp;
		for (char ch : x) {
			if (ch >= 'a' && ch <= 'z') {
				tmp.push_back(ch);
			}
			else if (ch >= 'A' && ch <= 'Z') {
				ch = ch - 'A' + 'a';
				tmp.push_back(ch);
			}
			else if (ch == '-') {
				continue;
			}
			else if (ch == '\'') {
				break;
			}
			else {
				continue;
			}
		}
		if (tmp.empty())continue;
		freq[tmp]++;
	}

	int max_freq = 0;
	for (const auto& pair : freq) {
		max_freq = max(max_freq, pair.second);
	}
	vector<vector<string>> buckets(max_freq + 1);

	for (const auto& pair : freq) {
		buckets[pair.second].push_back(pair.first);
	}
	for (int i = 1; i < buckets.size(); i++) {
		sort(buckets[i].begin(), buckets[i].end());
	}

	for (int i = buckets.size() - 1; i >= 1; i--) {
		if (buckets[i].empty())continue;
		for (const auto& s : buckets[i]) {
			cout << s << '\n';
		}
	}

	return 0;
}
