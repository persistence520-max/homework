#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 2000
void add(char* sum, char* a, char* b) {
	char t[MAX + 2] = { 0 };
	int i = strlen(a), j = strlen(b);
	int k = 0, c = 0;
	while (i > 0 || j > 0 || c) {
		int d = (i > 0 ? a[--i] : '0') + (j > 0 ? b[--j] : '0') - 2 * '0' + c;
		t[k++] = d % 10 + '0';
		c = d / 10;
	}
	sum[0] = 0;
	for (int i = 0; i < k; i++) {
		sum[i] = t[k - i - 1];
	}
	sum[k] = 0;
}
void sub(char* sum, char* a, char* b) {
	char t[MAX + 2] = { 0 };
	int i = strlen(a), j = strlen(b);
	int k = 0, c = 0;
	while (i > 0 || j > 0 || c) {
		int d = (i > 0 ? a[--i] : '0') - (j > 0 ? b[--j] : '0') - c;
		c = 0;
		if (d < 0) {
			d += 10;
			c = 1;
		}
		t[k++] = d + '0';
	}
	while (k > 1 && t[k - 1] == '0') {
		k--;
	}
	for (int i = 0; i < k; i++) {
		sum[i] = t[k - i - 1];
	}
	sum[k] = '\0';

}
int main()
{
	char in[MAX] = "0";
	char out[MAX] = "0";
	char sum[MAX] = "0";
	char line[MAX] = "0";
	while (fgets(line, sizeof(line), stdin)) {
		line[strcspn(line, "\n")] = 0;
		if (line[0] == '-') {
			add(out, out, line + 1);
		}
		else {
			add(in, in, line);
		}
	}
	if (strlen(in) > strlen(out)) {
		sub(sum, in, out);
		printf("%s\n", sum);
	}
	else if (strlen(in) < strlen(out)) {
		sub(sum, out, in);
		printf("-%s\n", sum);
	}
	else {
		if (strcmp(in, out) >= 0) {  // in >= out
			sub(sum, in, out);
			printf("%s\n", sum);
		}
		else {
			sub(sum, out, in);
			printf("-%s\n", sum);
		}
	}

	printf("-%s\n", out);
	printf("%s\n", in);
	return 0;
}