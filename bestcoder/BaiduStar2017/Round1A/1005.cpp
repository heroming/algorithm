/*
 * Author:heroming
 * File:1005.cpp
 * Time:2017/08/12 02:47:51
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

inline bool is_leap_yaer(const int x) {
    return x % 400 == 0 || (x % 4 == 0 && x % 100 != 0);
}

int t;
char date[16];

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%s", date);
        int year = 0;
        for (int i = 0; i < 4; ++ i) {
            year = year * 10 + (date[i] - '0');
        }
        int month = 0;
        for (int i = 5; i < 7; ++ i) {
            month = month * 10 + (date[i] - '0');
        }
        int day = 0;
        for (int i = 8; i < 10; ++ i) {
            day = day * 10 + (date[i] - '0');
        }
        int all_day = 0;
        if (month == 2 && day == 29) {
            do {
                year += 4;
                all_day += 365 * 3 + 366;
            } while (all_day % 7 != 0);
        } else if (month < 2 || (month == 2 && day <= 28)) {
            do {
                all_day += is_leap_yaer(year) ? 366 : 365;
                ++ year;
            } while (all_day % 7 != 0);
        } else {
            do {
                ++ year;
                all_day += is_leap_yaer(year) ? 366 : 365;
            } while (all_day % 7 != 0);
        }
        printf("%04d\n", year);
    }
    return 0;
}
