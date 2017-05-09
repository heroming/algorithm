/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/06 06:21:58
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

const int maxn = 50010;

vpint po;
int t, n;
int ans[maxn];
int vis[maxn];
vint maps[maxn];

int main() {
    scanf("%d", &t);
    while (t --) {
        po.clear();
        clr(vis, 0);
        scanf("%d", &n);
        form (i, 1, n) maps[i].clear();
 
        int u, v, w;
        form (i, 1, n) {
            scanf("%d", &w);
            po.pb({w, i});
        }
        sort(all(po), greater<pint>());
        form (i, 2, n) {
            scanf("%d%d", &u, &v);
            maps[u].pb(v);
            maps[v].pb(u);
        }
        form (i, 1, n) {
            if (sz(maps[i]) == n - 1) {
                ans[i] = 0;
                continue;
            }
            vis[i] = i;
            rep (it, maps[i]) {
                vis[it] = i;
            }
            rep (it, po) {
                if (vis[it.py] != i) {
                    ans[i] = it.py;
                    break;
                }
            }
        }
        form (i, 1, n) {
            if (i != 1) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
