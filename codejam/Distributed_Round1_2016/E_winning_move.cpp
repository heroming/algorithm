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
#include "winning_move.h"
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

const lint n = GetNumPlayers();

const lint a = 7;
const lint b = 1e4 + 7;
const lint mod = 1e6 + 3;
const lint inf = 0x4FFFFFFFFFFFFFFFLL;

const int id = MyNodeId();
const int node = NumberOfNodes();

const int master = 0;

unordered_map<lint, int> dic;

int main() {
    
    // use hash fuction to handle data belong to own node
    forn (k, n) {
        lint x = GetSubmission(k);
        if ((a * x + b) % mod % node == id) {
            ++ dic[x];
        }
    }
    
    // use hash_map to keep result
    lint ret = inf;
    iter(it, dic) {
        if (it->second == 1 && it->first < ret) {
            ret = it->first;
        }
    }
    
    // send data to master
    PutLL(master, ret);
    Send(master);
    
    // master calculate and print ans
    if (id == master) {
        lint ans = inf;
        forn (no, node) {
            Receive(no);
            ans = min(ans, GetLL(no));
        }
        printf("%lld\n", ans == inf ? 0 : ans);
    }
    return 0;
}
