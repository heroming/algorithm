/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/16 14:17:44
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

const int N = 100;
const int maxn = 110;
const int maxe = 1100;

int t, n, m;
map<pint, int> dp[maxn];
int table[maxn][maxn];

inline bool valid(const int x, const int y, const int s) {
    for (int i = 2; i < m; ++ i) {
        if ((s >> i) & (s >> (i - 1)) & (s >> (i - 2)) & 1) return 0;
    }
    forn (i, m) {
        if ((x >> i) & (y >> i) & (s >> i) & 1) return 0;
    }
    return 1;
}

inline int bit_count(const int s) {
    int ret = 0;
    forn (i, m) {
        ret += ((s >> i) & 1);
    }
    return ret;
}

int solve() {
    form (i, 1, n) dp[i].clear();
    forn (s, 1 << m) {
        if (valid(0, 0, s)) {
            dp[1][{0, s}] = bit_count(s);
        }
    }
    form (k, 2, n) {
        iter (it, dp[k - 1]) {
            int x = it->px.px, y = it->px.py, w = it->py;
            forn (s, 1 << m) {
                if (valid(x, y, s)) {
                    dp[k][{y, s}] = max(dp[k][{y, s}], w + bit_count(s)); 
                }
            }
        }
    }
    int ans = 0;
    iter (it, dp[n]) {
        ans = max(ans, it->py);
    }
    return ans;
}

int main() {
    freopen("heroming.out", "w", stdout);
    table[1][1] = 1;
    form (k, 2, N) {
        table[1][k] = table[k][1] = (k % 3 == 0 ? table[1][k - 1] : table[1][k - 1] + 1);
        table[2][k] = table[k][2] = (k % 3 == 0 ? table[2][k - 1] : table[2][k - 1] + 2);
    }
    form (i, 3, N) {
        form (j, 3, N) {
            if (i % 3 == 0) {
                table[i][j] = table[j][i] = table[i][j - 1] + table[i][1];
            } else {
                table[i][j] = table[j][i] = (j % 3 == 0 ? table[i][j - 1] + table[i][1] - i % 3 : table[i][j - 1] + table[i][1]);
            }
        }
    }
    scanf("%d", &t);
    form (cas, 1, t) {
        scanf("%d%d", &n, &m);
        printf("Case #%d: %d\n", cas, table[n][m] - (int)(n > 3 && m > 3 && n % 3 == 2 && m % 3 == 2));
    }
    return 0;
}
