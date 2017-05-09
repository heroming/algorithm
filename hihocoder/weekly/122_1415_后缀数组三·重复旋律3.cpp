/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/09 11:30:30
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

const int chars = 32;
const int maxn = 200010;

int n, s[maxn];
int a[maxn], b[maxn], x[maxn], y[maxn];
int sa[maxn], tsa[maxn], ranking[maxn], height[maxn];

void suffix_array() {
    for (int i = 0; i < chars; ++ i) a[i] = 0;
    for (int i = 1; i <= n; ++ i) ++ a[s[i]];
    for (int i = 1; i < chars; ++ i) a[i] += a[i - 1];
    for (int i = n; i; -- i) sa[a[s[i]] --] = i;
    ranking[sa[1]] = 1;
    for (int i = 2; i <= n; ++ i) {
        ranking[sa[i]] = ranking[sa[i - 1]];
        if (s[sa[i]] != s[sa[i - 1]]) ++ ranking[sa[i]];
    }
    for (int l = 1; ranking[sa[n]] < n; l <<= 1) {
        for (int i = 0; i <= n; ++ i) a[i] = b[i] = 0;
        for (int i = 1; i <= n; ++ i) {
            ++ a[x[i] = ranking[i]];
            ++ b[y[i] = (i + l <= n ? ranking[i + l] : 0)];
        }
        for (int i = 1; i <= n; ++ i) a[i] += a[i - 1], b[i] += b[i - 1];
        for (int i = n; i; -- i) tsa[b[y[i]] --] = i;
        for (int i = n; i; -- i) sa[a[x[tsa[i]]] --] = tsa[i];
        ranking[sa[1]] = 1;
        for (int i = 2; i <= n; ++ i) {
            ranking[sa[i]] = ranking[sa[i - 1]];
            if (x[sa[i]] != x[sa[i - 1]] || y[sa[i]] != y[sa[i - 1]]) ++ ranking[sa[i]];
        }
    }
    for (int i = 1, j = 0; i <= n; ++ i) {
        if (j) -- j;
        while (s[i + j] == s[sa[ranking[i] - 1] + j]) ++ j;
        height[ranking[i]] = j;
    }
}

char s1[maxn], s2[maxn];

int main() {
    scanf("%s%s", s1, s2);
    n = 0;
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    forn (i, n1) s[++ n] = s1[i] - 'a' + 1;
    s[++ n] = 27;
    forn (i, n2) s[++ n] = s2[i] - 'a' + 1;
    suffix_array();
    int ans = 0;
    int sp = n1 + 1;
    form (i, 1, n) {
        if (ans < height[i] && ((sa[i - 1] < sp && sa[i] > sp) || (sa[i - 1] > sp && sa[i] < sp))) {
            ans = height[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
