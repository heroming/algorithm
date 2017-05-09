/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/23 09:59:51
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

int t, n;
vpint v;

int main() {
    scanf("%d", &t);
    while (t --) {
        v.clear();
        scanf("%d", &n);
        int c, w;
        forn (i, n) {
            scanf("%d%d", &w, &c);
            v.pb({w, c});
        }
        sort(all(v), greater<pint>());
        lint ans = 0, val = 0;
        rep (it, v) {
            w = it.px, c = it.py;
            form (i, 1, c) {
                val += w;
                if (val <= 0) break;
                ans += val;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
