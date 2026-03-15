#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int k = 1;
	int n, q;
	
	while (cin >> n >> q) {
		vector<int> arr(n), fin(q);

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < q; i++) {
			cin >> fin[i];
		}

		sort(arr.begin(), arr.end());

		cout << "Case #" << k++ << ':' << '\n';
		for (int q : fin) {
			auto it = lower_bound(arr.begin(), arr.end(), q);
			if (it != arr.end() && *it == q) {
				int pos = it - arr.begin() + 1;
				cout << q << " found at " << pos << endl;
			}
			else {
				cout << q << " not found" << endl;
			}
		}
	}
	return 0;
}