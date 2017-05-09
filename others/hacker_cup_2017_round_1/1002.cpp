/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/15 03:16:38
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

const int maxn = 64;

int t, n, r, ans;
bool vis[2][maxn];
int x[maxn], y[maxn];

inline void get_answer() {
    int ret = 0;
    forn (i, n) {
        if (vis[0][i] || vis[1][i]) ++ ret;
    }
    ans = max(ret, ans);
}

void left_lower(const int k, const int s) {
    clr(vis[s], 0);
    forn (i, n) {
        int dx = x[i] - x[k], dy = y[i] - y[k];
        if (dx >= 0 && dx <= r && dy >= 0 && dy <= r) vis[s][i] = 1;
    }
    if (s) get_answer();
}

void left_upper(const int k, const int s) {
    clr(vis[s], 0);
    forn (i, n) {
        int dx = x[i] - x[k], dy = y[k] - y[i];
        if (dx >= 0 && dx <= r && dy >= 0 && dy <= r) vis[s][i] = 1;
    }
    if (s) get_answer();
}

int main() {
    freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    form (cas, 1, t) {
        scanf("%d%d", &n, &r);
        forn (i, n) scanf("%d%d", &x[i], &y[i]);
        ans = 0;
        forn (i, n) {
            left_lower(i, 0);
            forn (j, n) {
                left_lower(j, 1);
                left_upper(j, 1);
            }
            left_upper(i, 0);
            forn (j, n) {
                left_lower(j, 1);
                left_upper(j, 1);
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
