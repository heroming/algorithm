/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/16 08:30:08
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

const int n = 5;
const int m = 6;
const int N = 30;
const int maxn = 10;
const int maxm = 35;

const int dx[] = {0, -1, 0, 1, 0};
const int dy[] = {0, 0, 1, 0, -1};

char s[maxn][maxn];
int w[maxm][maxm];

inline bool valid(const int x, const int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

inline void swap_row(const int a, const int b) {
    if (a == b) return;
    form (i, 0, N) swap(w[a][i], w[b][i]);
}

void gauss_elimination() {
    forn (k, N) {
        int idx = -1;
        form (i, k, N - 1) {
            if (w[i][k]) {
                idx = i;
                break;
            }
        }
        swap_row(k, idx);
        forn (i, N) {
            if (i == k || w[i][k] == 0) continue;
            form (j, k, N) {
                w[i][j] ^= w[k][j];
            }
        }
    }
}

int main() {
    forn (i, n) scanf("%s", s[i]);
    clr(w, 0);
    forn (i, n) forn (j, m) {
        int x = i * m + j;
        forn (k, 5) {
            int a = i + dx[k], b = j + dy[k];
            if (valid(a, b)) {
                int y = a * m + b;
                w[x][y] = 1;
            }
        }
        w[x][N] = (s[i][j] - '0') ^ 1;
    }
    gauss_elimination();
    int ans = 0;
    forn (k, N) if (w[k][N]) ++ ans;
    printf("%d\n", ans);
    forn (k, N) if (w[k][N]) printf("%d %d\n", k / m + 1, k % m + 1);
    return 0;
}
