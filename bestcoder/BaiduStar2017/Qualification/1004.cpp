/*
 * Author:heroming
 * File:1004.cpp
 * Time:2017/08/05 01:03:40
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

const int maxn = 110;
const int maxm = 1010;

int t, n, m, a, b;
int dp[maxn][maxm], ord[maxn][maxm];
string path[maxn][maxm];
string mp[maxn];

string int_to_string(const int x) {
    string s = "0";
    s[0] = char(x);
    return s;
}

int main() {
    scanf("%d", &t);
    for (int i = 1; i < maxn; ++ i) {
        mp[i] = int_to_string(i);
    }
    form (i, 1, n) dp[0][i] = -1;
    form (cas, 1, t) {
        printf("Case #%d:\n", cas);
        scanf("%d%d", &n, &m);
        form (k, 1, m) {
            scanf("%d%d", &a, &b); 
            form (i, 0, n) {
                dp[k][i] = dp[k - 1][i];
                ord[k][i] = ord[k - 1][i];
                path[k][i] = path[k - 1][i];
            }
            form (i, 0, n) if (i + b <= n && dp[k - 1][i] != -1) {
                int c = i + b;
                if (dp[k][c] < dp[k - 1][i] + a || (dp[k][c] == dp[k - 1][i] + a && ord[k - 1][i] + k < ord[k][c]) ||
                        (dp[k][c] == dp[k - 1][i] + a && ord[k - 1][i] + k == ord[k][c] && path[k - 1][i] + mp[k] < path[k][c])) {
                    dp[k][c] = dp[k - 1][i] + a;
                    ord[k][c] = ord[k - 1][i] + k;
                    path[k][c] = path[k - 1][i] + mp[k];
                }
            }
        }

        int score = 0, cost = 0;
        form (k, 0, n) if (score < dp[m][k]) {
            cost = k;
            score = dp[m][k];
        }
        printf("%d %d\n", score, cost);

        if (! path[m][cost].empty()) {
            forv (i, path[m][cost]) {
                if (i) printf(" ");
                printf("%d", int(path[m][cost][i]));
            }
            printf("\n");
        }
    }
    return 0;
}
