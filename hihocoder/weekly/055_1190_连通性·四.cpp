/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/14 10:40:26
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
const int maxm = 100010;

int n, m;
int top, sta[maxm];
int idx, low[maxn], dfn[maxn];
int part, belong[maxm], num[maxm];
vpint g[maxn];

void tarjan(const int u, const int p) {
    low[u] = dfn[u] = ++ idx;
    rep (it, g[u]) {
        int v = it.px, id = it.py;
        if (v == p) continue;
        if (dfn[v] == 0) {
            sta[++ top] = id;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v]) {
                int e = 0;
                num[++ part] = maxm;
                do {
                    e = sta[top --];
                    belong[e] = part;
                    num[part] = min(num[part], e);
                } while (e != id);
            }
        } else if (dfn[v] < dfn[u]) {
            sta[++ top] = id;
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    form (i, 1, m) {
        scanf("%d%d", &u, &v);
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    tarjan(1, 0);
    printf("%d\n", part);
    form (i, 1, m) {
        if (i > 1) printf(" ");
        printf("%d", num[belong[i]]);
    }
    printf("\n");
    return 0;
}
