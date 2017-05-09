
/*
 * Author:heroming
 * File:d.cpp
 * Time:2017/05/04 11:16:21
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

const int maxn = 1000010;
const lint mod = 1e9 + 7;

char s[maxn];

int main() {
    while (scanf("%s", s) != EOF) {
        lint b = 0;
        lint ans = 0;
        int k = strlen(s) - 1;
        while (k >= 0 && s[k] == 'a') -- k;
        while (k >= 0 && s[k] == 'b') ++ b, -- k;
        while (k >= 0) {
            if (s[k] == 'a') {
                ans = (ans + b) % mod;
                b = (b << 1) % mod;
            } else {
                ++ b;
            }
            -- k;
        }
        cout << ans << endl;
    }
    return 0;
}
