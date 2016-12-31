/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/12/30 11:14:59
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
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 8;
const int mod = 40000;

const int N = 0;
const int S = 20000;

int n, x;
char s[maxn];

int main() {
    while (scanf("%d", &n) != EOF) {
        int w = 0;
        bool ans = 1;
        forn (i, n) {
            scanf("%d%s", &x, s);
            if (w == N && s[0] != 'S') ans = 0;
            if (w == S && s[0] != 'N') ans = 0;
            if (s[0] == 'S') {
                if (w + x > S) ans = 0;
                w += x;
            } else if (s[0] == 'N') {
                if (w < x) ans = 0;
                w -= x;
            }
            if (w > S) w = mod - w;
        }
        if (w != 0) ans = 0;
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}
