/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/10 07:06:51
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

const int maxn = 200010;

int n, m, idx;
int p[maxn];
int ans[maxn];
bool vis[maxn];
vint g[maxn];
vpint q[maxn];
string name[maxn];
map<string, int> mp;

int find(const string & s) {
    auto it = mp.find(s);
    if (it != mp.end()) return it->py;
    mp[s] = ++ idx;
    name[idx] = s;
    return idx;
}

int find_set(int x) {
    if (p[x] != x) p[x] = find_set(p[x]);
    return p[x];
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) p[b] = a;
}

void tarjan(const int u) {
    rep (v, g[u]) {
        tarjan(v);
        union_set(u, v);
    }
    vis[u] = 1;
    rep (it, q[u]) {
        int v = it.px, id = it.py;
        if (vis[v]) {
            ans[id] = find_set(v);
        }
    }
}

int main() {
    cin >> n;
    string a, b;
    forn (i, n) {
        cin >> a >> b;
        int u = find(a);
        int v = find(b);
        g[u].pb(v);
    }
    clr(vis, 0);
    forn (i, maxn) p[i] = i;
    cin >> m;
    forn (i, m) {
        cin >> a >> b;
        int u = find(a);
        int v = find(b);
        q[u].pb({v, i});
        q[v].pb({u, i});
    }
    tarjan(1);
    forn (i, m) {
        cout << name[ans[i]] << endl;
    }
    return 0;
}
