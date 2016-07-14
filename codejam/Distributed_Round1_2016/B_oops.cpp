/*
 * Author:heroming
 * File:distributed.cpp
 * Time:2016/5/29 21:55:20
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
#include "oops.h"

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
    
const int node = NumberOfNodes();
const int id = MyNodeId();

const lint l = n * id / node;
const lint r = n * (id + 1) / node;

const lint inf = 2305843009213693952LL;

int main() {
    lint l_max = -inf;
    lint l_min = inf;
    for (lint k = l; k < r; ++ k) {
        lint x = GetNumber(k);
        l_max = max(l_max, x);
        l_min = min(l_min, x);
    }
    PutLL(0, l_max);
    PutLL(0, l_min);
    Send(0);

    if (id == 0) {
        for (lint i = 0; i < node; ++ i) {
            Receive(i);
            lint x = GetLL(i);
            lint y = GetLL(i);
            l_max = max(l_max, x);
            l_min = min(l_min, y);
        }
        printf("%lld\n", l_max - l_min);
    }
    return 0;
}

