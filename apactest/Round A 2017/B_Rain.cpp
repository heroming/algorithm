/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/7/10 12:57:25
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
typedef __int128 llint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int N = 4;
const int maxn = 55;
const int inf = 1000;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int t, n, m;
int h[maxn][maxn];
bool vis[maxn][maxn];

inline bool outer(const int x, const int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

bool dfs(const int x, const int y, const int w) {
    vis[x][y] = 0;
    forn (k, N) {
        int a = x + dx[k];
        int b = y + dy[k];
        if (outer(a, b)) return 0;
        if (vis[a][b]) {
            if (w <= h[a][b]) continue;
            if (! dfs(a, b, w)) return 0;
        }
    }
    return 1;
}

int main() {
    freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    form (cas, 1, t) {
        printf("Case #%d: ", cas);
        scanf("%d%d", &n, &m);
        forn (i, n) forn (j, m) {
            scanf("%d", &h[i][j]);
        }
        int ans = 0;
        forn (i, n) forn (j, m) {
            int l = h[i][j], r = inf;
            while (l <= r) {
                int mi = (l + r) >> 1;
                clr(vis, 1);
                if (dfs(i, j, mi)) {
                    l = mi + 1;
                } else {
                    r = mi - 1;
                }
            }
            if (h[i][j] < r) {
                ans += r - h[i][j];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
