/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/13 10:11:18
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

const int N = 10;
const int maxn = 310;
const int maxm = 16;

char s[maxn];
int t, n, m, x, y;
map<lint, bool> dp[maxm][maxn];

inline int id(const int k) {
    return k % maxm;
}

lint gcd(lint a, lint b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

lint solve(lint a, lint b) {
    if (a == 0 && b == 0) return 0;
    if (a == 0 || b == 0) return max(a, b);
    return gcd(a, b);
}

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        scanf("%d%d%d", &m, &x, &y);
        forn (i, maxm) forn (j, maxn) dp[i][j].clear();
        dp[0][0][0] = 1;
        form (k, 0, n - 1) {
            int p = k / m, q = min(k, y);
            forn (i, maxn) dp[id(k + N)][i].clear();
            form (i, p, q) {
                if (dp[id(k)][i].empty()) continue;
                lint w = 0;
                int idx = 1;
                while (idx <= m && k + idx <= n) {
                    w = w * 10 + s[k + idx] - '0';
                    if (k == 0) {
                        dp[id(k + idx)][i + 1][w] = 1;
                    } else {
                        rep (it, dp[id(k)][i]) {
                            dp[id(k + idx)][i + 1][solve(it.px, w)] = 1;
                        }
                    }
                    ++ idx;
                }
            }
        }
        lint ans = 0;
        form (i, x + 1, y + 1) {
            ans = max(ans, dp[id(n)][i].rbegin()->px);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
