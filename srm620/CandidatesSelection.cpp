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

class CandidatesSelection {
 public:
  string possible(vector<string> score, vector<int> result) {
		int n = result.size();
		cout << n << endl;
		int m = score[0].size();
		if (n == 1) return "Possible";
		vector<bool> fix(n, false);
		bool over;
		while (true) {
			over = true;
			for (int i = 0; i != n-1; i++) 
				if (!fix[i]) over &= (result[i] < result[i+1]); 
			if (over) break;
			int k = -1;
			for (int i = 0; i != m; i++) {
				int canfix = 0;
				for (int j = 0; j != n-1; j++) 
				if (!fix[j]) {
					if (score[result[j]][i] > score[result[j+1]][i]) {
						canfix = 0; 
						break;
					}
					canfix += (score[result[j]][i] < score[result[j+1]][i]);
				}
				if (canfix > 0) {
					k = i;
					break;
				}
			}
			if (k < 0) break;
			for (int j = 0; j != n-1; j++)
				fix[j] = fix[j] | (score[result[j]][k] < score[result[j+1]][k]);
		}	
		return over ? "Possible" : "Impossible";
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"CC", "AA", "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, possible(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"BAB", "ABB", "AAB", "ABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,0,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, possible(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"BAB", "ABB", "AAB", "ABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, possible(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAA", "ZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(3, Arg2, possible(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ZZZ", "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(4, Arg2, possible(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"ZYYYYX","YXZYXY","ZZZZXX","XZXYYX","ZZZYYZ","ZZXXYZ","ZYZZXZ","XZYYZX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,7,1,0,2,5,6,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(5, Arg2, possible(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  CandidatesSelection ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
