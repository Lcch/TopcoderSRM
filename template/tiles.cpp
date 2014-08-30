#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 10;
const int maxm = 1 << maxn;
int f[maxm],d[maxm], n, m, t;

void dfs(int k, int st, int pre_st) {
	if (k >= m) {
		f[st] += d[pre_st];
	} else {
		if ((pre_st >> k) & 1) {
			dfs(k+1, st, pre_st);
		} else {
			dfs(k+1, st + (1<<k), pre_st);
			if (k+1 < m && !((pre_st >> (k+1)) & 1)) {
				dfs(k+2, st, pre_st);
			}
		}
	}
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(f, 0, sizeof(f));
		f[(1 << m) - 1] = 1;
		for (int i = 0; i <= n; i++) {
			for (int st = 0; st != (1 << m); st++) {
				d[st] = f[st];
			}
			memset(f, 0, sizeof(f));
			for (int st = 0; st != (1 << m); st++) 
			if (d[st] > 0) dfs(0, 0, st);
		}
		printf("ans: %d\n", f[0]); 
	}
	return 0;
}

