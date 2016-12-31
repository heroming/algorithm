/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/12/31 11:16:56
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

const int maxn = 100010;
const int maxm = 1000010;

int t, n, m;
int c[maxn];
int bit[maxn];
int dic[maxm];
int cnt[maxm];
int h[maxm], nxt[maxm];

inline int lowbit(const int x) {
    return x & -x;
}

void add(int x, const int w) {
    while (x <= n) {
        bit[x] += w;
        x += lowbit(x);
    }
}

int query(int x) {
    int ret = 0;
    while (x) {
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

void merge(const int x, const int y) {
    for (int k = h[x]; k; k = nxt[k]) {
        if (c[k - 1] == y) add(k, -1);
        if (c[k + 1] == y) add(k + 1, -1);
    }
    int it = 0;
    for (int k = h[x]; k; k = nxt[k]) {
        it = k;
        c[k] = y;
    }
    if (it != 0) {
        nxt[it] = h[y];
        h[y] = h[x];
    }
    h[x] = 0;
 
    cnt[y] += cnt[x];
    cnt[x] = 0;
}

int main() {
    scanf("%d", &t);
    while (t --) {
        clr(c, 0);
        clr(h, 0);
        clr(nxt, 0);
        clr(bit, 0);
        clr(cnt, 0);
        clr(dic, 0);
        scanf("%d%d", &n, &m);
        form (i, 1, n) {
            scanf("%d", &c[i]);
            ++ cnt[c[i]];
            dic[c[i]] = c[i];
            nxt[i] = h[c[i]];
            h[c[i]] = i;
            if (c[i] != c[i - 1]) add(i, 1);
        }
        int op, x, y;
        forn (i, m) {
            scanf("%d%d%d", &op, &x, &y);
            if (op == 1) {
                if (x == y) continue;
                int dx = dic[x], dy = dic[y];
                if (cnt[dx] > cnt[dy]) {
                    swap(dic[x], dic[y]);
                }
                merge(dic[x], dic[y]);
            } else {
                printf("%d\n", query(y) - query(x) + 1);
            }
        }
    }
    return 0;
}
