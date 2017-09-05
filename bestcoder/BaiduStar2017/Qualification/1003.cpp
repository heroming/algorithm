/*
 * Author:heroming
 * File:1003.cpp
 * Time:2017/08/05 12:05:54
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

const int maxm = 1010;
const int maxe = 2020;
const int maxn = 100010;
const lint inf = 1ll << 62;

int n, m;
lint dp[maxe];
int a[maxn], b[maxn];
int c[maxm], p[maxm];

lint solve() {
    lint ans = 0;
    form (t, 0, 10) {
        forn (i, maxe) dp[i] = inf;
        dp[0] = 0;
        forn (k, maxm) forn (i, m) if (p[i] > t) {
            int x = k + (p[i] - t);
            dp[x] = min(dp[x], dp[k] + c[i]);
        }
        rforn (i, maxe - 1) dp[i] = min(dp[i], dp[i + 1]);
        forn (i, n) if (b[i] == t) {
            if (dp[a[i]] == inf) return -1;
            ans += dp[a[i]];
        }
    }
    return ans;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        forn (i, n) scanf("%d%d", &a[i], &b[i]);
        forn (i, m) scanf("%d%d", &c[i], &p[i]);
        cout << solve() << endl;
    }
    return 0;
}
