/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/03/31 10:54:19
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

const int maxn = 16;

int t, n, w;
char s[maxn];
map<string, pint> mp;

int main() {
    scanf("%d", &t);
    while (t --) {
        mp.clear();
        scanf("%d", &n);
        forn (i, n) {
            scanf("%s%d", s, &w);
            string c(s);
            auto it = mp.find(c);
            if (it == mp.end()) {
                mp[c] = {w, 0};
            } else {
                int x = it->py.px;
                int y = it->py.py;
                if (x < w) {
                    y = x;
                    x = w;
                } else if (y < w) {
                    y = w;
                }
                mp[c] = {x, y};
            }
        }
        int ans = 0;
        iter (it, mp) {
            ans += it->py.px + it->py.py;
        }
        printf("%d\n", ans);
    }
    return 0;
}
