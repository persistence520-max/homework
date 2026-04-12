#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;

int simulate(int n, int u, int d, int s,
	const vector<int> up_c[201],
	const vector<int> down_c[201],
	int L, int H, int dir
	) {

	vector<int> up[201], down[201];
	for (int i = 0; i < 201; i++) {
		up[i] = up_c[i];
		down[i] = down_c[i];
	}
	int in[201] = { 0 };
	int cur = n;
	int time = 0;

	if (dir == 1) {
		for (int to : up[cur])in[to]++;
		up[cur].clear();
	}
	else {
		for (int to : down[cur])in[to]++;
		down[cur].clear();
	}

	while (true) {
		bool stop = false;
		if (in[cur] > 0)stop = true;
		if (dir == 1 && !up[cur].empty())stop = true;
		if (dir == -1 && !down[cur].empty())stop = true;

		if (stop) {
			time += s;
			if (in[cur] > 0)in[cur] = 0;
			if (dir == 1) {
				for (int to : up[cur])in[to]++;
				up[cur].clear();
			}
			else {
				for (int to : down[cur])in[to]++;
				down[cur].clear();
			}
		}

		bool done = true;
		for (int i = L; i <= H; i++) {
			if (in[i] > 0 || !up[i].empty() || !down[i].empty()) {
				done = false;
				break;
			}
		}
		if (done)break;

		int next = -1;
		if (dir == 1) {
			for (int i = cur + 1; i <= H; i++) {
				if (in[i] > 0 || !up[i].empty()) {
					next = i;
					break;
				}
			}
		}
		else {
			for (int i = cur - 1; i >= L; i--) {
				if (in[i] > 0 || !down[i].empty()) {
					next = i;
					break;
				}
			}
		}

		if (next != -1) {
			int t = abs(next - cur);
			time += t * (dir == 1 ? u : d);
			cur = next;
		}
		else {
			next = cur;
			if (dir == 1) {
				for (int i = H; i >= L; i--) {
					if (!down[i].empty()) {
						next = i;
						break;
					}
				}
			}
			else {
				for (int i = L; i <= H; i++) {
					if (!up[i].empty()){
						next = i;
						break;
					}
				}
			}

			if (cur == next) {
				dir = -dir;
				if (dir == 1) {
					for (int to : up[cur])in[to]++;
					up[cur].clear();
				}
				else {
					for (int to : down[cur])in[to]++;
					down[cur].clear();
				}
			}
			else {
				int t = abs(next - cur);
				time += t * (next > cur ? u : d);
				cur = next;
				dir = -dir;
			}
		}
	}

	return time;
}

int main() {
	int n, u, d, s;
	int casenum = 1;
	string line;

	while (cin >> n >> u >> d >> s) {
		cin.ignore();
		getline(cin, line);

		vector<int> up[201], down[201];
		int L = 201, H = 1;

		stringstream ss(line);
		int from, to;
		char ch;
		while (ss >> from >> ch >> to) {
			L = min(L, min(from, to));
			H = max(H, max(from, to));
			if (from > to) {
				down[from].push_back(to);
			}
			else {
				up[from].push_back(to);
			}
		}

		int t1 = simulate(n, u, d, s, up, down, L, H, 1);
		int t2 = simulate(n, u, d, s, up, down, L, H, -1);

		cout << "Case " << casenum++ << ": " << min(t1, t2) << "\n";
	}
	return 0;
}

/*
1 6 4 5
1-3 2-3 5-6 8-10 5-4
2 6 4 5
1-3 2-3 5-6 8-10 5-4
11 6 4 5
1-3 2-3 5-6 8-10 5-4
7 6 4 5
1-3 2-3 5-6 8-10 5-4
8 6 4 5
1-3 2-3 5-6 8-10 5-4
8 6 4 5
1-3 2-3 5-6 8-10 5-4 2-3 1-3

1 6 4 5
1-3 1-4 1-5 2-4 2-3 5-6 8-10 5-4 5-1 6-3 2-4 2-8
2 6 4 5
1-3 1-4 1-5 2-4 2-3 5-6 8-10 5-4 5-1 6-3
3 6 4 5
1-3 1-4 1-5 2-4 2-3 5-6 8-10 5-4 5-1 6-3
4 6 4 5
1-3 1-4 1-5 2-4 2-3 5-6 8-10 5-4 5-1 6-3
5 6 4 5
1-3 1-4 1-5 2-4 2-3 5-6 8-10 5-4 5-1 6-3
12 6 4 5
1-3 1-4 1-5 2-4 2-3 5-6 8-10 5-4 5-1 6-3
8 6 4 5
1-3 1-4 1-5 2-4 2-3 5-6 8-10 5-4 5-1 6-3
*/