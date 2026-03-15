#include<iostream>
using namespace std;
int main()
{
	int n;
	char ch;
	cin >> ch;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++)cout << ' ';
		cout << ch;
		if (i == 1) {
			cout << endl;
		}
		else if(i == n) {
			for (int k = 1; k < i; k++) {
				cout << ' ' << ch;
			}
			
			cout << endl;
		}
		else {
			for (int k = 0; k < 2 * i - 3; k++) {
				cout << ' ';
			}
			cout << ch << endl;
		}
	}
	return 0;
}