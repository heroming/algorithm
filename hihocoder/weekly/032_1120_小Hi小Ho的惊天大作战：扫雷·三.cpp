/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/12 04:42:38
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

const int N = 8;
const int maxn = 16;
const int dx[N] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[N] = {-1, 0, 1, 1, 1, 0, -1, -1};

const int BLANK = 16;
const int MINE = 256;
const int UNKNOWN = -1;

struct Mine {
    int x, y, w;
    bool operator < (const Mine & mi) const {
        return w < mi.w;
    }
} mine;


int t, n, m;
int w[maxn][maxn];
int ans, s[maxn], u[maxn];
vector<Mine> v;

inline bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

inline bool check() {
    form (i, 1, n) form (j, 1, m) if (w[i][j] >= 0 && w[i][j] <= 8) {
        int mine = 0;
        forn (k, N) {
            int a = i + dx[k], b = j + dy[k];
            if (valid(a, b) && w[a][b] == MINE) ++ mine;
        }
        if (mine != w[i][j]) return 0;
    }
    return 1;
}

void dfs(const int k) {
    if (k == sz(v)) {
        if (check()) {
            ++ ans;
            forv (i, v) s[i] += u[i];
        }
        return;
    }
    // blank
    u[k] = 0;
    w[v[k].x][v[k].y] = BLANK;
    dfs(k + 1);
    // mine
    u[k] = 1;
    w[v[k].x][v[k].y] = MINE;
    bool ok = 1;
    forn (i, N) {
        int a = v[k].x + dx[i], b = v[k].y + dy[i];
        if (valid(a, b) && w[a][b] >= 1 && w[a][b] <= 8) {
            int mine = 0;
            forn (j, N) {
                int c = a + dx[j], d = b + dy[j];
                if (valid(c, d) && w[c][d] == MINE) ++ mine;
            }
            if (w[a][b] < mine) {
                ok = 0;
                break;
            }
        }
    }
    if (ok) dfs(k + 1);
    w[v[k].x][v[k].y] = UNKNOWN;
}

int main() {
    scanf("%d", &t);
    while (t --) {
        ans = 0;
        v.clear();
        clr(w, 0);
        clr(s, 0);
        scanf("%d%d", &n, &m);
        form (i, 1, n) form (j, 1, m) scanf("%d", &w[i][j]);
        // rule 1
        form (i, 1, n) form (j, 1, m) if (w[i][j] == 0) {
            forn (k, N) {
                int a = i + dx[k], b = j + dy[k];
                if (valid(a, b) && w[a][b] == UNKNOWN) w[a][b] = BLANK;
            }
        }
        // rule 2
        form (i, 1, n) form (j, 1, m) if (w[i][j] > 0 && w[i][j] <= 8) {
            int unknown = 0, mine = 0;
            forn (k, N) {
                int a = i + dx[k], b = j + dy[k];
                if (valid(a, b)) {
                    if (w[a][b] == MINE) ++ mine;
                    if (w[a][b] == UNKNOWN) ++ unknown;
                }
            }
            if (unknown + mine == w[i][j]) {
                forn (k, N) {
                    int a = i + dx[k], b = j + dy[k];
                    if (valid(a, b) && w[a][b] == UNKNOWN) w[a][b] = MINE;
                }
            }
        }
        form (i, 1, n) form (j, 1, m) if (w[i][j] == UNKNOWN) {
            mine.x = i, mine.y = j, mine.w = 0;
            forn (k, N) {
                int a = i + dx[k], b = j + dy[k];
                if (w[a][b] > 0 && w[a][b] <= 8) mine.w += w[a][b];
            }
            v.pb(mine);
        }
        sort(all(v));
        dfs(0);
        int p = 0, q = 0;
        form (i, 1, n) form (j, 1, m) {
            if (w[i][j] == MINE) ++ p;
            if (w[i][j] == BLANK) ++ q;
        }
        forv (i, v) {
            if (s[i] == 0) ++ q;
            if (s[i] == ans) ++ p;
        }
        printf("%d %d\n", p, q);
    }
    return 0;
}
