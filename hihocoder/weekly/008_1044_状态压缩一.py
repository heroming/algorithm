/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/05 11:52:12
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

const int maxn = 1050;

vint v;
bool dic[maxn];
int n, m, q, w;
int dp[maxn][maxn];

inline bool valid(int x) {
    int cnt = 0;
    while (x) {
        if (x & 1) ++ cnt;
        x >>= 1;
    }
    return cnt <= q;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    forn (s, 1 << m) {
        if (valid(s)) {
            v.pb(s);
            dic[s] = 1;
        }
    }
    const int mask = (1 << m) - 1;
    forn (k, n) {
        scanf("%d", &w);
        rep (s, v) {
            int x = s << 1 & mask;
            dp[k + 1][x] = max(dp[k + 1][x], dp[k][s]);
            if (dic[x | 1]) dp[k + 1][x | 1] = max(dp[k + 1][x | 1], dp[k][s] + w);
        }
    }
    int ans = 0;
    rep (s, v) ans = max(ans, dp[n][s]);
    printf("%d\n", ans);
    return 0;
}
