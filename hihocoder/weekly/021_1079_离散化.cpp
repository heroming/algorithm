/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/10 09:23:20
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
const int maxm = 800010;

vint ve;
bool vis[maxn];
int tree[maxm];
int n, m, a, b, ans;
int x[maxn], y[maxn];

int find(const int w) {
    int l = 0, r = m - 1;
    while (l <= r) {
        int mi = (l + r) >> 1;
        if (ve[mi] == w) return mi + 1;
        if (ve[mi] < w) {
            l = mi + 1;
        } else {
            r = mi - 1;
        }
    }
    return -1;
}

void update(const int v, const int l, const int r, const int w) {
    if (a <= l && r <= b) {
        tree[v] = w;
        return;
    }
    if (l + 1 == r) return;
    if (tree[v]) {
        tree[v << 1] = tree[v];
        tree[v << 1 | 1] = tree[v];
        tree[v] = 0;
    }
    int mi = (l + r) >> 1;
    if (b <= mi) {
        update(v << 1, l, mi, w);
    } else if (a >= mi) {
        update(v << 1 | 1, mi, r, w);
    } else {
        update(v << 1, l, mi, w);
        update(v << 1 | 1, mi, r, w);
    }
}

void query(const int v, const int l, const int r) {
    if (tree[v]) {
        ans += vis[tree[v]];
        vis[tree[v]] = 0;
        return;
    }
    if (l + 1 == r) return;
    int mi = (l + r) >> 1;
    query(v << 1, l, mi);
    query(v << 1 | 1, mi, r);
}

int main() {
    scanf("%d%d", &n, &a);
    form (i, 1, n) {
        scanf("%d%d", &x[i], &y[i]);
        ve.pb(x[i]);
        ve.pb(y[i]);
    }
    sort(all(ve));
    ve.erase(unique(all(ve)), ve.end());
    m = sz(ve);
    form (i, 1, n) {
        a = find(x[i]);
        b = find(y[i]);
        update(1, 1, m, i);
    }
    clr(vis, 1);
    query(1, 1, m);
    printf("%d\n", ans);
    return 0;
}
