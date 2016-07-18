/*
 * Author:heroming
 * File:fft.cpp
 * Time:2016/07/18 03:55:27
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

const int maxn = 1024;
const double pi = acos(-1.0);

struct Complex {
    double x, y;
    Complex(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}
    Complex operator + (const Complex & a) const {
        return Complex(x + a.x, y + a.y);
    }
    Complex operator - (const Complex & a) const {
        return Complex(x - a.x, y - a.y);
    }
    Complex operator * (const Complex & a) const {
        return Complex(x * a.x - y * a.y, x * a.y + y * a.x);
    }
};

void dft(Complex src[], Complex dst[], const int n, const int on) {
    const double e = 2.0 * pi / n;
    forn (k, n) {
        dst[k].x = dst[k].y = 0.0;
        forn (i, n) {
            Complex w(cos(k * i * e), -on * sin(k * i * e));
            dst[k] = dst[k] + src[i] * w;
        }
        if (on == -1) {
            dst[k].x /= n;
        }
    }
}

vector<Complex> fft(const vector<Complex> & u, const int on) {
    int n = sz(u);
    if (n == 1) return u;
    
    double e = 2.0 * pi / n;
    Complex w = Complex(1.0, 0.0);
    Complex wn = Complex(cos(e), -on * sin(e));
    vector<Complex> le, ri, v(n);
    forn (i, n) {
        if (i & 1) {
            ri.pb(u[i]);
        } else {
            le.pb(u[i]);
        }
    }
    le = fft(le, on);
    ri = fft(ri, on);
    forn (k, n >> 1) {
        Complex t = w * ri[k];
        v[k] = le[k] + t;
        v[k + (n >> 1)] = le[k] - t;
        w = w * wn;
    }
    return v;
}

void butterfly(Complex v[], const int n) {
    for(int i = 0, j = 0; i < n; ++ i) {
        if(i < j) swap(v[i], v[j]);
        int k = n;
        while (j & (k >>= 1)) j ^= k;
        j |= k;
    }
}

void fft(Complex v[], const int n, const int on) {
    butterfly(v, n);
    const double e = -on * 2.0 * pi;
    for (int m = 2; m <= n; m <<= 1) {
        Complex wn(cos(e / m), sin(e / m));
        for (int i = 0; i < n; i += m) {
            Complex w(1.0, 0.0);
            int h = m >> 1;
            for (int k = i; k < i + h; ++ k) {
                Complex u = v[k];
                Complex t = w * v[k + h];
                v[k] = u + t;
                v[k + h] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1) {
        for (int i = 0; i < n; ++ i) {
            v[i].x /= n;
        }
    }
}

Complex a[maxn];
Complex b[maxn];
Complex c[maxn];
vector<Complex> u;

int main() {
    clock_t start, end;

    srand(0);
    forn (i, maxn) {
        a[i].x = rand() % 100;
        u.pb(a[i]);
    }

    start = clock();
    dft(a, b, maxn, 1);
    dft(b, c, maxn, -1);
    end = clock();
    printf("======= %lf =======\n", (end - start + 0.0) / CLOCKS_PER_SEC);

    start = clock();
    vector<Complex> ret = fft(u, 1);
    vector<Complex> ans = fft(ret, -1);
    end = clock();
    forn (i, maxn) ans[i].x /= maxn;
    printf("======= %lf =======\n", (end - start + 0.0) / CLOCKS_PER_SEC);

    start = clock();
    fft(a, maxn, 1);
    fft(a, maxn, -1);
    end = clock();
    printf("======= %lf =======\n", (end - start + 0.0) / CLOCKS_PER_SEC);

    return 0;
}
