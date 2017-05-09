/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/06 10:29:25
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

int n, v[maxn];

int main() {
    while (scanf("%d", &n) != EOF) {
        int sum = 0, zero = 0;
        form (i, 1, n) {
            scanf("%d", &v[i]);
            sum += v[i];
            if (v[i] == 0) ++ zero;
        }
        if (sum) {
            printf("YES\n");
            printf("1\n1 %d\n", n);
        } else {
            if (zero == n) {
                printf("NO\n");
            } else {
                int s = 0;
                form (i, 1, n) {
                    s += v[i];
                    if (s != 0) {
                        printf("YES\n");
                        printf("2\n");
                        printf("1 %d\n%d %d\n", i, i + 1, n);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
