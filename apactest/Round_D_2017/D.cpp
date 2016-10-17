/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/16 18:45:57
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

const int maxn = 1010;
const int maxm = 20010;
const lint inf = 1000100100;

int t, n, m, s;
lint dp[maxm], sh[maxm];
lint a[maxn], b[maxn], p[maxn];

int main() {
    freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    form (cas, 1, t) {
        scanf("%d%d%d", &n, &m, &s);
        lint w = 0;
        forn (i, n) {
            scanf("%lld%lld%lld", &a[i], &b[i], &p[i]);
            p[i] = -p[i];
            w = max(w, b[i]);
        }
        lint x = s + w;
        form (i, 0, x) {
            dp[i] = -inf;
            sh[i] = inf;
        }
        dp[0] = sh[0] = 0;
        forn (k, n) {
            if (m < -p[k]) continue;
            rform (i, 0, x - b[k]) {
                if (dp[i] == -inf) continue;
                if (dp[i + b[k]] < dp[i] + p[k]) {
                    dp[i + b[k]] = dp[i] + p[k];
                    sh[i + b[k]] = sh[i] + a[k];
                } else if (dp[i + b[k]] == dp[i] + p[k]) {
                    sh[i + b[k]] = min(sh[i + b[k]], sh[i] + a[k]);
                }
            }
        }
        lint ans = inf;
        form (i, s, x) {
            if (-dp[i] <= m && sh[i] <= s) {
                ans = min(ans, -dp[i]);
            }
        }
        if (ans == inf) {
            printf("Case #%d: IMPOSSIBLE\n", cas);
        } else {
            printf("Case #%d: %lld\n", cas, ans);
        }
    }
    return 0;
}
