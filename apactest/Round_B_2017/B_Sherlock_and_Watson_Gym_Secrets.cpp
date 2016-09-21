/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/9/3 9:03:23
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
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 100010;
const lint mod = 1e9 + 7;

lint n, m;
int t, a, b;
lint da[maxn], db[maxn];

lint power(lint x, lint y, const lint z) {
    x %= z;
    lint ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % z;
        y >>= 1;
        x = x * x % z;
    }
    return ret % z;
}

int main() {
    scanf("%d", &t);
    //freopen("heroming.out", "w", stdout);
    form (cas, 1, t) {
        scanf("%d%d%lld%lld", &a, &b, &n, &m);
        clr(da, 0);
        clr(db, 0);
        lint ans = 0;
        if (n <= m) {
            form (k, 1, n) {
                lint pa = power(k, a, m);
                lint pb = power(k, b, m);
                ++ da[pa], ++ db[pb];
                if ((pa + pb) % m == 0) -- ans;
            }
        } else {
            lint n_mod = n % m;
            lint n_div = n / m % mod;
            form (k, 1, m) {
                lint pa = power(k, a, m);
                lint pb = power(k, b, m);
                lint w = n_div + (n_mod >= k ? 1 : 0);
                da[pa] = (da[pa] + w) % mod;
                db[pb] = (db[pb] + w) % mod;
                if ((pa + pb) % m == 0) ans = (ans - w) % mod;
            }
        }
        forn (k, m) {
            ans = (ans + da[k] * db[(m - k) % m]) % mod;
        }
        printf("Case #%d: %lld\n", cas, (ans + mod) % mod);
    }
    return 0;
}
