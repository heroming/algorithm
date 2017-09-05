/*
 * Author:heroming
 * File:c.cpp
 * Time:2017/07/31 10:59:58
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
typedef vector<string> vstr;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 110;
const int maxe = 100010;

int n, q, c;
int w[maxn][maxn];
vint v[maxn][maxn];
int ans[maxe], u[maxe][5];

int main() {
    scanf("%d%d%d", &n, &q, &c);
    int x, y, s;
    forn (i, n) {
        scanf("%d%d%d", &x, &y, &s);
        v[x][y].pb(s);
    }
    forn (i, q) {
        scanf("%d%d%d%d%d", &u[i][0], &u[i][1], &u[i][2], &u[i][3], &u[i][4]);
        u[i][0] %= (c + 1);
    }
    form (l, 0, c) {
        clr (w, 0);
        form (i, 1, 100) form (j, 1, 100) {
            w[i][j] = w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];
            rep (it, v[i][j]) {
                w[i][j] += (it + l) % (c + 1);
            }
        }
        forn (i, q) if (u[i][0] == l) {
            int a = u[i][1], b = u[i][2];
            int c = u[i][3], d = u[i][4];
            ans[i] = w[c][d] + w[a - 1][b - 1] - w[a - 1][d] - w[c][b - 1];
        }
    }
    forn (i, q) printf("%d\n", ans[i]);
    return 0;
}
