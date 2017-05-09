/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/14 10:05:17
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

const int maxn = 1 << 7;
const lint mod = 12357;

class Mat {
public :
    int n;
    lint w[maxn][maxn];
    Mat(int m = 1) {
        n = m;
        clr(w, 0);
        forn (i, n) w[i][i] = 1;
    }
    Mat(int m, const lint x[maxn][maxn]) {
        n = m;
        forn (i, n) forn (j, n) w[i][j] = x[i][j];
    }
    Mat operator * (const Mat & mat) const {
        Mat ret(n);
        forn (i, n) forn (j, n) {
            ret.w[i][j] = 0;
            forn (k, n) {
                ret.w[i][j] += w[i][k] * mat.w[k][j];
            }
            ret.w[i][j] %= mod;
        }
        return ret;
    }
    Mat operator ^ (int m) const {
        Mat ret(n), x = *this;
        while (m > 0) {
            if (m & 1) ret = ret * x;
            x = x * x;
            m >>= 1;
        }
        return ret;
    }
};

int m, n;
lint dp[maxn][maxn];

void dfs(const int k, const int s, const int t) {
    if (k == m) {
        dp[s][t] = 1;
        return;
    }
    dfs(k + 1, s << 1, t << 1 | 1);
    dfs(k + 1, s << 1 | 1, t << 1);
    if (k + 2 <= m) dfs(k + 2, s << 2 | 3, t << 2 | 3);
}

int main() {
    scanf("%d%d", &m, &n);
    clr(dp, 0);
    dfs(0, 0, 0);
    Mat mat(1 << m, dp);
    mat = mat ^ n;
    printf("%lld\n", mat.w[mat.n - 1][mat.n - 1]);
    return 0;
}
