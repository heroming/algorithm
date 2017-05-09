/*
 * Author:heroming
 * File:c.cpp
 * Time:2017/05/09 08:13:06
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

int t;
lint x, y, p, q;

const lint inf = 0x7777FFFF7777FFFF;

int main() {
    scanf("%d", &t);
    while (t --) {
        lint ans;
        cin >> x >> y >> p >> q;
        if (p == q) {
            if (x == y) {
                ans = 0;
            } else {
                ans = -1;
            }
        } else if (p == 0) {
           if (x == 0) {
               ans = 0;
           } else {
               ans = -1;
           } 
        } else {
            lint l = 1, r = inf / q;
            while (l <= r) {
                lint m = (l + r) >> 1;
                if (y <= q * m) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }

            lint pp = p * l;
            lint s = q * l - y;
 
            if (x <= pp && x + s >= pp) {
                ans = q * l - y;
            } else {
                if (x > pp) {
                    lint k = (x - p * l + p - 1) / p;
                    ans = q * (l + k) - y;
                } else {
                    lint k = (pp - x - s + q - p - 1) / (q - p);
                    ans = q * (l + k) - y;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
