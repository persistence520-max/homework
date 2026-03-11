#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> arr;
	int a;
	cin >> a;
	while (cin >> a) {
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	a = arr[(int)arr.size() - 1] - arr[0];

	cout << a << '\n';

	return 0;
}