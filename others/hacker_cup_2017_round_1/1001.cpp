/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/15 03:16:38
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

const int maxn = 310;
const int inf = 0x3FFF3FFF;

vint v;
int t, n, m, w;
int dp[maxn][maxn];

int main() {
    //freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    form (cas, 1, t) {
        scanf("%d%d", &n, &m);
        forn (i, maxn) forn (j, maxn) dp[i][j] = inf;
        dp[0][0] = 0;
        form (k, 1, n) {
            v.clear();
            v.pb(0);
            forn (i, m) {
                scanf("%d", &w);
                v.pb(w);
            }
            sort(all(v));
            forn (i, n) {
                int s = 0;
                forv (j, v) {
                    if (i + j < k || i + j > n) break;
                    s += v[j];
                    dp[k][i + j] = min(dp[k][i + j], min(dp[k - 1][i + j], dp[k - 1][i] + s + j * j));
                }
            }
        }
        printf("Case #%d: %d\n", cas, dp[n][n]);
    }
    return 0;
}
