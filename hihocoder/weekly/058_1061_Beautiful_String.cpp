/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/16 10:01:32
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

vint v;
int t, n;
string s;

bool beautiful() {
    int cnt = 1;
    form (i, 1, n) {
        if (s[i] != s[i - 1] || i == n) {
            if (sz(v) == 2) {
                if (v[1] <= cnt && v[1] <= v[0]) return 1;
            }
            if (i == n) return 0;
            if (s[i] == s[i - 1] + 1) {
                if (sz(v) < 2) {
                    v.pb(cnt);
                } else {
                    v[0] = v[1], v[1] = cnt;
                }
            } else {
                v.clear();
            }
            cnt = 0;
        }
        ++ cnt;
    }
    return 0;
}

int main() {
    cin >> t;
    while (t --) {
        v.clear();
        cin >> n >> s;
        printf("%s\n", beautiful() ? "YES" : "NO");
    }
    return 0;
}
