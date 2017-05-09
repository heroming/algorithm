/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/11 04:05:42
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

const int maxa = 10;
const int maxb = 100;
const int maxn = 200010;
const lint mod = 1e9 + 7;

int n;
char s[maxn];
lint a[maxb], b[maxa], c[maxa];

inline bool valid(int x) {
    return (x & 7) == 0;
}

void add(lint & x, lint w) {
    x += w;
    if (x >= mod) x -= mod;
}

lint power(lint x, lint m) {
    lint ret = 1;
    while (m) {
        if (m & 1) ret = ret * x % mod;
        x = x * x % mod;
        m >>= 1;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    lint ans = 0;
    forn (k, n) {
        int x = s[k] - '0';
        if (valid(x)) add(ans, 1);
        forn (i, maxa) {
            if (valid(i * 10 + x)) {
                add(ans, c[i]);
            }
        }
        add(c[x], 1);
        forn (i, maxb) {
            if (valid(i * 10 + x)) {
                add(ans, a[i]);
            }
        }
        forn (i, maxa) {
            add(a[i * 10 + x], b[i]);
        }
        add(b[x], power(2, k));
    }
    printf("%lld\n", ans);
    return 0;
}
