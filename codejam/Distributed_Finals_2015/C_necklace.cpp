/*
 * Author:heroming
 * File:distributed.cpp
 * Time:2016/7/30 11:27:15
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
#include "necklace.h"
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

const lint m = GetMessageLength();
const lint n = GetNecklaceLength();

const int id = MyNodeId();
const int node = NumberOfNodes();

const lint l = n * id / node;
const lint r = n * (id + 1) / node;

const int master = 0;

const int maxn = 3010;
const int maxm = 10010;
const int inf = 0x4FFFFFFF;

int mess[maxn];
vint maps[maxm];
int dp[maxn][maxn];

// binary search
int find(const int k, const int w) {
    int len = sz(maps[k]);
    int s = 0, e = len - 1;
    while (s <= e) {
        int mi = (s + e) >> 1;
        if (maps[k][mi] < w) {
            s = mi + 1;
        } else {
            e = mi - 1;
        }
    }
    if (s == len) return -1;
    return maps[k][s];
}

int main() {
    // preprocess necklace for [l, r)
    for (lint k = l; k < r; ++ k) {
        maps[GetNecklaceElement(k)].pb(k);
    }
    
    // get all the message
    for (lint k = 0; k < m; ++ k) {
        mess[k] = GetMessageElement(k);
    }
    
    // for every start point k, check the longest substring
    for (int k = 0; k < m; ++ k) {
        int idx = k;
        int pos = l;
        while (idx < m) {
            int x = find(mess[idx], pos);
            if (x == -1) break;
            ++ idx;
            pos = x + 1;
        }
        PutInt(master, idx);
    }
    Send(master);
    
    // master receive all the data
    if (id == master) {
        for (int no = 0; no < node; ++ no) {
            Receive(no);
            for (int i = 0; i < m; ++ i) {
                dp[no][i] = GetInt(no);
            }
        }
        // check the start point
        int ans = 0;
        for (int k = 0; k < m; ++ k) {
            int idx = k;
            for (int i = 0; i < node; ++ i) {
                idx = dp[i][idx];
                if (idx == m) break;
            }
            ans = max(ans, idx - k);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
