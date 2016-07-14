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
#include "crates.h"

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

const lint mod = 1000000007;

const lint n = GetNumStacks();
    
const int node = NumberOfNodes();
const int id = MyNodeId();

const lint l = n * id / node;
const lint r = n * (id + 1) / node;


lint total, base, rem;

inline lint get_shuld(const int k) {
    return base + lint(k < rem);
}

int main() {
    
    if (n <= 1000000) {
        lint sum = 0, flow = 0, ans = 0;
        for (lint i = 1; i <= n; ++ i) {
            sum += GetStackHeight(i);
        }
        for (lint i = 1; i <= n; ++ i) {
            ans = (ans + abs(flow)) % mod;
            flow += GetStackHeight(i) - (sum / n + lint(i - 1 < sum % n));
        }
        if (id == 0) {
            printf("%lld\n", ans);
        }
    } else {

        lint sum = 0;
        for (lint k = l; k < r; ++ k) {
            sum += GetStackHeight(k + 1);
        }

        PutLL(0, sum);
        Send(0);

        if (id == 0) {
            lint tot = 0;
            for (int i = 0; i < node; ++ i) {
                Receive(i);
                tot += GetLL(i);
            }
            for (int i = 0; i < node; ++ i) {
                PutLL(i, tot);
                Send(i);
            }
        }

        Receive(0);
        total = GetLL(0);

        base = total / n;
        rem = total % n;

        lint shuld = 0;
        for (lint k = l; k < r; ++ k) {
            shuld += get_shuld(k);
        }

        lint flow = 0;
        if (id == 0) {
            if (node > 1) {
                PutLL(1, sum - shuld);
                Send(1);
            }
        } else {
            Receive(id - 1);
            flow = GetLL(id - 1);
            if (id + 1 < node) {
                PutLL(id + 1, flow + sum - shuld);
                Send(id + 1);
            }
        }

        lint ans = 0;
        for (lint k = l; k < r; ++ k) {
            flow += GetStackHeight(k + 1) - get_shuld(k);
            ans = (ans + abs(flow)) % mod;
        }

        PutLL(0, ans);
        Send(0);

        if (id == 0) {
            lint ret = 0;
            for (int i = 0; i < node; ++ i) {
                Receive(i);
                ret += GetLL(i);
            }
            printf("%lld\n", ret % mod);
        }
    }

    return 0;
}

