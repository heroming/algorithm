/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/7/14 21:39:01
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
#include "again.h"
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

const int maxn = 32;
const int master = 0;
const lint mod = 1000000007;

const lint n = GetN();

const int id = MyNodeId();
const int node = NumberOfNodes();

const lint l = n * id / node;
const lint r = n * (id + 1) / node;

lint vect[maxn];

int main() {
    
    // calculate sum
    lint sum_part = 0;
    for (lint k = id; k < n; k += node) {
        sum_part += GetA(k);
    }
    
    // send sum to master
    PutLL(master, sum_part % mod);
    Send(master);
    
    if (id == master) {
        // master receive part sum and calculate real sum
        lint ret = 0;
        for (int k = 0; k < node; ++ k) {
            Receive(k);
            vect[k] = GetLL(k);
            ret += vect[k];
        }
        vect[node] = ret % mod;
        
        // send part sum and real sum back
        for (int k = 0; k < node; ++ k) {
            for (int i = 0; i <= node; ++ i) {
                PutLL(k, vect[i]);
            }
            Send(k);
        }
    }
    
    // get real sum form master
    Receive(master);
    for (int k = 0; k <= node; ++ k) {
        vect[k] = GetLL(master);
    }
    
    // calculate product of A and B
    lint sum_all = 0;
    for (lint k = l; k < r; ++ k) {
        lint x = node - k % node;
        if (x == node) x = 0;
        sum_all += (vect[node] - vect[x] + mod) * GetB(k) % mod;
    }
    
    // send sum to master
    PutLL(master, sum_all % mod);
    Send(master);
    
    // master get the sum and print ans
    if (id == master) {
        lint ans = 0;
        for (int k = 0; k < node; ++ k) {
            Receive(k);
            ans += GetLL(k);
        }
        printf("%lld\n", ans % mod);
    }
    
    return 0;
}
