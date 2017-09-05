/*
 * Author:heroming
 * File:b.cpp
 * Time:2017/07/31 10:44:38
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

const int maxm = 10;
const int maxn = 100010;

int n;
int c[maxm];
char s[maxn];

int main() {
    while (scanf("%d%s", &n, s) != EOF) {
        const int m = strlen(s);
        clr (c, 0);
        int sum = 0;
        forn (i, m) {
            sum += s[i] - '0';
            ++ c[s[i] - '0'];
        }
        if (sum >= n) {
            printf("0\n");
        } else {
            int ans = 0;
            int left = n - sum;
            forn (i, maxm) {
                int w = 9 - i;
                if (left <= w * c[i]) {
                    ans += (left + w - 1) / w;
                    break;
                } else {
                    ans += c[i];
                    left -= w * c[i];
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
