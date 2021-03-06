/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/12 02:52:57
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

const int MINE = 64;
const int BLANK = 32;
const int UNKNOWN = -1;
const int maxn = 210;

const int N = 8;
const int dx[N] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[N] = {-1, 0, 1, 1, 1, 0, -1, -1};

int t, n, m;
int w[maxn][maxn];
int v[maxn][maxn];
int r[maxn][maxn];

inline bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() {
    scanf("%d", &t);
    while (t --) {
        clr(w, 0);
        clr(v, 0);
        clr(r, 0);
        scanf("%d%d", &n, &m);
        form (i, 1, n) form (j, 1, m) scanf("%d", &w[i][j]);
        // rule 1
        form (i, 1, n) form (j, 1, m) {
            if (w[i][j] == 0) {
                forn (k, N) {
                    int a = i + dx[k], b = j + dy[k];
                    if (w[a][b] == UNKNOWN) v[a][b] = BLANK;
                }
            }
        }
        // rule 2
        form (i, 1, n) form (j, 1, m) {
            if (w[i][j] > 0) {
                int unknown = 0;
                forn (k, N) {
                    int a = i + dx[k], b = j + dy[k];
                    if (w[a][b] == UNKNOWN) ++ unknown;
                }
                if (unknown == w[i][j]) {
                    forn (k, N) {
                        int a = i + dx[k], b = j + dy[k];
                        if (w[a][b] == UNKNOWN) v[a][b] = MINE;
                    }
                }
            }
        }
        // rule 3
        form (i, 1, n) form (j, 1, m) {
            if (w[i][j] > 0) {
                int code = i * m + j;
                form (x, -2, 2) form (y, -2, 2) {
                    int ii = i + x, jj = j + y;
                    if (valid(ii, jj) && w[ii][jj] >= 0 && w[ii][jj] < w[i][j]) {
                        int unknown = 0;
                        forn (k, N) {
                            int a = i + dx[k], b = j + dy[k];
                            if (valid(a, b) && w[a][b] == UNKNOWN) {
                                ++ unknown;
                                r[a][b] = code;
                            }
                        }
                        int same = 0;
                        forn (k, N) {
                            int a = ii + dx[k], b = jj + dy[k];
                            if (valid(a, b) && w[a][b] == UNKNOWN) {
                                if (r[a][b] != code) {
                                    same = -1;
                                    break;
                                } else {
                                    ++ same;
                                    r[a][b] = -code;
                                }
                            }
                        }
                        if (same != -1 && unknown - same == w[i][j] - w[ii][jj]) {
                            forn (k, N) {
                                int a = i + dx[k], b = j + dy[k];
                                if (r[a][b] == code) v[a][b] = MINE;
                            }
                        }
                    }
                }
            }
        }
        int p = 0, q = 0;
        form (i, 1, n) form (j, 1, m) {
            if (v[i][j] == BLANK) {
                ++ q;
            } else if (v[i][j] == MINE) {
                ++ p;
            }
        }
        printf("%d %d\n", p, q);
    }
    return 0;
}
