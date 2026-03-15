#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int k;
	long long sum = 0;
	vector<long long> pos, neg;
	int a;

	cin >> k;
	while (cin >> a) {
		sum += a;
		if (a > 0)pos.push_back(a);
		else neg.push_back(a);
	}

	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end(), greater<int>());

	cout << sum << '\n';

	int num = min(k, (int)neg.size());
	for (int i = 0; i < num; i++) {
		if (i > 0)cout << ' ';
		cout << -neg[i];
	}
	cout << '\n';

	num = min(k, (int)pos.size());
	for (int i = 0; i < num; i++) {
		if (i > 0)cout << ' ';
		cout << pos[i];
	}
	cout << '\n';
	return 0;
}