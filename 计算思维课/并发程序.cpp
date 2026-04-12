#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct program {
	int id;
	vector<string> cmd;
	int pc;
};

int n, t1, t2, t3, t4, t5, t6, t7, Q;

int cost(const string& cmd) {
	if (cmd.find("print") != string::npos) return t4;
	if (cmd == "lock") return t5;
	if (cmd == "unlock") return t6;
	if (cmd.find("+=") != string::npos) return t2;
	if (cmd.find("-=") != string::npos) return t3;
	if (cmd.find("=") != string::npos) return t1;
	if (cmd == "end") return t7;
	return 0;
}

int main() {
	bool locked = false;
	int owner = -1;
	vector<int> vars(256, 0);
	queue<int> wait_queue, lock_queue;
	program p[101];
	
	cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> t6 >> t7 >> Q;
	cin.ignore();
	string line;
	
	for (int i = 1; i <= n; i++) {
		p[i].id = i;
		p[i].pc = 0;
		while (getline(cin, line)) {
			if (line.empty()) continue;
			p[i].cmd.push_back(line);
			if (line == "end")break;
		}
	}

	for (int i = 1; i <= n; i++) {
		wait_queue.push(i);
	}

	while (!wait_queue.empty()) {
		int id = wait_queue.front();
		wait_queue.pop();
		bool turn = false;
		bool last = false;
			
		for (int t = 0; p[id].pc < p[id].cmd.size() && !last; p[id].pc++) {
			string cmd = p[id].cmd[p[id].pc];
			if (cmd.empty())break;
			if (Q < cost(cmd) + t && t < Q)last = true;
			if (t == Q)break;
			istringstream iss(cmd);

			t += cost(cmd);

			if (cmd.find("+=") != string::npos) {
				string ch, h;
				char c;
				iss >> c >> ch >> h;
				if (h.size() == 1 && h[0] >= 'a' && h[0] <= 'z') {
					vars[c] += vars[h[0]];
				}
				else {
					vars[c] += stoi(h);
				}
			}
			else if (cmd.find("-=") != string::npos) {
				string ch, h;
				char c;
				iss >> c >> ch >> h;
				if (h.size() == 1 && h[0] >= 'a' && h[0] <= 'z') {
					vars[c] -= vars[h[0]];
				}
				else {
					vars[c] -= stoi(h);
				}
			}
			else if (cmd.find("=") != string::npos) {
				string ch, h;
				char c;
				iss >> c >> ch >> h;
				if (h.size() == 1 && h[0] >= 'a' && h[0] <= 'z') {
					vars[c] = vars[h[0]];
				}
				else {
					vars[c] = stoi(h);
				}
			}
			else if (cmd.find("print") != string::npos) {
				string ch;
				char c;
				iss >> ch >> c;
				cout << id << ": " << vars[c] << endl;
			}
			else if (cmd == "lock") {
				if (locked) {
					lock_queue.push(id);
					turn = true;
					break;
				}
				else {
					locked = true;
					owner = id;
				}
			}
			else if (cmd == "unlock") {
				locked = false;
				owner = -1;
				if (!lock_queue.empty()) {
					queue<int> temp;
					int tem = lock_queue.front();
					lock_queue.pop();
					temp.push(tem);
					while (!wait_queue.empty()) {
						tem = wait_queue.front();
						temp.push(tem);
						wait_queue.pop();
					}
					wait_queue = temp;
				}
			}
			else if (cmd == "end") {

			}
		}
		if(!turn && p[id].pc < p[id].cmd.size())wait_queue.push(id);
	}
	return 0;
}
/*
3 1 1 1 1 1 1 1 1
a = 4
print a
lock
b = 9
print b
unlock
print b
end
a = 3
print a
lock
b = 8
print b
unlock
print b
end
b = 5
a += 17
print a
print b
lock
b -= 21
print b
unlock
print b
end
*/