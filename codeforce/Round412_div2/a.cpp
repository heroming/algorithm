/*
 * Author:heroming
 * File:a.cpp
 * Time:2017/05/08 02:08:00
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
typedef vector<string> vstr;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 1010;

int n;
int a[maxn], b[maxn];

bool rated() {
    forn (i, n) {
        if (a[i] != b[i]) return 1;
    }
    return 0;
}

bool unrated() {
    forn (i, n) {
        if (i && a[i] > a[i - 1]) return 1;
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    forn (i, n) scanf("%d%d", &a[i], &b[i]);
    if (rated()) {
        printf("rated\n");
    } else if (unrated()) {
        printf("unrated\n");
    } else {
        printf("maybe\n");
    }
    return 0;
}
