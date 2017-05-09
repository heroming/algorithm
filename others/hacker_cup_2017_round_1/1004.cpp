/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/15 05:23:16
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

const int maxn = 2010;
const lint mod = 1e9 + 7;

vint v;
int t, n, m, r;
lint s[maxn];
unordered_map<lint, lint> mp;

lint power(lint x, lint e) {
    lint ret = 1;
    while (e > 0) {
        if (e & 1) ret = ret * x % mod;
        x = x * x % mod;
        e >>= 1;
    }
    return ret;
}

lint combination(lint a, lint b) {
    auto it = mp.find(a);
    if (it != mp.end()) return it->py;
    if (a == b) return 1;
    if (a - b < b) b = a - b;
    lint x = 1, y = 1;
    forn (i, b) {
        x = x * (a - i) % mod;
        y = y * (b - i) % mod;
    }
    return mp[a] = x * power(y, mod - 2) % mod;
}

int main() {
    freopen("heroming.out", "w", stdout);
    s[0] = 1;
    for (lint k = 1; k < maxn; ++ k) {
        s[k] = s[k - 1] * k % mod;
    }
    scanf("%d", &t);
    form (cas, 1, t) {
        v.clear();
        mp.clear();
        scanf("%d%d", &n, &m);
        int w = 0;
        forn (i, n) {
            scanf("%d", &r);
            v.pb(r);
            w += (r << 1);
        }
        lint ans = 0;
        if (n == 1) {
            ans = m;
        } else {
            -- m;
            sort(all(v), greater<int>());
            forv (k, v) {
                forn (i, k) {
                    int x = w - v[k] - v[i];
                    if (m < x) break;
                    ans = (ans + combination(m - x + n, n) * s[n - 2] * 2) % mod;
                }
            }
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}
