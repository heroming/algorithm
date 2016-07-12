/*
 * Author:heroming
 * File:_run_python.cpp
 * Time:2015/9/12 11:27:49
 */
#include <vector>
#include <list>
#include <cmath>
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

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define clr(v, e) memset(v, e, sizeof(v))
#define forn(i, n) for (int i = 0; i < n; ++ i)
#define form(i, a, b) for (int i = a; i <= b; ++ i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vs;
typedef pair<int,int> pint;
typedef vector<long long> vlint;

const int maxn = 256;

int main(int argc, char ** argv) {
    char runcommand[maxn] = {};
    sprintf(runcommand, "python %s", argv[1]);
    int start_time = clock();
    system(runcommand);
    int end_time = clock();
    printf("\nRun Time: %dms\n", end_time - start_time);
    return 0;
}
