/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/14 11:21:18
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

const int mod = 142857;
const int maxn = 100010;

int n, m, p;
vint g[maxn];
int de[maxn];
int vi[maxn];

int solve() {
    queue<int> que;
    form (i, 1, n) {
        if (de[i] == 0) que.push(i);
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        rep (v, g[u]) {
            if (-- de[v] == 0) que.push(v);
            vi[v] += vi[u];
            if (vi[v] >= mod) vi[v] -= mod;
        }
    }
    int ret = 0;
    form (i, 1, n) {
        ret += vi[i];
        if (ret >= mod) ret -= mod;
    }
    return ret;
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    int u, v;
    forn (i, p) {
        scanf("%d", &u);
        ++ vi[u];
    }
    forn (i, m) {
        scanf("%d%d", &u, &v);
        ++ de[v];
        g[u].pb(v);
    }
    printf("%d\n", solve());
    return 0;
}
