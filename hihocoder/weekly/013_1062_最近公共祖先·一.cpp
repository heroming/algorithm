/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/10 06:10:01
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

const int maxn = 210;

int p[maxn];
int n, m, idx;
bool vis[maxn];
string name[maxn];
map<string, int> mp;

int find(const string & s) {
    auto it = mp.find(s);
    if (it != mp.end()) return it->py;
    mp[s] = ++ idx;
    name[idx] = s;
    return idx;
}

int lca(int u, int v) {
    if (u == 0 || v == 0) return -1;
    clr(vis, 0);
    while (u != -1) {
        vis[u] = 1;
        u = p[u];
    }
    while (v != -1) {
        if (vis[v]) return v;
        v = p[v];
    }
    return -1;
}

int main() {
    cin >> n;
    string a, b;
    clr(p, -1);
    forn (i, n) {
        cin >> a >> b;
        int u = find(a);
        int v = find(b);
        p[v] = u;
    }
    cin >> m;
    forn (i, m) {
        cin >> a >> b;
        if (a == b) {
            cout << a << endl;
            continue;
        }
        int u = mp[a], v = mp[b];
        int k = lca(u, v);
        if (k == -1) {
            cout << -1 << endl;
        } else {
            cout << name[k] << endl;
        }
    }
    return 0;
}
