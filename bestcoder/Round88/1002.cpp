/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/1 19:09:52
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

const int maxn = 100010;

int t, n;
int x[maxn];
int w[maxn];
vint v, ans;

int main() {
    scanf("%d", &t);
    while (t --) {
        clr(w, 0);
        v.clear();
        ans.clear();
        scanf("%d", &n);
        forn (i, n) {
            scanf("%d", &x[i]);
            ++ w[x[i]];
        }
        form (i, 1, n) if (w[i]) v.pb(w[i]);
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        form (k, 1, n - 1) {
            if (n % k != 0) continue;
            int m = n / k;
            bool valid = 1;
            forv (i, v) {
                if (v[i] % m != 0) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                for (int i = 0; i < n && valid; i += k) {
                    map<int, int> mp;
                    for (int j = 0; j < k; ++ j) {
                        ++ mp[x[i + j]];
                    }
                    iter(it, mp) {
                        if (it->py * m != w[it->px]) {
                            valid = 0;
                            break;
                        }
                    }
                }
            }
            if (valid) {
                ans.pb(k);
            }
        }
        ans.pb(n);
        forv (i, ans) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
