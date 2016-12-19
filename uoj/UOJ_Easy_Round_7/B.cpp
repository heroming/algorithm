/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/16 20:33:08
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
#define rall(v) (v).rbegin(), (v).rend()
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
const int inf = 1000000000;

int ans[maxn];
int n, w[maxn];
int min_front, min_tail, min_s[maxn];
int max_front, max_tail, max_s[maxn];

inline bool valid(const int x, const int y) {
    return y == 0 || y - x < x * 0.05;
}

int solve(const int m) {
    int ret = inf;
    min_front = min_tail = 0;
    max_front = max_tail = 0;
    form (t, 1, n) {
        while (min_front < min_tail && w[t] <= w[min_s[min_tail]]) -- min_tail;
        min_s[++ min_tail] = t;
        if (min_s[min_front + 1] + m <= t) ++ min_front;
        while (max_front < max_tail && w[max_s[max_tail]] <= w[t]) -- max_tail;
        max_s[++ max_tail] = t;
        if (max_s[max_front + 1] + m <= t) ++ max_front;
        if (t >= m) ret = min(ret, w[max_s[max_front + 1]] - w[min_s[min_front + 1]]);
    }
    return ret;
}

void dfs(const int l, const int r) {
    if (l == r) {
        if (ans[l] == -1) ans[l] = solve(l);
        return;
    }
    if (ans[l] == -1) ans[l] = solve(l);
    if (ans[r] == -1) ans[r] = solve(r);
    if (l + 1 == r || valid(ans[l], ans[r])) {
        form (i, l + 1, r - 1) ans[i] = ans[l];
        return;
    }
    int m = (l + r) >> 1;
    if (l < m && m < r) ans[m] = solve(m);
    dfs(l, m);
    dfs(m, r);
}

int main() {
    scanf("%d", &n);
    form (i, 1, n) scanf("%d", &w[i]);
    clr(ans, -1);
    dfs(2, n);
    form (i, 2, n) printf("%d\n", ans[i]);
    return 0;
}
