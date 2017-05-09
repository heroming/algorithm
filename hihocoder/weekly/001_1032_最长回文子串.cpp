/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/04 08:44:46
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

const int maxn = 2000010;

int t;
int dp[maxn];
char s[maxn], c[maxn];


int Manacher() {
    clr(s, 0);
    int n = 0, m = strlen(c);
    s[n ++] = '^';
    s[n ++] = '#';
    forn (i, m) {
        s[n ++] = c[i];
        s[n ++] = '#';
    }
    clr(dp, 0);
    int mx = 0, id = 0;
    for (int i = 1; i < n; ++ i) {
        if (i < mx) {
            dp[i] = min(dp[2 * id - i], mx - i);
        } else {
            dp[i] = 1;
        }
        while (s[i - dp[i]] == s[i + dp[i]]) {
            ++ dp[i];
        }
        if (i + dp[i] > mx) {
            id = i;
            mx = i + dp[i];
        }
    }
    int ans = 0;
    forn (i, n) ans = max(ans, dp[i]);
    return ans - 1;
}

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%s", c);
        printf("%d\n", Manacher());
    }
    return 0;
}

