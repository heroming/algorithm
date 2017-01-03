/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/12/30 06:01:01
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
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
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
    
    const static int inf = 0x80000000;

    int solve(const vector<int> & v, const int w) {
        const int n = v.size();
        int s = 0;
        int ret = inf;
        set<int> se;
        se.insert(0);
        for (int i = 0; i < n; ++ i) {
            s += v[i];
            auto it = se.lower_bound(s - w);
            if (it != se.end()) {
                ret = max(ret, s - *it);
            }
            se.insert(s);
        }
        return ret;
    }
    
    int solve(vector<vector<int>> & mat, const int w) {
        const int n = mat.size(), m = mat[0].size();
        for (int j = 0; j < m; ++ j) {
            for (int i = 1; i < n; ++ i) {
                mat[i][j] += mat[i - 1][j];
            }
        }
        
        int ans = inf;
        for (int j = 0; j < n; ++ j) {
            for (int i = 0; i <= j; ++ i) {
                vector<int> v(m);
                if (i == 0) {
                    for (int k = 0; k < m; ++ k) {
                        v[k] = mat[j][k];
                    }
                } else {
                    for (int k = 0; k < m; ++ k) {
                        v[k] = mat[j][k] - mat[i - 1][k];
                    }
                }
                ans = max(ans, solve(v, w));
                if (ans == w) return ans;
            }
        }
        return ans;
    }
    
    int maxSumSubmatrix(vector<vector<int>> & mat, int w) {
        const int n = mat.size(), m = mat[0].size();
        if (n <= m) return solve(mat, w);
        vector<vector<int>> v(m);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                v[j].push_back(mat[i][j]);
            }
        }
        return solve(v, w);
    }
};

int main() {
    Solution so;
    vector<int> u{1, 0, 1};
    vector<int> v{0, -2, 3};
    vector<vector<int>> mat;
    mat.push_back(u);
    mat.push_back(v);
    printf("%d\n", so.maxSumSubmatrix(mat, 2));
    return 0;
}
