/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/7/23 20:32:41
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

const int maxn = 32000;

vint v;
int t, n, d;
bool vis[maxn];

void get_prime() {
    clr(vis, 1);
    for (int k = 2; k < maxn; ++ k) {
        if (vis[k]) v.pb(k);
        for (int i = 0; i < sz(v) && k * v[i] < maxn; ++ i) {
            vis[k * v[i]] = 0;
            if (k % v[i] == 0) break;
        }
    }
}

int find(const int w) {
    int l = 0, r = min(w, sz(v) - 1);
    while (l <= r) {
        int m = (l + r) >> 1;
        if (v[m] <= w) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int main() {
    get_prime();
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &d);
        if (n <= (d << 1)) {
            printf("0\n");
        } else {
            int min_div = d;
            forv (i, v) {
                if (d % v[i] == 0) {
                    min_div = v[i];
                    break;
                }
                if (d < v[i] * v[i]) break;
            }
            min_div = min(min_div, (n - 1) / d);
            printf("%d\n", find(min_div));
        }
    }
    return 0;
}
