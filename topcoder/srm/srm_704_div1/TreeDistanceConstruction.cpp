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

class TreeDistanceConstruction {
public:
	vector <int> construct(vector <int>);
};

vector<int> TreeDistanceConstruction::construct(vector<int> d) {
    const int n = sz(d);
    const int maxn = 55;
    vint v[maxn];
    int m = d[0];
    forv (i, d) {
        v[d[i]].pb(i);
        m = max(m, d[i]);
    }
    vint no, line, ans;
    form (i, 0, m) {
        int x = max(i, m - i);
        if (v[x].empty()) return no;
        line.pb(v[x].back());
        v[x].pop_back();
    }
    for (int i = 0; i + 1 < sz(line); ++ i) {
        ans.pb(line[i]);
        ans.pb(line[i + 1]);
    }
    forn (i, n) {
        if (! v[i].empty()) {
            if (i <= ((m + 1) >> 1)) return no;
            rep (it, v[i]) {
                ans.pb(it);
                ans.pb(line[i - 1]);
            }
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	TreeDistanceConstruction *obj;
	vector <int> answer;
	obj = new TreeDistanceConstruction();
	clock_t startTime = clock();
	answer = obj->construct(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
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
	vector <int> p1;
	
	{
	// ----- test 0 -----
	int t0[] = {3,2,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,1,0,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,2,2,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,1,0,2,0,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1.clear() /*{}*/;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1.clear() /*{}*/;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
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
// In a tree, the distance d(u,v) between vertices u and v is the smallest number of edges you need to traverse in order to get from u to v.
// 
// 
// The eccentricity of a vertex u is the maximum of all d(u,v). In other words, the eccentricity of u is the distance between u and the vertex that is the farthest away from u.
// 
// 
// You are given a vector <int> d with n elements.
// Construct any tree with the following properties:
// 
// The tree has n vertices, numbered 0 through n-1.
// For each i, the eccentricity of vertex i is exactly d[i].
// 
// 
// If there is no such tree, return an empty vector <int>.
// If there are multiple such trees, you may output any of them.
// If your tree contains the edges a[0] - b[0], a[1] - b[1], ..., a[n-2] - b[n-2], return the following vector <int>:
// {a[0], b[0], a[1], b[1], ..., a[n-2], b[n-2]}.
// Note that the return value should contain exactly 2*(n-1) elements.
// 
// DEFINITION
// Class:TreeDistanceConstruction
// Method:construct
// Parameters:vector <int>
// Returns:vector <int>
// Method signature:vector <int> construct(vector <int> d)
// 
// 
// CONSTRAINTS
// -d will contain between 2 and 50 elements, inclusive.
// -Each element in d will be between 1 and |d|-1, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {3,2,2,3}
// 
// Returns: {1, 2, 1, 0, 2, 3 }
// 
// The return value shown in this example describes the chain 0 - 1 - 2 - 3.
// This is one of multiple correct trees for this test case.
// 
// 1)
// {1,2,2,2}
// 
// Returns: {0, 1, 0, 2, 0, 3 }
// 
// In this case the only correct tree is a star with vertex 0 in the middle.
// 
// 2)
// {1,1,1,1}
// 
// Returns: { }
// 
// 
// 
// 3)
// {1,1,1}
// 
// Returns: { }
// 
// 
// 
// 4)
// {1,1}
// 
// Returns: {0, 1 }
// 
// 
// 
// END KAWIGIEDIT TESTING









//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
