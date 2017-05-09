/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/12 10:22:26
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
#define all(v) ((v).begin(), (v).end())
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

int n, m;
int v[maxn];

int solve(const int l, const int r, const int k) {
    if (r < l) return -1;
    if (l == r) return v[l];
    int idx = l - 1;
    for (int i = l; i < r; ++ i) {
        if (v[i] <= v[r]) swap(v[++ idx], v[i]);
    }
    swap(v[++ idx], v[r]);
    if (idx - l + 1 == k) return v[idx];
    if (k <= idx - l) return solve(l, idx - 1, k);
    return solve(idx + 1, r, k - (idx - l + 1));
}

int main() {
    scanf("%d%d", &n, &m);
    forn (i, n) scanf("%d", &v[i]);
    if (n < m || m <= 0) {
        printf("-1\n");
    } else {
        random_shuffle(v, v + n);
        printf("%d\n", solve(0, n - 1, m));
    }
    return 0;
}
