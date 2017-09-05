/*
 * Author:heroming
 * File:1006.cpp
 * Time:2017/08/13 02:24:18
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
const int inf = 2000000010;

vint v;
int n, m, ln, s, e;
int a[maxn], b[maxn];

int sum[maxn << 3];
bool flag[maxn << 3];

int find(const int x) {
    int l = 0, r = ln;
    while (l <= r) {
        int mi = (l + r) >> 1;
        if (v[mi] == x) return mi;
        if (v[mi] < x) {
            l = mi + 1;
        } else {
            r = mi - 1;
        }
    }
    return 0;
}

void build(const int k, const int l, const int r) {
    sum[k] = 0;
    flag[k] = 0;
    if (l + 1 >= r) return;
    int mi = (l + r) >> 1;
    build(k << 1, l, mi);
    build(k << 1 | 1, mi, r);
}

void update(const int k, const int l, const int r) {
    if (s <= l && r <= e) {
        flag[k] = 1;
        return;
    }
    int mi = (l + r) >> 1;
    if (e <= mi) {
        update(k << 1, l, mi);
    } else if (mi <= s) {
        update(k << 1 | 1, mi, r);
    } else {
        update(k << 1, l, mi);
        update(k << 1 | 1, mi, r);
    }
}

void push_down(const int k, const int l, const int r) {
    if (l + 1 >= r) {
        if (flag[k]) sum[k] = v[r] - v[l];
    } else {
        int mi = (l + r) >> 1;
        if (flag[k]) flag[k << 1] = flag[k << 1 | 1] = 1;
        push_down(k << 1, l, mi);
        push_down(k << 1 | 1, mi, r);
        sum[k] = sum[k << 1] + sum[k << 1 | 1];
    }
}

int query(const int k, const int l, const int r) {
    if (sum[k] == 0) return 0;
    if (s <= l && r <= e) return sum[k];
    int mi = (l + r) >> 1;
    if (e <= mi) {
        return query(k << 1, l, mi);
    } else if (mi <= s) {
        return query(k << 1 | 1, mi, r);
    } else {
        return query(k << 1, l, mi) + query(k << 1 | 1, mi, r);
    }
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        v.clear();
        forn (i, n) {
            scanf("%d%d", &a[i], &b[i]);
            v.pb(a[i]);
            v.pb(b[i] + 1);
        }
        v.pb(0);
        v.pb(inf);
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        ln = sz(v) - 1;
        build(1, 1, ln);
        forn (i, n) {
            s = find(a[i]);
            e = find(b[i] + 1);
            update(1, 1, ln);
        }
        push_down(1, 1, ln);

        int ans = 0;
        forv (st, v) {
            s = st, e = st + 1;
            if (st == ln || query(1, 1, ln) == 0) continue;
            int l = st, r = ln;
            while (l <= r) {
                int mi = (l + r) >> 1;
                s = st, e = mi;
                int w = query(1, 1, ln);
                if (w + m < v[mi] - v[st]) {
                    r = mi - 1;
                } else {
                    l = mi + 1;
                }
            }
            s = st, e = r;
            int cover = query(1, 1, ln);
            ans = max(ans, cover + m);
        }
        printf("%d\n", ans);
    }
    return 0;
}
