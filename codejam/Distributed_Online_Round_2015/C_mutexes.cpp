/*
 * Author:heroming
 * File:distributed.cpp
 * Time:2016/7/17 20:15:39
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
#include "mutexes.h"

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

const lint n = NumberOfOperations(0);
const lint m = NumberOfOperations(1);

const int id = MyNodeId();
const int node = NumberOfNodes();

const lint ln = n * id / node;
const lint rn = n * (id + 1) / node;

const lint lm = m * id / node;
const lint rm = m * (id + 1) / node;

const int master = 0;

const int maxn = 100010;

int oper_x[maxn];
int oper_y[maxn];
bool mutex_x[maxn];
bool mutex_y[maxn];

int main() {
    
    // initialize all the operation of two thread
    for (int k = 0; k < n; ++ k) {
        oper_x[k] = GetOperation(0, k);
    }
    
    for (int k = 0; k < m; ++ k) {
        oper_y[k] = GetOperation(1, k);
    }
    
    int deadlock = maxn;
    
    // for first thread run first
    clr(mutex_x, 0);
    for (int k = 0; k < ln; ++ k) {
        int x = oper_x[k];
        if (x < 0) {
            mutex_x[-x] = 0;
        } else {
            mutex_x[x] = 1;
        }
    }
 
    // for every acquire operation of first thread in [ln, rn)
    for (int k = ln; k < rn; ++ k) {
        int x = oper_x[k];
        if (x < 0) {
            mutex_x[-x] = 0;
        } else {
            
            memcpy(mutex_y, mutex_x, sizeof(mutex_y));
            
            // follow all operation of thread 1
            for (int i = 0; i < m; ++ i) {
                int y = oper_y[i];
                if (y < 0) {
                    mutex_y[-y] = 0;
                } else {

                    // check if two thread wait resource for each other
                    if (mutex_y[y]) {
                        if (mutex_y[x]) {
                            deadlock = min(deadlock, k + i + 2);
                        }
                        break;
                    }
                    mutex_y[y] = 1;
                }
            }
            mutex_x[x] = 1;
        }
    }
    
    // for second thread run first
    clr(mutex_y, 0);
    for (int k = 0; k < lm; ++ k) {
        int y = oper_y[k];
        if (y < 0) {
            mutex_y[-y] = 0;
        } else {
            mutex_y[y] = 1;
        }
    }
 
    // for every acquire operation of second thread in [lm, rm)
    for (int k = lm; k < rm; ++ k) {
        int y = oper_y[k];
        if (y < 0) {
            mutex_y[-y] = 0;
        } else {
            
            memcpy(mutex_x, mutex_y, sizeof(mutex_x));
            
            // follow all operation of thread 1
            for (int i = 0; i < n; ++ i) {
                int x = oper_x[i];
                if (x < 0) {
                    mutex_x[-x] = 0;
                } else {

                    // check if two thread wait resource for each other
                    if (mutex_x[x]) {
                        if (mutex_x[y]) {
                            deadlock = min(deadlock, k + i + 2);
                        }
                        break;
                    }
                    mutex_x[x] = 1;
                }
            }
            mutex_y[y] = 1;
        }
    }
    
    // send deadlock information to master
    PutInt(master, deadlock);
    Send(master);
    
    // master get deadlock information and print answer
    if (id == master) {
        int ans = maxn;
        for (int no = 0; no < node; ++ no) {
            Receive(no);
            ans = min(ans, GetInt(no));
        }
        if (ans == maxn) {
            printf("OK\n");
        } else {
            printf("%d\n", ans);
        }
    }
}

