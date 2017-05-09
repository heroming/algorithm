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

const int maxe = 20;
const int maxn = 200010;
const int maxm = 500010;

int n, m, idx;
vint g[maxn];
string name[maxn];
map<string, int> mp;

int head[maxn];
int rmq[maxm][maxe];
int depth[maxm], seq[maxm];

int find(const string & s) {
    auto it = mp.find(s);
    if (it != mp.end()) return it->py;
    mp[s] = ++ idx;
    name[idx] = s;
    return idx;
}

void dfs(const int u, const int d) {
    seq[++ idx] = u;
    depth[idx] = d;
    head[u] = idx;
    rep (v, g[u]) {
        dfs(v, d + 1);
        seq[++ idx] = u;
        depth[idx] = d;
    }
}

void init_rmq() {
    form (i, 1, idx) rmq[i][0] = i;
    for (int k = 1; (1 << k) <= idx; ++ k) {
        for (int i = 1; i + (1 << k) - 1 <= idx; ++ i) {
            int l = rmq[i][k - 1];
            int r = rmq[i + (1 << (k - 1))][k - 1];
            rmq[i][k] = (depth[l] < depth[r] ? l : r);
        }
    }
}

int query_rmq(const int a, const int b) {
    const static double e = log(2.0);
    int k = log(b - a + 1.0) / e;
    int l = rmq[a][k];
    int r = rmq[b - (1 << k) + 1][k];
    return depth[l] < depth[r] ? seq[l] : seq[r];
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
    idx = 0;
    dfs(1, 0);
    init_rmq();
    cin >> m;
    forn (i, m) {
        cin >> a >> b;
        int u = find(a);
        int v = find(b);
        if (head[v] < head[u]) {
            swap(u, v);
        }
        int x = query_rmq(head[u], head[v]);
        cout << name[x] << endl;
    }
    return 0;
}
