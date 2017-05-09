/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/06 10:45:52
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

const int M = 3;
const int N = 4;
const int maxn = 8;

const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

char c[maxn][maxn];

bool valid(const int x, const int y) {
    return x >= 0 && x < N && y >= 0 && y < N && c[x][y] == 'x';
}

bool solve(const int x, const int y) {
    if (c[x][y] != '.') return 0;
    forn (k, N) {
        int u = 0, v = 0;
        int a = x + dx[k], b = y + dy[k];
        while (valid(a, b)) {
            ++ u;
            a += dx[k];
            b += dy[k];
        }
        a = x - dx[k], b = y - dy[k];
        while (valid(a, b)) {
            ++ v;
            a -= dx[k];
            b -= dy[k];
        }
        if (u + v + 1 >= M) return 1;
    }
    return 0;
}

bool win() {
    forn (i, N) forn (j, N) {
        if (solve(i, j)) return 1;
    }
    return 0;
}

int main() {
    forn (i, N) scanf("%s", c[i]);
    printf("%s\n", win() ? "YES" : "NO");
    return 0;
}
