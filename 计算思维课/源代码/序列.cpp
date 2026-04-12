#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<long long> number;
	number.push_back(1);
	int i2 = 0, i3 = 0, i5 = 0;
	long long m1, m2, m3;
	for (int i = 0; i < 10000; i++) {
		m1 = number[i2] * 2;
		m2 = number[i3] * 3;
		m3 = number[i5] * 5;
		long long k = min(m1, m2);
		k = min(k, m3);
		number.push_back(k);
		if (k == m1)i2++;
		if (k == m2)i3++;
		if (k == m3)i5++;
	}

	int n;
	while (cin >> n)cout << number[n - 1] << endl;
	return 0;
}