/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/07 08:12:29
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

int main() {
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        int x = c - a, y = d - b;
        string ans = "";
        forn (i, y) ans += 'U';
        forn (i, x) ans += 'R';
        forn (i, y) ans += 'D';
        forn (i, x + 1) ans += 'L';
        forn (i, y + 1) ans += 'U';
        forn (i, x + 1) ans += 'R';
        ans += "DR";
        forn (i, y + 1) ans += 'D';
        forn (i, x + 1) ans += 'L';
        ans += 'U';
        cout << ans << endl;
    }
    return 0;
}
