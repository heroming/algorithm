
/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/12 11:34:15
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

int t, n, m;
int p[maxn], w[maxn];

int find_set(int x) {
    if (p[x] != x) p[x] = find_set(p[x]);
    return p[x];
}

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        form (i, 1, n) {
            w[i] = 1;
            p[i] = i;
        }
        int a, b;
        forn (i, m) {
            scanf("%d%d", &a, &b);
            a = find_set(a);
            b = find_set(b);
            if (a != b) {
                p[b] = a;
                w[a] += w[b];
            }
        }
        vlint v;
        form (i, 1, n) {
            int x = find_set(i);
            if (w[x] > 1) {
                v.pb(w[x]);
                w[x] = 0;
            }
        }
        int remind = m;
        lint cnt = 0, ans = 0;
        sort(all(v), greater<lint>());
        rep (it, v) {
            remind -= it - 1;
            for (lint i = 2; i <= it; ++ i) ans += i * (i - 1) + cnt;
            cnt += it * (it - 1);
        }
        while (remind --) ans += cnt;
        printf("%lld\n", ans);
    }
    return 0;
}
