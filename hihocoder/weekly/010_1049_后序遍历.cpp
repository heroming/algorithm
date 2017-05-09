/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/10 04:17:19
 */
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
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

string a, b;

string dfs(const string & a, const string & b) {
    if (sz(a) <= 1) return a;
    int k = b.find(a[0]);
    string l = b.substr(0, k);
    string r = b.substr(k + 1);
    string x = a.substr(1, sz(l));
    string y = a.substr(1 + sz(l));
    return dfs(x, l) + dfs(y, r) + a[0];
}

int main() {
    cin >> a >> b;
    cout << dfs(a, b) << endl;
    return 0;
}
