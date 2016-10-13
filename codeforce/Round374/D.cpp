/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/9/30 22:04:30
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
typedef pair<lint, int> plint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;
typedef vector<plint> vplint;

const int maxn = 200010;

int n, m;
lint x, w;
lint s[maxn];
priority_queue<plint> u;
priority_queue<plint, vplint, greater<plint>> v;

int main() {
    while (scanf("%d%d%I64d", &n, &m, &x) != EOF) {
        forn (i, n) {
            scanf("%I64d", &w);
            if (w < 0) {
                u.push({w, i});
            } else {
                v.push({w, i});
            }
        }
        
        int ne = sz(u);
        if (ne & 1) {
            forn (i, m) {
                if (v.empty()) {
                    plint p = u.top();
                    u.pop();
                    u.push({p.px - x, p.py});
                } else {
                    plint p = u.top(), q = v.top();
                    if (-p.px < q.px) {
                        u.pop();
                        u.push({p.px - x, p.py});
                    } else {
                        v.pop();
                        v.push({q.px + x, q.py});
                    }
                }
            }
        } else {
            int t = m;
            if (ne == 0) {
                plint p = v.top();
                v.pop();
                if (p.px - m * x >= 0) {
                    v.push({p.px - m * x, p.py});
                } else {
                    t = (p.px + x - 1) / x;
                    u.push({p.px - t * x, p.py});
                }
            } else if (ne == n) {
                plint p = u.top();
                u.pop();
                if (p.px + m * x < 0) {
                    u.push({p.px + m * x, p.py});
                } else {
                    t = (-p.px + x - 1) / x;
                    v.push({p.px + t * x, p.py});
                }
            } else {
                plint p = u.top(), q = v.top();
                if (-p.px < q.px) {
                    u.pop();
                    if (p.px + m * x < 0) {
                        u.push({p.px + m * x, p.py});
                    } else {
                        t = (-p.px + x - 1) / x;
                        v.push({p.px + t * x, p.py});
                    }
                } else {
                    v.pop();
                    if (q.px - m * x >= 0) {
                        v.push({q.px - m * x, q.py});
                    } else {
                        t = (q.px + x - 1) / x;
                        u.push({q.px - t * x, q.py});
                    }
                }
            }
            for (int i = t; i < m; ++ i) {
                if (v.empty()) {
                    plint p = u.top();
                    u.pop();
                    u.push({p.px - x, p.py});
                } else if (u.empty()) {
                    plint p = v.top();
                    v.pop();
                    v.push({p.px + x, p.py});
                } else {
                    plint p = u.top(), q = v.top();
                    if (-p.px < q.px) {
                        u.pop();
                        u.push({p.px - x, p.py});
                    } else {
                        v.pop();
                        v.push({q.px + x, q.py});
                    }
                }
            }
        }
        while (! u.empty()) {
            plint p = u.top();
            s[p.py] = p.px;
            u.pop();
        }
        while (! v.empty()) {
            plint p = v.top();
            s[p.py] = p.px;
            v.pop();
        }
        forn (i, n) {
            printf("%I64d ", s[i]);
        }
    }
    return 0;
}
