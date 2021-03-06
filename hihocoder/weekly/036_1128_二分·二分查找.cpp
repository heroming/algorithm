/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/12 08:17:15
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

int n, m, ans;
int v[maxn];

void dfs(const int l, const int r) {
    if (r < l) {
        ans = -1;
        return;
    }
    int k = l - 1;
    form (i, l, r - 1) {
        if (v[i] <= v[r]) swap(v[++ k], v[i]);
    }
    swap(v[++ k], v[r]);
    if (m == v[k]) {
        ans += k - l + 1;
        return;
    }
    if (m < v[k]) {
        dfs(l, k - 1);
    } else {
        ans += k - l + 1;
        dfs(k + 1, r);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    forn (i, n) scanf("%d", &v[i]);
    random_shuffle(v, v + n);
    dfs(0, n - 1);
    printf("%d\n", ans);
    return 0;
}
