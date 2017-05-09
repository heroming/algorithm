/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/11 06:58:38
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

const int maxn = 1010;
const int inf = 0x7FFF7FFF;

int n, ans;
int w[maxn];
bool vis[maxn];
int dis[maxn][maxn];

int main() {
    scanf("%d", &n);
    clr(vis, 1);
    form (i, 1, n) form (j, 1, n) scanf("%d", &dis[i][j]);
    vis[1] = 0;
    form (i, 1, n) w[i] = dis[1][i];
    form (k, 2, n) {
        int idx = 0, x = inf;
        form (i, 1, n) if (vis[i] && w[i] < x) {
            idx = i, x = w[i];
        }
        ans += x;
        vis[idx] = 0;
        form (i, 1, n) {
            w[i] = min(w[i], dis[idx][i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
