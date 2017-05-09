/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/04 10:03:12
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

struct KMP {
    string s, t;
    vector<int> nxt;

    KMP() {}
    KMP(const string & _s, const string & _t): s(_s), t(_t) {};

    void compute_prefix() {
        const int n = (int)t.size();
        nxt.assign(n, -1);
        int k = -1;
        for (int q = 1; q < n; ++ q) {
            while (k > 0 && t[k + 1] != t[q]) k = nxt[k];
            if (t[k + 1] == t[q]) ++ k;
            nxt[q] = k;
        }
    }

    int match() {
        compute_prefix();
        const int n = (int)s.size();
        const int m = (int)t.size();
        int q = -1, ans = 0;
        for (int i = 0; i < n; ++ i) {
            while (q != -1 && t[q + 1] != s[i]) q = nxt[q];
            if (t[q + 1] == s[i]) ++ q;
            if (q + 1 == m) {
                ++ ans;
                q = nxt[q];
            }
        }
        return ans;
    }
} kmp;

const int maxn = 1000010;

int n;
char t[maxn], s[maxn];

int main() {
    scanf("%d", &n);
    forn (i, n) {
        scanf("%s%s", t, s);
        kmp.t = string(t);
        kmp.s = string(s);
        printf("%d\n", kmp.match());
    }
    return 0;
}
