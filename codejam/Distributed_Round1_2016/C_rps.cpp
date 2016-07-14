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
#include "rps.h"

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

const int maxn = 4200000;

const lint n = GetN();
    
const int node = NumberOfNodes();
const int id = MyNodeId();

int v[maxn];
char s[maxn];

void solve(const lint a, const lint b) {
    lint m = b - a;
    while (m > 1) {
        for (int i = 0; i < m; i += 2) {
            bool left = 1;
            if ((s[i] == 'R' && s[i + 1] == 'P')
                    || (s[i] == 'P' && s[i + 1] == 'S')
                    || (s[i] == 'S' && s[i + 1] == 'R')) {
                left = 0;
            }
            if (left) {
                s[i >> 1] = s[i];
                v[i >> 1] = v[i];
            } else {
                s[i >> 1] = s[i + 1];
                v[i >> 1] = v[i + 1];
            }
        }
        m >>= 1;
    }
}

int main() {
    lint bit = 0;
    const lint team = 1LL << n;
    while ((1LL << (bit + 1)) <= node && (1LL << (bit + 1)) <= team) ++ bit;
    const lint part = 1LL << bit;
    if (id < part) {
        const lint l = team * id / part;
        const lint r = team * (id + 1) / part;
        for (lint k = l; k < r; ++ k) {
            v[k - l] = k;
            s[k - l] = GetFavoriteMove(k);
        }

        solve(l, r);

        PutChar(0, s[0]);
        PutInt(0, v[0]);
        Send(0);

        if (id == 0) {
            for (int i = 0; i < part; ++ i) {
                Receive(i);
                s[i] = GetChar(i);
                v[i] = GetInt(i);
            }
            solve(0, part);
            printf("%d\n", v[0]);
        }
    }

    return 0;
}

