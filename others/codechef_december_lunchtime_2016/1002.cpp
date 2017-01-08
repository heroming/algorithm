/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/12/31 10:10:22
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

const int maxn = 200010;

vint v;
int m, bit[maxn];
int n, h[maxn];

inline int lowbit(const int x) {
    return x & -x;
}

void add(int x, const int w) {
    while (x <= m) {
        bit[x] += w;
        x += lowbit(x);
    }
}

int query(int x) {
    int ret = 0;
    while (x) {
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

int find(const int x) {
    int l = 0, r = sz(v) - 1;
    while (l <= r) {
        int mi = (l + r) >> 1;
        if (v[mi] == x) return mi + 1;
        if (v[mi] < x) {
            l = mi + 1;
        } else {
            r = mi - 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    forn (i, n) {
        scanf("%d", &h[i]);
        v.pb(h[i]);
    }
    if (n == 1) {
        printf("%d\n", h[0]);
    } else {
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        m = sz(v) << 1;
        int k = 1;
        while (k < n) {
            int x = h[k - 1], y = 0;
            if (h[k - 1] < h[k]) {
                while (k < n && h[k - 1] < h[k]) ++ k;
                y = h[k - 1];
            } else {
                while (k < n && h[k] < h[k - 1]) ++ k;
                y = h[k - 1];
            }
            x = find(x), y = find(y);
            if (y < x) swap(x, y);
            add(x << 1, 1);
            add(y << 1 | 1, -1);
        }
        int ans = 0;
        form (i, 1, sz(v)) {
            int w = query(i << 1);
            if (ans <= w) ans = w;
        }
        printf("%d\n", ans);
        return 0;
    }
}
