/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/12/27 12:22:00
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

const int maxn = 100010;

int n, m;
char c[maxn];
char s[maxn];

int main() {
    scanf("%d%s", &m, c);
    n = strlen(c);
    int top = -1;
    forn (i, n) {
        if (n - i + top + 1 == m) {
            while (i < n) s[++ top] = c[i ++];
        } else {
            while (top >= 0 && c[i] < s[top] && m < n - i + top + 1) -- top;
            if (top + 1 < m) s[++ top] = c[i];
        }
    }
    s[++ top] = 0;
    printf("%s\n", s);
    return 0;
}
