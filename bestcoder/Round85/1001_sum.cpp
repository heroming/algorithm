/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/7/30 18:59:37
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

const int maxn = 5010;

int t, n, m, w;
bool vis[maxn];

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        clr(vis, 0);
        lint s = 0;
        vis[0] = 1;
        bool flag = 0;
        forn (i, n) {
            scanf("%d", &w);
            s += w;
            int e = s % m;
            if (vis[e]) {
                flag = 1;
            }
            vis[e] = 1;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
