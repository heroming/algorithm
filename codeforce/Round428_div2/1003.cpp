/*
 * Author:heroming
 * File:1003.cpp
 * Time:2017/08/12 11:16:14
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

const int maxn = 100010;

int n;
vint maps[maxn];
double ans = 0.0;

void dfs(const int u, const int p, const double e, const int w) {
    int m = sz(maps[u]);
    if (p != -1) m -= 1;
    rep (v, maps[u]) if (v != p) {
        dfs(v, u, e / m, w + 1);
    }
    if (m == 0) ans += e * w;
}

int main() {
    scanf("%d", &n);
    int a, b;
    form (k, 2, n) {
        scanf("%d%d", &a, &b);
        maps[a].pb(b);
        maps[b].pb(a);
    }
    dfs(1, -1, 1.0, 0);
    printf("%.8lf\n", ans);
    return 0;
}
