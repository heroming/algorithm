#include <vector>
#include <list>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

#define px first
#define py second
#define pb push_back
#define mp make_pair
#define pque priority_queue
#define lowbit(x) ((x) & -(x))
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define clr(v, e) memset(v, e, sizeof(v))
#define rep(it, v) for (auto it : v)
#define forn(i, n) for (int i = 0; i < (n); ++ i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; -- i)
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define rform(i, a, b) for (int i = (b); i >= (a); -- i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

class LongJump2 {
public:
	int countNewLeaders(int, vector <int>);
};

int LongJump2::countNewLeaders(int N, vector <int> v) {
    int leader = -1, len = -1, ans = 0;
	forv (i, v) {
        int k = i % N;
        if (v[i] > len) {
            if (leader != k) {
                ++ ans;
                leader = k;
            }
            len = v[i];
        }
    }
    return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	LongJump2 *obj;
	int answer;
	obj = new LongJump2();
	clock_t startTime = clock();
	answer = obj->countNewLeaders(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	vector <int> p1;
	int p2;

	{
	// ----- test 0 -----
	p0 = 1;
	int t1[] = {812,780,815};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 2;
	int t1[] = {0,0,0,0,0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 2;
	int t1[] = {810,811,812,813,814,815};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 3;
	int t1[] = {800,10,20,810,30,40,50,830,830};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// 
// You are watching the finals of a long jump competition.
// There are N contestants with bib numbers 1 through N.
// There will be three rounds of jumps.
// In each round, the contestants jump in the order from 1 to N.
// 
// 
// At the beginning, there is no leader.
// After each jump, if the jump is strictly longer than each of the previous jumps and the contestant who made the jump isn't the current leader, the contestant becomes the leader.
// 
// 
// You are given the int N.
// You are also given the vector <int> jumpLengths that contains the lengths of all 3N jumps in the competition, in the order in which they were performed.
// Compute how many times some contestant became the leader during the competition.
// 
// 
// DEFINITION
// Class:LongJump2
// Method:countNewLeaders
// Parameters:int, vector <int>
// Returns:int
// Method signature:int countNewLeaders(int N, vector <int> jumpLengths)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 50, inclusive.
// -jumpLengths will contain exactly 3*N elements.
// -Each element of jumpLengths will be between 0 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// {812, 780, 815}
// 
// Returns: 1
// 
// There is a single contestant. When they made their first jump, they became the leader. As there was nobody else to overtake them, the only contestant then remained the leader for the rest of the competition. Note that the last jump did not change the leader, even though it was longer than the first one.
// 
// 1)
// 2
// {0, 0, 0, 0, 0, 0}
// 
// Returns: 1
// 
// The first jump of length 0 is enough to become the leader. The subsequent jumps of length 0 are not enough to overtake the leader.
// 
// 2)
// 2
// {810, 811, 812, 813, 814, 815}
// 
// Returns: 6
// 
// 
// 
// 3)
// 3
// {800, 10, 20, 810, 30, 40, 50, 830, 830}
// 
// Returns: 2
// 
// 
// Round 1, jump 1: contestant #1 jumps 800 and becomes the leader.
// Round 2, jump 1: contestant #1 jumps 810, but she is already the leader, so the leader does not change.
// Round 3, jump 2: contestant #2 jumps 830 and overtakes contestant #1 to become the new leader.
// Round 3, jump 3: contestant #3 also jumps 830, but contestant #2 remains the leader - you need to jump strictly more than the previous leader in order to overtake them.
// 
// 
// 
// END KAWIGIEDIT TESTING










//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
