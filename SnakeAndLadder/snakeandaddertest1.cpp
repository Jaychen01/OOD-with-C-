/*----------------------------------------------------------------
Copyright (c) 2021 Author: Jagadeesh Vasudevamurthy
file: snakeandadder1test.cpp

On linux:
g++ snakeandadder1.cpp snakeandadder1test.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test snakeandadder1 object
0 grade will be given if you change anything in this file
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "snakeandadder1.h"

static int marks = 0;
const static int inr = 10;
const static int minm = 85;

static void M(bool fail) {
		if (fail) {
				if (marks < minm) {
						cout << "Your final mark = " << marks << endl;
						cout << "But still I will give you " << minm << endl;
						cout << "Still you will say this class is useless" << endl;
						cout << "upload only snakeandadder1.cpp  snakeandadder1.h as a zip file" << endl;
						cout << "If you upload any other files, or program crashes, you will get only 70" << endl;
				} 
		} else {
				marks += inr;
				cout << "At this point you got " << marks << endl;
		}
}
/*----------------------------------------------------------------
assert ansers
-----------------------------------------------------------------*/
static bool assert_ans(const int N, const vector<int>& ans, const vector<int>& dice_thrown) {
		int s = 1;
		for (auto e : dice_thrown) {
				int t = s + e ; // + 10 Intrdoce bug
				if (t <= N) {
						s = ans[t];
				}		
		}
		if (s != N) {
				cout << "With your answers you will land at " << s << " But you should reach "<< N << endl;
				M(true);
				return false;
		}
		M(false);
		return true;
}

/*----------------------------------------------------------------
print and verify one data
-----------------------------------------------------------------*/
static void print(const int B, const vector<int>& ans, const char* t, const result& d) {
		cout << "------------------- " << t << " -------------- " << endl;
		cout << "Game number " << d.game_number << endl;
		cout << "Num dice thrown " << d.dice_thrown.size() << endl;
		cout << "Num Ladder got " << d.num_ladder_got << endl;
		cout << "Num Snake got " << d.num_snake_got << endl;
		cout << "Most Never moved " << d.num_never_moved << endl;
		cout << "ans = " << d.ans << endl;
		bool x = assert_ans(B, ans, d.dice_thrown);
		assert(x);

}

/*----------------------------------------------------------------
build ds
-----------------------------------------------------------------*/
static vector<int> build_ds(const int B, const vector<int>& la, const vector<int>& sa) {
		vector<int> ans(B + 1);
		iota(ans.begin(), ans.end(), 0);
		{
				auto k = la.size();
				assert(k % 2 == 0);
				for (int i = 0; i < k; i = i + 2) {
						int f = la[i];
						int s = la[i + 1];
						if (f > s) {
								int t = f;
								f = s;
								s = t;
						}
						assert(f < s);
						ans[f] = s;
				}
		}
		{
				auto k = sa.size();
				assert(k % 2 == 0);
				for (int i = 0; i < k; i = i + 2) {
						int f = sa[i];
						int s = sa[i + 1];
						if (f < s) {
								int t = f;
								f = s;
								s = t;
						}
						assert(f > s);
						ans[f] = s;
				}
		}
		return ans;
}

/*----------------------------------------------------------------
print and verify all data
-----------------------------------------------------------------*/
static void print(const int B, const char** rs, const int N, const vector<result> data, const vector<int>& l, const vector<int>& s) {
		vector<int> ans = build_ds(B, l,s);
		auto k = data.size();
		cout << "-------  NUMBER OF games played ------ " << N << endl;
		for (int i = 0; i < k; ++i) {
				print(B,ans, rs[i], data[i]);
		}
}

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
static void testbed() {
		{
				//http://tfortoys.com/product/snake-ladder-paper/#&gid=1&pid=1
				int NUMROUND = 20000; //20000
				const int N = 100;
				const int numl = 9;
				const vector<int> l = { 20, 38, 4, 14, 31, 9, 21, 42, 28,84,36,44,51,67,71,91,100,80 };
				const auto nl = l.size();
				assert(numl * 2 == nl);
				const int nums = 10;
				const vector<int> s = { 98,78,75,95,93,73,87,24,64,60,62,19,56,53,49,11,16,6,26,47 };
				const auto ns = s.size();
				assert(nums * 2 == ns);

				const char* rs[] = { "BEST ROUND","WORST ROUND","MOST Ladder got round", "MOST Snake got round", "MOST NEVER MOVED" };
				int num_result_to_fill = sizeof(rs) / sizeof(const char*);
				vector<result> data(num_result_to_fill);
				snakeandadder1 a(N, l, s, NUMROUND, data);
				print(N,rs, NUMROUND, data,l,s);
		}
		{
				cout << "--------------------------------------------------------------\n";
				int NUMROUND = 2000; //20000
				const int N = 99;
				const int numl = 2;
				const vector<int> l = { 2,82,64,99};
				const auto nl = l.size();
				assert(numl * 2 == nl);
				const int nums = 1;
				const vector<int> s = { 84,63 };
				const auto ns = s.size();
				assert(nums * 2 == ns);

				const char* rs[] = { "BEST ROUND","WORST ROUND","MOST Ladder got round", "MOST Snake got round", "MOST NEVER MOVED" };
				int num_result_to_fill = sizeof(rs) / sizeof(const char*);
				vector<result> data(num_result_to_fill);
				snakeandadder1 a(N, l, s, NUMROUND, data);
				print(N,rs, NUMROUND, data, l, s);
		}
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() { //mainSL1
#ifdef _WIN32
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
		testbed();
		cout << "Your final marks = " << marks << endl ;
		cout << "upload only snakeandadder1.cpp  snakeandadder1.h as a zip file" << endl;
		cout << "If you upload any other files, or program crashes, you will get only 70" << endl;
		cout << "If you like this calss can you please writr review at \n";
		cout << "https://www.linkedin.com/in/jagadeesh-vasudevamurthy-6796591/" << endl;
		return 0;
}

//EOF

