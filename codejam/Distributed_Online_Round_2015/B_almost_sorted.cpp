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
#include "almost_sorted.h"

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

const int maxn = 3000010;
const lint mod = 1ll << 20;

const lint n = NumberOfFiles();
const lint dis = MaxDistance();

const int id = MyNodeId();
const int node = NumberOfNodes();

const lint l = n * id / node;
const lint r = n * (id + 1) / node;

const int master = 0;

lint v[maxn];

int main() {
    
    // calulate the bound
    lint s = max(0ll, l - dis);
    lint e = min(n, r + dis);
    for (lint k = s; k < e; ++ k) {
        v[k - s] = Identifier(k);
    }
    
    // sort the identifier
    sort(v, v + e - s);
    
    // calculate the local result
    lint ret = 0;
    for (lint k = l; k < r; ++ k) {
        ret += v[k - s] % mod * k;
    }
    
    // send result to master
    PutLL(master, ret % mod);
    Send(master);
    
    // master receive the result and print the global answer
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
