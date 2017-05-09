/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/14 04:03:25
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

const int maxn = 1010;
const int maxm = 5010;

int n, m;
vpint g[maxn];
bool vis[maxm];
int idx, ans[maxm];

void dfs(const int u) {
    while (!g[u].empty()) {
        pint it = g[u].back();
        g[u].pop_back();
        int v = it.px, id = it.py;
        if (vis[id]) {
            vis[id] = 0;
            dfs(v);
        }
    }
    ans[idx ++] = u;
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    form (i, 1, m) {
        scanf("%d%d", &u, &v);
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    clr(vis, 1);
    dfs(1);
    forn (i, idx) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
