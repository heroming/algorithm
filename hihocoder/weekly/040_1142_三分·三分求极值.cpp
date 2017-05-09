/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/13 08:56:44
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
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const double inf = 200;
const double eps = 1e-6;
int a, b, c, x, y;

inline double distance(const double p) {
    double q = a * p * p + b * p + c;
    return (p - x) * (p - x) + (q - y) * (q - y);
}

int main() {
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
    double l = -inf, r = inf;
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = l + (r - l) * 2 / 3;
        double d1 = distance(m1);
        double d2 = distance(m2);
        if (d1 < d2) {
            r = m2;
        } else {
            l = m1;
        }
    }
    printf("%.3lf\n", sqrt(distance(l)));
    return 0;
}
