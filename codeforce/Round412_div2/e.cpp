/*
 * Author:heroming
 * File:e.cpp
 * Time:2017/05/09 03:37:49
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
typedef vector<string> vstr;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxm = 110;

int n;
lint x;
int ones;
int cnt[maxm];
int use[maxm];
int chain[maxm];

void find(const lint w) {
    int k = 0;
    lint e = 1;
    while (1) {
        if (w < e) {
            ++ cnt[k - 1];
            break;
        } else if (w == e) {
            ++ cnt[k];
            break;
        }
        k += 2;
        e <<= 1;
    }
}

bool solve(const int m) {
    clr(chain, 0);
    memcpy(use, cnt, sizeof(cnt));
    for (int k = 0; k < m; ++ k) {
        int p = 0;
        while (use[p]) {
            -- use[p];
            p += 2;
        }
        if (p) ++ chain[p];
    }
    ones = use[0];
    rforn (k, maxm) {
        while (use[k] --) {
            bool finish = 0;
            rforn (i, maxm) {
                if (i < k) break;
                if (chain[i]) {
                    finish = 1;
                    -- chain[i];
                    break;
                }
            }
            if (! finish) return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    forn (i, n) {
        scanf("%I64d", &x);
        find(x);
    }
    vint ans;
    int l = (cnt[0] + 1) >> 1, r = cnt[0];
    while (l <= r) {
        int m = (l + r) >> 1;
        if (solve(m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    if (solve(l)) {
        form (i, 0, ones) ans.pb(l + i);
    }
    if (ans.empty()) {
        printf("-1\n");
    } else {
        printf("%d", ans[0]);
        for (int i = 1; i < sz(ans); ++ i) {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
