/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/07 10:29:38
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

struct Point {     
    double x, y;
     Point(): x(0), y(0) {} 
     Point(double a, double b): x(a), y(b) {}
     Point operator + (const Point & po) const {
         return Point(x + po.x, y + po.y);
     }
     Point operator - (const Point & po) const {
         return Point(x - po.x, y - po.y);
     
     } 
     Point operator * (const double k) const {
         return Point(x * k, y * k);
     }
     double operator * (const Point & po) const {
         return x * po.x + y * po.y;
     }
     double operator ^ (const Point & po) const {
         return x * po.y - y * po.x;
     }
     double length() const {
         return sqrt(x * x + y * y);
     }
};

const int R = 50;
const double eps = 1e-6;
const double pi = acos(-1.0);

inline int sgn(const double e) {
    return (int)(e > eps) - (e < -eps);
}

int t, p, x, y;
int main() {
    freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    Point o(R, R);
    form (cas, 1, t) {
        scanf("%d%d%d", &p, &x, &y);
        Point po = Point(x, y) - o;
        bool white = 1;
        double dis = po.length();
        if (sgn(dis - R) <= 0) {
            if (x == R && y == R) {
                if (p) white = 0;
            } else {
                double e = 2.0 * pi * p / 100;
                Point pt  = Point(sin(e), cos(e)) * R;
                if (x >= R) {
                    if (p <= R) {
                        double c = po ^ pt;
                        if (sgn(c) <= 0) white = 0;
                    } else {
                        white = 0;
                    }
                } else {
                    if (p <= R) {
                        white = 1;
                    } else {
                        double c = po ^ pt;
                        if (sgn(c) <= 0) white = 0;
                    }
                }
            }
        }
        printf("Case #%d: %s\n", cas, white ? "white" : "black");
    }
    return 0;
}
