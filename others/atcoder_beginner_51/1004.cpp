/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/07 08:21:17
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

const int maxn = 110;
const int maxm = 1010;
const int inf = 10001000;

int n, m;
int dis[maxn][maxn];
int u[maxm], v[maxm], w[maxm];

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        form (i, 1, n) form (j, 1, n) dis[i][j] = (i == j ? 0 : inf);
        forn (i, m) {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            dis[u[i]][v[i]] = dis[v[i]][u[i]] = w[i];
        }
        form (k, 1, n) form (i, 1, n) form (j, 1, n) {
            if (dis[i][k] + dis[k][j] < dis[i][j]) {
                dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
        int ans = 0;
        forn (i, m) {
            if (dis[u[i]][v[i]] < w[i]) ++ ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
