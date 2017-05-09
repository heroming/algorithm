/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/08 04:14:08
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
#include <unordered_map>
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

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> & v, int m) {
        set<pair<int, int>> se;
        vector<double> ans;
        for (int i = 0; i < m; ++ i) {
            se.insert({v[i], i});
        }
        int n = v.size();
        int s = (m - 1) >> 1;
        auto it = se.begin();
        for (int i = 0; i < s; ++ i) ++ it;
        if (m & 1) {
            ans.push_back(it->first);
        } else {
            double x = it->first;
            ++ it;
            x = (x + it->first) * 0.5;
            -- it;
            ans.push_back(x);
        }
        for (int i = m; i < n; ++ i) {
            pair<int, int> l = {v[i - m], i - m};
            pair<int, int> r = {v[i], i};
 
            se.insert(r);
            if (l == *it) {
                if (r < *it) {
                    -- it;
                } else {
                    ++ it;
                }
            } else {
                if (l < *it) {
                    if (r > *it) ++ it;
                } else {
                    if (r < *it) -- it;
                }
            }
            se.erase(l);

            if (m & 1) {
                ans.push_back(it->first);
            } else {
                double x = it->first;
                ++ it;
                x = (x + it->first) * 0.5;
                -- it;
                ans.push_back(x);
            }
        }
        return ans;
    }
};

int main() {
    Solution so;
    return 0;
}
