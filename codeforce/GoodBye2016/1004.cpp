/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/12/31 10:21:00
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
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int dir = 8;
const int dx[dir] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[dir] = {0, 1, 1, 1, 0, -1, -1, -1};

const int maxn = 200;
const int maxe = 400;

int n, t[maxn];
bool grid[maxe][maxe];
int flag[maxe][maxe][dir];

void dfs(const int k, const int d, int x, int y) {
    if (k == n) return;
    if (flag[x][y][d] & (1 << k)) return;
    flag[x][y][d] |= (1 << k);
    forn (i, t[k]) {
        x += dx[d];
        y += dy[d];
        grid[x][y] = 1;
    }
    dfs(k + 1, (d + 1) % dir, x, y);
    dfs(k + 1, (d - 1 + dir) % dir, x, y);
}

int main() {
    scanf("%d", &n);
    forn (i, n) scanf("%d", &t[i]);
    dfs(0, 0, maxn, maxn);
    int ans = 0;
    forn (i, maxe) forn (j, maxe) {
        ans += grid[i][j];
    }
    printf("%d\n", ans);
    return 0;
}
