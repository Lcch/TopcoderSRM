// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ostream>
#include <sstream>
using namespace std;

const int maxn = 50 + 5;
vector<vector<pair<int, int> > > gr(maxn);
int ans;

class Egalitarianism3 {
 public:
	void dfs(int u, int fa, int len, vector<int>* dist) {
    dist->push_back(len);
		for (int t = 0; t != gr[u].size(); t++)
			if (gr[u][t].first != fa)
				dfs(gr[u][t].first, u, len + gr[u][t].second, dist);
	}

  int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
	  if (n <= 2) return n;
		for (int i = 1; i <= n; i++) gr[i].clear();
		for (int i = 0; i != n-1; i++) {
			gr[a[i]].push_back(make_pair(b[i], len[i]));
			gr[b[i]].push_back(make_pair(a[i], len[i]));
		}	
		ans = 2;
		for (int i = 1; i <= n; i++) {
			if (gr[i].size() <= ans) continue;
			vector<vector<int> > dist(gr[i].size());
			for (int j = 0; j != gr[i].size(); j++) {
				dfs(gr[i][j].first, i, gr[i][j].second, &dist[j]);
				sort(dist[j].begin(), dist[j].end());
				vector<int>::iterator iter = unique(dist[j].begin(), dist[j].end());
				dist[j].erase(iter, dist[j].end());
			}
			vector<int> ind(gr[i].size(), 0);
			int prev_min = -1, num = 0;
			while (1) {
				int k = -1, min = -1;
				for (int j = 0; j != gr[i].size(); j++) 
				if (ind[j] < dist[j].size() && (min == -1 || dist[j][ind[j]] < min)) {
					k = j;
					min = dist[j][ind[j]];
				}
				if (k == -1) break;
				++ind[k];
				if (min != prev_min) {
					ans = max(ans, num);
					prev_min = min;
					num = 1;
				} else num++;
			}
			ans = max(ans, num);
		}
		return ans;
	}
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {1,2,3,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,1,3,2,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(1, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {1,1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 9; verify_case(2, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(3, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  Egalitarianism3 ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
