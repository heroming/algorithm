/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/10 07:53:18
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

const int maxn = 1000010;
const int maxm = 4000010;

int tree[maxm];
int n, m, w[maxn];

void build(const int v, const int l, const int r) {
    if (l == r) {
        tree[v] = w[l];
        return;
    }
    int mi = (l + r) >> 1;
    build(v << 1, l, mi);
    build(v << 1 | 1, mi + 1, r);
    tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
}

void update(const int v, const int l, const int r, const int x, const int w) {
    if (l == r) {
        tree[v] = w;
        return;
    }
    int mi = (l + r) >> 1;
    if (x <= mi) {
        update(v << 1, l, mi, x, w);
    } else {
        update(v << 1 | 1, mi + 1, r, x, w);
    }
    tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
}

int query(const int v, const int l, const int r, const int a, const int b) {
    if (a <= l && r <= b) return tree[v];
    int mi = (l + r) >> 1;
    if (b <= mi) return query(v << 1, l, mi, a, b);
    if (mi < a) return query(v << 1 | 1, mi + 1, r, a, b);
    return min(query(v << 1, l, mi, a, b), query(v << 1 | 1, mi + 1, r, a, b));
}

int main() {
    scanf("%d", &n);
    form (i, 1, n) scanf("%d", &w[i]);
    build(1, 1, n);
    scanf("%d", &m);
    int op, a, b;
    forn (i, m) {
        scanf("%d%d%d", &op, &a, &b);
        if (op) {
            update(1, 1, n, a, b);
        } else {
            printf("%d\n", query(1, 1, n, a, b));
        }
    }
    return 0;
}
