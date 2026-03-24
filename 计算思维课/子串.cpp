#include<iostream>
#include<string>
using namespace std;
int main() {
	string ch;
	cin >> ch;
	int x;
	int casenum = 1;
	while (cin >> x) {
		cout << "Case " << casenum++ << ":" << endl;
		int num = ch.size() % x;
		for (int i = 1; i <= x; i++) {
			for (int j = 0; j < ch.size();) {
				bool first = false;
				for (; j < i; j++) {
					if (j == ch.size())break;
					cout << ch[j];
					first = true;
				}
				if (first)cout << " ";
				for (int k = 0; k < x; k++) {
					if (j == ch.size())break;
					cout << ch[j++];
				}
				cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}