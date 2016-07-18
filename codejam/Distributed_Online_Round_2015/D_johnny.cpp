/*
 * Author:heroming
 * File:distributed.cpp
 * Time:2016/7/18 20:46:38
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
#include <unordered_map>

#include "message.h"
#include "johnny.h"

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

const lint n = NumberOfCards();

const int id = MyNodeId();
const int node = NumberOfNodes();

const lint l = n * id / node;
const lint r = n * (id + 1) / node;

const int master = 0;

const int maxn = 256;

int score[maxn];

int main() {
    
    // calculate score of range [l, r)
    for (lint k = l; k < r; ++ k) {
        int better = 0;
        for (lint i = 0; i < n; ++ i) {
            if (IsBetter(k, i)) {
                ++ better;
            }
        }
        score[k - l] = better;
    }
    
    // send all the score to master node
    PutInt(master, r - l);
    for (lint k = l; k < r; ++ k) {
        PutInt(master, score[k - l]);
    }
    Send(master);
    
    // master receive all the data and print ans
    if (id == master) {
        vector<int> score_all;
        for (int no = 0; no < node; ++ no) {
            Receive(no);
            int m = GetInt(no);
            for (int i = 0; i < m; ++ i) {
                score_all.pb(GetInt(no));
            }
        }
        sort(all(score_all), std::greater<int>());
        int idx = 0, cnt = 0, ret = 0, ans = -1;
        for (int k = 0; k + 1 < sz(score_all); ++ k) {
            ret += n - k - 1;
            cnt += score_all[k];
            if (ret == cnt) {
                ans = k + 1;
            }
        }
        if (ans == -1) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
