#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string input[1000];
	vector<string> result;
	vector<int> data[1000] = {};
	string ch;
	vector<int> out(1000);
	int k = 0;
	while (cin >> ch ) {

		if (ch == "#")break;

		input[k] = ch;
		for (size_t i = 0; i < ch.size(); i++) {
			if (ch[i] >= 'A' && ch[i] <= 'Z') {
				ch[i] = ch[i] - 'A' + 'a';
			}
		}

		for (int i = 0; i < ch.size(); i++) {
			if (ch[i] >= '0' && ch[i] <= '9') {
				data[k].push_back(ch[i]);
				continue;
			}
			data[k].push_back(ch[i] - 'a');
		}
		sort(data[k].begin(), data[k].end());
		k++;
	}

	vector<vector<int>> res(1000);
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (data[i] == data[j] && !out[i] && !out[j] && input[i] != input[j]) {
				bool pass = true;
				for (const auto& h : result)if (h == input[i])pass = false;
				for (const auto& m : res)if (data[i] == m)pass = false;
				if (pass) {
					result.push_back(input[i]);
					res.push_back(data[i]);
					out[i] = out[j] = 1;
				}
			}
		}
	}

	sort(result.begin(), result.end());
	for (const auto& w : result)cout << w << endl;
	return 0;
}