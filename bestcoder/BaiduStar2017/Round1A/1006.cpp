/*
 * Author:heroming
 * File:1006.cpp
 * Time:2017/08/12 03:05:28
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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const int maxn = 110;

int n, m;
char s[maxn][maxn];
bool vis[maxn][maxn];

inline bool valid(const int x, const int y, const char c) {
    return x >= 0 && x < n && y >= 0 && y < m && vis[x][y] && s[x][y] == c;
}

int dfs(const int x, const int y, const char c) {
    int ret = 1;
    vis[x][y] = 0;
    forn (k, 4) {
        int a = x + dx[k];
        int b = y + dy[k];
        if (valid(a, b, c)) {
            ret += dfs(a, b, c);
        }
    }
    return ret;
}

int solve() {
    clr(vis, 1);
    int count_one = 0;
    forn (i, n) forn (j, m) if (valid(i, j, '1')) {
        if (count_one) return -1;
        count_one += dfs(i, j, '1');
    }
    if (count_one == 0) return -1;
    int border_zero = 0;
    forn (i, n) {
        if (valid(i, 0, '0')) border_zero += dfs(i, 0, '0');
        if (valid(i, m - 1, '0')) border_zero += dfs(i, m - 1, '0');
    }
    forn (j, m) {
        if (valid(0, j, '0')) border_zero += dfs(0, j, '0');
        if (valid(n - 1, j, '0')) border_zero += dfs(n - 1, j, '0');
    }
    int center_zero = 0;
    forn (i, n) forn (j, m) if (valid(i, j, '0')) {
        if (center_zero) return -1;
        center_zero += dfs(i, j, '0');
    }
    return center_zero == 0 ? 1 : 0;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        forn (i, n) scanf("%s", s[i]);
        printf("%d\n", solve());
    }
    return 0;
}
