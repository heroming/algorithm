/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/11 07:08:12
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

const int maxn = 100010;

struct edge {
    int u, v, w;
    bool operator < (const edge & e) const {
        return w < e.w;
    }
} e;

int n, m;
int p[maxn];
vector<edge> ve;

int find_set(int x) {
    if (p[x] != x) p[x] = find_set(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    forn (i, m) {
        scanf("%d%d%d", &e.u, &e.v, &e.w);
        ve.pb(e);
    }
    sort(all(ve));
    form (i, 1, n) p[i] = i;
    int ans = 0, cnt = 1;
    rep (it, ve) {
        int a = find_set(it.u);
        int b = find_set(it.v);
        if (a != b) {
            p[b] = a;
            ans += it.w;
            if (++ cnt == n) break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
