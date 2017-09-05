/*
 * Author:heroming
 * File:d.cpp
 * Time:2017/08/01 12:15:42
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
typedef vector<string> vstr;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 5010;

char s[maxn];
unsigned int has[maxn][maxn];
int pali[maxn][maxn];
int ans[maxn];

bool palidrome(int a, int b, int c, int d) {
    if (has[a][b] == has[c][d]) {
        return 1;
    }
    return 0;
}

int main() {
    scanf("%s", s + 1);
    const int n = strlen(s + 1);
    for (int i = 1; i <= n; ++ i) {
        has[i][i] = s[i] - 'A';
        for (int j = i + 1; j <= n; ++ j) {
            has[i][j] = has[i][j - 1] * 61 + s[j] - 'A';
        }
        for (int j = i - 1; j >= 1; -- j) {
            has[i][j] = has[i][j + 1] * 61 + s[j] - 'A';
        }
        pali[i][i] = 1;
    }
    for (int k = 1; k <= n; ++ k) {
        for (int i = 1; i <= n; ++ i) {
            if (k & 1) {
                int x = i + (k >> 1);
                if (pali[i][x] == pali[x + 1][i + k] && palidrome(x, i, x + 1, i + k)) {
                    pali[i][i + k] = pali[i][x] + 1;
                }
            } else {
               int x = i + (k >> 1) - 1; 
               if (pali[i][x] == pali[x + 2][i + k] && palidrome(x, i, x + 2, i + k)) {
                   pali[i][i + k] = pali[i][x] + 1;
               }
            }
        }
    }
    for (int i = 1; i <= n; ++ i) {
        for (int j = i; j <= n; ++ j) {
            for (int k = 1; k <= pali[i][j]; ++ k) {
                ++ ans[k];
            }
        }
    }
    for (int i = 1; i < n; ++ i) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[n]);
    return 0;
}
