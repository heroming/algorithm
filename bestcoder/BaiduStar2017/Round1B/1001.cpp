/*
 * Author:heroming
 * File:1001.cpp
 * Time:2017/08/13 02:09:40
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

const int maxn = 1010;
const lint mod = 1000000007;

int t, n, m;
int dp[maxn][maxn];

inline void add(int & a, const int b) {
    a += b;
    if (a >= mod) a -= mod;
}

void init() {
   for (int i = 1; i < maxn; ++ i) {
       dp[1][i] = i; 
   }
   for (int i = 2; i < maxn; ++ i) {
       for (int j = i; j < maxn; ++ j) {
           if (i < j) {
               add(dp[i][j], dp[i][j - 1] + dp[i - 1][j - 1]);
           } else {
               add(dp[i][j], dp[i - 1][j - 1]);
           }
       }
   }
}

int main() {
    init();
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        if (m < n) swap(n, m);
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
