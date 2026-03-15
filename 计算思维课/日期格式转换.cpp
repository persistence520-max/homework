#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	string line;
	while (getline(cin, line)) {
		int y, m, d;
		if (sscanf(line.c_str(), "%d-%d-%d", &y, &m, &d) == 3) {
			printf("%02d/%02d/%04d\n", m, d, y);
		}
	}
	return 0; 
}