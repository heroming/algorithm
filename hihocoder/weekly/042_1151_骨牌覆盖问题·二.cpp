/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/13 09:21:40
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

class Mat {
public :
    static const int N = 8;
    static const int mod = 12357;
 
    Mat() {
        clr(w, 0);
        forn (i, N) w[i][i] = 1;
    }
    Mat(const int x[N][N]) {
        forn (i, N) forn (j, N) w[i][j] = x[i][j];
    }
    void set(const int a, const int b, const int c) {
        w[a][b] = c;
    }
    int get(const int a, const int b) const {
        return w[a][b];
    }
    Mat operator * (const Mat & ma) const {
        int x[N][N];
        forn (i, N) forn (j, N) {
            x[i][j] = 0;
            forn (k, N) x[i][j] += w[i][k] * ma.w[k][j];
            x[i][j] %= mod;
        }
        return Mat(x);
    }
    Mat operator ^ (int n) const {
        Mat ret, ma = *this;
        while (n > 0) {
            if (n & 1) ret = ret * ma;
            ma = ma * ma;
            n >>= 1;
        }
        return ret;
    }
private :
    int w[N][N];
};


int main() {
    int n;
    while (cin >> n) {
        int x[Mat::N][Mat::N] = {0};
        x[3][7] = x[6][7] = x[7][3] = x[7][6] = 1;
        forn (i, Mat::N) x[i][Mat::N - i - 1] = 1;
        Mat mat(x);
        mat = mat ^ n;
        printf("%d\n", mat.get(7, 7));
    }
    return 0;
}
