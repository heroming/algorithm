/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/06 11:13:05
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
typedef vector<string> vstr;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 110;

int t, n, m;
int ans[maxn];
int miss[maxn];
int path[maxn][maxn];
bool vis[maxn][maxn];

string ms[maxn];
string name[maxn];
map<string, int> mp;

vstr split(string s) {
    vstr vs;
    forv (i, s) if (s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?') s[i] = ' ';
    string c = "";
    form (i, 0, sz(s)) {
        if (i == sz(s) || s[i] == ' ') {
            if (!c.empty()) vs.pb(c);
            c = "";
        } else {
            c += s[i];
        }
    }
    return vs;
}

bool solve() {
    clr(path, -1);
    queue<pint> que;
    que.push({0, 0});
    while (!que.empty()) {
        pint p = que.front();
        que.pop();
        int k = p.px + 1, u = p.py;
        form (v, 1, n) {
            if (v != u && vis[k][v] && path[k][v] == -1) {
                path[k][v] = u;
                que.push({k, v});
            }
        }
    }
    bool flag = 0;
    form (i, 1, n) {
        if (path[m][i] != -1) {
            flag = 1;
            int u = m, v = i;
            while (u) {
                ans[u] = v;
                v = path[u --][v];
            }
            break;
        }
    }
    return flag;
}

int main() {
    scanf("%d", &t);
    while (t --) {
        mp.clear();
        clr(vis, 1);
        clr(ans, 0);
        clr(miss, 0);
        scanf("%d", &n);
        form (i, 1, n) {
            cin >> name[i];
            mp[name[i]] = i;
        }
        scanf("%d\n", &m);
        form (k, 1, m) {
            getline(cin, ms[k]);
            string s = ms[k];
            if (s[0] == '?') {
                miss[k] = 1;
                s = s.substr(2);
                vstr vs = split(s);
                rep (c, vs) {
                    auto it = mp.find(c);
                    if (it != mp.end()) {
                        vis[k][it->py] = 0;
                    }
                }
            } else {
                string c = "";
                forv (i, s) {
                    if (s[i] == ':') {
                        ans[k] = mp[c];
                        break;
                    }
                    c += s[i];
                }
                form (i, 1, n) vis[k][i] = 0;
                vis[k][ans[k]] = 1;
            }
        }
        if (solve()) {
            form (k, 1, m) {
                if (miss[k]) {
                    cout << name[ans[k]] << ms[k].substr(1) << endl;
                } else {
                    cout << ms[k] << endl;
                }
            }
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}
