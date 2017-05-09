/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/07 09:36:35
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

const int maxn = 300010;

struct Node {
    int x, s, id;
    Node() {}
    Node(int a, int b, int c): x(a), s(b), id(c) {}
    bool operator < (const Node & no) const {
        return x < no.x || (x == no.x && s < no.s) || (x == no.x && s == no.s && id < no.id);
    }
};

int n, m;
int px[maxn], py[maxn];

set<pint> se;
vector<Node> v;

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        v.clear();
        se.clear();
        form (i, 1, n) {
            scanf("%d%d", &px[i], &py[i]);
            v.pb(Node(px[i], 0, i));
            v.pb(Node(py[i], 1, i));
        }
        sort(all(v));
        int l = -1, r = -2;
        auto it = se.end();
        rep (no, v) {
            if (no.s == 0) {
                se.insert({no.x, no.id});
                if (sz(se) == m) {
                    it = se.end();
                    -- it;
                }
            } else {
                pint p = {px[no.id], no.id};
                if (sz(se) >= m) {
                    int ll = it->px;
                    int rr = no.x;
                    if (r - l < rr - ll) {
                        l = ll, r = rr;
                    }
                    if (p <= *it) ++ it;
                }
                se.erase(p);
            }
        }
        if (l == -1) {
            printf("0\n");
            form (i, 1, m) {
                if (i > 1) printf(" ");
                printf("%d", i);
            }
            printf("\n");
        } else {
            int cnt = 0;
            printf("%d\n", r - l + 1);
            form (i, 1, n) {
                if (px[i] <= l && py[i] >= r && cnt < m) {
                    if (cnt ++) printf(" ");
                    printf("%d", i);
                }
            }
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
