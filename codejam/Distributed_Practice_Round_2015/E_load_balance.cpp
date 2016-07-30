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
#include "load_balance.h"
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

const lint n = GetN();

const int id = MyNodeId();
const int node = NumberOfNodes();

const lint a = n * 1 / 3;
const lint b = n * 2 / 3;

const int master = 0;

vlint number;
vlint left_sum, middle_sum, right_sum;

void calculate(vlint & v, const int l, const int r) {
    v.pb(0);
    for (int k = l; k < r; ++ k) {
        int len = sz(v);
        lint x = number[k];
        forn (i, len) {
            v.pb(v[i] + x);
        }
    }
    sort(all(v));
}

bool solve(const lint target) {
    lint l = 0, r = sz(right_sum) - 1;
    while (l < sz(left_sum) && r >= 0) {
        lint w = left_sum[l] + right_sum[r];
        if (w == target) return 1;
        if (w < target) {
            ++ l;
        } else {
            -- r;
        }
    }
    return 0;
}

int main() {
    lint sum = 0;
    forn (i, n) {
        lint x = GetWeight(i);
        sum += x;
        number.pb(x);
    }
    char status = 1 ^ (sum & 1);
    if (status) {
        status = 0;
        calculate(left_sum, 0, a);
        calculate(middle_sum, a, b);
        calculate(right_sum, b, n);
        for (int k = id; k < sz(middle_sum); k += node) {
            lint target = (sum >> 1) - middle_sum[k];
            if (solve(target)) {
                status = 1;
                break;
            }
        }
    }
 
    PutChar(master, status);
    Send(master);
    
    if (id == master) {
        char ans = 0;
        forn (no, node) {
            Receive(no);
            ans |= GetChar(no);
        }
        printf("%s\n", ans ? "POSSIBLE" : "IMPOSSIBLE");
    }
    return 0;
}
