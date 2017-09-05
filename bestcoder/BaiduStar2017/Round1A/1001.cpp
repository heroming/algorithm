/*
 * Author:heroming
 * File:1001.cpp
 * Time:2017/08/12 02:27:17
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

const int maxn = 32000;

lint t, p;

vlint prime;
bool s[maxn];

void init() {
    clr(s, 1);
    for (lint k = 2; k < maxn; ++ k) {
        if (s[k]) prime.pb(k);
        for (int i = 0; i < sz(prime) && prime[i] * k < maxn; ++ i) {
            s[prime[i] * k] = 0;
            if (k % prime[i] == 0) break;
        }
    }
}

int main() {

    init();
    cin >> t;
    while(t --) {
        cin >> p;
        lint n = p - 1;
        lint ans = 1;
        for (int i = 0; i < sz(prime) && prime[i] <= n; ++ i) {
            if (n % prime[i] == 0) {
                lint cnt = 0;
                while (n % prime[i] == 0) {
                    ++ cnt;
                    n /= prime[i];
                }
                ans *= (cnt + 1);
            }
        }
        if (n > 1) ans *= 2;
        cout << ans << endl;
    }
    return 0;
}
