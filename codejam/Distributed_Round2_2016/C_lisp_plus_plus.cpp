/*
 * Author:heroming
 * File:distributed.cpp
 * Time:2016/7/17 20:15:39
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
#include "lisp_plus_plus.h"

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

const lint n = GetLength();

const int id = MyNodeId();
const int node = NumberOfNodes();

const lint l = n * id / node;
const lint r = n * (id + 1) / node;

const int master = 0;

const int maxn = 128;

int local_diff[maxn];

int main() {
    
    // calculate local difference
    int diff = 0;
    for (lint k = l; k < r; ++ k) {
        diff += GetCharacter(k) == '(' ? 1 : -1;
    }
    
    // send local difference to master
    PutInt(master, diff);
    Send(master);
    
    // master receive local difference and send back prefix information to every node
    if (id == master) {
        
        // receive local difference
        for (int no = 0; no < node; ++ no) {
            Receive(no);
            local_diff[no] = GetInt(no);
        }
        
        // send back prefix information
        for (int no = 0; no < node; ++ no) {
            if (no == 0) {
                PutInt(no, 0);
            } else {
                local_diff[no] += local_diff[no - 1];
                PutInt(no, local_diff[no - 1]);
            }
            Send(no);
        }
    }
    
    // receive information from master
    Receive(master);
    int prefix = GetInt(master);
    
    // calculate first invalid position
    int pos = (int)n;
    if (prefix < 0) {
        pos = (int)l;
    } else {
        for (lint k = l; k < r; ++ k) {
            prefix += GetCharacter(k) == '(' ? 1 : -1;
            if (prefix < 0) {
                pos = k;
                break;
            }
        }
    }
 
    // send first invalid position to master
    PutInt(master, pos);
    Send(master);
    
    // master receive position information
    if (id == master) {
        int ans = (int)n;
        for (int no = 0; no < node; ++ no) {
            Receive(no);
            ans = min(ans, GetInt(no));
        }
        printf("%d\n", (ans == n && local_diff[node - 1] == 0) ? -1 : ans);
    }
    
    return 0;
}
