/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/23 10:40:52
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

const int maxn = 50010;

struct node {
    int x, y, id;
    node() {}
    node(int _x, int _y, int _id): x(_x), y(_y), id(_id) {}
    bool operator < (const node & no) const {
        return x < no.x || (x == no.x && y < no.y);
    }
};

int t, n;
vector<node> v;
int a[maxn], b[maxn], c[maxn];

int main() {
    scanf("%d", &t);
    while (t --) {
        v.clear();
        scanf("%d", &n);
        int l, r;
        forn (i, n) {
            scanf("%d%d%d%d%d", &l, &r, &a[i], &b[i], &c[i]);
            v.pb(node(l, 0, i));
            v.pb(node(r, 1, i));
        }
        sort(all(v));
        lint ans = 0, ret = 0;
        forn (i, n) ret += c[i];
        forv (i, v) {
            if (v[i].y == 0) {
                ret -= c[v[i].id];
                ret += a[v[i].id];
            } else {
                ret -= a[v[i].id];
                ret += b[v[i].id];
            }
            if (i + 1 == sz(v) || v[i].x != v[i + 1].x || v[i].y != v[i + 1].y) {
                ans = max(ans, ret);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
