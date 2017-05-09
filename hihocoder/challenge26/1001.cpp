/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/01 07:00:37
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

const int inf = 1e9;
const int maxn = 60;
const int maxe = 10000;

vint v;
int t, n;

bool solve(int a, int b) {
    if (a == 0) return b == 1;
    if (sz(v) >= maxn) return 0;
    if (a < b) {
        v.pb(1);
        if ((b - a) / a + sz(v) >= maxn) return 0;
        return solve(a, b - a);
    } else {
        v.pb(0);
        if ((a - b) / b + sz(v) >= maxn) return 0;
        return solve(a - b, b);
    } 
}

int main() {
    scanf("%d", &t);
    while (t --) {
        v.clear();
        scanf("%d", &n);
        if (n <= maxe) {
            rform (i, (n >> 1) + 1, n) {
                v.clear();
                if (solve(i, n)) break;
            }
        } else {
            int a = (n >> 1) + 1, b = n;
            while (1) {
                int m = rand() % (b - a) + a;
                v.clear();
                if (solve(m, n)) break;
            }
        }
        rforn (i, sz(v)) printf("%d", v[i]);
        printf("\n");
    }
    return 0;
}
