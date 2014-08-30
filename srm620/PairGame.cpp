// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <sstream>
using namespace std;

class PairGame {
	public:
  int maxSum(int a, int b, int c, int d) {
  	pair<int, int> g[2];
		g[0] = make_pair(a, b);
		g[1] = make_pair(c, d);
		while (g[0] != g[1]) {
			int ind = (g[1] > g[0]);
			if (g[ind].first <= 0 || g[ind].second <= 0) break;
			if (g[ind].first > g[ind].second) {
				g[ind] = make_pair(g[ind].first - g[ind].second, g[ind].second);
			} else {
				g[ind] = make_pair(g[ind].first, g[ind].second - g[ind].first);
			}
		}
		if (g[0] != g[1] || g[0].second <= 0 || g[0].first <= 0) return -1;
		return g[0].first + g[0].second;
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; int Arg4 = 2; verify_case(0, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 15; int Arg1 = 4; int Arg2 = 10; int Arg3 = 7; int Arg4 = 7; verify_case(1, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 10; int Arg4 = -1; verify_case(2, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1001; int Arg2 = 2000; int Arg3 = 2001; int Arg4 = 1001; verify_case(3, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10944; int Arg1 = 17928; int Arg2 = 7704; int Arg3 = 21888; int Arg4 = 144; verify_case(4, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; verify_case(5, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  PairGame ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
