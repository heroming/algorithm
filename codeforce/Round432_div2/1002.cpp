/*
 * Author:heroming
 * File:1002.cpp
 * Time:2017/09/04 10:45:26
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

lint a0, b0, a1, b1, a2, b2;

lint distance(lint a, lint b, lint c, lint d) {
    return (c - a) * (c - a) + (d - b) * (d - b);
}

bool equal_distance() {
    return distance(a0, b0, a1, b1) == distance(a1, b1, a2, b2);
}

bool not_in_a_line() {
    return (a1 - a0) * (b2 - b0) - (b1 - b0) * (a2 - a0) != 0;
}

int main() {
    while (cin >> a0 >> b0 >> a1 >> b1 >> a2 >> b2) {
        printf("%s\n", equal_distance() && not_in_a_line() ? "YES" : "NO");
    }
    return 0;
}
