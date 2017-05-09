
/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/09 07:15:37
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

const int maxe = 20;
const int maxn = 1000010;

int n, v[maxn];
int rmq[maxn][maxe];

void init() {
    for (int i = 1; i <= n; ++ i) rmq[i][0] = v[i];
    for (int k = 1; (1 << k) <= n; ++ k) {
        for (int i = 0; i + (1 << k) - 1 <= n; ++ i) {
            rmq[i][k] = min(rmq[i][k - 1], rmq[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int query(const int l, const int r) {
    const static double e = log(2.0);
    int k = log(r - l + 1.0) / e;
    return min(rmq[l][k], rmq[r + 1 - (1 << k)][k]);
}

int main() {
    scanf("%d", &n);
    form (i, 1, n) scanf("%d", &v[i]);
    init();
    int m, l, r;
    scanf("%d", &m);
    forn (i, m) {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}
