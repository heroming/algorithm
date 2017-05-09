/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/10 12:50:32
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

const int maxn = 1010;
const int maxm = 1 << 5;
const lint mod = 1e9 + 7;

int n, m;
lint dp[maxn][maxm];

inline bool bit(const int k, const int s) {
    return (1 << k) & s;
}

void dfs(const int k, const int e, const int x, const int s) {
    if (k == m) {
        dp[x][e] = (dp[x][e] + dp[x - 1][s]) % mod;
        return;
    }
    if (bit(k, s)) {
        dfs(k + 1, e, x, s);
    } else {
        dfs(k + 1, e | (1 << k), x, s);
        if (k + 1 < m && !bit(k + 1, s)) {
            dfs(k + 2, e, x, s);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    clr(dp, 0);
    dp[0][0] = 1;
    form (k, 1, n) {
        forn (s, 1 << m) {
            if (dp[k - 1][s]) {
                dfs(0, 0, k, s);
            }
        }
    }
    printf("%lld\n", dp[n][0]);
    return 0;
}
