/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/14 04:03:25
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

const int maxn = 10010;

int n, m;
int d[maxn];
vint g[maxn];

int dfs(const int u) {
    int w = 1;
    rep (v, g[u]) {
        if (d[v]) {
            d[v] = 0;
            w += dfs(v);
        }
    }
    return w;
}

bool connect() {
    clr(d, 1);
    bool part = 0;
    form (i, 1, n) {
        int x = dfs(i);
        if (x > 1) {
            if (part) return 0;
            part = 1;
        }
    }
    return 1;
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    forn (i, m) {
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
        ++ d[u]; ++ d[v];
    }
    int odd = 0;
    form (i, 1, n) {
        if (d[i] & 1) ++ odd;
    }
    printf("%s\n", (connect() && odd <= 2) ? "Full" : "Part");
    return 0;
}
