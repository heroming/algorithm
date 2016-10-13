/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/9/30 22:50:54
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
#include <fstream>
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

const int maxn = 5010;

vint ans;
int n, m, t;
vpint maps[maxn];
vpint vmaps[maxn];
int dp[maxn][maxn];

void dfs(const int k, const int u) {
    forv (i, maps[u]) {
        int v = maps[u][i].px, w = maps[u][i].py;
        if (dp[v][k] < dp[u][k - 1] - w) {
            dp[v][k] = dp[u][k - 1] - w;
            dfs(k + 1, v);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &t);
    int u, v, w, k;
    forn (i, m) {
        scanf("%d%d%d", &u, &v, &w);
        maps[u].pb({v, w});
        vmaps[v].pb({u, w});
    }
    clr(dp, -1);
    dp[1][0] = t;
    dfs(1, 1);
    u = n, k = 0;
    forn (i, n) if (dp[n][i] != -1) k = i;
    ans.pb(n);
    while (u != 1) {
        forv (i, vmaps[u]) {
            int v = vmaps[u][i].px, w = vmaps[u][i].py;
            if (dp[u][k] + w == dp[v][k - 1]) {
                u = v;
                ans.pb(v);
                break;
            }
        }
        -- k;
    }
    reverse(all(ans));
    printf("%d\n", sz(ans));
    rep (it, ans) printf("%d ", it);
    return 0;
}
