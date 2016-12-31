/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/12/17 19:02:28
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

const int _K=50268147,_B=6082187,_P=100000007;
int _X;
inline int get_rand(int _l,int _r){
    _X=((long long)_K*_X+_B)%_P;
    return _X%(_r-_l+1)+_l;
}

int t,n,m,k,seed;
int x[1000006],y[1000006];
void Init(){
    scanf("%d%d%d%d",&n,&m,&k,&seed);
    _X=seed;
    for (int i=1;i<=k;++i)
        x[i]=get_rand(1,n),
        y[i]=get_rand(1,m);
}

bool row[1000006], col[1000006];

int main() {
    scanf("%d", &t);
    while (t --) {
        Init();
        int a = n, b = m;
        clr(row, 1);
        clr(col, 1);
        form (i, 1, k) {
            if (row[x[i]]) {
                -- a;
                row[x[i]] = 0;
            }
            if (col[y[i]]) {
                -- b;
                col[y[i]] = 0;
            }
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}
