#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

void mv_on(int x, int y, vector<vector<int>> &arr, vector<int> &pos) {
	int locx = pos[x], locy = pos[y];

		auto itx = find(arr[locx].begin(), arr[locx].end(), x);
		auto ity = find(arr[locy].begin(), arr[locy].end(), y);

		for (auto iter = itx + 1; iter != arr[locx].end(); iter++) {
			arr[*iter].push_back(*iter);
			pos[*iter] = *iter;
		}
		arr[locx].erase(itx, arr[locx].end());

		for (auto iter = ity + 1; iter != arr[locy].end(); iter++) {
			arr[*iter].push_back(*iter);
			pos[*iter] = *iter;
		}
		arr[locy].erase(ity + 1, arr[locy].end());
		
		arr[locy].push_back(x);
		pos[x] = locy;
	
}

void mv_ov(int x, int y, vector<vector<int>> &arr, vector<int> &pos) {
	
	int locx = pos[x], locy = pos[y];

		auto itx = find(arr[locx].begin(), arr[locx].end(), x);
		for (auto iter = itx + 1; iter != arr[locx].end(); ++iter) {
			arr[*iter].push_back(*iter);
			pos[*iter] = *iter;
		}
		arr[locx].erase(itx, arr[locx].end());
		arr[locy].push_back(x);
		pos[x] = locy;
	
}

void st_on(int x, int y, vector<vector<int>> &arr, vector<int> &pos) {
	int locx = pos[x], locy = pos[y];

		auto ity = find(arr[locy].begin(), arr[locy].end(), y);
		for (auto iter = ity + 1; iter != arr[locy].end(); ++iter) {
			arr[*iter].push_back(*iter);
			pos[*iter] = *iter;
		}
		arr[locy].erase(ity + 1, arr[locy].end());

		auto itx = find(arr[locx].begin(), arr[locx].end(), x);
		for (auto iter = itx; iter != arr[locx].end(); ++iter) {
			arr[locy].push_back(*iter);
			pos[*iter] = locy;
		}
		arr[locx].erase(itx, arr[locx].end());
	
	
}

void st_ov(int x, int y, vector<vector<int>> &arr, vector<int> &pos) {
	int locx = pos[x], locy = pos[y];

		auto it = find(arr[locx].begin(), arr[locx].end(), x);
		for (auto iter = it; iter != arr[locx].end(); iter++) {
			arr[locy].push_back(*iter);
			pos[*iter] = locy;
		}
		arr[locx].erase(it, arr[locx].end());
}

void xh_an(int x, int y, vector<vector<int>> &arr, vector<int> &pos) {
	int locx = pos[x], locy = pos[y];
	
	swap(arr[locx], arr[locy]);
	for (int a : arr[locx])pos[a] = locx;
	for (int a : arr[locy])pos[a] = locy;
	
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	vector<vector<int>> arr(n);
	vector<int> pos(n);
	for (int i = 0; i < n; i++) {
		arr[i].push_back(i);
		pos[i] = i;
	}

	string line, order, order1;
	int x, y;
	
	while (getline(cin, line)) {

		if (line == "q") {
			for (int i = 0; i < n; i++) {
				cout << i << ":";
				for (int a : arr[i])cout << ' ' << a;
				cout << endl;
			}
			return 0;
		}
		
		istringstream iss(line);
		iss >> order;
		iss >> x;
		iss >> order1;
		iss >> y;
		order = order + order1;

		if (x == y || pos[x] == pos[y])continue;

		if (order == "mvon")mv_on(x, y, arr, pos);
		if (order == "mvov")mv_ov(x, y, arr, pos);
		if (order == "ston")st_on(x, y, arr, pos);
		if (order == "stov")st_ov(x, y, arr, pos);
		if (order == "xhan")xh_an(x, y, arr, pos);
	}
}