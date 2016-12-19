/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/16 19:28:44
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
#include <fstream>
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
#define rall(v) (v).rbegin(), (v).rend()
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

const int maxn = 100010;

int n;
lint w[maxn];

int main() {
    scanf("%d", &n);
    form (i, 0, n) scanf("%lld", &w[i]);
    lint x = w[n];
    lint ret = w[n] * ((n << 2) | 1);
    lint ans = ret;
    rform (k, 0, n - 1) {
        if (w[k] < x) {
            int m = (k << 2) | 1;
            ret += (w[k] - x) * m;
            x = w[k];
        } else {
            ret += (w[k] - x) << 1;
        }
        ans = min(ans, ret);
    }
    printf("%lld\n", ans);
    return 0;
}
