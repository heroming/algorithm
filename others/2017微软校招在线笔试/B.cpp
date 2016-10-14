/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/10 19:14:41
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
#include <fstream>
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

const int maxn = 100010;
const int letter = 26;

int n, m;
vint maps[letter];
char c[4], s[maxn];
bool vis[letter][letter];
int w[maxn][letter];

int dis[maxn];
bool inq[maxn];
queue<int> que;

int spfa() {
    clr(dis, 0);
    clr(inq, 1);
    forn (i, n) que.push(i);
    while (! que.empty()) {
        int u = que.front();
        que.pop();
        inq[u] = 0;
        rep (it, maps[s[u]]) {
            int v = w[u + 1][it];
            if (dis[v] < dis[u] + 1) {
                dis[v] = dis[u] + 1;
                if (! inq[v]) {
                    inq[v] = 1;
                    que.push(v);
                }
            }
        }
    }
    return dis[n];
}

int main() {
    while (scanf("%d", &n) != EOF) {
        scanf("%s", s);
        forn (i, n) s[i] -= 'a';
        scanf("%d", &m);
        clr(vis, 1);
        forn (i, m) {
            scanf("%s", c);
            int a = c[0] - 'a';
            int b = c[1] - 'a';
            vis[a][b] = vis[b][a] = 0;
        }
        forn (i, letter) {
            maps[i].clear();
            forn (j, letter) {
                if (vis[i][j]) {
                    maps[i].pb(j);
                }
            }
        }
        
        forn (i, letter) w[n][i] = n;
        rforn (k, n) {
            forn (i, letter) {
                w[k][i] = w[k + 1][i];
            }
            w[k][s[k]] = k;
        }
        printf("%d\n", n - spfa());
    }
    return 0;
}

