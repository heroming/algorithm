/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/18 07:54:05
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
typedef vector<string> vstr;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 2110;

int n, m;
int w[maxn][maxn];
int f[maxn][maxn];
int dp[maxn][maxn];
char a[maxn], b[maxn];

int main() {
    scanf("%s%s", a + 1, b + 1);
    n = strlen(a + 1);
    m = strlen(b + 1);
    form (i, 1, n) form (j, 1, m) {
        int x = max(dp[i - 1][j], dp[i][j - 1]);
        if (a[i] == b[j]) {
            w[i][j] = w[i - 1][j - 1] + 1;
            if (w[i][j] >= 3) {
                f[i][j] = max(f[i][j], dp[i - 3][j - 3] + 3);
                if (w[i][j] > 3) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
                }
                x = max(x, f[i][j]);
            }
        }
        dp[i][j] = max(dp[i][j], x);
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
