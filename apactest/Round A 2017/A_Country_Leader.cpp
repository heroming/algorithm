/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/7/10 12:57:25
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
typedef __int128 llint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 32;

int t, n;
char c[maxn];
int mp[maxn];
vector<string> v;

int get_count() {
    int m = strlen(c);
    clr(mp, 0);
    forn (i, m) {
        if (c[i] != ' ') {
            ++ mp[c[i] - 'A'];
        }
    }
    int ret = 0;
    forn (i, maxn) {
        if (mp[i]) ++ ret;
    }
    return ret;
}

int main() {
    freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    form (cas, 1, t) {
        printf("Case #%d: ", cas);
        scanf("%d", &n);
        getchar();
        int ans = 0;
        forn (i, n) {
            cin.getline(c, maxn);
            int cnt = get_count();
            if (ans < cnt) {
                ans = cnt;
                v.clear();
                v.pb(string(c));
            } else if (cnt == ans) {
                v.pb(string(c));
            }
        }
        sort(all(v));
        printf("%s\n", v[0].c_str());
    }
    return 0;
}
