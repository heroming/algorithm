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

#include "sandwich.h"
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

const int maxn = 5000010;

lint taste[maxn];
lint eat_left[maxn], eat_right[maxn];

int main() {
    
    // get the taste form range [l, r)
    for (lint k = l; k < r; ++ k) {
        taste[k - l + 1] = GetTaste(k);
    }
    
    // calculate eat only eat_left
    lint sum = 0;
    for (lint k = l; k < r; ++ k) {
        sum += taste[k - l + 1];
        eat_left[k - l + 1] = max(eat_left[k - l], sum);
    }
    
    // calculate eat only eat_right
    sum = 0;
    for (lint k = r - 1; k >= l; -- k) {
        sum += taste[k - l + 1];
        eat_right[k - l + 1] = max(eat_right[k - l + 2], sum);
    }
    
    // calculate eat form two sides
    lint ret = 0;
    for (lint k = l; k < r; ++ k) {
        ret = max(ret, eat_left[k - l] + eat_right[k - l + 2]);
    }
    
    // send information to master
    PutLL(master, sum);                 // sum of all
    PutLL(master, ret);                 // eat two side
    PutLL(master, eat_left[r - l]);     // eat only eat_left
    PutLL(master, eat_right[1]);        // eat only eat_right
    Send(master);
    
    if (id == master) {
        const int maxn_all = 110;
        lint sum_all[maxn_all], ret_all[maxn_all];
        lint left_all[maxn_all], right_all[maxn_all];
        for (int no = 0; no < node; ++ no) {
            Receive(no);
            sum_all[no] = GetLL(no);
            ret_all[no] = GetLL(no);
            left_all[no] = GetLL(no);
            right_all[no] = GetLL(no);
        }
        lint ans = 0;
        lint x = 0;
        for (int a = 0; a < node; ++ a) {
            lint y = 0;
            for (int b = node - 1; b >= a; -- b) {
                if (a == b) {
                    ans = max(ans, x + y + ret_all[a]);
                } else {
                    ans = max(ans, x + y + left_all[a] + right_all[b]);
                }
                y += sum_all[b];
            }
            x += sum_all[a];
        }
        printf("%lld\n", ans);
    }
    return 0;
}

