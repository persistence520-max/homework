#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a, b, c, d;
	int d1, d2, d3, d4;
	int date;
	int casenum = 1;
	while (cin >> a >> b >> c >> d) {
		
		cin >> d1 >> d2 >> d3 >> d4 >> date;

		

		d1 %= a;
		d2 %= b;
		d3 %= c;
		d4 %= d;
		

		cout << "Case " << casenum++ << ": ";
		bool found = false;
		for (int i = date + 1; i < a * b * c * d + 365; i++) {
			if (i % a == d1 && i % b == d2 && i % c == d3 && i % d == d4) {
				cout << i - date << endl;
				found = true;
				break;
			}
		}
		if (!found)cout << "No such days." << endl;
	}
	return 0;
}