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

class TaroJiroGrid {
public:
	bool check(vector <string> sb) {
		int n = sb.size();
		for (int col = 0; col != n; col++) {
			int num = 0;
			char color = '-';
			bool ok = true;
			for (int i = 0; i != n; i++) {
				if (sb[i][col] == color) ++num;
				else {
					ok &= !(num > n/2);
					num = 1;
					color = sb[i][col];
				}
			}
			ok &= !(num > n/2);
			if (!ok) return false;
		}
		return true;
	}

  int getNumber(vector<string> grid) {
  	int n = grid.size();
		vector <string> sb;
		for (int i = 0; i != n; i++) sb.push_back(grid[i]);
		string new_w = "";
		string new_b = "";
		for (int i = 0; i != n; i++) {
			new_w += "W";
			new_b += "B";
		}
		if (check(sb)) return 0;
		for (int i = 0; i != n; i++) {
			sb[i] = new_w;
			if (check(sb)) return 1;
			sb[i] = new_b;
			if (check(sb)) return 1;
			sb[i] = grid[i];
		}
		return 2;
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"WB",
 "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arr0[] = {"WB",
 "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arr0[] = {"WB",
 "WB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arr0[] = {"WBBW",
 "WBWB",
 "WWBB",
 "BWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arr0[] = {"WBBWBB",
 "BBWBBW",
 "WWBWBW",
 "BWWBBB",
 "WBWBBW",
 "WWWBWB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  TaroJiroGrid ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
