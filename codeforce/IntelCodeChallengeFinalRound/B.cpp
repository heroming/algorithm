/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/8 21:21:16
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

const int maxn = 24;

int n, m;
int w[maxn];
int v[maxn][maxn];

bool swap_once() {
    int x = 0, y = 0;
    form (i, 1, m) {
        if (w[i] != i) {
            if (x == 0) {
                x = i;
            } else if (y == 0) {
                y = i;
            } else {
                x = y = -1;
                break;
            }
        }
    }
    return x + y == 0 || (x != -1 && w[x] == y && w[y] == x);
}

bool finish() {
    form (i, 1, m) if (w[i] != i) return 0;
    return 1;
}

bool valid(const int k, const int a, const int b) {
    memcpy(w, v[k], sizeof(w));
    
    // columu swap before
    swap(w[a], w[b]);
    if (swap_once()) return 1;
    
    // columu swap after
    form (i, 1, m) form (j, i + 1, m) {
        memcpy(w, v[k], sizeof(w));
        swap(w[i], w[j]);
        swap(w[a], w[b]);
        if (finish()) return 1;
    }
    return 0;
}

bool check(const int a, const int b) {
    form (i, 1, n) {
        if (! valid(i, a, b)) return 0;
    }
    return 1;
}

bool no_column_swap() {
    form (i, 1, n) {
        memcpy(w, v[i], sizeof(w));
        if (! swap_once()) return 0;
    }
    return 1;
}

bool solve() {
    if (no_column_swap()) return 1;
    form (i, 1, m) form (j, i + 1, m) if (check(i, j)) return 1;
    return 0;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        form (i, 1, n) form (j, 1, m) scanf("%d", &v[i][j]);
        printf("%s\n", solve() ? "YES" : "NO");
    }
    return 0;
}
