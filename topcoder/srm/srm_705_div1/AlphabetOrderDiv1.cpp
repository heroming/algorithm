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
#include <unordered_map>
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

class AlphabetOrderDiv1 {
public:
	string isOrdered(vector <string>);
};

const int maxn = 32;

bool dp[maxn][maxn];

bool valid() {
    forn (k, maxn) {
        int idx = -1;
        forn (i, maxn) {
            int a = 0, b = 0;
            forn (j, maxn) {
                if (dp[j][i]) ++ a;
                if (dp[i][j]) ++ b;
            }
            if (a > 0 && b == 0) {
                idx = i;
                break;
            }
        }
        forn (i, maxn) dp[i][idx] = 0;
    }
    forn (i, maxn) forn (j, maxn) if (dp[i][j]) return 0;
    return 1;
}

string AlphabetOrderDiv1::isOrdered(vector<string> words) {
    clr(dp, 0);
    rep (s, words) {
        for (int i = 1; i < sz(s); ++ i) {
            int u = s[i - 1] - 'a';
            int v = s[i] - 'a';
            if (u != v) dp[u][v] = 1;
        }
    }
    return valid() ? "Possible" : "Impossible";
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	AlphabetOrderDiv1 *obj;
	string answer;
	obj = new AlphabetOrderDiv1();
	clock_t startTime = clock();
	answer = obj->isOrdered(p0);
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
	
	vector <string> p0;
	string p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"single","round","match"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Possible";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"topcoder","topcoder"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Impossible";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"algorithm","contest"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Impossible";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"pink","floyd"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Possible";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"gimnasia","y","esgrima","la","plata"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Impossible";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
// The ancient civilization of Nlogonia used the same 26 letters as modern English: 'a'-'z'.
// However, we do not know the order in which these letters appeared in the Nlogonian alphabet.
// 
// One particular custom in Nlogonia was that in a good word the letters appear in non-decreasing order.
// For example, in English the word "ciel" is not a good word because in the alphabet 'i' is after 'e'.
// The word "ceil" is a good word because 'c' <= 'e' <= 'i' <= 'l'.
// 
// You are given the vector <string> words.
// Each element of words is a nonempty string of lowercase English letters.
// Return "Possible" if it is possible that all elements of words were good words in Nlogonian, and "Impossible" otherwise.
// 
// In other words, return "Possible" if and only if there is at least one possible Nlogonian alphabet such that the letters of each word in words are in non-decreasing alphabetical order.
// 
// DEFINITION
// Class:AlphabetOrderDiv1
// Method:isOrdered
// Parameters:vector <string>
// Returns:string
// Method signature:string isOrdered(vector <string> words)
// 
// 
// CONSTRAINTS
// -words has between 2 and 100 elements inclusive.
// -The size of each element of words will be between 1 and 100 inclusive.
// -Elements of words contains only English lowercase letters from 'a' to 'z'.
// 
// 
// EXAMPLES
// 
// 0)
// {"single","round","match"}
// 
// Returns: "Possible"
// 
// A possible Nlogonian alphabet would be "bfjkmapqrositchundglevwxyz"
// 
// 1)
// {"topcoder","topcoder"}
// 
// Returns: "Impossible"
// 
// The word "topcoder" can never be a good word.
// The character 'o' cannot be both before 'p' and after 'p' in the alphabet.
// 
// 2)
// {"algorithm", "contest"}
// 
// Returns: "Impossible"
// 
// 
// 
// 3)
// {"pink","floyd"}
// 
// Returns: "Possible"
// 
// 
// 
// 4)
// {"gimnasia","y","esgrima","la","plata"}
// 
// Returns: "Impossible"
// 
// 
// 
// END KAWIGIEDIT TESTING









//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
