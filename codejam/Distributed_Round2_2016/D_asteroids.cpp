/*
 * Author:heroming
 * File:distributed.cpp
 * Time:2016/7/15 20:11:53
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

#include "message.h"
#include "asteroids.h"

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
typedef __int128 llint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 1024;
const int extend = 300;
const int commit = 250;

const lint w = GetWidth();
const lint h = GetHeight();

const int id = MyNodeId();
const int node_all = NumberOfNodes();

// calculate actually used node
const int node_use = (w + extend  - 1) / extend;

const lint l = w * id / node_use;
const lint r = w * (id + 1) / node_use;

// calculate the boundary
const lint s = max(0ll, w * (id - 1) / node_use);
const lint e = min(w, w * (id + 2) / node_use);

const int master = 0;
const int ending = node_use - 1;

char v[maxn];
int dp[maxn];
int dup[maxn];

void make_commit() {
    if (id != master) {
        for (lint k = l; k < r; ++ k) {
            PutInt(id - 1, dp[k - s]);
        }
        Send(id - 1);
    }
    if (id != ending) {
        Receive(id + 1);
        for (lint k = r; k < e; ++ k) {
            dp[k - s] = GetInt(id + 1);
        }
    }
    if (id != ending) {
        for (lint k = l; k < r; ++ k) {
            PutInt(id + 1, dp[k - s]);
        }
        Send(id + 1);
    }
    if (id != master) {
        Receive(id - 1);
        for (lint k = s; k < l; ++ k) {
            dp[k - s] = GetInt(id - 1);
        }
    }
}

int main() {

    clr(dp, 0);
    
    // for small data set
    if (w < maxn) {

        if (id == master) {
 
            for (lint row = 0; row < h; ++ row) {

                // calculate the value of move vertical
                for (lint k = 0; k < w; ++ k) {
                    v[k] = GetPosition(row, k);
                    if (v[k] == '#') {
                        dp[k] = -1;
                    } else {
                        if (dp[k] != -1) {
                            dp[k] += v[k] - '0';
                        }
                    }
                    dup[k] = dp[k];
                }

                // calculate the value of move horizontal
                for (lint k = 0; k < w; ++ k) {
                    if (dp[k] == -1) continue;
                    if (0 <= k - 1 && v[k - 1] != '#') {
                        dup[k - 1] = max(dup[k - 1], dp[k] + v[k - 1] - '0');
                    }
                    if (k + 1 < w && v[k + 1] != '#') {
                        dup[k + 1] = max(dup[k + 1], dp[k] + v[k + 1] - '0');
                    }
                }

                memcpy(dp, dup, sizeof(dup));
            }

            // calculate the answer
            int ans = -1;
            for (lint k = 0; k < w; ++ k) {
                ans = max(ans, dp[k]);
            }
            printf("%d\n", ans);
        }

    } else {

        if (id < node_use) {
            for (lint row = 0; row < h; ++ row) {

                // calculate the value of move vertical
                for (lint k = s; k < e; ++ k) {
                    v[k - s] = GetPosition(row, k);
                    if (v[k - s] == '#') {
                        dp[k - s] = -1;
                    } else {
                        if (dp[k - s] != -1) {
                            dp[k - s] += v[k - s] - '0';
                        }
                    }
                    dup[k - s] = dp[k - s];
                }

                // calculate the value of move horizontal
                for (lint k = s; k < e; ++ k) {
                    if (dp[k - s] == -1) continue;
                    if (0 <= k - s - 1 && v[k - s - 1] != '#') {
                        dup[k - s - 1] = max(dup[k - s - 1], dp[k - s] + v[k - s - 1] - '0');
                    }
                    if (k - s + 1 < e && v[k - s + 1] != '#') {
                        dup[k - s + 1] = max(dup[k - s + 1], dp[k - s] + v[k - s + 1] - '0');
                    }
                }
                
                memcpy(dp, dup, sizeof(dup));
 
                // commit every commit row
                if ((row + 1) % commit == 0) {
                    make_commit();
                }
            }

            // commit in final
            make_commit();


            // calculate local result and send to master
            int ret = -1;
            for (lint k = l; k < r; ++ k) {
                ret = max(ret, dp[k - s]);
            }
            PutInt(master, ret);
            Send(master);

            if (id == master) {
                int ans = -1;
                for (int k = 0; k < node_use; ++ k) {
                    Receive(k);
                    ans = max(ans, GetInt(k));
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
