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
#define all(v) ((v).begin(), (v).end())
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

lint ans;
int n, w[maxn], s[maxn];

int upper(int l, int r, const int x) {
    while (l <= r) {
        int m = (l + r) >> 1;
        if (w[m] <= x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l;
}

void merge(const int l, const int r) {
    if (l == r) return;
    int m = (l + r) >> 1;
    merge(l, m);
    merge(m + 1, r);
    int idx = upper(l, m, w[m + 1]);
    form (i, m + 1, r) {
        while (idx <= m && w[idx] <= w[i]) ++ idx;
        ans += m - idx + 1;
    }
    int k = l, a = l, b = m + 1;
    while (a <= m && b <= r) {
        if (w[a] < w[b]) {
            s[k ++] = w[a ++];
        } else {
            s[k ++] = w[b ++];
        }
    }
    while (a <= m) s[k ++] = w[a ++];
    while (b <= r) s[k ++] = w[b ++];
    form (i, l, r) w[i] = s[i];
}

int main() {
    scanf("%d", &n);
    forn (i, n) scanf("%d", &w[i]);
    merge(0, n - 1);
    printf("%lld\n", ans);
    return 0;
}
