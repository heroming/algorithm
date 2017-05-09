/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/11 06:51:20
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

const int maxn = 100010;
const int inf = 0x7FFFFFFF;

int n, m, s, t;
int dis[maxn];
bool inq[maxn];
vpint g[maxn];

int spfa() {
    clr(inq, 0);
    form (i, 1, n) dis[i] = inf;
    queue<int> que;
    dis[s] = 0;
    inq[s] = 1;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        inq[u] = 0;
        rep (it, g[u]) {
            int v = it.px, w = it.py;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (!inq[v]) {
                    inq[v] = 1;
                    que.push(v);
                }
            }
        }
    }
    return dis[t];
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int u, v, w;
    forn (i, m) {
       scanf("%d%d%d", &u, &v, &w);
       g[u].pb({v, w});
       g[v].pb({u, w});
    }
    printf("%d\n", spfa());
    return 0;
}
