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

class SelfDescFind {
public:
	string construct(vector <int>);
};

const int N = 10;

string ans;
int exist, n, c[N], s[N];

void dfs(const int k, const int w, const vint & d) {
    if (k == sz(d)) {
        if (w == 0) {
            for (int i = 0; i < N; ++ i) {
                if (c[i] != s[i]) {
                    return;
                }
            }
            vstr v;
            string x = "00";
            for (int i = 0; i < N; ++ i) {
                if (c[i]) {
                    x[0] = c[i] + '0';
                    x[1] = i + '0';
                    v.pb(x);
                }
            }
            sort(all(v));
            string ret = "";
            for (auto e : v) {
                ret += e;
            }
            if (exist) {
                if (ret < ans) {
                    ans = ret;
                }
            } else {
                exist = 1;
                ans = ret;
            }
        }
        return;
    }
    for (int i = 1; i <= w && i < N; ++ i) {
        c[d[k]] = i;
        ++ s[d[k]];
        ++ s[i];
        dfs(k + 1, w - i, d);
        -- s[i];
        -- s[d[k]];
    }
}

string SelfDescFind::construct(vector<int> d) {
    const string EMPTY = "";

    n = sz(d);
    sort(all(d));

    clr(c, 0);
    clr(s, 0);
    exist = 0;
    ans = EMPTY;
    dfs(0, sz(d) << 1, d);

    return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	SelfDescFind *obj;
	string answer;
	obj = new SelfDescFind();
	clock_t startTime = clock();
	answer = obj->construct(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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

	vector <int> p0;
	string p1;

	{
	// ----- test 0 -----
	int t0[] = {1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "22";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {0,1,3,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "10143133";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {0,1,2,4,5,6,8,9};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	int t0[] = {0,1,2,3,5,6,8,9};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "1016181923253251";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	int t0[] = {4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
// The number 31143310 is self-describing because we can read it as the statement "this number contains three '1's, one '4's, three '3's, and one '0'", and that statement correctly describes the whole number.
// 
// 
// More formally, a number is called self-describing if it satisfies the following:
// 
// 
// It has an even number of digits. Below, we will label the individual digits a[0], b[0], a[1], b[1], ... from the left to the right.
// The digits b[i] are all distinct.
// For each valid i, the number contains exactly a[i] copies of the digit b[i].
// The number does not contain any other digits, except for those described by the statements mentioned above.
// 
// 
// You are given the vector <int> digits.
// Find the smallest self-describing number N such that the digits that appear in N are precisely the digits in digits.
// If such a number exists, return a string with its decimal representation.
// Otherwise, return an empty string
// 
// 
// DEFINITION
// Class:SelfDescFind
// Method:construct
// Parameters:vector <int>
// Returns:string
// Method signature:string construct(vector <int> digits)
// 
// 
// NOTES
// -Watch out for integer overflow.
// 
// 
// CONSTRAINTS
// -digits will contain between 1 and 10 elements, inclusive.
// -Each element of digits will be between 0 and 9, inclusive.
// -The elements of digits will form a strictly increasing sequence.
// 
// 
// EXAMPLES
// 
// 0)
// {1}
// 
// Returns: ""
// 
// 
// 
// 1)
// {2}
// 
// Returns: "22"
// 
// The smallest self-describing number is 22. It contains two '2's, and it says about itself that it contains two '2's.
// 
// 2)
// {0,1,3,4}
// 
// Returns: "10143133"
// 
// 
// 
// 3)
// {0,1,2,4,5,6,8,9}
// 
// Returns: ""
// 
// 
// 
// 4)
// {0,1,2,3,5,6,8,9}
// 
// Returns: "1016181923253251"
// 
// 
// 
// 5)
// {4}
// 
// Returns: ""
// 
// Note that 4444 is not a valid self-describing number.
// 
// END KAWIGIEDIT TESTING










//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!