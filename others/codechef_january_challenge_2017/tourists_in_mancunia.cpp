/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/11 09:58:36
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

const int maxn = 100010;
const int maxm = 200010;

int n, m;
int a[maxm], b[maxm];
int din[maxn], dout[maxn];

bool vis[maxm];
vpint g[maxn];

void dfs(const int u) {
    vis[u] = 0;
    rep (it, g[u]) {
        int v = it.px;
        if (vis[v]) dfs(v);
    }
}

bool valid() {
    form (i, 1, n) {
        int x = din[i] + dout[i];
        if (x & 1) return 0;
    }
    clr(vis, 1);
    dfs(1);
    form (i, 1, n) if (vis[i]) return 0;
    return 1;
}

void solve(const int u) {
    while (!g[u].empty()) {
        pint it = g[u].back();
        g[u].pop_back();
        int v = it.px, id = it.py;
        if (vis[id]) continue;
        if (a[id] != u) swap(a[id], b[id]);
        vis[id] = 1;
        solve(v);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    form (i, 1, m) {
        scanf("%d%d", &a[i], &b[i]);
        ++ dout[a[i]];
        ++ din[b[i]];
        g[a[i]].pb({b[i], i});
        g[b[i]].pb({a[i], i});
    }
    if (valid()) {
        printf("YES\n");
        clr(vis, 0);
        solve(1);
        form (i, 1, m) printf("%d %d\n", a[i], b[i]);
    } else {
        printf("NO\n");
    }
    return 0;
}
