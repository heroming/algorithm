/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/12 11:02:43
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

vint v;
int n, m, w[maxn];
int bit[maxn];

inline int lowbit(const int x) {
    return x & -x;
}

void update(int x, const int e) {
    while (x <= m) {
        bit[x] += e;
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
    int l = 0, r = m - 1;
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
    form (i, 1, n) {
        scanf("%d", &w[i]);
        v.pb(w[i]);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    m = sz(v);

    lint ans = 0;
    form (i, 1, n) {
        int id = find(w[i]);
        update(id, 1);
        ans += i - query(id);
    }
    printf("%lld\n", ans);
    return 0;
}
