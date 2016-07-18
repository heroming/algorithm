/*
 * Author:heroming
 * File:distributed.cpp
 * Time:2016/7/18 21:18:47
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

#include "majority.h"
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
typedef __int128 llint;
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

const int master = 0;

int main() {
    
    // calculate local majority
    int majority = 0, count = 0;
    for (lint k = l; k < r; ++ k) {
        int x = (int)GetVote(k);
        if (x == majority) {
            ++ count;
        } else {
            if (count == 0) {
                count = 1;
                majority = x;
            } else {
                -- count;
            }
        }
    }
    
    // send local majority to master
    PutInt(master, majority);
    PutInt(master, count);
    Send(master);
    
    // for master node
    if (id == master) {
        
        // master node receive information and calculate global majority
        int global_majority = 0, global_count = 0;
        for (int no = 0; no < node; ++ no) {
            Receive(no);
            int maj = GetInt(no);
            int cnt = GetInt(no);
            if (global_majority == maj) {
                global_count += cnt;
            } else {
                if (global_count - cnt < 0) {
                    global_majority = maj;
                    global_count = cnt - global_count;
                } else {
                    global_count -= cnt;
                }
            }
        }
        
        // send back global majority to make a verify
        for (int no = 0; no < node; ++ no) {
            PutInt(no, global_majority);
            Send(no);
        }
    }
    
    // receive global majority
    Receive(master);
    majority = GetInt(master);
    
    // count the vote of majority
    count = 0;
    for (lint k = l; k < r; ++ k) {
        if (GetVote(k) == majority) {
            ++ count;
        }
    }
    
    // send count to master
    PutInt(master, count);
    Send(master);
    
    // master verfity the global majority
    if (id == master) {
        int vote = 0;
        for (int no = 0; no < node; ++ no) {
            Receive(no);
            vote += GetInt(no);
        }
        if (n < (vote << 1)) {
            printf("%d\n", majority);
        } else {
            printf("NO WINNER\n");
        }
    }
    
    return 0;
}

