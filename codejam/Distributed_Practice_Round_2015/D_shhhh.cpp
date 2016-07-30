/*
 * Author:heroming
 * File:distributed.cpp
 * Time:2016/7/25 20:06:22
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

#include "shhhh.h"
#include "message.h"
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

const lint n = GetN();

const int id = MyNodeId();
const int node = NumberOfNodes();

const lint l = n * id / node;
const lint r = n * (id + 1) / node;

const int maxn = 20010;
const lint points = 10;
const lint threhold = 1000000;

const int master = 0;
const int source = 0;
const int target = 1;

const int seed = 0xABCDEF;
std::mt19937 mt(seed);

unordered_map<int, bool> dic;
map<int, pint> maps;
int g[maxn][3];

int main() {
    
    // brute force for small data
    if (n <= threhold) {
        if (id == master) {
            int ans = 0;
            lint v = 0;
            while (v != 1) {
                ++ ans;
                v = GetLeftNeighbour(v);
            }
            if ((ans << 1) < n) {
                printf("LEFT %d\n", ans);
            } else if ((ans << 1) == n) {
                printf("WHATEVER %d\n", ans);
            } else {
                printf("RIGHT %d\n", n - ans);
            }
        }
    } else {
        // structure a 2*points*node+2 dictionary
        dic[source] = 1;
        dic[target] = 1;
        
        // points number of golbal random point
        int cnt = 0, m = points * node;
        while (cnt < m) {
            int x = mt() % n;
            if (dic.count(x) == 0) {
                ++ cnt;
                dic[x] = 1;
            }
        }
        // points number of local random point
        cnt = 0;
        for (int no = 0; no < node; ++ no) {
            int ll = n * no / node;
            int rr = n * (no + 1) / node;
            while (cnt < points) {
                int x = mt() % (rr - ll) + ll;
                if (dic.count(x) == 0) {
                    ++ cnt;
                    dic[x] = 1;
                }
            }
        }
 
        // calculate the point belong to [l, r)
        int idx = 0;
        for (auto & it : dic) {
            
            int u = it.first;
            if (u < l || u >= r) continue;
 
            // calculate the distance of first point appear in the left
            int cnt = 1;
            int v = GetLeftNeighbour(u);
            
            while (dic.count(v) == 0) {
                ++ cnt;
                v = GetLeftNeighbour(v);
            }
            g[idx][0] = u;
            g[idx][1] = v;
            g[idx ++][2] = cnt;
        }
        
        // send to master
        for (int no = 0; no < node; ++ no) {
            PutInt(master, idx);
            for (int k = 0; k < idx; ++ k) {
                PutInt(master, g[k][0]);
                PutInt(master, g[k][1]);
                PutInt(master, g[k][2]);
            }
            Send(master);
        }
        
        if (id == master) {
            
            // build the graph model
            idx = 0;
            for (int no = 0; no < node; ++ no) {
                Receive(no);
                int m = GetInt(no);
                for (int k = 0; k < m; ++ k) {
                    int u = GetInt(no);
                    int v = GetInt(no);
                    int w = GetInt(no);
                    maps[u] = {v, w};
                }
            }
            
            // get the distance of source -> target
            int ans = 0;
            int x = source;
            while (x != target) {
                pint po = maps[x];
                x = po.first;
                ans += po.second;
            }
            if ((ans << 1) < n) {
                printf("LEFT %d\n", ans);
            } else if ((ans << 1) == n) {
                printf("WHATEVER %d\n", ans);
            } else {
                printf("RIGHT %d\n", n - ans);
            }
        }
    }
    return 0;
}

