/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/11 07:27:05
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
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

class MaxHeap {
    int idx;
    vint v;
public :
    MaxHeap(): idx(0) {}
    MaxHeap(int n): idx(0), v(vint(n + 1, 0)) {}
    
    bool empty() const {
        return size() == 0;
    }
    
    int size() const {
        return idx;
    }
    
    void push(int w) {
        int k = ++ idx;
        v[k] = w;
        while (k > 1) {
            int p = k >> 1;
            if (v[k] <= v[p]) break;
            swap(v[k], v[p]);
            k = p;
        }
    }
    
    int pop() {
        if (empty()) return 0;
        int ret = v[1];
        swap(v[1], v[idx --]);
        int k = 1;
        while (k < idx) {
            int h = k, l = (k << 1), r = (k << 1 | 1);
            if (l <= idx && v[h] < v[l]) h = l;
            if (r <= idx && v[h] < v[r]) h = r;
            if (h == k) break;
            swap(v[k], v[h]);
            k = h;
        }
        return ret;
    }
};


int main() {
    int n, w;
    char c[4];
    scanf("%d", &n);
    MaxHeap heap(n);
    forn (i, n) {
        scanf("%s", c);
        if (c[0] == 'A') {
            scanf("%d", &w);
            heap.push(w);
        } else {
            printf("%d\n", heap.pop());
        }
    }
    return 0;
}
