/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/7/30 19:19:18
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

vpint v;
int t, n, m;
int dis[maxn];
bool vis[maxn];

lint solve(const int l, const int r) {
    lint sum = 1;
    for (int i = l + 1; i <= r; ++ i) {
        sum += dis[i] + 1;
    }
    return sum;
}

int main() {
    scanf("%d", &t);
    while (t --) {
        v.clear();
        scanf("%d%d", &n, &m);
        form (i, 1, n - 1) {
            scanf("%d", &dis[i]);
            v.pb(make_pair(dis[i], i));
        }
        if (n <= m) {
            printf("%d\n", n);
        } else {
            sort(all(v), greater<pint>());
            clr(vis, 1);
            vis[n] = 0;
            forn (i, m - 1) vis[v[i].py] = 0;
            lint ans = 0;
            int l = 0, r = 1;
            while (r <= n) {
                while (r <= n && vis[r]) ++ r;
                ans += solve(l, r - 1);
                l = r ++;
            }
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
