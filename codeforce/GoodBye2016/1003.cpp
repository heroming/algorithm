/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/12/30 09:58:36
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
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 200010;
const int inf = 0x7FFFFFFF;

int n, c[maxn], d[maxn];

bool valid(int s) {
   forn (i, n) {
       if (d[i] == 1) {
           if (s < 1900) return 0;
       } else {
           if (s > 1899) return 0;
       }
       s += c[i];
   } 
   return 1;
}

int main() {
    scanf("%d", &n);
    int one = 0, two = 0;
    forn (i, n) {
        scanf("%d%d", &c[i], &d[i]);
        if (d[i] == 1) {
            ++ one;
        } else {
            ++ two;
        }
    }
    if (one == n) {
        printf("Infinity\n");
    } else if (two == n) {
        int m = 0;
        int s = 0;
        for (int i = 0; i < n; ++ i) {
            s += c[i];
            m = max(m, s);
        }
        if (c[n - 1] > 0 && m == s) {
            m -= c[n - 1];
        }
        int ans = 1899 - m;
        forn (i, n) ans += c[i];
        printf("%d\n", ans);
    } else {
        int s = c[0];
        int min_x = 0, max_x = 0;
        for (int i = 1; i < n; ++ i) {
            if (d[i - 1] != d[i]) {
                if (d[i] == 1) {
                    min_x = 1900 - s;
                    max_x = 1899 + c[i - 1] - s;
                } else {
                    min_x = 1900 + c[i - 1] - s;
                    max_x = 1899 - s;
                }
                break;
            }
            s += c[i];
        }
        int ans = inf;
        for (int i = max_x; i >= min_x; -- i) {
            if (valid(i)) {
                ans = i;
                forn (k, n) ans += c[k];
                break;
            }
        }
        if (ans == inf) {
            printf("Impossible\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
