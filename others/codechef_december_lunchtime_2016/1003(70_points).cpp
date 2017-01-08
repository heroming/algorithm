/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/12/31 11:30:44
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
#include <unordered_map>
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

struct node {
    int a, b, w;
    bool operator < (const node & x) const {
        return w < x.w;
    }
} no;

const int maxn = 2010;
const int inf = 0x7FFFFFFF;

int n, m, q;
int p[maxn];
vector<node> edge;

int dis[maxn];
int path[maxn];
int eu, ev, ew;
vint maps[maxn];
map<pint, int> dic;

int ori[maxn][maxn];

int find(const int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void bfs(const int s, const int t) {
    clr(path, 0);
    form (i, 1, n) dis[i] = inf;
    dis[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        if (u == t) break;
        rep (v, maps[u]) {
            if (dis[u] + 1 < dis[v]) {
                que.push(v);
                path[v] = u;
                dis[v] = dis[u] + 1;
            }
        }
    }
    ew = 0;
    int b = t;
    while (path[b]) {
        int a = path[b], bak = path[b];
        if (b < a) swap(a, b);
        int w = dic[{a, b}];
        if (ew < w) {
            eu = a, ev = b, ew = w;
        }
        b = bak;
    }
}

void remove_edge(const int u, const int v) {
    int idx = 0;
    forv (i, maps[u]) {
        if (maps[u][i] == v) {
            idx = i;
            break;
        }
    }
    int e = sz(maps[u]) - 1;
    if (idx < e) {
        swap(maps[u][idx], maps[u][e]);
    }
    maps[u].pop_back();
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    if (n <= 200 && m <= 2000) {
        forn (i, m) {
            scanf("%d%d%d", &no.a, &no.b, &no.w);
            if (no.b < no.a) swap(no.a, no.b);
            ori[no.a][no.b] = no.w;
            edge.pb(no);
        }
        int op, a, b;
        forn (i, q) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d", &a, &b);
                if (b < a) swap(a, b);
                forv (k, edge) {
                    if (edge[k].a == a && edge[k].b == b) {
                        edge[k].w = 0;
                    }
                }
            } else if (op == 2) {
                scanf("%d%d", &a, &b);
                if (b < a) swap(a, b);
                forv (k, edge) {
                    if (edge[k].a == a && edge[k].b == b) {
                        edge[k].w = ori[a][b];
                    }
                }
            } else {
                lint ans = 0;
                sort(all(edge));
                form (i, 1, n) p[i] = i;
                rep (it, edge) {
                    int a = find(it.a), b = find(it.b);
                    if (a != b) {
                        p[a] = b;
                        ans += it.w;
                    }
                }
                printf("%lld\n", ans);
            }
        }
    } else {
        forn (i, m) {
            scanf("%d%d%d", &no.a, &no.b, &no.w);
            if (no.b < no.a) swap(no.a, no.b);
            edge.pb(no);
        }
        lint ans = 0;
        sort(all(edge));
        form (i, 1, n) p[i] = i;
        rep (it, edge) {
            int a = find(it.a), b = find(it.b);
            if (a != b) {
                p[a] = b;
                ans += it.w;
                dic[{it.a, it.b}] = it.w;
                maps[it.a].pb(it.b);
                maps[it.b].pb(it.a);
            }
        }
        int op, a, b;
        forn (i, q) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d", &a, &b);
                if (b < a) swap(a, b);
                auto it = dic.find({a, b});
                if (it != dic.end()) {
                    ans -= it->second;
                    it->second = 0;
                } else {
                    bfs(a, b);
                    if (ew) {
                        ans -= ew;
                        dic.erase({eu, ev});
                        dic[{a, b}] = 0;
                        remove_edge(eu, ev);
                        remove_edge(ev, eu);
                        maps[a].pb(b);
                        maps[b].pb(a);
                    }
                }
            } else if (op == 2) {
                scanf("%d%d", &a, &b);
            } else {
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
