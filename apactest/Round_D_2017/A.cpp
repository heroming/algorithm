/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/16 13:52:48
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

const int maxn = 2010;

int t, n, m;
double dp[maxn][maxn];

int main() {
    scanf("%d", &t);
    freopen("heroming.out", "w", stdout);
    form (cas, 1, t) {
        scanf("%d%d", &n, &m);
        clr(dp, 0);
        dp[0][0] = 1.0;
        dp[1][0] = (n + 0.0) / (n + m);
        form (k, 2, n + m) {
            for (int i = max(0, k - n); i <= m && i < k - i; ++ i) {
                if (i < k - i - 1) dp[k - i][i] += dp[k - i - 1][i] * (n - k + i + 1.0) / (n + m - k + 1.0);
                if (i) dp[k - i][i] += dp[k - i][i - 1] * (m - i + 1.0) / (n + m - k + 1.0);
            }
        }
        printf("Case #%d: %.9lf\n", cas, dp[n][m]);
    }
    return 0;
}
