/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/14 06:43:35
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

int n, m;
bool bridge[maxn];
int idx = 0, low[maxn], dfn[maxn];
vint g[maxn];
vint vertex;
vpint edge;

void tarjan(const int u, const int p) {
    low[u] = dfn[u] = ++ idx;
    int child = 0;
    rep (v, g[u]) {
        if (dfn[v] == -1) {
            ++ child;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if ((p == 0 && child > 1) || (p > 0 && low[v] >= dfn[u])) {
                bridge[u] = 1;
            }
            if (low[v] > dfn[u]) {
                edge.pb({min(u, v), max(u, v)});
            }
        } else if (v != p) {
            low[u] = min(low[u], dfn[v]);
        }
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
    clr(bridge, 0);
    tarjan(1, 0);
    form (u, 1, n) if (bridge[u]) vertex.pb(u);
    if (vertex.empty()) {
        printf("Null\n");
    } else {
        sort(all(vertex));
        forv (i, vertex) {
            if (i) printf(" ");
            printf("%d", vertex[i]);
        }
        printf("\n");
    }
    sort(all(edge));
    rep (it, edge) {
        printf("%d %d\n", it.px, it.py);
    }
    return 0;
}
