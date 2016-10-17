/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/16 16:48:20
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
#define rall(v) (v).rbegin(), (v).rend()
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

const int maxn = 4010;
const lint mod = 1000000007;

vint v;
string s;
map<string, lint> mp;

int t, n, m;
lint dp[maxn];

int main() {
    freopen("heroming.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin >> t;
    form (cas, 1, t) {
        printf("Case #%d:", cas);
        v.clear();
        mp.clear();
        cin >> n >> m;
        forn (i, n) {
            cin >> s;
            sort(all(s));
            ++ mp[s];
            v.pb(sz(s));
        }
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        while (m --) {
            clr(dp, 0);
            dp[0] = 1;
            cin >> s;
            forv (k, s) {
                if (dp[k] == 0) continue;
                rep (x, v) {
                    if (k + x > sz(s)) break;
                    string e = s.substr(k, x);
                    sort(all(e));
                    auto it = mp.find(e);
                    if (it != mp.end()) {
                        dp[k + x] = (dp[k + x] + dp[k] * it->py) % mod;
                    }
                }
            }
            printf(" %lld", dp[sz(s)]);
        }
        printf("\n");
        
    }
    return 0;
}
