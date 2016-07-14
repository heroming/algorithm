/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/7/10 12:57:25
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
typedef __int128 llint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int N = 8;
const int maxn = 15;
const int maxm = 12;
const int maxe = 10010;

lint ans;
vector<int> v;
int t, m, n, idx;
int K[maxn], L[maxn];
pair<int, lint> p[maxe];
int A[maxn][maxm], C[maxn][maxm];

int find(const int s) {
    int l = 0, r = idx - 1;
    while (l <= r) {
        int mi = (l + r) >> 1;
        if (p[mi].px <= s) {
            l = mi + 1;
        } else {
            r = mi - 1;
        }
    }
    return r;
}

void dfs(const int k, const int h, const lint w, const int s) {
    if (k == h) {
        if (h == 4) {
            p[idx ++] = {m - s, w};
        } else {
            int x = find(s);
            ans = max(ans, p[x].py + w);
        }
        return;
    }
    dfs(k + 1, h, w + A[v[k]][L[v[k]]], s);
    int cost = 0;
    for (int i = L[v[k]]; i < K[v[k]]; ++ i) {
        cost += C[v[k]][i];
        if (cost <= s) {
            dfs(k + 1, h, w + A[v[k]][i + 1], s - cost);
        }
    }
}

int main() {
    freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    form (cas, 1, t) {
        printf("Case #%d: ", cas);
        scanf("%d%d", &m, &n);
        forn (k, n) {
            scanf("%d%d", &K[k], &L[k]);
            form (i, 1, K[k]) scanf("%d", &A[k][i]);
            form (i, 1, K[k] - 1) scanf("%d", &C[k][i]);
        }
        ans = 0;
        forn (status, 1 << n) {
            v.clear();
            int cnt = 0;
            forn (i, n) {
                if (status & (1 << i)) {
                    ++ cnt;
                    v.pb(i);
                }
            }
            idx = 0;
            if (cnt == N) {
                dfs(0, 4, 0, m);
                sort(p, p + idx);
                int x = idx;
                idx = 0;
                forn (i, x) {
                    if (i == 0 || p[idx - 1].py < p[i].py) {
                        p[idx ++] = p[i];
                    }
                }
                dfs(4, 8, 0, m);
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
