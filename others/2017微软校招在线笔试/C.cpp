/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/10/10 20:05:53
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

const int maxm = 110;
const int maxn = 10010;
const lint inf = 0xFFFFFFFFFFFFFFFLL;

struct Student {
    lint t, id, ans;
    queue<pint> regist;
};

struct Item {
    lint t, id;
    int no, office;
    bool operator < (const Item & s) const {
        return t < s.t || (t == s.t && id < s.id);
    }
} it;

struct ItemCmp {
    bool operator() (Item a, Item b) const {
        return a.t > b.t || (a.t == b.t && a.id > b.id);
    }
};

lint ti[maxm];
int n, m, walk;
vector<Student> v;
priority_queue<Item, vector<Item>, ItemCmp> que;

int main() {

    cin >> n >> m >> walk;
    forn (k, n) {
        Student s;
        cin >> s.id >> s.t;
        v.pb(s);
        int off, a, b;
        cin >> off;
        forn (i, off) {
            cin >> a >> b;
            v[k].regist.push({a, b});
        }
        it.no = k;
        it.id = s.id;
        it.t = s.t + walk;
        it.office = v[k].regist.front().px;
        que.push(it);
    }
    
    clr(ti, 0);
    while (! que.empty()) {
        Item item = que.top();
        que.pop();
        int idx = item.no;
        int off = item.office;
        pint p = v[idx].regist.front();
        v[idx].regist.pop();
        ti[off] = item.t = max(ti[off], item.t) + p.py;
        if (v[idx].regist.empty()) {
            v[idx].ans = item.t;
        } else {
            item.t += walk;
            item.office = v[idx].regist.front().px;
            que.push(item);
        }
    }
    forn (i, n) cout << v[i].ans << endl;
    return 0;
}
