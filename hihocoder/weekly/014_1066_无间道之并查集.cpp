/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/10 06:51:46
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

const int maxn = 200010;

int n, idx, p[maxn];
map<string, int> mp;

int find(const string & s) {
    auto it = mp.find(s);
    if (it != mp.end()) return it->py;
    mp[s] = ++ idx;
    return idx;
}

void init_set() {
    forn (i, maxn) {
        p[i] = i;
    }
}

int find_set(int x) {
    if (p[x] != x) p[x] = find_set(p[x]);
    return p[x];
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) p[b] = a;
} 

int main() {
    cin >> n;
    init_set();
    int op;
    string a, b;
    forn (i, n) {
        cin >> op >> a >> b;
        int x = find(a);
        int y = find(b);
        if (op == 0) {
            union_set(x, y);
        } else {
            x = find_set(x);
            y = find_set(y);
            cout << (x == y ? "yes" : "no") << endl;
        }
    }
    return 0;
}
