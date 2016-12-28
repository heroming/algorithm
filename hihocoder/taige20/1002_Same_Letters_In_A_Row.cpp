
/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/12/25 08:06:33
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
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int letter = 26;
const int maxn = 100010;

int n, m;
char s[maxn];
int cnt[letter];

int main() {
    scanf("%d%s", &m, s);
    n = strlen(s);
    forn (i, n) {
        ++ cnt[s[i] - 'a'];
    }
    int ans = 0;
    for (char c = 'a'; c <= 'z'; ++ c) {
        if (cnt[c - 'a'] <= ans) continue;
        if (cnt[c - 'a'] <= m) {
            ans = max(ans, cnt[c - 'a']);
        } else {
            int ret = 0;
            int l = 0, r = 0, x = 0;
            while (r < n) {
                while (r < n && x <= m) {
                    if (s[r] != c) {
                        if (x == m) break;
                        ++ x;
                    }
                    ++ r;
                }
                ret = max(ret, r - l);
                while (l < n && s[l] == c) ++ l;
                ++ l, -- x;
            }
            ans = max(ans, min(ret, cnt[c - 'a']));
        }
    }
    printf("%d\n", ans);
    return 0;
}
