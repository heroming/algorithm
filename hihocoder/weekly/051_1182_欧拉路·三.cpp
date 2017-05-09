/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/14 05:02:07
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

const int maxn = 32800;

int n, m;
bool vis[maxn];
int idx, ans[maxn];

void dfs(const int u) {
    forn (i, 2) {
        int v = (u << 1) | i;
        if (!vis[v]) {
            vis[v] = 1;
            dfs(v & n);
        }
    }
    ans[idx ++] = u;
}

int main() {
    scanf("%d", &n);
    n = (1 << (n - 1)) - 1;
    dfs(0);
    for (int i = idx - 1; i > 0; -- i) printf("%d", ans[i] & 1);
    printf("\n");
    return 0;
}
