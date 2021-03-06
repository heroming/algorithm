/*
 * Author:heroming
 * File:1004.cpp
 * Time:2017/09/01 10:59:19
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

const int maxn = 100010;

struct Dancer {
    int id, x, y, t, s;
    bool operator < (const Dancer & dan) const {
        return s < dan.s;
    }
} d;

int n, w, h;
vector<Dancer> u, v;

int main() {
    scanf("%d%d%d", &n, &w, &h);
    int g;
    forn (i, n) {
        scanf("%d", &g);
        d.id = i;
        d.x = d.y = 0;
        if (g == 1) {
            scanf("%d%d", &d.x, &d.t);
            v.pb(d);
        } else {
            scanf("%d%d", &d.y, &d.t);
            u.pb(d);
        }
    }
    if (sz(u) <= sz(v)) {
        rep (it, v) it.s = it.t + it.x;
        sort(all(v));

    } else {

    }
    get_answer();
    return 0;
}
