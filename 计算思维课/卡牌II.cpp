#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int  n, q;
	int  x, y;
	int t = 1;
	while (cin >> n >> q) {

		vector<int> arr1, arr2, fin;
		for (int i = 0; i < n; i++) {
			cin >> x;
			arr1.push_back(x);
		}
		arr2 = arr1;
		sort(arr2.begin(), arr2.end());
		for (int i = 0; i < q; i++) {
			cin >> x;
			fin.push_back(x);
		}

		cout << "Case #" << t++ << ":\n";
		for (int a : fin) {
			x = y = -1;
			for (int i = 0; i < arr1.size(); i++) {
				if (a == arr1[i]) {
					x = i; 
					break;
				}
			}
			for (int i = 0; i < arr2.size(); i++) {
				if (a == arr2[i]) {
					y = i;
					break;
				}
			}
			if (x == -1 || y == -1) {
				cout << a << " not found\n";
			}
			else {
				cout << a << " from " << x + 1 << " to " << y + 1 << endl;
			}
		}
	}
	return 0;
}