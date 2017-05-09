/*
 * Author:heroming
 * File:b.cpp
 * Time:2017/05/09 08:01:53
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

int p, x, y;

bool valid(const int s) {
    int i = s / 50 % 475;
    forn (k, 25) {
        i = (i * 96 + 42) % 475;
        if (i + 26 == p) return 1;
    }
    return 0;
}

int main() {
    while (cin >> p >> x >> y) {
        int s = x, ans = -1;
        while (s < y) s += 50;
        while (s - 50 >= y) s -= 50;
        while (ans == -1) {
            if (valid(s)) {
                if (s <= x) {
                    ans = 0;
                } else {
                    ans = (s - x + 50) / 100;
                }
            }
            s += 50;
        }
        cout << ans << endl;
    }
    return 0;
}
