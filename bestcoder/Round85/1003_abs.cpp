/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/7/30 20:01:30
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

int t;
lint x;
vint v;
bool vis[maxn];

void prime() {
    clr(vis, 1);
    for (int k = 2; k < maxn; ++ k) {
        if (vis[k]) v.pb(k);
        for (int i = 0; i < sz(v) && k * v[i] < maxn; ++ i) {
            vis[k * v[i]] = 0;
            if (k % v[i] == 0) break;
        }
    }
}

bool invalid(const lint e) {
    lint m = e;
    forv (i, v) {
        if (m % v[i] == 0) {
            m /= v[i];
            if (m % v[i] == 0) return 1;
        }
    }
    return 0;
}

int main() {
    prime();
    scanf("%d", &t);
    while (t --) {
        scanf("%I64d", &x);
        lint l = max(2ll, (lint)sqrt(x + 0.0));
        lint r = max(2ll, l + 1);
        while (l >= 2 && invalid(l)) -- l;
        while (r >= 2 && invalid(r)) ++ r;
        lint ans = min(abs(x - l * l), abs(r * r - x));
        printf("%I64d\n", ans);
    }
    return 0;
}
