/*
 * Author:heroming
 * File:1003.cpp
 * Time:2017/09/01 10:27:43
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

const int maxn = 100010;

int n;
char s[maxn];
vint v;

int find(const int w) {
    int l = 1, r = sz(v) - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (v[m] <= w) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return r;
}

int main() {
    v.pb(0);
    int sum = 0, x = 0;
    while (sum < maxn) {
        v.pb(sum);
        sum += (++ x);
    }
    while (cin >> n) {
        if (n == 0) {
            printf("a\n");
            continue;
        }
        int idx = 0, c = 0;
        while (n) {
            int k = find(n);
            n -= v[k];
            while (k --) s[idx ++] = 'a' + c;
            ++ c;
        }
        s[idx] = '\0';
        printf("%s\n", s);
    }
    return 0;
}
