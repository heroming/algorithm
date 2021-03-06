/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/10 05:07:26
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

const int maxn = 110;

vint g[maxn];
int s[maxn];
int n, m, w[maxn];
int dp[maxn][maxn];

void dfs(const int u, const int p) {
    rep (v, g[u]) {
        if (v == p) continue;
        dfs(v, u);
        form (i, 1, m) s[i] = dp[u][i];
        for (int k = 1; k <= m; ++ k) {
            for (int i = 0; i <= k; ++ i) {
                dp[u][k] = max(dp[u][k], s[i] + dp[v][k - i]);
            }
        }
    }
    rform (i, 1, m) {
        dp[u][i] = dp[u][i - 1] + w[u];
    }
}

int main() {
    scanf("%d%d", &n, &m);
    form (i, 1, n) scanf("%d", &w[i]);
    int u, v;
    form (i, 2, n) {
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    printf("%d\n", dp[1][m]);
    return 0;
}
