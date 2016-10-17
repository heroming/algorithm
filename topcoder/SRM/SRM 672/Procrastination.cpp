#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
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
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int,int> pint;
typedef vector<long long> vlint;

class Procrastination {
public:
	long long findFinalAssignee(long long);
};

const lint maxn = 200000;
const lint maxm = 50000;

long long Procrastination::findFinalAssignee(long long n) {
    for (lint i = 2; i <= maxn; ++ i) {
        if (n < i * 2) break;
        if (n % i == 0) {
            ++ n;
        } else if ((n - 1) % i == 0) {
            n -= 1;
        }
    }
    lint s = maxn;
    while (true) {
        lint w = 1e12;
        for (lint k = 2; k <= maxm; ++ k) {
            if (n % k == 0) {
                lint e = n / k;
                if (s < e) {
                    w = min(w, e);
                }
            } else if ((n - 1) % k == 0) {
                lint e = (n - 1) / k;
                if (s < e) {
                    w = min(w, e);
                }
            }
        }
        if (n < w * 2) break;
        if (n % w == 0) {
            ++ n;
        } else {
            -- n;
        }
        s = w;
    }
    return n;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, long long p0, bool hasAnswer, long long p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	Procrastination *obj;
	long long answer;
	obj = new Procrastination();
	clock_t startTime = clock();
	answer = obj->findFinalAssignee(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	
	long long p0;
	long long p1;
	
	{
	// ----- test 0 -----
	p0 = 3ll;
	p1 = 3ll;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 8ll;
	p1 = 11ll;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 20ll;
	p1 = 20ll;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 196248ll;
	p1 = 196259ll;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 5587021440ll;
	p1 = 5587021440ll;
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
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!