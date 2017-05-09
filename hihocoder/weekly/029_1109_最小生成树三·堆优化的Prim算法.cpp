/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/11 07:58:15
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

template<class T>
class MinHeap {
    int n;
    vector<T> v;
public :
    MinHeap(): n(0) {}
    MinHeap(int m): n(0), v(vector<T>(m + 1)) {}
    
    bool empty() const {
        return size() == 0;
    }
    
    int size() const {
        return n;
    }
    
    void push(const T & e) {
        v[++ n] = e;
        int k = n;
        while (k > 1) {
            int p = k >> 1;
            if (v[p] <= v[k]) break;
            swap(v[p], v[k]);
            k = p;
        }
    }
    
    T top() const {
        if (empty()) return T();
        return v[1];
    }
    
    T pop() {
        if (empty()) return T();
        T ret = v[1];
        swap(v[1], v[n --]);
        int idx = 1;
        while (idx < n) {
            int k = idx, l = (idx << 1), r = (idx << 1 | 1);
            if (l <= n && v[l] < v[k]) k = l;
            if (r <= n && v[r] < v[k]) k = r;
            if (k == idx) break;
            swap(v[k], v[idx]);
            idx = k;
        }
        return ret;
    }
};

const int maxn = 100010;
const int inf = 0x3FFFFFFF;

int n, m;
int dis[maxn];
bool vis[maxn];
vpint g[maxn];

int main() {
    scanf("%d%d", &n, &m);
    int u, v, w;
    forn (i, m) {
        scanf("%d%d%d", &u, &v, &w);
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    int ans = 0;
    clr(vis, 1);
    form (i, 1, n) dis[i] = inf;
    MinHeap<pint> heap(m);
    heap.push({0, 1});
    form (k, 1, n) {
        do {
            pint pt = heap.pop();
            w = pt.px, u = pt.py;
        } while (!vis[u]);
        ans += w;
        vis[u] = 0;
        rep (it, g[u]) {
            v = it.px, w = it.py;
            if (vis[v] && w < dis[v]) {
                dis[v] = w;
                heap.push({w, v});
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
