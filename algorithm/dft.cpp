/*
 * Author:heroming
 * File:dft.cpp
 * Time:2016/07/15 12:23:09
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
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 64;
const double pi = acos(-1.0);
const double e = 2.0 * pi / maxn;

double v[maxn];
double a[maxn], b[maxn];
double x[maxn], y[maxn];

void dft() {
    for (int k = 0; k < maxn; ++ k) {
        x[k] = y[k] = 0.0;
        for (int i = 0; i < maxn; ++ i) {
            double l_cos = cos(e * k * i);
            double l_sin = sin(e * k * i);
            x[k] += v[i] * l_cos;
            y[k] -= v[i] * l_sin;
        }
    }
}

void idft() {
    for (int k = 0; k < maxn; ++ k) {
        a[k] = b[k] = 0.0;
        for (int i = 0; i < maxn; ++ i) {
            double l_cos = cos(e * k * i);
            double l_sin = sin(e * k * i);
            a[k] += x[i] * l_cos - y[i] * l_sin;
            b[k] += x[i] * l_sin + y[i] * l_cos;
        }
        a[k] /= maxn;
    }
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.dat", "w", stdout);
    for (int i = 0; i < maxn; ++ i) {
        scanf("%lf", &v[i]);
    }
    dft();
    const double threshold = 2000.0;
    int cnt = 0;
    for (int i = 0; i < maxn; ++ i) {
        double fre = sqrt(x[i] * x[i] + y[i] * y[i]);
        printf("%.6lf\n", fre < threshold ? 0.0 : 500);
        if (fre < threshold) {
            ++ cnt;
            x[i] = y[i] = 0.0;
        }
    }
    idft();
    freopen("data.out", "w", stdout);
    for (int i = 0; i < maxn; ++ i) {
        printf("%.6lf\n", a[i]);
    }
    freopen("/dev/tty", "w", stdout);
    double sum = 0.0, dif = 0.0;
    for (int i = 0; i < maxn; ++ i) {
        sum += v[i];
        dif += abs(v[i] - a[i]);
    }
    printf("%d : %.2lf\n", cnt, dif / sum * 100.0);
    return 0;
}
