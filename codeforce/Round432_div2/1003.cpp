/*
 * Author:heroming
 * File:1003.cpp
 * Time:2017/09/04 11:04:22
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

const int maxm = 245;
const int maxn = 1010;

struct Point {
    int x[5];
    Point() {}
    Point(const int a, const int b, const int c, const int d, const int e) {
        x[0] = a, x[1] = b, x[2] = c, x[3] = d, x[4] = e;
    }
    Point operator - (const Point & p) const {
        return Point(x[0] - p.x[0], x[1] - p.x[1], x[2] - p.x[2], x[3] - p.x[3], x[4] - p.x[4]);
    }
    int operator * (const Point & p) const {
        return x[0] * p.x[0] + x[1] * p.x[1] + x[2] * p.x[2] + x[3] * p.x[3] + x[4] * p.x[4];
    }
} po[maxn];

int n;
vint ans;

bool valid(const int k) {
    forn (i, n) forn (j, i) if (k != i && k != j) {
        int s = (po[i] - po[k]) * (po[j] - po[k]);
        if (s > 0) return 0;
    }
    return 1;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        ans.clear();
        forn (k, n) forn (i, 5) scanf("%d", &po[k].x[i]);
        if (n < maxm) {
            forn (k, n) if (valid(k)) ans.pb(k + 1);
        }
        printf("%d\n", sz(ans));
        forv (i, ans) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
