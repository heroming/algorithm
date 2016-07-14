/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/7/10 12:57:25
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
#define clr(v, e) memset(v, e, sizeof(v))
#define rep(it, v) for (auto it : v)
#define forn(i, n) for (int i = 0; i < (n); ++ i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; -- i)
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define rform(i, a, b) for (int i = (b); i >= (a); -- i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef __int128 llint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 110;
const double eps = 1e-12;

int t, n;
lint w[maxn];

double solve(const double e) {
    double ret = 0.0;
    double x = 1.0;
    rform(i, 1, n) {
        ret += w[i] * x;
        x *= e;
    }
    return ret - w[0] * x;
}

int main() {
    freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    form (cas, 1, t) {
        printf("Case #%d: ", cas);
        scanf("%d", &n);
        form (i, 0, n) {
            scanf("%I64d", &w[i]);
        }
        double l = 0.0, r = 2.0;
        while (r - l >= eps) {
            double e = (l + r) * 0.5;
            if (solve(e) < 0) {
                r = e;
            } else {
                l = e;
            }
        }
        printf("%.12lf\n", l - 1.0);
    }
    return 0;
}
