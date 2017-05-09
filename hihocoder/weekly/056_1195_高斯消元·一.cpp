/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/15 08:47:18
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

const int maxn = 510;
const int maxm = 1010;
const double eps = 1e-8;

int n, m;
double w[maxm][maxn];

inline int sgn(const double e) {
    return (int)(e > eps) - (e < -eps);
}

void swap_row(const int a, const int b) {
    if (a == b) return;
    form (i, 1, n + 1) swap(w[a][i], w[b][i]);
}

inline int double_to_int(const double e) {
    return int(e + 0.01);
}

void normalization(const int k) {
    const double e = w[k][k];
    form (i, k, n + 1) w[k][i] /= e;
}

bool valid() {
    form (i, 1, m) {
        bool zero = 1;
        form (j, 1, n) {
            if (sgn(w[i][j]) != 0) {
                zero = 0;
                break;
            }
        }
        if (zero && sgn(w[i][n + 1]) != 0) return 0;
    }
    return 1;
}

int main() {
    scanf("%d%d", &n, &m);
    form (i, 1, m) {
        form (j, 1, n + 1) {
            scanf("%lf", &w[i][j]);
        }
    }
    int blank = 0;
    form (k, 1, n) {
        int idx = 0;
        double x = 0;
        form (i, k, m) {
            if (sgn(w[i][k]) != 0 && x < abs(w[i][k])) {
                idx = i, x = abs(w[i][k]);
            }
        }
        if (idx == 0) {
            ++ blank;
            continue;
        }
        swap_row(k, idx);
        normalization(k);
        form (i, 1, m) {
            if (i == k || sgn(w[i][k]) == 0) continue;
            double e = w[i][k];
            form (j, k, n + 1) {
                w[i][j] -= w[k][j] * e; 
            }
        }
    }
    if (valid()) {
        if (blank) {
            printf("Many solutions\n");
        } else {
            form (i, 1, n) {
                printf("%d\n", double_to_int(w[i][n + 1]));
            }
        }
    } else {
        printf("No solutions\n");
    }
    return 0;
}
