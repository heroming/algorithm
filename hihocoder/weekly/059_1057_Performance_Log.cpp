/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/16 10:32:04
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
typedef vector<string> vstr;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

struct Log {
    string a, b, c;
} lo;

vstr ans;
vector<Log> v;
stack<string> sta;
map<string, string> mp;

string get_time(const string & s, const string & t) {
    int x = (s[0] - '0') * 10 + (s[1] - '0');
    int y = (s[3] - '0') * 10 + (s[4] - '0');
    int z = (s[6] - '0') * 10 + (s[7] - '0');
    int a = (t[0] - '0') * 10 + (t[1] - '0');
    int b = (t[3] - '0') * 10 + (t[4] - '0');
    int c = (t[6] - '0') * 10 + (t[7] - '0');
    int rh = 0, rm = 0, rs = 0;
    rs += c - z; if (rs < 0) { rs += 60; -- rm; }
    rm += b - y; if (rm < 0) { rm += 60; -- rh; }
    rh += a - x;
    string ret = "00:00:00";
    ret[0] = rh / 10 + '0', ret[1] = rh % 10 + '0';
    ret[3] = rm / 10 + '0', ret[4] = rm % 10 + '0';
    ret[6] = rs / 10 + '0', ret[7] = rs % 10 + '0';
    return ret;
}

bool solve() {
    int n;
    cin >> n;
    forn (i, n) {
        cin >> lo.a >> lo.b >> lo.c;
        v.pb(lo);
    }
    form (i, 1, n - 1) {
        if (v[i - 1].b > v[i].b) return 0;
    }
    forn (i, n) {
        if (v[i].c == "START") {
            ans.pb(v[i].a);
            sta.push(v[i].a);
            mp[v[i].a] = v[i].b;
        } else {
            auto it = mp.find(v[i].a);
            if (it == mp.end() || sta.empty() || sta.top() != v[i].a) return 0;
            sta.pop();
            it->py = get_time(it->py, v[i].b);
        }
    }
    return sta.empty();
}

int main() {
    if (solve()) {
        rep (it, ans) {
            cout << it << " " << mp[it] << endl;
        }
    } else {
        cout << "Incorrect performance log" << endl;
    }
    return 0;
}
