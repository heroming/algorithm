/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/7/24 9:39:13
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

const int maxn = 1024;
const int inf = 0x7fffffff;
int t, n, m;
int w[maxn][maxn];
int stk[maxn], top;
int L[maxn][maxn], R[maxn][maxn];
int U[maxn][maxn], D[maxn][maxn];

inline int solve(const int l, const int x, const int r) {
    int a = x - l + 1;
    int b = r - x + 1;
    return (a * (a + 1) >> 1) * b + (b * (b - 1) >> 1) * a;
}

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        form (i, 1, n) {
            form (j, 1, m) {
                scanf("%d", &w[i][j]);
            }
        }
        form (i, 1, n) {
            w[i][0] = -1;
            stk[top = 0] = 0;
            form (j, 1, m) {
                while (w[i][j] < w[i][stk[top]]) -- top;
                L[i][j] = stk[top] + 1;
                stk[++ top] = j;
            }

            w[i][m + 1] = -1;
            stk[top = 0] = m + 1;
            rform(j, 1, m) {
                while (w[i][j] < w[i][stk[top]]) -- top;
                R[i][j] = stk[top] - 1;
                stk[++ top] = j;
            }
        }
        form (i, 1, m) {
            w[0][i] = inf;
            stk[top = 0] = 0;
            form (j, 1, n) {
                while (w[stk[top]][i] < w[j][i]) -- top;
                U[j][i] = stk[top] + 1;
                stk[++ top] = j;
            }

            w[n + 1][i] = inf;
            stk[top = n + 1] = n + 1;
            rform(j, 1, n) {
                while (w[stk[top]][i] < w[j][i]) -- top;
                D[j][i] = stk[top] - 1;
                stk[++ top] = j;
            }
        }
        int ans = 0;
        form (i, 1, n) {
            form (j, 1, m) {
                ans += w[i][j] * solve(L[i][j], j, R[i][j]) * solve(U[i][j], i, D[i][j]);
            }
        }
        printf("%u\n", (unsigned int)ans);
    }
    return 0;
}
