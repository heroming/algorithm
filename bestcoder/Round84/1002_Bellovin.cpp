/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/7/23 19:55:29
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

vint v;
int t, n, w;

void update() {
    if (v.back() < w) {
        v.pb(w);
    } else {
        int l = 0, r = sz(v) - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (v[m] < w) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        v[l] = w;
    }
}

int find() {
    int l = 0, r = sz(v) - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (v[m] == w) return m;
        if (v[m] < w) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        v.clear();
        v.pb(0);
        forn (k, n) {
            scanf("%d", &w);
            update();
            if (k == 0) {
                printf("%d", find());
            } else {
                printf(" %d", find());
            }
        }
        printf("\n");
    }
    return 0;
}
