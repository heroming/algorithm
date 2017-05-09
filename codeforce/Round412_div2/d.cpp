/*
 * Author:heroming
 * File:d.cpp
 * Time:2017/05/09 09:38:55
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

const int maxn = 5;
const int inf = 10000;

int n;
int cnt[maxn];
int a[maxn], b[maxn], c[maxn];

int get_point(const lint x, const lint y) {
    if (x * 2 > y) return 500;
    if (x * 4 > y) return 1000;
    if (x * 8 > y) return 1500;
    if (x * 16 > y) return 2000;
    if (x * 32 > y) return 2500;
    return 3000;
}

bool valid(const int x) {
    int p = 0, q = 0, m = n + x;
    forn (i, maxn) {
        if (a[i] == -1) {
            if (b[i] != -1) {
                q += get_point(cnt[i], m) * (250 - b[i]);
            }
        } else {
            if (b[i] == -1) {
                p += get_point(cnt[i],  m) * (250 - a[i]);
            } else if (b[i] < a[i]) {
                p += get_point(cnt[i] + x, m) * (250 - a[i]);
                q += get_point(cnt[i] + x, m) * (250 - b[i]);
            } else {
                p += get_point(cnt[i], m) * (250 - a[i]);
                q += get_point(cnt[i], m) * (250 - b[i]);
            }
        }
    }
    return p > q;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        clr(cnt, 0);
        forn (i, maxn) {
            scanf("%d", &a[i]);
            if (a[i] != -1) ++ cnt[i];
        }
        forn (i, maxn) {
            scanf("%d", &b[i]);
            if (b[i] != -1) ++ cnt[i];
        }
        form (i, 3, n) forn (i, maxn) {
            scanf("%d", &c[i]);
            if (c[i] != -1) ++ cnt[i];
        }
        int ans = -1;
        forn (i, inf) if (valid(i)) {
            ans = i;
            break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
