#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	int cnt1[26] = { 0 }, cnt2[26] = { 0 };
	for (char c : s1)cnt1[c - 'A']++;
	for (char c : s2)cnt2[c - 'A']++;

	vector<int> str1(26), str2(26);
	for (int i = 0; i < 26; i++) {
		str1[i] = cnt1[i];
		str2[i] = cnt2[i];
	}
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	if (str1 != str2) {
		cout << "NO" << endl;
		return 0;
	}

	int first1[26], first2[26];
	fill(first1, first1 + 26, -1);
	fill(first2, first2 + 26, -1);
	for (int i = 0; i < s1.length(); i++) {
		int idx = s1[i] - 'A';
		if (first1[i] == -1)first1[idx] = i;
	}
	for (int i = 0; i < s2.length(); i++) {
		int idx = s2[i] - 'A';
		if (first2[i] == -1)first2[idx] = i;
	}

	vector<int> freq1[101], freq2[101];
	for (int i = 0; i < 26; i++) {
		if (cnt1[i] > 0)freq1[cnt1[i]].push_back(i);
		if (cnt2[i] > 0)freq2[cnt2[i]].push_back(i);
	}

	int mapping[26];
	for (int k = 0; k < 101; k++) {
		sort(freq1[k].begin(), freq1[k].end(), [&](int a, int b) {return first1[a] < first1[b]; });
		sort(freq2[k].begin(), freq2[k].end(), [&](int a, int b) {return first2[a] < first2[b]; });
		for (size_t q = 0; q < freq1[k].size(); q++) {
			mapping[freq1[k][q]] = freq2[k][q];
		}
	}

	cout << "YES" << endl;
	bool printed[26] = { false };
	bool first = true;
	for (char c : s1) {
		int idx = c - 'A';
		if (!printed[idx]) {
			if (!first)cout << ' ';
			first = false;
			printed[idx] = true;
			cout << c << "->" << char('A' + mapping[idx]);
		}
	}
	cout << endl;
	
	return 0;
}