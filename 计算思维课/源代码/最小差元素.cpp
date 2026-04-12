#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<long long> arr;
	long long a;
	cin >> a;
	while (cin >> a) {
		arr.push_back(a);
	}

	vector<long long> arr_s = arr;
	sort(arr.begin(), arr.end());
	int m = arr[0], n = arr[1];
	a = arr[1] - arr[0];
	int num = (int)arr.size() - 1;
	for (int i = 1; i < num; i++) {
		if (a > arr[i + 1] - arr[i]) {
			a = arr[i + 1] - arr[i];
			n = arr[i + 1];
			m = arr[i];
		}
	}
	cout << a << ' ';

	for (int i = 0; i <= num; i++) {
		if (arr_s[i] == m || arr_s[i] == n) {
			cout << i + 1 << ' ';
		}
	}
	return 0;
}