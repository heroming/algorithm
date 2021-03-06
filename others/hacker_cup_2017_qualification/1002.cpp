/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/07 11:28:24
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

const int N = 50;

vint v;
int t, n, w;

int main() {
    freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    form (cas, 1, t) {
        v.clear();
        scanf("%d", &n);
        
        int ans = 0;
        forn (i, n) {
            scanf("%d", &w);
            if (w < N) {
                v.pb(w);
            } else {
                ++ ans;
            }
        }
        sort(all(v));
        int l = 0, r = sz(v) - 1;
        while (l <= r) {
            int x = v[r --];
            int s = x;
            while (l <= r && s < N) {
                ++ l;
                s += x;
            }
            if (s >= N) ++ ans;
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
