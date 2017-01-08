/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/07 11:49:13
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

const int maxe = 25;
const int maxn = 500;

int t, n, m;
double dp[maxe][maxn];

int main() {
    freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    form (cas, 1, t) {
        double ans = 0;
        scanf("%d%d", &n, &m);
        forn (i, m) {
            int x, y, z = 0;
            scanf("%dd%d", &x, &y);
            char c = getchar();
            if (c == '+' || c == '-') {
                scanf("%d", &z);
                if (c == '-') z = -z;
            }
            clr(dp, 0);
            dp[0][0] = 1;
            double p = 1.0 / y;
            form (k, 1, x) {
                int s = 1 * (k - 1);
                int e = y * (k - 1);
                form (i, s, e) {
                    form (j, 1, y) {
                        dp[k][i + j] += dp[k - 1][i] * p;
                    }
                }
            }
            int s = 1 * x;
            int e = y * x;
            int k = n - z;
            if (k <= s) {
                ans = 1.0;
            } else {
                double g = 0;
                form (i, k, e) {
                    g += dp[x][i];
                }
                ans = max(ans, g);
            }
        }
        printf("Case #%d: %.8lf\n", cas, ans);
    }
    return 0;
}
