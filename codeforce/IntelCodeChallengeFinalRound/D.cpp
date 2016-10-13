/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/8 20:14:54
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
#include <fstream>
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
const int letter = 26;

int n, m;
char c[maxn];
int bit[maxn];
vint v[letter];
int ans[letter];

inline int lowbit(const int x) {
    return x & (-x);
}

void update(int x, const int w) {
    while (x <= n) {
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

bool finish() {
    form (i, m, n) {
        if (query(i) - query(i - m) == 0) return 0;
    }
    return 1;
}

void solve(const int k) {
    rep (idx, v[k]) {
        int w = query(idx);
        int l = 0, r = idx - 1;
        while (l <= r) {
            int mi = (l + r) >> 1;
            if (query(mi) + 1 == w) {
                r = mi - 1;
            } else {
                l = mi + 1;
            }
        }
        int s = l;
        l = idx, r = n;
        while (l <= r) {
            int mi = (l + r) >> 1;
            if (query(mi) == w) {
                l = mi + 1;
            } else {
                r = mi - 1;
            }
        }
        int e = r;
        if (e - s < m) {
            -- ans[k];
            update(idx, -1);
        }
    }
}

int main() {
    while (scanf("%d", &m) != EOF) {
        scanf("%s", c);
        clr(bit, 0);
        clr(ans, 0);
        forn (i, letter) v[i].clear();
        n = strlen(c);
        forn (i, n) v[c[i] - 'a'].pb(i + 1);
        forn (i, letter) {
            ans[i] += sz(v[i]);
            rep (idx, v[i]) update(idx, 1);
            if (finish()) {
                solve(i);
                break;
            }
        }
        forn (k, letter) {
            forn (i, ans[k]) printf("%c", 'a' + k);
        }
        printf("\n");
    }
    return 0;
}
