/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/15 03:16:38
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
const int maxm = 5010;
const int inf = 0xFFFAFFF;

int t, n, m, p;
int dp[maxm][2];
int dis[maxn][maxn];
int a[maxm], b[maxm];

int main() {
    freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    form (cas, 1, t) {
        scanf("%d%d%d", &n, &m, &p);
        int u, v, w;
        forn (i, maxn) forn (j, maxn) dis[i][j] = (i == j ? 0 : inf);
        forn (i, m) {
            scanf("%d%d%d", &u, &v, &w);
            dis[u][v] = dis[v][u] = min(dis[u][v], w);
        }
        form (k, 1, n) form (i, 1, n) form (j, 1, n) {
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
        bool valid = 1;
        a[0] = b[0] = 1;
        form (i, 1, p) {
            scanf("%d%d", &a[i], &b[i]);
            if (dis[a[i]][b[i]] == inf) valid = 0;
        }
        if (valid) {
            forn (i, maxm) dp[i][0] = dp[i][1] = inf;
            dp[0][0] = 0;
            form (k, 1, p) {
                int y0x1 = dis[b[k - 1]][a[k]];
                int x1y1 = dis[a[k]][b[k]];
                int y0y1 = dis[b[k - 1]][b[k]];
                int x1x2 = dis[a[k]][a[k + 1]];
                int y0x2 = dis[b[k - 1]][a[k + 1]];
                int x2y1 = dis[a[k + 1]][b[k]];
                dp[k][0] = min(dp[k - 1][0] + y0x1 + x1y1, dp[k - 1][1] + y0y1);
                if (k < p) dp[k][1] = min(dp[k - 1][0] + y0x1 + x1x2 + x2y1, dp[k - 1][1] + y0x2 + x2y1);
            }
            printf("Case #%d: %d\n", cas, dp[p][0]);
        } else {
            printf("Case #%d: %d\n", cas, -1);
        }
    }
    return 0;
}
