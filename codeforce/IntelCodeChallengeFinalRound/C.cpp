/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/13 16:57:22
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

const int maxn = 100010;
const int maxe = 200020;
const lint inf = 0xFFFFFFFFFFFFFFFLL;

vpint point;
int n, m, k;
lint ans[maxn];
bool vis[maxn];
vint u[maxe], v[maxe];

inline bool stop(const int x, const int y) {
    if (y == 0) return vis[x];
    return (x == n && y == 0) || (x == n && y == m) || (x == 0 && y == m);
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    int x, y;
    forn (i, k) {
        ans[i] = inf;
        scanf("%d%d", &x, &y);
        u[x + y].pb(i);
        v[y - x + maxn].pb(i);
        point.pb({x, y});
    }
    x = y = 0;
    lint t = 0;
    int mx = 1, my = 1;
    do {
        if (y == 0) vis[x] = 1;
        int dx = (mx == 1 ? n - x : x);
        int dy = (my == 1 ? m - y : y);
        int dis = min(dx, dy);
        if (mx * my == 1) {
            int w = y - x + maxn;
            rep (it, v[w]) {
                ans[it] = min(ans[it], t + abs(point[it].px - x));
            }
            v[w].clear();
        } else {
            int w = x + y;
            rep (it, u[w]) {
                ans[it] = min(ans[it], t + abs(point[it].px - x));
            }
            u[w].clear();
        }
        t += dis;
        x += dis * mx;
        y += dis * my;
        if (x == 0 || x == n) mx *= -1;
        if (y == 0 || y == m) my *= -1;
    } while (! stop(x, y));
    forn (i, k) printf("%I64d\n", ans[i] == inf ? -1 : ans[i]);
    return 0;
}
