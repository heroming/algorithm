/*
 * Author:heroming
 * File:d.cpp
 * Time:2017/05/05 12:01:33
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

const int maxn = 300010;

int n, m, s;
vint g[maxn];
vint ve[maxn];

int color[maxn];
bool vis[maxn];
int sol[maxn];

void dfs(const int u) {
    vis[u] = 0;
    forv (i, ve[u]) {
        int c = ve[u][i];
        if (color[c] != -1) sol[color[c]] = u;
    }
    int k = 1;
    forv (i, ve[u]) {
        int c = ve[u][i];
        if (color[c] == -1) {
            while (sol[k] == u) ++ k;
            sol[k] = u;
            color[c] = k;
        }
    }
    forv (i, g[u]) {
        int v = g[u][i];
        if (vis[v]) dfs(v);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int a, b;
    form (k, 1, n) {
        scanf("%d", &s);
        forn (i, s) {
            scanf("%d", &a);
            ve[k].pb(a);
        }
    }
    form (k, 2, n) {
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    clr(vis, 1);
    clr(color, -1);
    form (i, 1, n) if (vis[i]) dfs(i);
    int ans = 0;
    form (i, 1, m) ans = max(ans, color[i]);
    if (ans == 0) ans = 1;
    form (i, 1, m) if (color[i] == -1) color[i] = 1;
    printf("%d\n", ans);
    form (i, 1, m) {
        if (i > 1) printf(" ");
        printf("%d", color[i]);
    }
    printf("\n");
    return 0;
}
