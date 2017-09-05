/*
 * Author:heroming
 * File:1002.cpp
 * Time:2017/08/12 04:02:56
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

vint ans;
map<int> t;
int p[maxn];
int n, a, b, e;
set<int> se[maxn];

void init_set() {
    forn (i, maxn) p[i] = i;
}

int find_set(const int x) {
    if (p[x] != x) p[x] = find_set(p[x]);
    return p[x];
}

bool valid() {
    int x = find_set(a);
    int y = find_set(b);
    if (e) {
        if (x == y) return 1;

    }
}

int main() {
    init_set();
    scanf("%d", &n);
    int cnt = 0;
    forn (l, n) {
        ++ cnt;
        scanf("%d%d%d", &a, &b, &e);
        if (!valid()) {
            ans.pb(cnt);
            cnt = 0;
        }
    }
    return 0;
}
