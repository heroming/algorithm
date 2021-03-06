/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/14 07:45:56
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

int n, m, component;
int idx, dfn[maxn], low[maxn];
int top, sta[maxn];
int belong[maxn];
vint g[maxn];

void tarjan(const int u, const int p) {
    sta[++ top] = u;
    dfn[u] = low[u] = ++ idx;
    rep (v, g[u]) {
        if (dfn[v] == -1) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (v != p) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        vint vertex;
        ++ component;
        int v = 0, mi = maxn;
        do {
            v = sta[top --];
            vertex.pb(v);
            mi = min(mi, v);
        } while (v != u);
        rep (it, vertex) belong[it] = mi;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    forn (i, m) {
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    clr(dfn, -1);
    tarjan(1, 0);
    printf("%d\n", component);
    form (u, 1, n) {
        if (u != 1) printf(" ");
        printf("%d", belong[u]);
    }
    printf("\n");
    return 0;
}
