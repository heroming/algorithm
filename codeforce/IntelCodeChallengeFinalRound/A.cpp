/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/8 21:59:27
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

const vstring WEEK {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

string s, t;

int find(const string & x) {
    forv (i, WEEK) if (WEEK[i] == x) return i;
    return -1;
}

int main() {
    while (cin >> s >> t) {
        int a = find(s);
        int b = find(t);
        int w = (b - a + 7) % 7;
        printf("%s\n", (w == 0 || w == 3 || w == 2) ? "YES" : "NO");
    }
    return 0;
}
