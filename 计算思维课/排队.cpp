#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int g;
	int casenum = 1;

	while (cin >> g && g != 0) {

		cout << "Case #" << casenum++ << ":\n";

		unordered_map<string, int> group;

		for (int i = 0; i < g; i++) {
			int n; 
			cin >> n;
			for (int j = 0; j < n; j++) {
				string name;
				cin >> name;
				group[name] = i;
			}
		}

		vector<queue<string>> memberQueue;
		memberQueue.resize(g);

		queue<int> teamQueue;

		string cmd;
		while (cin >> cmd) {
			if (cmd == "stop")break;

			if (cmd == "enqueue") {

				string x;
				cin >> x;
				if (!group.count(x)) {
					group[x] = memberQueue.size();
					memberQueue.push_back(queue<string>());
				}
				int gid = group[x];

				if (memberQueue[gid].empty()) {
					teamQueue.push(gid);
				}

				memberQueue[gid].push(x);

			}
			else if (cmd == "dequeue") {

				if (teamQueue.empty())continue;

				int gid = teamQueue.front();
				string x = memberQueue[gid].front();
				memberQueue[gid].pop();

				cout << x << "\n";

				if (memberQueue[gid].empty()) {
					teamQueue.pop();
				}

			}
			else if (cmd == "deqteam") {

				string x;
				cin >> x;

				if (!group.count(x))continue;

				int gid = group[x];

				if (memberQueue[gid].empty())continue;

				bool first = true;
				while (!memberQueue[gid].empty()) {
					if (!first) cout << " ";
					cout << memberQueue[gid].front();
					memberQueue[gid].pop();
					first = false;
				}
				cout << "\n";

				queue<int> tmp;
				while (!teamQueue.empty()) {
					if (teamQueue.front() != gid) {
						tmp.push(teamQueue.front());
					}
					teamQueue.pop();
				}

				teamQueue = tmp;
			}
		}
	}
	return 0;
}
