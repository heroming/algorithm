/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/11 08:45:40
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

const int maxn = 100010;

int t, n;
int w[maxn], x[maxn], s[maxn];

bool solve(const int start) {
    x[1] = start;
    x[2] = w[1] - x[1];
    if (x[2] != 0 && x[2] != 1) return 0;
    form (i, 3, n) {
        x[i] = w[i - 1] - x[i - 2] - x[i - 1];;
        if (x[i] != 0 && x[i] != 1) return 0;
    }
    return w[n] == x[n] + x[n - 1];
}

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        x[0] = x[n + 1] = 0;
        form (i, 1, n) scanf("%d", &w[i]);
        clr(s, 0);
        int ok = 0; 
        int a = 0, b = 0;
        forn (i, 2) if (solve(i)) {
            ++ ok;
            form (i, 1, n) s[i] += x[i];
        }
        form (i, 1, n) {
            if (s[i] == ok) {
                ++ a;
            } else if (s[i] == 0) {
                ++ b;
            }
        }
        printf("%d", a);
        form (i, 1, n) if (s[i] == ok) printf(" %d", i);
        printf("\n");
        printf("%d", b);
        form (i, 1, n) if (s[i] == 0) printf(" %d", i);
        printf("\n");
    }
    return 0;
}
