/*
 * Author:heroming
 * File:1002.cpp
 * Time:2017/09/01 09:48:10
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

const int maxn = 1010;

int n;
int v[maxn];
bool vis[maxn];
map<pint, int> mp;

int gcd(const int a, const int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

pint slape(const int a, const int b) {
    int x = b - a;
    int y = v[b] - v[a];
    if (y == 0) return {1, 0};
    int g = gcd(x, abs(y));
    return {x / g, y / g};
}

pint most_slape() {
    int cnt = 0;
    pint ret = {0, 0};
    iter (it, mp) if (cnt < it->py) {
        cnt = it->py;
        ret = it->px;
    }
    return ret;
}

bool solve() {
    mp.clear();
    form (i, 1, n) form (j, 1, i - 1) ++ mp[slape(j, i)];

    pint po = most_slape();

    int cnt = 1;
    clr (vis, 1);
    vis[1] = 0;
    int k = 1;
    form (i, 2, n) if (slape(k, i) == po) {
        ++ cnt; k = i; vis[i] = 0;
    }
    if (cnt == n) return 0;
    k = -1;
    form (i, 2, n) if (vis[i]) {
        if (vis[i] && (k == -1 || slape(k, i) == po)) {
            ++ cnt; k = i;
        }
    }
    return cnt == n;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        form (i, 1, n) scanf("%d", &v[i]);

        printf("%s\n", solve() ? "YES" : "NO");

    }
    return 0;
}
