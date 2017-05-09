/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/10 04:57:17
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

int n, ans;
vint g[maxn];
int a[maxn], b[maxn];

void dfs(const int u, const int p) {
    a[u] = b[u] = 0;
    rep (v, g[u]) {
        if (v != p) {
            dfs(v, u);
            if (a[u] < a[v] + 1) {
                b[u] = a[u];
                a[u] = a[v] + 1;
            } else if (b[u] < a[v] + 1) {
                b[u] = a[v] + 1;
            }
        }
    }
    ans = max(ans, a[u] + b[u]);
}

int main() {
    scanf("%d", &n);
    int u, v;
    form (i, 2, n) {
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}
