/*
 * Author:heroming
 * File:1002.cpp
 * Time:2017/08/12 10:46:13
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

vint v;
int n, m, w;

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        v.clear();
        int seat_middle = 0;
        forn (i, m) {
            scanf("%d", &w);
            int a = w / 4, b = w % 4;
            if (seat_middle + a <= n) {
                seat_middle += a;
                if (b) v.pb(b);
            } else {
                v.pb(w - (n - seat_middle) * 4);
                seat_middle = n;
            }
        }
        if (seat_middle == n) {
            int all_seat = 0;
            rep (it, v) all_seat += (it & 1) ? it + 1 : it;
            printf("%s\n", all_seat <= n * 4 ? "YES" : "NO");
        } else {
            int cnt[4] = {0};
            rep (it, v) ++ cnt[it];
            if (cnt[3] + seat_middle < n) {
                int left = n - seat_middle - cnt[3];
                cnt[1] = max(0, cnt[1] - left);
                cnt[2] = max(0, cnt[2] - left);
                printf("%s\n", cnt[1] + cnt[2] <= n * 2 ? "YES" : "NO");
            } else {
                int seat_side = (cnt[3] + seat_middle - n) * 2;
                printf("%s\n", cnt[1] + cnt[2] + seat_side <= n * 2 ? "YES" : "NO");
            }
        }
    }
    return 0;
}
