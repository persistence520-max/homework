#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int a;
	vector<int> arr;
	cin >> a;
	while (cin >> a) {
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	a = arr[1] - arr[0];
	int num = (int)arr.size() - 1;
	for (int i = 1; i < num; i++) {
		a = min(a, arr[i + 1] - arr[i]);
	}
	cout << a << '\n';
	return 0;
}