#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	vector<int> str1, str2;
	cin >> s1 >> s2;
	
	int st1[26] = { 0 }, st2[26] = {0};
	for (char c : s1)st1[c - 'A']++;
	for (char c : s2)st2[c - 'A']++;

	for (int i = 0; i < 26; i++) {
		if (st1[i] > 0)str1.push_back(st1[i]);
		if (st2[i] > 0)str2.push_back(st2[i]);
	}

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	if (str1 == str2)cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
