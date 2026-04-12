#include<iostream>
#include<set>
#include<functional>
using namespace std;
int main()
{
	int n;
	cin >> n;
	set<int, greater<int>> s;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s.insert(x);
	}

	for (int x : s) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}