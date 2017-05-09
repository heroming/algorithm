/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/10 11:11:28
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

int t, n, m;
char s[maxn][maxn];

bool solve() {
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            if (s[i][j] == 'W') {
                if (j == 1 || j == m) return 0;
                if (s[i + 1][j] == 'A' || s[i][j - 1] == 'A' || s[i][j + 1] == 'A') return 0;
            } else if (s[i][j] == 'B') {
                if (s[i + 1][j] == 'A' || s[i + 1][j] == 'W') return 0;
            }
        }
    }
    return 1;
}

int main() {
    scanf("%d", &t);
    while (t --) {
        clr(s, 0);
        scanf("%d%d", &n, &m);
        form (i, 1, n) scanf("%s", s[i] + 1);
        printf("%s\n", solve() ? "yes" : "no");
    }
    return 0;
}
