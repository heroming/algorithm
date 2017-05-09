/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/14 08:09:43
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

const int maxn = 20010;

bool ins[maxn];
int n, m, w[maxn];
int top, sta[maxn];
int idx, low[maxn], dfn[maxn];
vint g[maxn];

int de[maxn];
int weight[maxn];
int part, belong[maxn];
vint maps[maxn];

void tarjan(const int u) {
    ins[u] = 1;
    sta[++ top] = u;
    low[u] = dfn[u] = ++ idx;
    rep (v, g[u]) {
        if (dfn[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++ part;
        int v = 0;
        do {
            v = sta[top --];
            ins[v] = 0;
            belong[v] = part;
        } while (v != u);
    }
}

void rebuild_graph() {
    form (i, 1, n) weight[belong[i]] += w[i];
    set<pint> edge;
    form (a, 1, n) {
        rep (b, g[a]) {
            int u = belong[a], v = belong[b];
            if (u != v && edge.find({u, v}) == edge.end()) {
                ++ de[v];
                maps[u].pb(v);
                edge.insert({u, v});
            }
        }
    }
}

int ans;

void dfs(const int u, const int e) {
    rep (v, maps[u]) dfs(v, e + weight[v]);
    ans = max(ans, e);
}

int main() {
    scanf("%d%d", &n, &m);
    form (i, 1, n) scanf("%d", &w[i]);
    int u, v;
    forn (i, m) {
        scanf("%d%d", &u, &v);
        g[u].pb(v);
    }
    clr(dfn, -1);
    tarjan(1);
    rebuild_graph();
    u = belong[1];
    dfs(u, weight[u]);
    printf("%d\n", ans);
    return 0;
}
