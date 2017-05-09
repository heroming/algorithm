/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/12 10:41:28
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
#define all(v) ((v).begin(), (v).end())
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

const int maxn = 10010;

vpint g[maxn];
int dis[maxn];
int n, m, k, t;

bool valid(const int x) {
    clr(dis, -1);
    queue<int> que;
    dis[1] = 0;
    que.push(1);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        rep (it, g[u]) {
            int v = it.py, w = it.px;
            if (w > x) break;
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                if (dis[v] < k) que.push(v);
            }
        }
    }
    return dis[t] != -1 && dis[t] <= k;
}

int solve(const int w) {
    int l = 1, r = w;
    while (l <= r) {
        int mi = (l + r) >> 1;
        if (valid(mi)) {
            r = mi - 1;
        } else {
            l = mi + 1;
        }
    }
    return l;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &t);
    int u, v, w, ma = 0;
    forn (i, m) {
        scanf("%d%d%d", &u, &v, &w);
        g[u].pb({w, v});
        g[v].pb({w, u});
        ma = max(ma, w);
    }
    form (u, 1, n) sort(g[u].begin(), g[u].end());
    printf("%d\n", solve(ma));
    return 0;
}
