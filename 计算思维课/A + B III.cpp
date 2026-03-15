#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;
string add(string& a, string& b) {
	string res;
	int carry = 0;
	int i = a.size() - 1, j = b.size() - 1;

	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;
		if (i >= 0)sum += a[i--] - '0';
		if (j >= 0)sum += b[j--] - '0';
		carry = sum / 10;
		res.push_back(sum % 10 + '0');
	}

	reverse(res.begin(), res.end());
	while (res[0] == '0') {
		res = res.substr(1);
	}
	return res;
}
string subtract(string& a, string& b) {
	string res;
	int borrow = 0, i = a.size() - 1, j = b.size() - 1;
	while (i >= 0) {
		int da = a[i--] - '0' - borrow;
		int db = (j >= 0) ? b[j--] - '0' : 0;
		if (da < db) {
			da += 10; borrow = 1;
		}
		else borrow = 0;
		res += char(da - db + '0');
	}
	reverse(res.begin(), res.end());
	while (res[0] == '0') {
		res = res.substr(1);
	}
	return res;
}

int main()
{
	string line;
	while (getline(cin, line)) {
		istringstream iss(line);
		string a, b;
		string res;
		iss >> a >> b;

		bool negA = false, negB = false;
		if (a[0] == '-') {
			negA = true;
			a = a.substr(1);
		}
		if (b[0] == '-') {
			negB = true;
			b = b.substr(1);
		}
		
		if (!negA && !negB) {
			res = add(a, b);
			cout << res << endl;
		}
		else if (negA && negB) {
			cout << '-';
			res = add(a, b);
			cout << res << endl;
		}
		else {
			//比较绝对值的大小
			int cmp = 0;
			if (a.size() != b.size())cmp = a.size() > b.size() ? 1 : -1;
			else if (a != b)cmp = a > b ? 1 : -1;

			if (cmp == 0) {
				cout << "0" << endl;
			}else if (cmp > 0) {
				res = subtract(a, b);
				if (negB)cout << res << endl;
				else cout << '-' << res << endl;
			}
			else {
				res = subtract(b, a);
				if (negA)cout << res << endl;
				else cout << '-' << res << endl;
			}
			
		}

		
	}
	return 0;
}