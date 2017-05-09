/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/12 06:57:15
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

int n, m;
vint g[maxn];
bool vis[maxn];
int match[maxn];

bool dfs(const int u) {
    rep (v, g[u]) {
        if (vis[v]) {
            vis[v] = 0;
            if (match[v] == -1 || dfs(match[v])) {
                match[u] = v;
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    forn (i, m) {
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans = 0;
    clr(match, -1);
    form (i, 1, n) {
        if (match[i] != -1) continue;
        clr(vis, 1);
        vis[i] = 0;
        if (dfs(i)) ++ ans;
    }
    printf("%d\n", ans);
    return 0;
}
