/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/7/10 16:42:46
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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct Grid {
    int x, y, w;
    Grid() {}
    Grid(int a, int b, int c) : x(a), y(b), w(c) {}
    bool operator < (const Grid & g) const {
        return g.w < w;
    }
};

int t, n, m;
int h[maxn][maxn];
bool vis[maxn][maxn];

inline bool valid(const int x, const int y) {
    return 0 <= x && x < n && 0 <= y && y < m && vis[x][y];
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
        clr(vis, 1);
        priority_queue<Grid> que;
        forn (i, n) {
            vis[i][0] = vis[i][m - 1] = 0;
            que.push(Grid(i, 0, h[i][0]));
            que.push(Grid(i, m - 1, h[i][m - 1]));
        }
        forn (i, m) {
            vis[0][i] = vis[n - 1][i] = 0;
            que.push(Grid(0, i, h[0][i]));
            que.push(Grid(n - 1, i, h[n - 1][i]));
        }
        int ans = 0;
        while (! que.empty()) {
            Grid g = que.top();
            que.pop();
            int x = g.x, y = g.y, w = g.w;
            forn (k, N) {
                int a = x + dx[k];
                int b = y + dy[k];
                if (valid(a, b)) {
                    vis[a][b] = 0;
                    if (h[a][b] < w) {
                        ans += w - h[a][b];
                        que.push(Grid(a, b, w));
                    } else {
                        que.push(Grid(a, b, h[a][b]));
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
