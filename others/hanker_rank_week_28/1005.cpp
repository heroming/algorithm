/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/13 07:01:44
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

const int maxn = 32;

int n, m;
char c[maxn];
double mem[maxn][maxn];
unordered_map<int, double> dp[maxn];

inline int pick(const int k, const int s, const int x) {
    const int a = (1 << k) - 1;
    const int b = (1 << (x + 1)) - 1;
    return ((s & (a - b)) >> 1) | (s & (b >> 1));
}

double dfs(const int k, const int s, const double e) {
    if (k <= n - m) return 0;
    auto it = dp[k].find(s);
    if (it != dp[k].end()) return it->py;
    double ret = 0, p = e / k;
    forn (i, k) mem[k][i] = dfs(k - 1, pick(k, s, i), p) + ((s & (1 << i)) > 0 ? p : 0);
    forn (i, k) ret += max(mem[k][i], mem[k][k - i - 1]);
    return dp[k][s] = ret;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        forn (i, maxn) dp[i].clear();
        scanf("%s", c);
        int s = 0;
        forn (i, n) {
            s <<= 1;
            if (c[i] == 'W') s |= 1;
        }
        printf("%.10lf\n", dfs(n, s, 1.0));
    }
    return 0;
}
