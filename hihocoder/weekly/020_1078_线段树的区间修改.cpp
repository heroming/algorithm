/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/10 08:16:49
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
const int maxm = 400010;

int a, b, x;
int n, m, w[maxn];
int tree[maxm], p[maxm];

void build(const int v, const int l, const int r) {
    p[v] = 0;
    if (l == r) {
        tree[v] = w[l];
        return;
    }
    int mi = (l + r) >> 1;
    build(v << 1, l, mi);
    build(v << 1 | 1, mi + 1, r);
    tree[v] = tree[v << 1] + tree[v << 1 | 1];
}

inline void push_down(const int v, const int l, const int r) {
    if (p[v] == 0) return;
    int mi = (l + r) >> 1;
    p[v << 1] = p[v];
    tree[v << 1] = p[v] * (mi - l + 1);
    p[v << 1 | 1] = p[v];
    tree[v << 1 | 1] = p[v] * (r - mi);
    p[v] = 0;
}

int query(const int v, const int l, const int r) {
    if (a <= l && r <= b) return tree[v];
    push_down(v, l, r);
    int mi = (l + r) >> 1;
    if (b <= mi) return query(v << 1, l, mi);
    if (mi < a) return query(v << 1 | 1, mi + 1, r);
    return query(v << 1, l, mi) + query(v << 1 | 1, mi + 1, r);
}

void update(const int v, const int l, const int r) {
    if (a <= l && r <= b) {
        p[v] = x;
        tree[v] = x * (r - l + 1);
        return;
    }
    push_down(v, l, r);
    int mi = (l + r) >> 1;
    if (b <= mi) {
        update(v << 1, l, mi);
    } else if (mi < a) {
        update(v << 1 | 1, mi + 1, r);
    } else {
        update(v << 1, l, mi);
        update(v << 1 | 1, mi + 1, r);
    }
    tree[v] = tree[v << 1] + tree[v << 1 | 1];
}

int main() {
    scanf("%d", &n);
    form (i, 1, n) scanf("%d", &w[i]);
    build(1, 1, n);
    scanf("%d", &m);
    int op;
    forn (i, m) {
        scanf("%d%d%d", &op, &a, &b);
        if (op) {
            scanf("%d", &x);
            update(1, 1, n);
        } else {
            printf("%d\n", query(1, 1, n));
        }
    }
    return 0;
}
