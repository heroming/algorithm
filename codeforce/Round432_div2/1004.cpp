/*
 * Author:heroming
 * File:1004.cpp
 * Time:2017/09/04 11:44:23
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
const int maxn = 500010;

vint v;
bool f[maxm];

lint n, x, y, ans;
int a[maxn], b[maxm];
map<int, int> dic;

void factor(int s) {
    forv (i, v) {
        if (s < v[i]) break;
        if (s % v[i] == 0) {
            ++ b[i];
            while (s % v[i] == 0) s /= v[i];
        }
    }
    if (s != 1) ++ dic[s];
}

void solve(const int k) {
    if (x <= y) {
        ans = min(ans, (n - b[k]) * x);
    } else {
        lint ret = 0;
        forn (i, n) {
            int s = v[k] - a[i] % v[k];
            if (s != v[k]) {
                ret += min(x, s * y);
            }
            if (ans <= ret) return;
        }
        ans = ret;
    }
}

void solve(const int w, const int m) {
    if (x <= y) {
        ans = min(ans, (n - m) * x);
    } else {
        lint ret = 0, left = n - m;
        forn (i, n) {
            int s = w - a[i] % w;
            if (s != w) {
                -- left;
                ret += min(x, s * y);
                if (ans <= ret + left * y) return;
            }
        }
        ans = ret;
    }
}

int main() {
    clr (f, 1);
    for (int k = 2; k < maxm; ++ k) {
        if (f[k]) v.pb(k);
        for (int i = 0; i < sz(v) && k * v[i] < maxm; ++ i) {
            f[k * v[i]] = 0;
            if (k % v[i] == 0) break;
        }
    }
    while (cin >> n >> x >> y) {
        clr(b, 0);
        dic.clear();
        forn (i, n) {
            scanf("%d", &a[i]);
            factor(a[i]);
        }
        ans = x * n;
        forv (k, v) solve(k);
        iter (it, dic) solve(it->px, it->py);
        cout << ans << endl;
    }
    return 0;
}
