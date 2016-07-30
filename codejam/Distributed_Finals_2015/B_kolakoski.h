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

#include "message.h"
#include "kolakoski.h"
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
typedef unsigned long long ulint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const lint n = GetIndex();

const int id = MyNodeId();
const int node = NumberOfNodes();

const lint l = n * id / node;
const lint r = n * (id + 1) / node;

const int master = 0;

const lint M = 1 << 20;
const lint N = 3000000100L >> 6;
const ulint G = 0x69B25A6D26964DA6ULL;

ulint bit[N];

int len[M];
ulint mp[M];

int main() {

    // calculate the prefix, treat every number a bit, and
    // batch solve the sequence every 20 bit
    {
        for (ulint s = 0; s < M; ++ s) {
            ulint k = 0;
            ulint x = 1;
            ulint w = 0;
            for (ulint i = 0; i < 20; ++ i) {
                w |= x << k ++;
                if ((s >> i) & 1) {
                    w |= x << k ++;
                }
                x ^= 1;
            }
            mp[s] = w;
            len[s] = k;
        }
    }

    // calculate all the sequence use the precalculated array
    // for 20 bit sequence s, find the sequence produced by s,
    // which has lenght len[s], and append it to the end
    {
        bit[0] = G;
        ulint k = 13;
        ulint t = 20;
        while (t < n) {
            ulint h = k >> 6;
            ulint l = k & 0x3F;
            ulint r = 64 - l;

            ulint s = ((bit[h] >> l) | (bit[h + 1] << r)) & 0xFFFFF;
            ulint x = mp[s];

            h = t >> 6;
            l = t & 0x3F;
            r = 64 - l;

            bit[h] |= x << l;
            bit[h + 1] = x >> r;

            k += 20;
            t += len[s];
        }
    }
    
    // simply solve the distributed sum problem
    {
        lint sum = 0;
        for (lint k = l; k < r; ++ k) {
            ulint h = k >> 6;
            ulint l = k & 0x3F;
            if ((bit[h] >> l) & 1) {
                sum += GetMultiplier(k) << 1;
            } else {
                sum += GetMultiplier(k);
            }
        }
        
        // send to master
        PutLL(master, sum);
        Send(master);
        
        // master calculate the global sum
        if (id == master) {
            lint ans = 0;
            for (int no = 0; no < node; ++ no) {
                Receive(no);
                ans += GetLL(no);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
